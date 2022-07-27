#include <iostream>
//最好情况(有序) 比较次数n-1，交换次数0 O(n)
//最坏情况(逆序) 比较次数=(n-1)+(n-2)+...+1=n(n-1)/2=交换次数 O(n^2)
//平均O(n^2)
//稳定排序
void bubbleSort(int a[],int len){
    bool flag; //某次冒泡是否发生交换的标志
    for (int i = len-1; i > 0; --i) { //逆序遍历，每次循环确定i位置的值
        flag = false;
        for (int j = 0; j < i; ++j) {
            if(a[j] > a[j+1]) //只有该情况才交换，所以排序稳定
            {
                std::swap(a[j],a[j+1]);
                flag = true;
            }
        }
        if(!flag) return; //若没发生交换，说明序列已经顺序排列完毕
    }
}

int main() {
    int data[7] = {2,1,5,4,7,9,3};
    bubbleSort(data,7);
    for (int i : data) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
