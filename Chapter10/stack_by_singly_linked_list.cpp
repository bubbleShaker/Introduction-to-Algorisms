#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
    T key;
    Node<T>* next;
};
template<typename T>
class SingleList {
private:
    Node<T>* head;
public:
    SingleList():head(nullptr) {}
    void LIST_INSERT(Node<T>* x){
        x->next=head;
        head=x;
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
    Node<T>* getHead(){
        return head;
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
class Stack {
private:
    SingleList<T>* slist;
    Node<T>* top;
public:
    Stack():slist(nullptr),top(nullptr) {
        slist=new SingleList<T>;
    }
    bool EMPTY(){
        return top==nullptr;
    }
    void PUSH(Node<T>* x){
        slist->LIST_INSERT(x);
        top=x;
    }
    T POP(){
        if(EMPTY()){
            throw invalid_argument("underflow");
        }else{
            Node<T>* ptr=slist->getHead();
            slist->LIST_DELETE(ptr);
            return ptr->key;
        }
    }
    void print(){
        Node<T>* ptr=slist->getHead();
        while(ptr!=nullptr){
            cout<<ptr->key<<((ptr->next!=nullptr)?"<-":"\n");
            ptr=ptr->next;
        }
    }
};
int main() {
    Stack<int> stk;
    Node<int>* node1=new Node<int>(5,nullptr);
    Node<int>* node2=new Node<int>(4,nullptr);
    Node<int>* node3=new Node<int>(1,nullptr);
    stk.PUSH(node1);
    stk.PUSH(node2);
    stk.PUSH(node3);
    stk.print();
    stk.POP();
    stk.print();
    return 0;
}