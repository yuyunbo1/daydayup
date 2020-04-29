/**
˼·��
�������ڡ��ѵ�����Ҫ��¼�����в�ͬ�ַ��ĸ�����
�������룺����ͬ���ַ��� = ���ڵ���Ŀ �C ������ͬ�������細��ΪABCC��A,B��C����Ŀ�ֱ�Ϊ1��1��2��,����ͬ�ĸ���Ϊ 4 �C 2��

Windows�����¼��ǰ�����и����ַ���Ӧ�ĸ�����
MaxSame��¼��ǰ��ͬ�������ĸ���
MaxSameIndex��¼��ͬ����������ĸ���±ꡣ

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
		// ����maxSame ��maxSameIndex
        if (windows[s[right]] >= maxSame) {
            maxSame = windows[s[right]];
            maxSameIndex = right;
        }
        // ��ǰ�����в�ͬ��ĸ�ĸ��� = ���ڳ��� - �ظ���������
        diffNum = (right - left + 1) - maxSame;
        while (diffNum > k) {
            // �������ɾȥ�Ĳ�������Ԫ�أ�����ֱ��ɾ��
            if (left != maxSameIndex) {
                windows[s[left]]--;
                left++;
                diffNum = (right - left + 1) - maxSame;
            } else {// ���������Ԫ�أ������maxSame
                maxSame--;
                windows[s[left]]--;
                left++;
                diffNum = (right - left + 1) - maxSame;
            }
        }
		//��ǰ�Ľ��Ϊ������ͬ��+��ͬ��
        max = GET_MAX(max, maxSame + k);
}
// Ϊ�˹����ĸȫ����ͬ�����
    return max > len ? len : max;
}
