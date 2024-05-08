#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Heap {
private:
    const int INF=1e9;
    vector<T> A;
    int heap_size;
public:
    Heap():heap_size(0) {}
    Heap(vector<T> vec):A(vec) {
        heap_size=vec.size();
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
    int get_length(){
        return A.size()-1;
    }
    int get_heap_size(){
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
        heap_size=get_length();
        for(int i=heap_size/2;i>=1;i--){
            MAX_HEAPIFY(i);
        }
    }
    void BUILD_MIN_HEAP(){
        heap_size=get_length();
        for(int i=heap_size/2;i>=1;i--){
            MIN_HEAPIFY(i);
        }
    }
    void HEAPSORT(){
        BUILD_MAX_HEAP();
        for(int i=get_length();i>=2;i--){
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
    void HEAP_INCREASE_KEY(int i,T key){
        if(key<A[i]){
            throw invalid_argument("new key is smaller than current key");
        }
        A[i]=key;
        while(i>1&&A[PARENT(i)]<A[i]){
            swap(A[i],A[PARENT(i)]);
            i=PARENT(i);
        }
    }
    void MAX_HEAP_INSERT(T key){
        heap_size++;
        A.push_back(-INF);
        HEAP_INCREASE_KEY(heap_size,key);
    }
    void ind_print(){
        for(int i=1;i<=get_length();i++){
            cout<<"i:"<<i<<" "<<"A[i]"<<A[i]<<endl;
        }
    }
    void print(){
        for(int i=1;i<=get_length();i++){
            cout<<A[i]<<" \n"[i==get_length()];
        }
    }
};
int main() {
    Heap<int> h({3,1,4,2,5});
    try{
        h.MAX_HEAP_INSERT(6);
    }catch(invalid_argument& e){
        cerr<<e.what()<<endl;
    }
    h.print();
    return 0;
}