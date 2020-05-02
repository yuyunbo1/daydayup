#include<stdio.h>
#include<stdlib.h>
int MyCmp(const void* a, const void* b)
{
    char** pa = (char**)a;
    char** pb = (char**)b;
    int paLen = strlen(*pa);
    int pbLen = strlen(*pb);
    int ret;
    int i = 0;
    if (paLen == pbLen) {
        for (i = 0; i < paLen; i++) {
            ret = strcmp(*pa, *pb);
            if (ret != 0) {
                return ret;
            }
        }
    } else {
        return paLen < pbLen;
    }
    return 0;
}
int IsSubStr(char* s, int sLen, char* target, int targetLen)
{
    int i = 0;
    int j = 0;
    while (i < sLen && j < targetLen) {
        if (s[i] == target[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (i == sLen && j < targetLen) {
        return 0;
    }
    return 1;
}
char * findLongestWord(char * s, char ** d, int dSize)
{
    int sLen = strlen(s);
    int i, j;

    if (dSize == 0 || sLen == 0) {
        return "";
    }
    qsort(d, dSize, sizeof(char*), MyCmp);
    for (i = 0; i < dSize; i++) {
        if (IsSubStr(s, sLen, d[i], strlen(d[i])) == 1) {
            return d[i];
        }
    }
    return "";
}
int main()
{
    char* d[] = {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};//"ale","apple","monkey","plea"
    //char **maz = NULL;
    int dSize = sizeof(d) / sizeof(char*);
    char* target = "aewfafwafjlwajflwajflwafj";
    char* res = NULL;
    int i;
    res = findLongestWord(target, d, dSize);
    printf("%s\n", res);
}
