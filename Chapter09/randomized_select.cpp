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
int RANDOMIZED_SELECT(vector<int> A,int p,int r,int i){
    if(p==r){
        return A[p];
    }
    int q=RANDOMIZED_PARTITION(A,p,r);
    int k=q-p+1;
    if(i==k){
        return A[q];
    }else if(i<k){
        return RANDOMIZED_SELECT(A,p,q-1,i);
    }else{
        return RANDOMIZED_SELECT(A,q+1,r,i-k);
    }
}
int main() {
    vector<int> a={3,1,2,4,5,8};
    int n=a.size();
    cout<<RANDOMIZED_SELECT(a,0,n-1,6)<<endl;
    return 0;
}