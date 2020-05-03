#define MAX 9 
static char* g_table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char **res = NULL;
char* ans = NULL;
int g_count = 0;
//int vis[10][4] = {0};

void step(char *digits, int box, int box_max)
{
	int i;
	if (box == box_max) {
		memcpy(res[g_count], ans, strlen(ans));
		g_count++;
		return;
	}
	for (i = 0; i < strlen(g_table[digits[box] - '0']); i++) {
		//if (vis[digits[box] - '0'][i] == 0) {
			//vis[digits[box] - '0'][i] = 1;
			ans[box] = g_table[digits[box] - '0'][i];
			step(digits, box + 1, box_max);
			//vis[digits[box] - '0'][i] = 0;
		//}
	}
}

char ** letterCombinations(char * digits, int* returnSize){
	
	int sum = 1;
	int i, j, len;
	
	g_count = 0;
	len  = strlen(digits);

	if (len == 0) {
		res = (char**)malloc(sizeof(char*));
		*returnSize = 0;
		return res;
	}

	// 计算总共可以返回多少个字符串
	for (i = 0; i < len; i++) {
		sum *= strlen(g_table[digits[i] - '0']);
	}
	*returnSize = sum;
	// 分配空间
	res = (char**)malloc(sum * sizeof(char*));
	for (i = 0; i < sum; i++) {
		res[i] = malloc(sizeof(char) * MAX);
		memset(res[i], 0, sizeof(char) * MAX);
	}
	/*for (i = 0; i < 10; i++) {
		for (j = 0; j < 4; j++) {
            vis[i][j] = 0;
        }
	}*/
	ans = (char*)malloc(MAX);
	memset(ans, 0 , MAX);
	step(digits, 0, len);
    return res;
}