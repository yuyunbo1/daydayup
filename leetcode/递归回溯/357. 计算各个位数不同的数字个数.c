int CountN(int n)
{
    int sum = 1;
    int i;
    if (n == 0) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        if (i == 0) {
            sum *= 9;
        } else {
            sum *= (10 - i);
        }
    }
    return sum + CountN(n -1);
}
int countNumbersWithUniqueDigits(int n){
    //return  CountN(n);
}

// Ò»°ãĞ´·¨
/*
int CountN1(int n)
{
    int i;
    int sum = 1;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            sum *= 9;
        }
        else {
            sum *= (10 -i);
        }
    }
    return sum;
}
int countNumbersWithUniqueDigits(int n){
    //return  CountN(n);

    int i;
    int sum = 0;
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 10;
    }
    sum = 10;
    for (i = 2; i <= n; i++) {
        sum += CountN1(i);
    }
    return sum;
}
*/
