#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Heap {
private:
    vector<int> A;
    int size;
public:
    Heap():size(0) {}
    Heap(vector<int> vec):A(vec) {
        size=vec.size();
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
        return size;
    }
    int LEFT(int i){
        return (i<<1);
    }
    int RIGHT(int i){
        return (i<<1)+1;
    }
    void MAX_HEAPIFY(int i){
        int l=LEFT(i);
        int r=RIGHT(i);
        int largest=0;
        if(l<=A.size()&&A[l]>A[i]){
            largest=l;
        }else{
            largest=i;
        }
        if(r<=A.size()&&A[r]>A[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(A[i],A[largest]);
            MAX_HEAPIFY(largest);
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<"i:"<<i<<" "<<"A[i]"<<A[i]<<endl;
        }
    }
};
int main() {
    vector<int> a={1,3,2,4,5};
    Heap<int> h(a);
    h.MAX_HEAPIFY(1);
    h.print();
    return 0;
}
