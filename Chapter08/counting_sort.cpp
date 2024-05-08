#include <bits/stdc++.h>
using namespace std;
void COUNTING_SORT(vector<int> A,vector<int>& B,int k){
    vector<int> C(k+1);
    for(int j=0;j<A.size();j++){
        C[A[j]]++;
    }
    for(int i=1;i<=k;i++){
        C[i]+=C[i-1];
    }
    for(int j=A.size()-1;j>=0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
}
int main() {
    vector<int> a={2,8,7,1,3,5,6,6};
    int n=a.size();
    vector<int> b(n+1);
    int k=10;
    COUNTING_SORT(a,b,k);
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" \n"[i==n];
    }
    return 0;
}