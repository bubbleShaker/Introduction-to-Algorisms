#include <bits/stdc++.h>
using namespace std;
const int INF=(int)1e9;
void MERGE(vector<int>& A,int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    vector<int> L(n1+1),R(n2+1);
    for(int i=1;i<=n1;i++){
        L[i-1]=A[p+i-1];
    }
    for(int j=1;j<=n2;j++){
        R[j-1]=A[q+j];
    }
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }
}
void MERGE_SORT(vector<int>& A,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MERGE_SORT(A,p,q);
        MERGE_SORT(A,q+1,r);
        MERGE(A,p,q,r);
    }
}
int main() {
    vector<int> a={5,2,4,7,1,3,2,6};
    int n=a.size();
    MERGE_SORT(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}
