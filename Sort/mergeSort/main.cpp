#include <iostream>
//合并两个有序数组
//空间复杂度: O(n) 辅助数组
//时间复杂度: O(n)
void Merge(int a[],int assist[],int low,int high,int mid){
    int j,k,m; //三个指针，j指向左表元素，k指向右表元素，m指向原数组
    for (int i = low; i <= high; ++i) { //将a中所有元素赋值到辅助数组assist中,防止覆盖丢失数据
        assist[i] = a[i];
    }
    for (j = low,k=mid+1,m=low; j <= mid && k <= high; ++m) {
        if(assist[j] <= assist[k]){ //取左右表中较小值赋值到a中,取等于值是考虑稳定性
            a[m] = assist[j];
            j++;
        } else {
            a[m] = assist[k];
            k++;
        }
    }
    while(k <= high) a[m++] = assist[k++]; //将左右表中的剩余元素依次赋值给a
    while(j <= mid) a[m++] = assist[j++];
}
//二路归并
//时间复杂度：O(n*递归次数) = O(n*log2n)
//稳定排序
void mergeSort(int a[],int assist[],int low,int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(a,assist,low,mid);
        mergeSort(a,assist,mid+1,high);
        Merge(a,assist,low,high,mid);
    }
}

int main() {
    int a[6] = {5,7,2,1,3,6};
    int assist[10] = {0};
    mergeSort(a,assist,0,5);
    for (int i : a) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
