#include<stdio.h>
#include<stdlib.h>
/**暴力解法，分表用2个数组记录2个单词在原数组的index,然后问题转化为求2个数组之前最短的距离。可暴力，也可以二分优化
#define MAX 1000000

int findClosest(char** words, int wordsSize, char* word1, char* word2)
{
    int word1IndexSize = 0;
    int word2IndexSize = 0;
    int i, j;
    int word1IndexVector[MAX] = {0};
    int word2IndexVector[MAX] = {0};
    int minDis = 0xffffff;
    int index;
    int tmpDis;
    for (i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word1) == 0) {
            word1IndexVector[word1IndexSize] = i;
            word1IndexSize++;
        }
        if (strcmp(words[i], word2) == 0) {
            word2IndexVector[word2IndexSize] = i;
            word2IndexSize++;
        }
    }

    for (i = 0; i < word1IndexSize; i++) {
        for (j = 0; j < word2IndexSize; j++) {
            tmpDis = word1IndexVector[i] - word2IndexVector[j];
            minDis = minDis > tmpDis ? tmpDis : minDis;
        }
    }
    return minDis;
}*/
int findClosest(char** words, int wordsSize, char* word1, char* word2)
{
    int i;
    int minDis = 0xffffff;
    int word1Index = -1;
    int word2Index = -1;
    int tmpDis = 0;
    for (i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word1) == 0) {
            word1Index = i;
        }
        if (strcmp(words[i], word2) == 0) {
            word2Index = i;
        }
        if (word1Index != -1 && word2Index != -1) {
            tmpDis = abs(word1Index - word2Index);
            minDis = (minDis >= tmpDis) ? tmpDis : minDis;
        }
    }
    return minDis;
}
int main()
{
    char* words[] = {"I","am","a","student","from","a","university","in","a","city"};
    char* word1 = "a";
    char* word2 = "student";
    char** word = (char**)calloc(sizeof(words) / sizeof(char*), sizeof(char*));
    int i;
    int ret;
    for (i = 0; i < sizeof(words) / sizeof(char*); i++) {
        word[i] = (char*)calloc(15, sizeof(char));
        memcpy(word[i], words[i], strlen(words[i]) + 1);
        printf("%s\n", word[i]);
    }

    ret = findClosest(word, sizeof(words) / sizeof(char*), word1, word2);//sizeof(words) / sizeof(char*)
    printf("%d\n", ret);
    return 0;
}
