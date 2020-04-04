#include<stdlib.h>
#include<stdio.h>
/*
˼·��
���������е�˼�룬Ҳ���Ǻ��ӡ�forѭ��������ϵĸ�����dfs������ϸ���Ϊnʱ���������ࡣ
��["cha","r","act","ers"]��
��ϸ���Ϊ4��
    ��ʵֻ��һ�֡���Ԫ��0��1��2��3��ѡ�� ÿ��ѡȡʱ��ѡȡ�Ķ�Ҫȥ�͵�ǰans�Ƚ�������ظ�������
��ϸ���Ϊ3��ͬ��ÿ��ѡȡʱ�������е�ans�Ƚϣ�������ظ�����ֹͣ
    0��1��2 cha,r,act ѡactʱ�ͷ��ֲ�����
    0��1��3
    0��2��3
    1��2��3

ע�⣺������ѡȡ�ĺ�����ans�ȣ���Ҫ�жϵ�ǰԪ���Ƿ����ظ�������yy�����������dfsǰ��
�������鴦�����ظ���Ԫ�ص��±�ֱ������Ϊ���ѷ��ʡ�

*/
int g_max = -1;
int* vis =NULL;
int* visBack = NULL;
// �ж�str2�е��ַ��Ƿ���str1�г�����
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
// �ж����ظ�
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
        // vis[1] == 1��ʾ�ѷ��ʻ������ظ� || �¼���Ĳ����뵱ǰ���ظ�
        if (vis[i] == 1 || IsStr2SomeInStr1(ans, arr[i])) {
            continue;
        }
        vis[i] = 1;
        memcpy(&ans[ansIndex], arr[i], strlen(arr[i]) + 1);
        Step(arr, size, maxBox, i + 1, ans, ansIndex + strlen(arr[i]), box + 1);
        // Ҫ��ans�е������θ���ԭ
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
        // �������ظ�ֱ����Ϊ�ѷ��ʣ����ҳ���Ҳֻ��
        if (IsSelfCom(arr[i])) {
            visBack[i] = 1;
            continue;
        }
        maxLen += strlen(arr[i]);
    }
    ans = calloc(maxLen + 1, sizeof(char));
    // forѭ��������ϵĸ���
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
