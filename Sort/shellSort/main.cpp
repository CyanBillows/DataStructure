#include <iostream>
//不稳定，时间复杂度：未知(优于插排)，最坏情况退化为插入排序O(n^2)
//每轮以特定步长d将原数组分为几个子表，分别对每个子表进行插入排序
//d每轮后除以2，当d=1时对相对有序的所有子表进行最终排序
void shellSort(int a[],int len){
    int tmp,j;
    for (int d = len / 2; d >= 1; d /= 2) { //步长每轮除以二
        for (int i = d; i < len; ++i) {
            if(a[i] < a[i-d]){
                tmp = a[i];
                for (j = i-d; j >= 0 && a[j] > tmp; j-=d) {
                    a[j+d] = a[j];
                }
                a[j+d] = tmp;
            }
        }
    }
}

int main() {
    int data[7] = {2,1,5,4,7,9,3};
    shellSort(data,7);
    for (int i : data) {
        std::cout.width(3);
        std::cout << i;
    }
    return 0;
}
