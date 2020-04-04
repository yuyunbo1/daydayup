#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 10
int g_count = 0;
int vis[N] = {0};
int CountSize(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * CountSize(n - 1);
}
int MyCmp(const void* a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    return *pa - *pb;
}
void Step(char** res, char* s, char* ans, int box)
{
    int i;
    int len = strlen(s);
    if (box == len) {
        memcpy(res[g_count], ans, box);
        res[g_count][box] = '\0';
        g_count++;
        return;
    }
    for  (i = 0; i < len; i++) {
        if (vis[i] == 1) {
            continue;
        }
        if (i > 0 && s[i - 1] == s[i] && vis[i - 1] == 0) {
            continue;
        }
        vis[i] = 1;
        ans[box] = s[i];
        Step(res, s, ans, box + 1);
        vis[i] = 0;
    }
}
char** permutation(char* s, int* returnSize){
    char** res = NULL;
    char* ans = NULL;
    char* temp = NULL;
    int i;
    int len = strlen(s);
    g_count = 0;
    *returnSize = CountSize(len);
    res = (char**)calloc(*returnSize, sizeof(char*));
    for (i = 0; i <*returnSize; i++){
        res[i] = (char*)calloc(len + 1, sizeof(char));
    }
    ans = (char*)calloc(len + 1, sizeof(char));
    temp = (char*)calloc(len + 1, sizeof(char));
    memcpy(temp, s, len + 1);
    qsort(temp, len, sizeof(char), MyCmp);
    printf("%s\n", temp);
    Step(res, temp, ans, 0);
    *returnSize = g_count;
    return res;
}

int main()
{
    char** res = NULL;
    int size = 0;
    int i = 0;
    res = permutation("aacbber", &size);
    for (i = 0; i < size; i++) {
        printf("%s\n", res[i]);
    }
    printf("%d\n",size);
}
