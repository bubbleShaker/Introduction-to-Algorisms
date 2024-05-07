#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Heap {
private:
    vector<T> A;
    int length;
    int heap_size;
public:
    Heap():heap_size(0),length(0) {}
    Heap(vector<T> vec):A(vec) {
        heap_size=vec.size();
        length=vec.size();
        reverse(A.begin(),A.end());
        A.push_back(-1);
        reverse(A.begin(),A.end());
    }
    T& operator[](int i) {
        return A[i];
    }
    const T& operator[](int i) const {
        return A[i];
    }
    int getSize(){
        return heap_size;
    }
    int PARENT(int i){
        return (i>>1);
    }
    int LEFT(int i){
        return (i<<1);
    }
    int RIGHT(int i){
        return (i<<1)+1;
    }
    void MAX_HEAPIFY(int i){
        T l=LEFT(i);
        T r=RIGHT(i);
        T largest=0;
        if(l<=heap_size&&A[l]>A[i]){
            largest=l;
        }else{
            largest=i;
        }
        if(r<=heap_size&&A[r]>A[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(A[i],A[largest]);
            MAX_HEAPIFY(largest);
        }
    }
    void MIN_HEAPIFY(int i){
        T l=LEFT(i);
        T r=RIGHT(i);
        T smallest=0;
        if(l<=heap_size&&A[l]<A[i]){
            smallest=l;
        }else{
            smallest=i;
        }
        if(r<=heap_size&&A[r]<A[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(A[i],A[smallest]);
            MIN_HEAPIFY(smallest);
        }
    }
    void BUILD_MAX_HEAP(){
        heap_size=length;
        for(int i=heap_size/2;i>=1;i--){
            MAX_HEAPIFY(i);
        }
    }
    void BUILD_MIN_HEAP(){
        heap_size=length;
        for(int i=heap_size/2;i>=1;i--){
            MIN_HEAPIFY(i);
        }
    }
    void HEAPSORT(){
        BUILD_MAX_HEAP();
        for(int i=length;i>=2;i--){
            swap(A[1],A[i]);
            heap_size--;
            MAX_HEAPIFY(1);
        }
    }
    void HEAP_MAXIMUM(){
        return A[1];
    }
    T HEAP_EXTRACT_MAX(){
        if(heap_size<1){
            throw invalid_argument("heap underflow");
        }
        T MAX=A[1];
        A[1]=A[heap_size];
        heap_size--;
        MAX_HEAPIFY(1);
        return MAX;
    }
    void HEAP_INCREASE_KEY(i,key){
        if(key<A[i]){
            throw invalid_argument("new key is smaller than current key");
        }
        A[i]=key;
        while(i>1&&A[PARENT(i)]<A[i]){
            swap(A[i],A[PARENT(i)]);
            i=PARENT(i);
        }
    }
    void ind_print(){
        for(int i=1;i<=length;i++){
            cout<<"i:"<<i<<" "<<"A[i]"<<A[i]<<endl;
        }
    }
    void print(){
        for(int i=1;i<=length;i++){
            cout<<A[i]<<" \n"[i==length];
        }
    }
};
int main() {
    Heap<int> h({3,1,4,2,5});
    h.HEAPSORT();
    h.print();
    try{
        cout<<h.HEAP_EXTRACT_MAX()<<endl;
    }catch(invalid_argument& e){
        cerr<<e.what()<<endl;
    }
    h.print();
    return 0;
}