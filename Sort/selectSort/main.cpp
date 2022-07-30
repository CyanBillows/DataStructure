#include <iostream>
//简单选择排序，不稳定
//时间复杂度: O(n^2)
void selectSort(int a[],int len){
    int min,k; //指针k指向某一轮的最小值min
    for (int i = 0; i < len; ++i) { //每次循环选择出一个最小值赋给i
        min = a[i];
        for (int j = i+1; j < len; ++j) { //两两对比a[i]和i后元素，一轮循环后找到最小值min
            if(min > a[j]){
                min = a[j];
                k = j;
            }
        }
        a[k] = a[i]; //原a[i]值放入a[k]
        a[i] = min;  //将最小值放入a[i]
    }
}

int main() {
    int data[7] = {2,1,5,4,7,9,3};
    selectSort(data,7);
    for (int i : data) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
