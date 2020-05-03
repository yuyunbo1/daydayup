/*
输入: "199100199"
输出: true
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
        // 截取字符串
        GetFromStr(num, curSum, i, ans);
        // 如果此次截取的长度非1，并且首字母是0则不符合
        if (ans[0] == '0' && i != 1) {
            continue;
        }
        temp = atoll(ans);
        // 如果res中已经有2个结果了，那么需要判断是否符合2个之和是否为当前这个数
        if (box > 1 && res[box - 2] + res[box - 1] < temp) {
            return 0;
        }
        if (box > 1 && res[box - 2] + res[box - 1] > temp) {
            continue;
        }
        res[box] = temp;
        // 这个写法可以在找到一个结果的时候，也让上层函数栈返回结果，因此上层直接在下面判断这个rs，就不会继续
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
