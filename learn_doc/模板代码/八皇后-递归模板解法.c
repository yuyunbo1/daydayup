/**
	2.�˻ʺ�����
	������4*4�ĸ��ӣ��ʺ�Ҫ�ڸ����ϣ����ܻ��๥�������Թ����Ĺ������������£���45�Ƚǡ����ж�����״̬��
	
	��ʵ���ö�ά���飬��һ��queue_pos��һά���飬��ʾÿһ�лʺ����ڵ��кš���ô�����������step�����ﶨ����ǲ���һ���ʺ󣻹���Ǳ�����ÿ��step������ɵģ��������

�ǲ�����index�е�ĳһ�С�
*/
#include<stdio.h>
#include<stdlib.h>
#define N 8
int queue_pos[N] = {0};
static int g_kind = 0;
void step(int index)
{
	int i = 0;
	int j = 0;
	//printf("?\n");
	// ���𵽵�index���ʺ󣬾���Ϊ����һ��OK��״̬
	if (index == N + 1) {
		g_kind++;	
	}
	// option�������Ҫ�ж��Ƿ����,��index�е�0�е�N�ж���һ��
	for (i = 0 ; i < N; i++) {
		//���Բ���һ��
		queue_pos[index] = i;
		// �ж��Ƿ���ϲ�������״̬����һ���ж������λ�ò�����ǰ���λ�ó�����ͬһ��
		for (j = 0; j < index; j++) {
			// ������ͬһ��
			if (queue_pos[j] == queue_pos[index]) {
				break;
			}
			// ������45��
			if (abs(queue_pos[index] - queue_pos[j]) == abs(index - j)) {
				break;
			}
		}
		if (j >= index) {
			 step(index + 1);
		}
		
	}

}
int main()
{
	step(0);
	printf("hello%d\n",g_kind);
}