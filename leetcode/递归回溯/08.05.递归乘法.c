/*
func(a,b) = a*b = func(a,b/2) + func(a,b/2)
ªÚ’ﬂfunc(a,b) = a*b = func(a,b/2) + func(a,b/2) + a
*/
int func(int a, int b)
{
	int temp;
	if (b == 0) {
		return 0;
	}
	if (b % 2 == 0) {
		temp = func(a, b / 2);
		return temp + temp;
	}
	else {
		temp = func(a, b / 2);
		return temp + temp + a;
	}

}
int multiply(int A, int B){
    return func(A,B);
}