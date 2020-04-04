#include<stdlib.h>
#include<stdio.h>
/*
思路：
可以用排列的思想，也就是盒子。for循环控制组合的个数，dfs控制组合个数为n时的排列种类。
如["cha","r","act","ers"]：
组合个数为4：
    其实只有一种。即元素0，1，2，3都选上 每次选取时新选取的都要去和当前ans比较如果有重复不继续
组合个数为3：同样每次选取时都和现有的ans比较，如果有重复立即停止
    0，1，2 cha,r,act 选act时就发现不行了
    0，1，3
    0，2，3
    1，2，3

注意：除了新选取的和现有ans比，还要判断当前元素是否自重复，比如yy，这个可以在dfs前对
输入数组处理，把重复的元素的下表直接设置为“已访问”

*/
int g_max = -1;
int* vis =NULL;
int* visBack = NULL;
// 判断str2中的字符是否在str1中出现了
int IsStr2SomeInStr1(char* str1, char* str2)
{
    int i;
    int len = strlen(str2);
    if (str1 == NULL) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (strchr(str1, str2[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}
int MyCmp(const void* a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    return *pa - *pb;
}
// 判断自重复
int IsSelfCom(char* s)
{
    char temp[50] = {0};
    int i;
    int len = strlen(s);
    if (len < 2) {
        return 0;
    }
    memcpy(temp, s, len);
    qsort(temp, len, sizeof(char), MyCmp);
    for (i = 0; i < len - 1; i++) {
        if (temp[i] == temp[i + 1]) {
            return 1;
        }
    }
    return 0;
}
void Step(char** arr, int size, int maxBox, int startIndex, char* ans, int ansIndex, int box)
{
    int i;
    int tmp;
    if (box == maxBox) {
        tmp = strlen(ans);
        g_max = (g_max < tmp) ? tmp : g_max;
        return;
    }
    for (i = startIndex; i < size; i++) {
        // vis[1] == 1表示已访问或者自重复 || 新加入的不能与当前的重复
        if (vis[i] == 1 || IsStr2SomeInStr1(ans, arr[i])) {
            continue;
        }
        vis[i] = 1;
        memcpy(&ans[ansIndex], arr[i], strlen(arr[i]) + 1);
        Step(arr, size, maxBox, i + 1, ans, ansIndex + strlen(arr[i]), box + 1);
        // 要把ans中的新增段给复原
        memset(&ans[ansIndex], 0, strlen(arr[i]) + 1);
        ans[ansIndex] = '\0';
        vis[i] = 0;
    }
}
int maxLength(char** arr, int arrSize)
{
    int i;
    int maxLen = 0;

    vis = calloc(arrSize, sizeof(int));
    visBack = calloc(arrSize, sizeof(int));
    char* ans = NULL;
    g_max = 0;
    for (i = 0; i < arrSize; i++) {
        // 对于自重复直接置为已访问，并且长度也只加
        if (IsSelfCom(arr[i])) {
            visBack[i] = 1;
            continue;
        }
        maxLen += strlen(arr[i]);
    }
    ans = calloc(maxLen + 1, sizeof(char));
    // for循环控制组合的个数
    for (i = arrSize; i > 0; i--) {
        memset(ans, 0, maxLen + 1);
        memcpy(vis, visBack, arrSize * sizeof(int));
        Step(arr, arrSize, i, 0, ans, 0, 0);
    }
    return g_max;
}
int main()
{
    char* arr[] = {"yy","bkhwmpbiisbldzknpm"};//{"cha","r","act","ers"};
    int len = maxLength(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n", len);
}
