/* ˼·������+��֦

1.���ú��ӵķ�����Ҳ���Ƿ��ĸ�С����

2.step�Ķ����Ƿ�һ��С����

3.option��������ѡ�������ǰ��������startIndex,��ôС������Դ�startIndex-strlen(s)ѡ��, i < startIndex +3���ڼ�֦����

4.ÿһ��option����s��startIndexλ�ý�ȡ�ַ����ж�ֵ�������255���˳��������ȡ����������ĸΪ0���� ������Ȳ���1��Ҳ�ǷǷ����

5.����������boxΪ4���������ĸ�С���㣻������Ҫ��֤startIndex����С��strlen(s),�����255.2.5.5.11133

*/

#define RES_MAX 50
int g_count = 0;

void MySubstr(char *str, char* dst, int startIndex, int len)
{
	if (str == NULL) {
		dst[0] = 0;
		return;
	}
	memcpy(dst, (char*)&str[startIndex], sizeof(char) * len);
	dst[len] = '\0';
	return;
}

void step(char* s, char** res, char* ans, int ans_index, int box, int startIndex)
{
	int i;
	int len = strlen(s);
	char temp[50] = {0};
	if (box == 4) {
		if (startIndex < strlen(s)) {
            return;
		}
		// ans_index - 1��Ϊ�˲������һ��С���������
        memcpy(res[g_count], ans, ans_index - 1);
        g_count++;
		return;
	}
	// option�Ǵ�startIndex��startIndex + 3�в���
	for (i = startIndex; i < len && i < startIndex + 3; i++) {
		MySubstr(s, temp, startIndex, i - startIndex + 1);
		if (atoi(temp) > 255) {
			return;
		}
        // ���00. ��01.��001.�����
        if (temp[0] == '0' && strlen(temp) != 1) {
            return;
        }
		sprintf((char*)&ans[ans_index], "%s%s", temp, ".");
        // ans_index��Ҫ��ans_index + temp�ĳ��ȵĺ�һ����ʼ
		step(s, res, ans, ans_index + i - startIndex + 2, box + 1, i + 1);
	}
}

char ** restoreIpAddresses(char * s, int* returnSize){
	char** res = NULL;
	char* ans = NULL;
	int i;
	int len;
	g_count = 0;
	len = strlen(s);

    if (len >= 13) {
        *returnSize = 0;
        res = (char**)malloc(sizeof(char*));
        res[0] = (char*)malloc(sizeof(char));
        res[0][0] = '\0';
        return res;
    }

	res = (char**)malloc(sizeof(char*) * RES_MAX);
	for (i = 0; i < RES_MAX; i++) {
		res[i] = (char*)malloc(sizeof(char) * (len + 5));
		memset(res[i], 0, sizeof(char) * (len + 5));
	}
	ans = (char*)malloc(sizeof(char) * (len + 5));
	memset(ans, 0, sizeof(char) * (len + 5));
	step(s, res, ans, 0, 0, 0);
    free(ans);
	*returnSize = g_count;
	return res;
}
