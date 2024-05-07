#include <bits/stdc++.h>
using namespace std;
int RANDOM(int p,int r){
    random_device rnd; 
    mt19937 mt(rnd());
    uniform_int_distribution<> RAND(p,r);
    return RAND(mt);
}
int PARTITION(vector<int>& A,int p,int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int RANDOMIZED_PARTITION(vector<int>& A,int p,int r){
    int i=RANDOM(p,r);
    swap(A[r],A[i]);
    return PARTITION(A,p,r);
}
void RANDOMIZED_QUICKSORT(vector<int>& A,int p,int r){
    if(p<r){
        int q=RANDOMIZED_PARTITION(A,p,r);
        RANDOMIZED_QUICKSORT(A,p,q-1);
        RANDOMIZED_QUICKSORT(A,q+1,r);
    }
}
int main() {
    vector<int> a={2,8,7,1,3,5,6,4};
    int n=a.size();
    RANDOMIZED_QUICKSORT(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}