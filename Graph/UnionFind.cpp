#include "UnionFind.h"

using namespace std;
void initArray(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        a[i] = i;
    }
}

void PrintN(int a[],int n){
    for(int i = 0;i<n;++i){
        cout << a[i] << endl;
    }
}
//查前驱，压缩路径为高度为2的多叉树
int Find(int pre[],int x){
    if(pre[x] == x){ //递归出口，x的根节点
        return x;
    } else {
        pre[x] = Find(pre,pre[x]); //找到根节点后沿路赋值给x的上级，压缩路径
    }
    return -1;
}

void Union(int pre[],int a,int b){
    int aR = Find(pre,a); //a根
    int bR = Find(pre,b);  //b根
    if(aR != bR){ //不属于同一集合
        pre[aR] = bR; //将bR设为aR的上级
    }
}

