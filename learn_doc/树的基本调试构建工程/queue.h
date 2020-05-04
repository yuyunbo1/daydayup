#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "tree_base.h"

#define QUEUE_MAX 100

typedef struct Queue {
    TREENODE_T* nodePool[QUEUE_MAX];
    int head;
    int tail;
    int size;
}QUEUE_T;

int QueueReInit(QUEUE_T* queue);
int QueueIsFull(QUEUE_T* queue);
int QueueIsEmpty(QUEUE_T* queue);
TREENODE_T* QueuePop(QUEUE_T* queue);
int QueueSize(QUEUE_T* queue);

#endif // __QUEUE_H_
