/*1.第N层，第K个位置上的数字，是由N-1层，（K+1）/2位置上的数字生成的。（记N-1层，（K+1）/2位置上的数字为last）。 

2.如果last是0，那么last第N行生成了01，如果K%2==0，说明K是偶数，返回1；否则返回0； 
  如果last是1，那么last第N行生成了10，如果K%2==1，说明K是奇数，返回1；否则返回0； 
  把这两条规律一起综合成if else的判断。
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001
  */
int kthGrammar(int N, int K)
{
	if (N == 1 || K == 1) {
		return 0;
	}
	if (K == 2) {
		return 1;
	}
	if (kthGrammar(N - 1, (K + 1) / 2) == 0) {
		if (K % 2 == 0) {
			return 1;
		}
		else {
			return 0;
		}	
	}
    else {
        if (K % 2 == 0) {
			return 0;
		}
		else {
			return 1;
		}	
    }
}