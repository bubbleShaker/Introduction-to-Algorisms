#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* next;
};
template<typename T>
class CircularSinglyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    CircularSinglyLinkedList():head(nullptr),tail(nullptr) {}
    void LIST_INSERT(Node<T>* x){
        if(head==nullptr){
            head=x;
        }
        if(tail!=nullptr){
            tail->next=x;
        }
        tail=x;
        tail->next=head;
    }
    void SLIST_DELETE(Node<T>* x){
        Node<T>* ptr=head;
        Node<T>* prevPtr=tail;
        while(ptr!=tail&&ptr!=x){
            prevPtr=ptr;
            ptr=ptr->next;
        }
        prevPtr->next=ptr->next;
    }
    void LIST_DELETE(Node<T>* x){
        Node<T>* ptr=head;
        Node<T>* prevPtr=tail;
        do{
            prevPtr=ptr;
            ptr=ptr->next;
        }while(ptr!=head&&ptr!=x);
        if(ptr==x&&head==tail){
            head=tail=nullptr;
        }else if(ptr==x&&ptr==head){
            tail->next=x->next;
            head=x->next;
        }else if(ptr==x&&ptr==tail){
            prevPtr->next=head;
            tail=prevPtr;
        }else if(ptr==x){
            prevPtr->next=ptr->next;
        }
    }
    Node<T>* LIST_SEARCH(T k){
        Node<T>* ptr=head;
        while(ptr!=tail&&ptr->key!=k){
            ptr=ptr->next;
        }
        if(ptr->key!=k){
            return nullptr;
        }else{
            return ptr;
        }
    }
    void print(){
        Node<T>* ptr=head;
        if(ptr==nullptr){
            cout<<"no element"<<endl;
            return;
        }
        do{
            cout<<ptr->key<<((ptr->next!=head)?"->":"\n");
            ptr=ptr->next;
        }while(ptr!=head);
    }
};
int main() {
    CircularSinglyLinkedList<int> cslist;
    Node<int>* node1=new Node<int>(4,nullptr);
    Node<int>* node2=new Node<int>(1,nullptr);
    Node<int>* node3=new Node<int>(2,nullptr);
    Node<int>* node4=new Node<int>(7,nullptr);
    cslist.LIST_INSERT(node1);
    cslist.LIST_INSERT(node2);
    cslist.LIST_INSERT(node3);
    cslist.print();
    cslist.LIST_DELETE(node3);
    cslist.print();
    cslist.LIST_INSERT(node4);
    cslist.print();
    cslist.LIST_DELETE(node1);
    cslist.print();
    cout<<((cslist.LIST_SEARCH(4)!=nullptr)?to_string(cslist.LIST_SEARCH(4)->key):"nullptr")<<endl;
    cout<<((cslist.LIST_SEARCH(7)!=nullptr)?to_string(cslist.LIST_SEARCH(7)->key):"nullptr")<<endl;
    return 0;
}
