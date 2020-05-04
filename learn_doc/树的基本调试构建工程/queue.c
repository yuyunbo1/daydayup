#include "queue.h"
#include<stdlib.h>
int QueueReInit(QUEUE_T* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    memset(queue->nodePool, 0, QUEUE_MAX * sizeof(TREENODE_T*));
}
int QueueIsFull(QUEUE_T* queue)
{
    return queue->size >= QUEUE_MAX ? 1 : 0;//(queue->tail + 1) % QUEUE_MAX == queue->head;
}
int QueueIsEmpty(QUEUE_T* queue)
{
    return queue->size == 0 ? 1 : 0;//queue->head == queue->tail;
}
int QueuePush(QUEUE_T* queue, TREENODE_T* root)
{
    if (QueueIsFull(queue) == 1) {
        return 0;
    }
    queue->nodePool[queue->tail] = root;
    queue->tail = (++queue->tail) % QUEUE_MAX;
    queue->size++;
    return 1;
}
TREENODE_T* QueuePop(QUEUE_T* queue)
{
    TREENODE_T* node = NULL;
    if (QueueIsEmpty(queue) == 1) {
        return NULL;
    }
    node = queue->nodePool[queue->head];
    queue->head = (++queue->head) % QUEUE_MAX;
    queue->size--;
    return node;
}
int QueueSize(QUEUE_T* queue)
{
    return queue->size;
}
