#define MAX 13
int vis[MAX][2] = {0};
int g_count = 0;
void Step(char** res, char* S, char* ans, int box, int index, int len)
{
	int i;
	if (box == 0) {
        memcpy(res[g_count], ans, len + 1);
        g_count++;
		return;
	}
	for (i = index; i < len; i++) {
		if (vis[i][0] == 1 && vis[i][1] == 1) {
			ans[i] = S[i];
			continue;
		}
		if (vis[i][0] != 1) {
			vis[i][0] = 1;
			ans[i] = S[i];
			Step(res, S, ans, box - 1, i + 1, len);
			vis[i][0] = 0;
		}
		if (vis[i][1] != 1) {
			vis[i][1] = 1;
			ans[i] = (S[i] >= 'a' && S[i] <= 'z') ? (S[i] - 32) : (S[i] + 32);
			Step(res, S, ans, box - 1, i + 1, len);
			vis[i][1] = 0;
		}	
	}
}

char ** letterCasePermutation(char * S, int* returnSize){
	int len, i;
	int box = 0;
	int sum = 1;
	char **res;
	char* ans ;
	len = strlen(S);
	g_count = 0;
	// 计算总共的大小，并标记非字母的已经处理
	for (i = 0; i < len; i++) {
		if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
			sum *= 2;
			box++;
			vis[i][0] = 0;
			vis[i][1] = 0;
		}
		else {
			vis[i][0] = 1;
			vis[i][1] = 1;
		}
	}
	// 如果没有字母直接返回原串
	if(box == 0) {
		*returnSize = 1;
		res = (char**)malloc(sizeof(char*) * (*returnSize));
		res[0] = (char*)malloc(sizeof(char) * (len + 1));
		memcpy(res[0], S, len + 1);
		return res;
	}
	// 分配空间
	*returnSize = sum;
	res = (char**)malloc(sizeof(char*) * (*returnSize));
	for (i = 0; i < *returnSize; i++) {
		res[i] = (char*)malloc(sizeof(char) * (len + 1));
		memset(res[i], 0 , sizeof(char) * (len + 1));
	}
	// ans用于保存每次step的结果，如果直接用res[g_count][i]会导致越界。这里赋值，可以规避像1ab2的串第一次只返回1ab的问题
	ans = (char*)malloc(len + 1);
	memcpy(ans, S, len + 1);
	
	Step(res, S, ans, box, 0, len);
    return res;
}