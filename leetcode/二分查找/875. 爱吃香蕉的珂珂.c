
int IsOk(int* piles, int pilesSize, int speed, int h)
{
    int i;
    int t = 0;
    int tmp = 0;
    for (i = 0; i < pilesSize; i++) {
        tmp = piles[i] / speed;
        t += (piles[i] % speed == 0) ? tmp : tmp + 1;
        if (t > h) {
            return 0;
        }
    }
    return 1;
}
int minEatingSpeed(int* piles, int pilesSize, int H)
{
    int i = 0;
    int minSpeed = -1;
    int maxSpeed = -1;
    int speed, midSpeed;
    minSpeed = 1;
    maxSpeed = piles[0];

    for (i = 1; i < pilesSize; i++) {
        minSpeed = (minSpeed < piles[i]) ? minSpeed : piles[i];
        maxSpeed = (maxSpeed < piles[i]) ? piles[i] : maxSpeed;
    }
    maxSpeed += 1;
    while(minSpeed < maxSpeed) {
        midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
        // 能吃完的话，继续缩小范围
        if (IsOk(piles, pilesSize, midSpeed, H) == 1) {
            maxSpeed = midSpeed;
        } else {    // 不能吃完
            minSpeed = midSpeed + 1;
        }
    }
    return (IsOk(piles, pilesSize, minSpeed, H) == 1) ? minSpeed : -1;
}
int main()
{
    int piles[] = {30, 11, 23, 4, 20};
    int ret = minEatingSpeed(piles, 5, 5);
    printf("%d\n", ret);
    return 0;
}
