#include<stdlib.h>
#include<stdio.h>
int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int numRescueBoats(int* people, int peopleSize, int limit)
{
    int left = 0;
    int right = peopleSize;
    int curBoat = 0;
    qsort(people, peopleSize, sizeof(int), MyCmp);
    if (limit < people[peopleSize - 1]) {
        return 0;
    }
    while (left < right) {
        if (left < right - 1 && people[left] + people[right - 1] > limit) {
            right--;
        } else if (left < right - 1 && people[left] + people[right - 1] <= limit){
            left++;
            right--;
        } else {
            left++;
        }
        curBoat++;
    }
    return curBoat;
}
/*int IsCanShip(int *people, int peopleSize, int limit, int boat)
{
    int left = 0;
    int right = peopleSize;
    int curBoat = 0;
    int tmp;

    while (left < right) {
        tmp = limit;
        if (left < right - 1 && people[left] + people[right - 1] > limit) {
            right--;
        } else if (left < right - 1 && people[left] + people[right - 1] <= limit) {
            left++;
            right--;
        } else {
            left++;
        }
        curBoat++;
        if (curBoat > boat) {
            return 0;
        }
    }
    return 1;
}
int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int numRescueBoats(int* people, int peopleSize, int limit)
{
    int left = 1;
    int right = peopleSize; // 最多每个人1只船
    int mid;
    qsort(people, peopleSize, sizeof(int), MyCmp);
    if (limit < people[peopleSize - 1]) {
        return 0;
    }
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (IsCanShip(people, peopleSize, limit, mid) == 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (left > peopleSize) {
        return -1;
    }
    return IsCanShip(people, peopleSize, limit, left) == 1 ? left : 0;
}*/

int main()
{
    int people[] = {3,2,2,1};
    int peopleSize = sizeof(people) / sizeof(people[0]);
    int limit = 3;
    int boat = numRescueBoats(people, peopleSize, limit);
    printf("%d\n", boat);
}
