#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* next;
};
template<typename T>
class SinglyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    SinglyLinkedList():head(nullptr) {}
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
    void UNION(SinglyLinkedList<T>* L){
        tail->next=L->head;
        tail=L->tail;
    }
    void REVERSE(){
        Node<T>* ptr=head;
        Node<T>* prevPtr=nullptr;
        head=tail;
        tail=ptr;
        while(ptr!=nullptr){
            Node<T>* nextPtr=ptr->next;
            ptr->next=prevPtr;
            prevPtr=ptr;
            ptr=nextPtr;
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
int main() {
    SinglyLinkedList<int> slist;
    Node<int>* node1=new Node<int>(5,nullptr);
    Node<int>* node2=new Node<int>(4,nullptr);
    Node<int>* node3=new Node<int>(1,nullptr);
    Node<int>* node4=new Node<int>(7,nullptr);
    slist.LIST_INSERT(node1);
    slist.LIST_INSERT(node2);
    slist.LIST_INSERT(node3);
    slist.LIST_INSERT(node4);
    slist.print();
    slist.REVERSE();
    slist.print();
    return 0;
}