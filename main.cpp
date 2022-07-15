#include <iostream>

#define N 10
//循环队列，最大size = N-1(为区分列满和列空条件，入队时rear!=head)，浪费一个空间
//解决方案: 1.添加size成员变量，此时列满为size ==N,列空 size == 0
//        2.添加bool tag,为0表示最近一次执行的是删除操作，只有删除才可能队空rear == head && tag == 0，插入才可能队满
template <class T>
class Queue{
private:
    T data[N];
    int rear,head;
public:
    Queue(){
        for (int i = 0; i < N; ++i) {
            data[i] = 0;
        }
        rear = head = 0;
    }
    bool isEmpty(){
        if(rear == head)
            return true;
        else
            return false;
    }
    bool isFull(){
        if( (rear+1) % N == head)
            return true;
        else
            return false;
    }
    bool push(T e){
        if(isFull()) {
            return false;
        } else {
            data[rear] = e;
            rear = (rear+1) % N; //循环利用空间
            return true;
        }
    }
    bool pop(T &x){
        if(isEmpty()){
            return false;
        } else {
            x = data[head];
            head = (head + 1) % N;
            return true;
        }
    }
    int size(){
        return (rear+N-head) % N;
    }
};

int main() {
    Queue<int> test;
    test.push(1);
    test.push(2);
    int x;
    test.pop(x);
    std::cout << x << "\nsize" << test.size();
    return 0;
}
