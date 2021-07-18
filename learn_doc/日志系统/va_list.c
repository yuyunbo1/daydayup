#if 0
#define BOLI_SHM_LOG_PATH "/tmp/boli_shm.log"
static void MyLogFunc(char* buffer)
{
    int fd = open(BOLI_SHM_LOG_PATH, O_CREAT | O_APPEND | O_RDWR, 0666);
    write(fd, buffer, strlen(buffer));
    close(fd);
    return;
}
void (*g_logFunc)(char*) = MyLogFunc;
#else
void (*g_logFunc)(char*) = NULL;
#endif

static void BoliShmLog(char* fmt, ...)
{
    char buffer[1024] = {0};
    va_list arg;
    va_start(arg, fmt);
    (void)vsprintf(buffer, fmt, arg);
    if (g_logFunc == NULL) {
        printf("%s", buffer);
    } else {
        g_logFunc(buffer);
    }
    va_end(arg);
    return;
}
#define BOLI_SHM_LOG(fmt, ...) do {\
    char _buff[1024] = {0};\
	sprintf(_buff, "%s line [%d]: "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    BoliShmLog(_buff);\
}while(0)