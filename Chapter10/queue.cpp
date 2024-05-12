#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Queue {
private:
    vector<T> q;
    int head;
    int tail;
    int length;
public:
    Queue():head(0),tail(0) { q.resize(0); }
    Queue(int n):head(0),tail(0),length(n) { q.resize(n+1); }
    void ENQUEUE(T x){
        q[tail]=x;
        if(tail==length-1){
            tail=0;
        }else{
            tail++;
        }
    }
    T DEQUEUE(){
        T x=q[head];
        if(head==length-1){
            head=0;
        }else{
            head++;
        }
        return x;
    }
    void print(){
        int ni=head;
        while(ni!=tail){
            cout<<q[ni]<<" ";
            if(ni==length-1){
                ni=0;
            }else{
                ni++;
            }
        }
        cout<<endl;
    }
};
int main() {
    Queue<int> que(10);
    que.ENQUEUE(5);
    que.ENQUEUE(2);
    que.ENQUEUE(11);
    que.print();
    que.DEQUEUE();
    que.print();
    que.DEQUEUE();
    que.print();
    return 0;
}