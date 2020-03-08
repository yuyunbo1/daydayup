#include<stdio.h>
#include<stdlib.h>

#define N 2

void step(char* buff, int index, int left, int right)
{
	if (index == 2 * N) {
		buff[index + 1] = '\0';
		printf("%s\n",buff);
	}
	if (left < N)
	{
		buff[index]  = '(';
		step(buff,index + 1, left + 1,right);
	}
	if (right < left) {
		buff[index]  = ')';
		step(buff,index + 1, left, right + 1);
	}

}
int main()
{
	char buff[100] = {0};
	step(buff, 0, 0, 0);
}