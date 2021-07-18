#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<time.h>
#define LOG_PATH "E:\\code_workpath\\code_block\\va_arg\\log.txt"
#define DEBUG(...)  printf(__VA_ARGS__)
typedef enum {
    LEVEL_INIT,
    LEVEL_EEROR,
    LEVEL_INFO
}LOG_LEVEL;
void TestLog(LOG_LEVEL level, char* fmt)
{
    FILE* fp = NULL;
    char strBuff[1024] = {0};
    fp = fopen(LOG_PATH, "a+");
    if (fp == NULL) {
        return;
    }
    switch(level) {
        case LEVEL_INIT:
            fprintf(fp, fmt);
            fclose(fp);
            break;
        case LEVEL_INFO:
            break;
        default:
            break;
    }
}
#define InitLog(fmt, ...) \
do {\
    char buff[1024] = {0};\
    time_t timer;\
	struct tm* tmer;\
	char* str;\
	time(&timer);\
	tmer = localtime(&timer);\
	str = asctime(tmer);\
	strcat(buff, str);\
	sprintf(&buff[strlen(buff) - 1], " init error  %s, %d: "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    TestLog(LEVEL_INIT, buff);\
}while(0)


#define TestInfoLog(fmt, ...) \
do {\
    char buff[1024] = {0};\
    sprintf(buff, "Test error %s,%d: "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    TestLog(LEVEL_TEST, buff);\
}while(0)

int main()
{
    InitLog("hello %s %d\n", "world", 100);
}
