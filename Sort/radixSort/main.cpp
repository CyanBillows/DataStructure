#include <iostream>
#include "Lqueue.h"

using namespace std;

int pow(int a,int b){
    int result = 1;
    for (int i = 0; i < b; ++i) {
        result *=a;
    }
    return result;
}

// O(d*(n+r)) d为权重分类数量，r为各权重中最广的基数范围 例：对百位数而言，位数d=3,各位数取值范围r=10 （0..9）
//适用情况: 1.元素数量n较大
//  2.数据元素关键字可以方便拆分为d组，且d较小
//  3.每组取值范围r不大
void radixSort(int a[],int r,int d,int len){
    LinkQueue q[r];
    for (int i = 0; i < r; ++i) {
        initQueue(q[i]);
    }
    int weight;
    LinkNode *head = nullptr; //记录经过一轮入队出队后，各数据元素的排列顺序
    for (int i = 1; i <= d; ++i) {
        for (int j = 0; j < len; ++j) { //计算每个元素的该轮权重，放入相应队列
            weight =  a[j] / pow(10,i-1); //十进制右移i-1位
            weight =  weight % 10;
            push(q+weight,a[j]);
        }
        LinkNode *lastRear = nullptr; //存储最近一轮非空队列的尾部，以便构建联系
        for (int k = 0; k < r; ++k) {
            if(q[k].front == nullptr) continue;
            if(head == nullptr) head = q[k].front; //初始化head指针，指向首节点
            if(lastRear == nullptr) { //第一次遇到非空队列，只更新lastRear
                lastRear = q[k].rear;
            } else { //第二次及之后先将上一轮的非空队列尾指针的next指向本轮队列的front,再更新lastRear
                lastRear->next = q[k].front;
                lastRear = q[k].rear;
            }
            q[k].front = q[k].rear = nullptr; //清空队列
        }
        if(head != nullptr) { //若head被初始化，表示有了新的取值顺序，依次赋值给a
            int k = 0;
            while(head != nullptr){
                a[k++] = head->data;
                lastRear = head; //此时lastRear作为中间变量，存储head方便释放内存
                head = head->next;
                free(lastRear);
            }
        }
    }
}

int main() {
    int a[6] = {25611,12821,53691,16411,76661,52221};
    radixSort(a,10,5,6);
    for (int i : a) {
        std::cout.width(8);
        std::cout << i;
    }
    return 0;
}
