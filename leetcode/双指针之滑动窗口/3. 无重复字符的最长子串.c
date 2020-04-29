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
    // �����ܵ�ȥ��չ�ұ߽磬��������window�ĳ���curRes,ֻ���ڵ�ǰԪ�صļ���window[s[right]]Ϊ1��ʱ������ۼ�
    for (right = 0; right < len; right++) {
        window[s[right]]++;
        curRes += window[s[right]] == 1 ? 1 : 0;
        res = GET_MAX(res, curRes);
        // ���s[right]��������1������С�����ƶ�leftȥ��,���ڼ���ܰѳ��ȱ�̣��������Ƴ���һ��Ԫ�أ�ǡ��ʹ��Ϊ0�ˣ�window�ĳ��ȿ϶������
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
