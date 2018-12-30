#pragma once
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <vector>
#include <string>
class TRANS
{
	struct MemoryStruct {
		char *memory;
		size_t size;
	};

	static size_t
		WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
	{

		size_t realsize = size * nmemb;
		struct MemoryStruct *mem = (struct MemoryStruct *)userp;
		//需要的数据大于现在的存储空间，重新分配存储空间
		mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
		if (mem->memory == NULL) {
			printf("not enough memory (realloc returned NULL)\n");
			return 0;
		}
		//将数据拷贝到原来的结构
		memcpy(&(mem->memory[mem->size]), contents, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
		return realsize;
	}
	//requests_for_dst用于得到返回的Unicode码
private:
	char *requests_for_dst(char *q) {
		CURL *curl;
		CURLcode res;
		struct MemoryStruct chunk;
		chunk.memory = (char*)malloc(1);
		chunk.size = 0;
		curl = curl_easy_init();
		if (curl) {
			char myurl[1000] = "http://api.fanyi.baidu.com/api/trans/vip/translate?";
			char *appid = const_cast<char*>("20181115000235023");    //replace myAppid with your own appid
																	 //char *q = const_cast<char*>("my\nname\nis\nBob");          //replace apple with your own text to be translate, ensure that the input text is encoded with UTF-8!
			char *from = const_cast<char*>("en");          //replace en with your own language type of input text
			char *to = const_cast<char*>("zh");            //replace zh with your own language type of output text
			char salt[60];
			int a = rand();
			sprintf(salt, "%d", a);
			char *secret_key = const_cast<char*>("5bmd55BmOMEQj845fiks");   //replace mySecretKey with your own mySecretKey
			char sign[120] = "";
			strcat(sign, appid);
			strcat(sign, q);
			strcat(sign, salt);
			strcat(sign, secret_key);
			//printf("%s\n", sign);
			unsigned char md[16];
			int i;
			char tmp[3] = { '\0' }, buf[33] = { '\0' };
			MD5((unsigned char *)sign, strlen(sign), md);
			for (i = 0; i < 16; i++) {
				sprintf(tmp, "%2.2x", md[i]);
				strcat(buf, tmp);
			}
			//printf("%s\n", buf);
			strcat(myurl, "appid=");
			strcat(myurl, appid);
			strcat(myurl, "&q=");
			strcat(myurl, q);
			strcat(myurl, "&from=");
			strcat(myurl, from);
			strcat(myurl, "&to=");
			strcat(myurl, to);
			strcat(myurl, "&salt=");
			strcat(myurl, salt);
			strcat(myurl, "&sign=");
			strcat(myurl, buf);
			//printf("%s\n", myurl);
			//进行URL,但是下面函数好像没有用
			//q = const_cast<char*>("my\\nname\\is\\Bob\\.");
			//设置访问的地址
			curl_easy_setopt(curl, CURLOPT_URL, &myurl);
			//接收数据函数
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
			//接收数据的存储地址
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
			res = curl_easy_perform(curl);
			/* Check for errors */
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			/* always cleanup */
			curl_easy_cleanup(curl);
		}
		return chunk.memory;
	}
	std::string get_ch_answer(char *s) {
		std::string tmp;
		int sum = 0;
		for (int i = 0; sum < 18; ++i) {
			if (sum == 17 && s[i] != '"') tmp.push_back(s[i]);
			if (s[i] == '"') {
				++sum;
			}
		}
		return tmp;
	}
	char* print_ch_char(std::string s) {

	}
public:
	TRANS() {}
	~TRANS() {}
	std::string translate(char *s) {
		char *tmp = requests_for_dst(s);
		return get_ch_answer(tmp);
	}
};

