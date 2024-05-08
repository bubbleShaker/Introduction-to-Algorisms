#include <bits/stdc++.h>
using namespace std;
template<typename T>
class SingleList {
private:
    struct Node{
        T key;
        Node* next;
    };
    Node* head;
public:
    SingleList():head(nullptr) {}
    void insert(int ky){
        Node* newNode=new Node;
        newNode->key=ky;
        newNode->next=nullptr;
        if(head==nullptr){
            head=newNode;
        }else{
            Node* ptr=head;
            while(ptr->next!=nullptr){
                ptr=ptr->next;
            }
            ptr->next=newNode;
        }
    }
    void print(){
        Node* ptr=head;
        while(ptr!=nullptr){
            cout<<ptr->key<<((ptr->next!=nullptr)?"->":"\n");
            ptr=ptr->next;
        }
    }
};
template<typename T>
class DoublyLinkedList {
private:
    struct Node{
        T key;
        Node* prev;
        Node* next;
    };
    Node* nil;
public:
    DoublyLinkedList():nil(nullptr) {
        nil=new Node;
        nil->key=-1;
        nil->prev=nil;
        nil->next=nil;
    }
    void insert(T ky){
        Node* newNode=new Node;
        newNode->key=ky;
        newNode->prev=nil->prev;
        nil->prev->next=newNode;
        newNode->next=nil;
        nil->prev=newNode;
    }
    void insertion_sort(){
        if(nil->next==nil){
            return;
        }
        Node* ptr=nil->next;
        while(ptr!=nil){
            T ky=ptr->key;
            Node* prevPtr=ptr->prev;
            while(prevPtr!=nil&&prevPtr->key>ky){
                prevPtr->next->key=prevPtr->key;
                prevPtr=prevPtr->prev;
            }
            prevPtr->next->key=ky;
            ptr=ptr->next;
        }
    }
    vector<T> concat(){
        vector<T> ret;
        Node* ptr=nil->next;
        while(ptr!=nil){
            ret.push_back(ptr->key);
            ptr=ptr->next;
        }
        return ret;
    }
    void print(){
        Node* ptr=nil->next;
        while(ptr!=nil){
            cerr<<ptr->key<<((ptr->next!=nil)?"->":"\n");
            ptr=ptr->next;
        }
    }
    void printd(){
        Node* ptr=nil->next;
        while(ptr!=nil){
            cout<<fixed<<setprecision(2);
            cout<<ptr->key<<((ptr->next!=nil)?"->":"\n");
            ptr=ptr->next;
        }
    }
};
void BUCKET_SORT(vector<double>& A){
    int n=A.size();
    vector<DoublyLinkedList<double>> B(n);
    for(int i=0;i<n;i++){
        B[floor(n*A[i])].insert(A[i]);
    }
    for(int i=0;i<n;i++){
        B[i].insertion_sort();
    }
    vector<double> ret;
    for(int i=0;i<n;i++){
        vector<double> tmp=B[i].concat();
        ret.insert(ret.end(),tmp.begin(),tmp.end());
    }
    A=ret;
}
int main() {
    vector<double> a={0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    int n=a.size();
    BUCKET_SORT(a);
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}