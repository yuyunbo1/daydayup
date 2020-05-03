#include<stdlib.h>
#include<stdio.h>
char * pushDominoes(char * dominoes)
{
    int map[256] = {0};
    int len;
    int left, right, mid;
    int sumLeft, sumRight;
    char* res = NULL;
    len = strlen(dominoes);
    if (len == 0) {
        return "";
    }
    res = calloc(len + 1, sizeof(char));
    map['L'] = -1;
    map['.'] = 0;
    map['R'] = 1;

    for (mid = 0; mid < len; mid++) {
        if (dominoes[mid] != '.') {
            res[mid] = dominoes[mid];
            continue;
        }
        left = mid - 1;
        right = mid + 1;
        sumLeft = 0;
        while (left >= 0 && sumLeft == 0) {
            sumLeft += map[dominoes[left]];
            left--;
        }
        sumRight = 0;
        while (right < len && sumRight == 0) {
            sumRight += map[dominoes[right]];
            right++;
        }

        if (sumRight + sumLeft == 0) {
            if (sumLeft == 0 || (mid - left == right - mid)) {
                res[mid] = '.';
            } else {
                if (mid - left > right - mid) {
                    res[mid] = (dominoes[right - 1] == 'R') ? '.' : 'L';
                } else {
                    res[mid] = (dominoes[left + 1] == 'L') ? '.' : 'R';
                }
            }
        } else {
            // sumLeft == sumRight
            if (sumLeft == sumRight) {
                res[mid] = dominoes[left + 1];
            } else if (sumLeft == 0) {
                res[mid] = (dominoes[right - 1] == 'R') ? '.' : 'L';
            } else {
                res[mid] = (dominoes[left + 1] == 'L') ? '.' : 'R';
            }
        }
    }
    return res;
}
int main()
{
    char* dominoes = "L.LL";
    char* res = pushDominoes(dominoes);
    printf("res %s\n", res);
    return 0;
}
