/*
1.快速幂法
因为任意一个整数都可以用二进制表示，如10即1010,因此x^10 = (x^2)^3) * x^(2^2),即对对应为1的项进行累乘
*/
double quick_mul(double x, int n)
{
	double res = 1;
	while (n > 0) {
		if (n & 0x1 == 1) {
			res *= x;
		}
		x = x * x;
		n = n >>1;
	}
	return res;
}
double myPow(double x, int n)
{
	if (x == 1) {
		return 1;
	}
	if (x == -1) {
		if (n % 2 == 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	if (n == -2147483648) {
		return 0;
	}
	if (n > 0) {
		return quick_mul(x, n);
	}
	else {
		n = -n;
		return 1 / quick_mul(x, n);
	}

}

/* 2.递归法
fun(x,n) = x^n;
fun(x,n) = fun(x,n/2) *  fun(x,n/2)
或者fun(x,n) = fun(x,n/2) *  fun(x,n/2) * x
*/
double func(double x, int n)
{
	double temp;
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		temp = func(x, n/2);
		return temp * temp;
	}
	else {
		temp = func(x, n/2);
		return temp * temp * x;
	}
}

double myPow(double x, int n)
{
	double res = 1;
	int i;
	
	if (x == 1) {
		return 1;
	}
	if (x == -1) {
		if (n % 2 == 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	// 因为取反我的话是0了
	if (n == -2147483648) {
		return 0;
	}
	if (n < 0) {
		n = -n;
		res = func(x, n);
		return 1 / res;
	}
	res = func(x, n);
	return res;
}