#include <iostream>
//把以节点k为根节点的子树调整为大顶堆 O(log2n)
void adjustHeap(int heap[],int k,int len){
    heap[0] = heap[k];//heap[0]暂存子树根节点
    for(int i = k * 2;i <= len;i*=2){
        if(i < len && heap[i] < heap[i+1]){ //i < len，保证i节点有右兄弟
            i++;
        }
        if(heap[i] <= heap[0]) break;
        else {
            heap[k] = heap[i]; //将heap[i]调整到双亲节点上
            k = i; //修改K值，以便继续向下筛选
        }
    }
    heap[k] = heap[0]; //被筛选节点的值放入最终位置
}
//将整个树变为大根堆：遍历非叶子节点，将其子树都调整为大根堆O(n)
void buildHeap(int heap[],int len){
    for (int i = len / 2; i>0 ; --i) {
        adjustHeap(heap,i,len);
    }
}
//时间复杂度:O(n*log2n) 不稳定排序
void heapSort(int heap[],int len){
    buildHeap(heap,len);
    for (int i = len; i > 1; --i) { //n-1次交换和建堆
        std::swap(heap[i],heap[1]);
        adjustHeap(heap,1,i-1); //把剩余待排序元素整理成堆
    }
}
//从堆中删除一个节点
bool deleteHeapNode(int heap[],int len,int x){
    int index = 0;
    for (int i = 1; i <= len; ++i) { //查找值为x的下标
        if(heap[i] == x)
            index = i;
    }
    if(index == 0) return false;
    heap[index] = heap[len]; //用堆底元素的值覆盖待删除元素
    heap[len] = 0;
    adjustHeap(heap,index,len-1); //让该元素不断下坠，直至满足大根堆
    return true;
}
//给堆添加一个节点
int *insertHeapNode(const int heap[],int len,int x){
    int *newHeap = static_cast<int *>(malloc(sizeof(int) * (len + 2)));
    for (int i = 0; i < len+1; ++i) {
        newHeap[i] = heap[i];
    }
    newHeap[len+1] = x; //将x插入堆尾
    for (int i = len+1; i > 1; i = i/2) { //反复对比x和其父节点，若子大于父则交换，i一路上升直到父大于子
        if(newHeap[i/2] < newHeap[i]){
            std::swap(newHeap[i/2],newHeap[i]);
        } else {
            break;
        }
    }
    return newHeap;
}

using namespace std;
int main() {
    int data[9] = {0,5,7,4,9,11,3,6,4};
    buildHeap(data,8);
    for (int i = 1; i < 9; ++i) {
        cout.width(3);
        cout << data[i];
    }
    cout << endl;
    int *a = insertHeapNode(data,8,3);
    for (int i = 1; i < 10; ++i) {
        cout.width(3);
        cout << a[i];
    }
    cout << endl;
    deleteHeapNode(a,9,3);
    for (int i = 1; i < 10; ++i) {
        cout.width(3);
        cout << a[i];
    }
    return 0;
}
