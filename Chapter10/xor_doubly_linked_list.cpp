#include <bits/stdc++.h>
using namespace std;
template<typename T>
uintptr_t xor_pointers(T* ptr1, T* ptr2) {
    return reinterpret_cast<uintptr_t>(ptr1) ^ reinterpret_cast<uintptr_t>(ptr2);
}
template<typename T>
T* to_pointer(uintptr_t value) {
    return reinterpret_cast<T*>(value);
}
template<typename T>
struct XorNode{
    T key;
    XorNode<T>* np;
};
template<typename T>
class XorDoublyLinkedList {
private:
    XorNode<T>* head;
    XorNode<T>* tail;
public:
    XorDoublyLinkedList():head(0),tail(0) {}
    XorNode<T>* LIST_SEARCH(T k){
        XorNode<T>* ptr=head;
        XorNode<T>* prevPtr=0;
        while(ptr!=0&&ptr->key!=k){
            uintptr_t res=xor_pointers(ptr->np,prevPtr);
            XorNode<T>* nextPtr=to_pointer<XorNode<T>>(res);
            prevPtr=ptr;
            ptr=nextPtr;
        }
        if(ptr==0){
            return nullptr;
        }else{
            return ptr;
        }
    }
    void LIST_INSERT(XorNode<T>* x){
        if(head==0){
            head=x;
        }
        XorNode<T>* prevPtr=tail;
        if(tail!=0){
            uintptr_t res=xor_pointers(tail->np,x);
            tail->np=to_pointer<XorNode<T>>(res);
        }
        tail=x;
        tail->np=prevPtr;
    }
    void LIST_DELETE(XorNode<T>* x){
        uintptr_t res;
        XorNode<T>* ptr=head;
        XorNode<T>* prevPtr=0;
        while(ptr!=0&&ptr!=x){
            res=xor_pointers(ptr->np,prevPtr);
            XorNode<T>* nextPtr=to_pointer<XorNode<T>>(res);
            prevPtr=ptr;
            ptr=nextPtr;
        }
        res=xor_pointers(ptr->np,prevPtr);
        XorNode<T>* nextPtr=to_pointer<XorNode<T>>(res);
        if(ptr==head){
            head=nextPtr;
        }else if(ptr==tail){
            tail=ptr->np;
        }
        if(prevPtr!=0){
            res=xor_pointers(to_pointer<XorNode<T>>(xor_pointers(prevPtr->np,ptr)),nextPtr);
            prevPtr->np=to_pointer<XorNode<T>>(res);
        }
        if(nextPtr!=0){
            res=xor_pointers(to_pointer<XorNode<T>>(xor_pointers(nextPtr->np,ptr)),prevPtr);
            nextPtr->np=to_pointer<XorNode<T>>(res);
        }
    }
    void print(){
        XorNode<T>* ptr=head;
        XorNode<T>* prevPtr=0;
        while(ptr!=0){
            uintptr_t res=xor_pointers(ptr->np,prevPtr);
            XorNode<T>* nextPtr=to_pointer<XorNode<T>>(res);
            prevPtr=ptr;
            cout<<ptr->key<<((nextPtr!=0)?"->":"\n");
            ptr=nextPtr;
        }
    }
    void print_reverse(){
        XorNode<T>* ptr=tail;
        XorNode<T>* prevPtr=0;
        while(ptr!=0){
            uintptr_t res=xor_pointers(ptr->np,prevPtr);
            XorNode<T>* nextPtr=to_pointer<XorNode<T>>(res);
            prevPtr=ptr;
            cout<<ptr->key<<((nextPtr!=0)?"->":"\n");
            ptr=nextPtr;
        }
    }
};
int main() {
    XorDoublyLinkedList<int> xdlist;
    XorNode<int>* node1=new XorNode<int>(1,0);
    XorNode<int>* node2=new XorNode<int>(4,0);
    XorNode<int>* node3=new XorNode<int>(16,0);
    XorNode<int>* node4=new XorNode<int>(9,0);
    xdlist.LIST_INSERT(node1);
    xdlist.LIST_INSERT(node2);
    xdlist.LIST_INSERT(node3);
    xdlist.LIST_INSERT(node4);
    xdlist.print();
    xdlist.print_reverse();
    return 0;
}