#include <bits/stdc++.h>
using namespace std;
int PERTITION(vector<int>& A,int p,int r){
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
int main() {
    vector<int> a={2,8,7,1,3,5,6,4};
    int n=a.size();
    cout<<PERTITION(a,0,n-1)+1<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}