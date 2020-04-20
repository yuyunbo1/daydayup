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
    // ��[left, right]Ѱ������ߵ�perWeight,ע����С������������weight�е����ֵ
    while (left <= right) {
        mid = left + (right - left) / 2;
        temp = CanTransport(weights, weightsSize, D, mid);
        if (temp == 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
}
// ������ʵ��Ѱ����߽��һ��˼·���������ʡ�ԡ�����Ϊ�˹淶д������
    if (right < 1) {
        return 0;
    }
    return left;
}
