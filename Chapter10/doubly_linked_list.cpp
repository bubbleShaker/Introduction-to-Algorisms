#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* prev;
    Node<T>* next;
};
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
public:
    DoublyLinkedList():head(nullptr) {}
    Node<T>* LIST_SEARCH(T k){
        Node<T>* x=head;
        while(x!=nullptr&&x->key!=k){
            x=x->next;
        }
        return x;
    }
    void LIST_INSERT(Node<T>* x){
        x->next=head;
        if(head!=nullptr){
            head->prev=x;
        }
        head=x;
        x->prev=nullptr;
    }
    void LIST_DELETE(Node<T>* x){
        if(x->prev!=nullptr){
            x->prev->next=x->next;
        }else{
            head=x->next;
        }
        if(x->next!=nullptr){
            x->next->prev=x->prev;
        }
    }
    void print(){
        Node<T>* ptr=head;
        while(ptr!=nullptr){
            cout<<ptr->key<<" \n"[ptr->next==nullptr];
            ptr=ptr->next;
        }
    }
};
int main() {
    DoublyLinkedList<int> dlist;
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
    cout<<dlist.LIST_SEARCH(9)->key<<endl;;
    return 0;
}