int CanTransport(int* weights, int weightsSize, int D, int perWeight)
{
    int i;
    int cur = 0;
    int day = 0;
    for (i = 0; i < weightsSize; i++) {
        cur += weights[i];
        if (cur > perWeight) {
            day++;
            cur = weights[i];
            continue;
        }
        if (cur == perWeight) {
            day++;
            cur = 0;
        }
    }
    if (cur != 0) {
        day++;
    }
    return day <= D ? 1 : 0;
}
int shipWithinDays(int* weights, int weightsSize, int D)
{
    int sum = 0;
    int i;
    int left = 1;
    int right;
    int mid;
    int temp;
    int max = -1;
    for (i = 0; i < weightsSize; i++) {
        sum += weights[i];
        max = (max <= weights[i]) ? weights[i] : max;
    }
    left = max;
    right = sum;
    // 在[left, right]寻找最左边的perWeight,注意最小的运输能力是weight中的最大值
    while (left <= right) {
        mid = left + (right - left) / 2;
        temp = CanTransport(weights, weightsSize, D, mid);
        if (temp == 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
}
// 这里其实是寻找左边界的一般思路，本题可以省略。但是为了规范写起来。
    if (right < 1) {
        return 0;
    }
    return left;
}
