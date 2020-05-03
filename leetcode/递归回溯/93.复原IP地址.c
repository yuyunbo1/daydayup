/* 思路：回溯+剪枝

1.采用盒子的方法，也就是放四个小数点

2.step的定义是放一个小数点

3.option是有三个选择，如果当前的索引是startIndex,那么小数点可以从startIndex-strlen(s)选择, i < startIndex +3属于剪枝操作

4.每一个option都从s的startIndex位置截取字符，判断值如果大于255就退出；如果截取下来的首字母为0，但 如果长度不是1，也是非法情况

5.结束条件是box为4，即放了四个小数点；并且需要保证startIndex不能小于strlen(s),即情况255.2.5.5.11133

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
		// ans_index - 1是为了不把最后一个小数点给带上
        memcpy(res[g_count], ans, ans_index - 1);
        g_count++;
		return;
	}
	// option是从startIndex到startIndex + 3中插入
	for (i = startIndex; i < len && i < startIndex + 3; i++) {
		MySubstr(s, temp, startIndex, i - startIndex + 1);
		if (atoi(temp) > 255) {
			return;
		}
        // 规避00. 及01.及001.的情况
        if (temp[0] == '0' && strlen(temp) != 1) {
            return;
        }
		sprintf((char*)&ans[ans_index], "%s%s", temp, ".");
        // ans_index需要从ans_index + temp的长度的后一个开始
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
