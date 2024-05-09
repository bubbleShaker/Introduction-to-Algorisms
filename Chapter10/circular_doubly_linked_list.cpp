#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* prev;
    Node<T>* next;
};
template<typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* nil;
public:
    CircularDoublyLinkedList():nil(nullptr) {
        nil=new Node<T>;
        nil->key=-1;
        nil->prev=nil;
        nil->next=nil;
    }
    Node<T>* LIST_SEARCH(T k){
        nil->key=k;
        Node<T>* x=nil->next;
        while(x->key!=k){
            x=x->next;
        }
        return x;
    }
    void LIST_INSERT(Node<T>* x){
        x->next=nil->next;
        nil->next->prev=x;
        nil->next=x;
        x->prev=nil;
    }
    void LIST_DELETE(Node<T>* x){
        x->prev->next=x->next;
        x->next->prev=x->prev;
    }
    void print(){
        Node<T>* ptr=nil->next;
        while(ptr!=nil){
            cout<<ptr->key<<" \n"[ptr->next==nil];
            ptr=ptr->next;
        }
    }
};
int main() {
    CircularDoublyLinkedList<int> dlist;
    Node<int>* node1=new Node<int>(1,nullptr,nullptr);
    Node<int>* node2=new Node<int>(4,nullptr,nullptr);
    Node<int>* node3=new Node<int>(16,nullptr,nullptr);
    Node<int>* node4=new Node<int>(9,nullptr,nullptr);
    Node<int>* node5=new Node<int>(25,nullptr,nullptr);
    dlist.LIST_INSERT(node1);
    dlist.LIST_INSERT(node2);
    dlist.LIST_INSERT(node3);
    dlist.LIST_INSERT(node4);
    dlist.LIST_INSERT(node5);
    dlist.print();
    dlist.LIST_DELETE(node2);
    dlist.print();
    cout<<dlist.LIST_SEARCH(9)->key<<endl;
    cout<<dlist.LIST_SEARCH(10)->key<<endl;
    return 0;
}
