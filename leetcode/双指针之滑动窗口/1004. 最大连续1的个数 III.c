#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)
int longestOnes(int* A, int ASize, int K)
{
    int left = 0;
    int right = 0;
    int zeroNum = 0;
    int tmpLen = -1;
    for (right = 0; right < ASize; right++) {
        if (A[right] == 0) {
            zeroNum++;
        }
        // ���ܵ��ڣ�����{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1},K = 3 indexΪ9֮���2��1��©��
        while (zeroNum > K) {
            if (A[left] == 0) {
                zeroNum--;
            }
            left++;
        }
        tmpLen = GET_MAX(tmpLen, right - left + 1);
    }
    return tmpLen;
}

