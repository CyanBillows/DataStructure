#include <iostream>
//快排划分，确定基点/枢轴坐标
int Partition(int a[],int low,int high){
    int pivot = a[low]; //采用第一个元素作为基点
    while(low < high) {
        while(low < high && a[high] >= pivot) --high;
        a[low] = a[high];
        while(low < high && a[low] <= pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
//时间复杂度取决于基点pivot的选择，若能将序列划分成均匀的两部分最佳，即尽量选择趋于中间值的数作为基点。
// O(n*递归次数) 最佳：O(n*log2n) 最坏：O(n^2) 平均: O(n*log2n)
//空间复杂度：O(递归次数)
//不稳定
void quickSort(int a[],int low,int high){
    if(low < high){ //递归终止条件
        int mid = Partition(a,low,high); //首次划分，确定基点
        quickSort(a,low,mid-1); //划分左子表
        quickSort(a,mid+1,high); //划分右子表
    }
}

int main() {
    int data[7] = {2,1,5,4,7,9,3};
    quickSort(data,0,6);
    for (int i : data) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
