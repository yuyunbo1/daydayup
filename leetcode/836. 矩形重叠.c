#include<stdio.h>
#include<stdlib.h>
/*
不想交的情况：
1.纵向看的话，如果2条横线不想交那肯定不会相交：rec1.x2 < rec1.x1 || rec2.x2 < rec1.x1
2.横向看的话，如果2个竖线不想交那肯定不会相交: rec1.y2 < rec2.y1 || rec2.y2 < rec1.y1
3.如果2个完全重叠也不算重叠:rec1[0] = rec2[0] && rec1[1] = rec2[1] && rec1[2] = rec2[2] && rec1[3] = rec2[3]
4.只是顶点或者边重合的话算不重叠，因此在1，2中需要加=号
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