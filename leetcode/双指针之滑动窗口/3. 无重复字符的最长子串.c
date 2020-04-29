#define MAX 256
#define GET_MAX(a, b) ((a) >= (b)) ? (a) : (b)
int lengthOfLongestSubstring(char * s)
{
    int left = 0;
    int right = 0;
    int window[MAX] = {0};
    int len;
    int res = -1;
    int curRes = 0;
    if (s == NULL) {
        return 0;
    }
    len = strlen(s);
    if (len <= 0) {
        return 0;
    }
    // 尽可能的去扩展右边界，对于现有window的长度curRes,只有在当前元素的计数window[s[right]]为1的时候对其累加
    for (right = 0; right < len; right++) {
        window[s[right]]++;
        curRes += window[s[right]] == 1 ? 1 : 0;
        res = GET_MAX(res, curRes);
        // 如果s[right]计数超过1，就缩小区间移动left去重,这期间可能把长度变短，条件是移除了一个元素，恰好使其为0了，window的长度肯定变短了
        while (window[s[right]] > 1) {
            window[s[left]]--;
            if (window[s[left]] == 0) {
                curRes--;
            }
            left++;
        }
    }
    return res;
}
