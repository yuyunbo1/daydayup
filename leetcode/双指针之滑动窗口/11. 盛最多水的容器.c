#define GET_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define GET_MIN(x, y) (((x) < (y)) ? (x) : (y))
int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int len, h;
    int maxS = -1;
    while (left <= right) {
        len = right - left;
        h = GET_MIN(height[left], height[right]);
        maxS = GET_MAX(maxS, len * h);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxS;
}
