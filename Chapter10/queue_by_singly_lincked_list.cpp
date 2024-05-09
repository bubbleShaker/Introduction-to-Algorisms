#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* next;
};
template<typename T>
class SingleList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    SingleList():head(nullptr) {}
    void LIST_INSERT(Node<T>* x){
        if(head==nullptr){
            head=x;
        }
        if(tail!=nullptr){
            tail->next=x;
        }
        tail=x;
    }
    void LIST_DELETE(Node<T>* x){
        Node<T>* ptr=head;
        Node<T>* prevPtr=nullptr;
        while(ptr!=nullptr&&ptr!=x){
            prevPtr=ptr;
            ptr=ptr->next;
        }
        if(ptr==x&&prevPtr==nullptr){
            head=ptr->next;
        }else if(ptr==x){
            prevPtr->next=ptr->next;
        }
    }
    void print(){
        Node<T>* ptr=head;
        while(ptr!=nullptr){
            cout<<ptr->key<<((ptr->next!=nullptr)?"->":"\n");
            ptr=ptr->next;
        }
    }
};
template<typename T>
class Queue {
private:
    SingleList<T>* slist;
    Node<T>* head;
    Node<T>* tail;
public:
    Queue():head(nullptr),tail(nullptr) {
        slist=new SingleList<T>;
    }
    void ENQUEUE(Node<T>* x){
        slist->LIST_INSERT(x);
        tail=x;
        if(head==nullptr){
            head=x;
        }
    }
    Node<T>* DEQUEUE(){
        Node<T>* ptr=head;
        head=ptr->next;
        return ptr;
    }
    void print(){
        Node<T>* ptr=head;
        while(ptr!=nullptr){
            cout<<ptr->key<<((ptr->next!=nullptr)?"->":"\n");
            ptr=ptr->next;
        }
    }
};
int main() {
    Queue<int> que;
    Node<int>* node1=new Node<int>(4,nullptr);
    Node<int>* node2=new Node<int>(1,nullptr);
    Node<int>* node3=new Node<int>(5,nullptr);
    que.ENQUEUE(node1);
    que.ENQUEUE(node2);
    que.ENQUEUE(node3);
    que.print();
    que.DEQUEUE();
    que.print();
    return 0;
}