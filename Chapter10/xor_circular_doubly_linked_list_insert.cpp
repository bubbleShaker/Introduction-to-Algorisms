#include <bits/stdc++.h>
using namespace std;
template<typename T>
uintptr_t xor_pointers(T* ptr1, T* ptr2) {
    return reinterpret_cast<uintptr_t>(ptr1) ^ reinterpret_cast<uintptr_t>(ptr2);
}
template<typename T>
T* xor_to_pointer(uintptr_t value) {
    return reinterpret_cast<T*>(value);
}
template<typename T>
struct XorNode{
    T key;
    XorNode<T>* np;
};
template<typename T>
class XorCircularDoublyLinkedList {
private:
    XorNode<T>* nil;
    bool initialized;
    XorNode<T>* head;
    XorNode<T>* tail;
public:
    void init(){
        nil=new XorNode<T>;
        nil->key=-1;
        nil->np=0;
    }
    XorCircularDoublyLinkedList():nil(nullptr),initialized(false),head(0),tail(0) {
        if(!initialized){
            init();
            initialized=true;
        }
    }
    void LIST_INSERT(XorNode<T>* x){
        if(head==0){
            head=x;
        }
        XorNode<T>* prevPtr=tail;
        if(tail!=0){
            uintptr_t res=xor_pointers(tail->np,x);
            tail->np=xor_to_pointer<XorNode<T>>(res);
        }
        tail=x;
        tail->np=prevPtr;
    }
    void print(){
        XorNode<T>* ptr=head;
        XorNode<T>* prevPtr=nil->np;
        while(ptr!=nil->np){
            uintptr_t res=xor_pointers(ptr->np,prevPtr);
            XorNode<T>* nextPtr=xor_to_pointer<XorNode<T>>(res);
            prevPtr=ptr;
            cout<<ptr->key<<((nextPtr!=nil->np)?"->":"\n");
            ptr=nextPtr;
        }
    }
};
int main() {
    XorCircularDoublyLinkedList<int> xcdlist;
    XorNode<int>* node1=new XorNode<int>(1,0);
    XorNode<int>* node2=new XorNode<int>(4,0);
    XorNode<int>* node3=new XorNode<int>(16,0);
    XorNode<int>* node4=new XorNode<int>(9,0);
    xcdlist.LIST_INSERT(node1);
    xcdlist.LIST_INSERT(node2);
    xcdlist.LIST_INSERT(node3);
    xcdlist.LIST_INSERT(node4);
    xcdlist.print();
    return 0;
}