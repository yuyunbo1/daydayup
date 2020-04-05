/*
����: "199100199"
���: true
����: �ۼ�����Ϊ: 1, 99, 100, 199��1 + 99 = 100, 99 + 100 = 199

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/additive-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define bool int
#define true 1
#define false 0
void GetFromStr(char* source, int start, int size, char* target)
{
    int len = strlen(source);
    if (start > len || size > len) {
        return;
    }
    memcpy(target, &source[start], size);
    target[size] = '\0';
}
int Step(char* num, char* ans, unsigned long long* res, int box, int curSum)
{
    int i;
    unsigned long long temp;
    int len = strlen(num);
    int rs = 0;
    if (curSum == len && box > 2) {
        for (i = 0; i < box; i++) {
            printf("%l ",res[i]);
        }
        return 1;
    }
    for (i = 1; i <= len && i + curSum <= len; i++) {
        // ��ȡ�ַ���
        GetFromStr(num, curSum, i, ans);
        // ����˴ν�ȡ�ĳ��ȷ�1����������ĸ��0�򲻷���
        if (ans[0] == '0' && i != 1) {
            continue;
        }
        temp = atoll(ans);
        // ���res���Ѿ���2������ˣ���ô��Ҫ�ж��Ƿ����2��֮���Ƿ�Ϊ��ǰ�����
        if (box > 1 && res[box - 2] + res[box - 1] < temp) {
            return 0;
        }
        if (box > 1 && res[box - 2] + res[box - 1] > temp) {
            continue;
        }
        res[box] = temp;
        // ���д���������ҵ�һ�������ʱ��Ҳ���ϲ㺯��ջ���ؽ��������ϲ�ֱ���������ж����rs���Ͳ������
        rs = Step(num, ans, res, box + 1, curSum + i);
        if (rs == 1) {
            return 1;
        }
    }
    return 0;
}

bool isAdditiveNumber(char * num)
{
    char* ans = NULL;
    int rs = 0;
    int len = strlen(num);
    unsigned long long* res = (long*)calloc(len, sizeof(unsigned long long));
    ans = (char*)calloc(len + 1, sizeof(char));
    if (len < 3) {
        return false;
    }
    rs = Step(num, ans, res, 0, 0);
    return rs;
}
int main()
{
    int rs = 0;
    rs = isAdditiveNumber("121474836472147483648");//2461016264268110179;121474836472147483648
    printf("\n%d\n", rs);
}
