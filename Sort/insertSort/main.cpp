#include <iostream>
//最坏情况：逆序，时间复杂度O(n^2)
//最好情况: 顺序，时间复杂度O(n)
//平均：O（n^2)
//稳定排序
void insertSort(int data[],int len){
    int tmp,j;
    for (int i = 1; i < len; ++i) {
        if(data[i-1] > data[i]) //前面的数大于后面
        {
            tmp = data[i]; //临时变量存储待插入值
            for (j = i-1; j >=0 ; --j) { //检查所有前面已排好序的数
                if(tmp < data[j]){
                    data[j+1] = data[j]; //所有大于tmp的元素向后移位
                } else {
                    break;
                }
            }
            data[j+1] = tmp; //将待插入值放入对应位置
        }
    }
}
//采用折半查找优化比较次数,由于移动元素的次数不变，时间复杂度仍然为O(n^2)
void insertSort2(int data[],int len){
    int tmp,j,low,high,mid;
    for (int i = 1; i < len; ++i) {
        if(data[i-1] > data[i]) //前面的数大于后面
        {
            tmp = data[i]; //临时变量存储待插入值
            low = 0;       //查找范围：0到i-1
            high = i-1;
            while(low <= high){
                mid = (low+high)/2;
                if(tmp < data[mid]){ //查找左半表
                    high = mid - 1;
                } else { //查找右半表
                    low = mid + 1;
                }
            }
            for (j = i-1; j >= high+1; --j) {
                data[j+1] = data[j];
            }
            data[j+1] = tmp; //将待插入值放入对应位置
        }
    }
}

int main() {
    int data[7] = {2,1,5,4,7,9,3};
    insertSort2(data,7);
    for (int i : data) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
