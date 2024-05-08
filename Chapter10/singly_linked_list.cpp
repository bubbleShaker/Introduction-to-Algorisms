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
int main() {
    SingleList<int> slist;
    Node<int>* node1=new Node<int>(5,nullptr);
    Node<int>* node2=new Node<int>(4,nullptr);
    Node<int>* node3=new Node<int>(1,nullptr);
    slist.LIST_INSERT(node1);
    slist.LIST_INSERT(node2);
    slist.LIST_INSERT(node3);
    slist.print();
    slist.LIST_DELETE(node2);
    slist.print();
    return 0;
}