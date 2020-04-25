    char * minWindow(char * s, char * t)
{
    int window[256] = {0};
    int need[256] = {0};
    int i;
    int tLen, sLen;
    int left = 0;
    int right = 0;
    int matchNum = 0;
    char temp;
    int res = 10000000;
    int startindex = 0;
    char *ans = NULL;
    int targetLen = 0;
    sLen = strlen(s);
    tLen = strlen(t);
    startindex = -1;
    if (s == NULL || t == NULL || sLen <= 0 || tLen == 0) {
        ans = (char*)calloc(1, sizeof(char));
        ans[0] = '\0';
    }
    sLen = strlen(s);
    tLen = strlen(t);
    ans = (char*)calloc(sLen + 1, sizeof(char));
    // 初始化hash表
    for (i = 0; i < tLen; i++) {
        need[t[i]]++;
        if (need[t[i]] == 1) {
            targetLen++;
        }
    }

    for (right = 0; right < sLen; right++) {
        // 不受关注的字符直接跳过
        if (need[s[right]] <= 0) {
            continue;
        }
        window[s[right]]++;
        if (window[s[right]] == need[s[right]]) {
             matchNum++;
        }
        // 当找到可行解之后优化可行解,使用targetLen 是防止t中有重复字符串
        while (matchNum == targetLen) {
            if (res >= right - left) {
                res = right - left;
                startindex = left;
            }
            temp = s[left];
            // 如果不是关注的字符，直接丢弃
            if (need[temp] <= 0) {
                left++;
                continue;
            }
            window[temp]--;
            if (window[temp] < need[temp]) {
                matchNum--;
            }
            left++;
        }
    }
    if (startindex == -1) {
        return ans;
    }
    memcpy(ans, &s[startindex], res + 1);
    return ans;
}
