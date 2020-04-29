/**
思路：
滑动窗口。难点在于要记录窗口中不同字符的个数。
反过来想：不相同的字符数 = 窗口的数目 – 最大的相同数，不如窗口为ABCC（A,B，C的数目分别为1，1，2）,，则不同的个数为 4 – 2。

Windows数组记录当前窗口中各个字符对应的个数。
MaxSame记录当前相同个数最大的个数
MaxSameIndex记录相同个数最大的字母的下标。

*/
#define MAX 256
#define GET_MAX(x, y) ((x) > y) ? (x) : (y)
int characterReplacement(char * s, int k)
{
    int windows[MAX] = {0};
    int diffNum = 0;
    int left = 0;
    int right;
    int max = -1;
    int maxSame = -1;
    int maxSameIndex;
    int len;
    if (s == NULL) {
        return 0;
    }
    len = strlen(s);
    if (len == 0) {
        return 0;
    }
    for (right = 0; right < len; right++) {
        windows[s[right]]++;
		// 更新maxSame 及maxSameIndex
        if (windows[s[right]] >= maxSame) {
            maxSame = windows[s[right]];
            maxSameIndex = right;
        }
        // 当前窗口中不同字母的个数 = 窗口长度 - 重复次数最多的
        diffNum = (right - left + 1) - maxSame;
        while (diffNum > k) {
            // 如果即将删去的不是最大的元素，可以直接删除
            if (left != maxSameIndex) {
                windows[s[left]]--;
                left++;
                diffNum = (right - left + 1) - maxSame;
            } else {// 如果是最大的元素，则更新maxSame
                maxSame--;
                windows[s[left]]--;
                left++;
                diffNum = (right - left + 1) - maxSame;
            }
        }
		//当前的结果为最大的相同数+不同数
        max = GET_MAX(max, maxSame + k);
}
// 为了规避字母全部相同的情况
    return max > len ? len : max;
}
