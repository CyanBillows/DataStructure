//
// Created by DELL on 2022/7/29.
//

#ifndef RADIXSORT_LQUEUE_H
#define RADIXSORT_LQUEUE_H

#include <memory>
typedef struct LinkNode{
    int data;
    LinkNode * next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
void push(LinkQueue *q,int data);
void pop(LinkQueue *q,int *x);
void initQueue(LinkQueue &q);

#endif //RADIXSORT_LQUEUE_H
