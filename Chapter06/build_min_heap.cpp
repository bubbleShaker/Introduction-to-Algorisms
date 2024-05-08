#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Heap {
private:
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
    int getSize(){
        return heap_size;
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
        for(int i=heap_size/2;i>=1;i--){
            MAX_HEAPIFY(i);
        }
    }
    void BUILD_MIN_HEAP(){
        for(int i=heap_size/2;i>=1;i--){
            MIN_HEAPIFY(i);
        }
    }
    void print(){
        for(int i=1;i<=heap_size;i++){
            cout<<"i:"<<i<<" "<<"A[i]"<<A[i]<<endl;
        }
    }
};
int main() {
    Heap<int> h({4,2,3,1,5});
    h.BUILD_MIN_HEAP();
    h.print();
    return 0;
}