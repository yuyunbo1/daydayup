#include<stdio.h>
#include<stdlib.h>
/*
���뽻�������
1.���򿴵Ļ������2�����߲��뽻�ǿ϶������ཻ��rec1.x2 < rec1.x1 || rec2.x2 < rec1.x1
2.���򿴵Ļ������2�����߲��뽻�ǿ϶������ཻ: rec1.y2 < rec2.y1 || rec2.y2 < rec1.y1
3.���2����ȫ�ص�Ҳ�����ص�:rec1[0] = rec2[0] && rec1[1] = rec2[1] && rec1[2] = rec2[2] && rec1[3] = rec2[3]
4.ֻ�Ƕ�����߱��غϵĻ��㲻�ص��������1��2����Ҫ��=��
*/
int PointIsInRec(int x, int y,int* rec)
{
	if
}
//[x1, y1, x2, y2]
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
	if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) {
		return false;
	}
	if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) {
		return false;
	}
	if (rec1[0] = rec2[0] && rec1[1] = rec2[1] && rec1[2] = rec2[2] && rec1[3] = rec2[3]) {
		return false;
	}
	return true;
}
int main()
{

}