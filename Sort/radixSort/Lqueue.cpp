//
// Created by DELL on 2022/7/29.
//

#include "Lqueue.h"

//无头节点的链表队列
void initQueue(LinkQueue &q){
    q.front = nullptr;
    q.rear = nullptr;
}

void push(LinkQueue *q,int data){
    if(q == nullptr) return;
    LinkNode *node = (LinkNode *)(malloc(sizeof(LinkNode)));
    node->next = nullptr;
    node->data = data;
    if(q->front == nullptr){ //队列为空
        q->rear = node;
        q->front = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

void pop(LinkQueue *q,int *x){
    LinkNode *tmp;
    if(q == nullptr) return;
    if(q->front == nullptr) { //队列为空
        return;
    }
    if(q->front->next == nullptr){ //队列仅有一个元素，出队需重置rear指针
        q->rear = nullptr;
    }
    tmp = q->front;
    q->front = q->front->next;
    *x = tmp->data; //取出data
    free(tmp); //释放队内元素内存
}

bool isEmpty(LinkQueue *q){
    if (q->front == nullptr) return true;
    return false;
}


