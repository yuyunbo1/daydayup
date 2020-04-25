#define MAX 256
#define GET_MAX(x, y) ((x) >= (y)) ? x : y
int* partitionLabels(char * S, int* returnSize)
{
    int hashIndex[MAX] = {0};
    int len;
    int* res = NULL;
    int resIndex = 0;
    int left, right;
    int start, end = 0;
    if (S == NULL || (len = strlen(S)) == 0) {
        *returnSize = 0;
        return NULL;
    }

    res = (int*)calloc(len, sizeof(int));
    for (right = len - 1; right >= 0; right--) {
        hashIndex[S[right]] = GET_MAX(right, hashIndex[S[right]]);
    }
    start = 0;
    // babcbacadefegdehijhklij
    for (right = 0; right < len; right++) {
        if (right > end) {
            res[resIndex] = end - start + 1;
            resIndex++;
            start = right;
        }
        end = GET_MAX(end, hashIndex[S[right]]);
    }
    res[resIndex] = end - start + 1;
    resIndex++;
    *returnSize = resIndex;
    return res;
}
