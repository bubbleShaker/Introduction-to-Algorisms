#include <bits/stdc++.h>
using namespace std;
vector<int> COUNTING_SORT(vector<int> A,vector<int>& B,int k,int ind){
    vector<int> C(k+1);
    vector<int> cA=A;
    for(int j=0;j<A.size();j++){
        cA[j]/=pow(10,ind-1);
        C[cA[j]%10]++;
    }
    for(int i=1;i<=k;i++){
        C[i]+=C[i-1];
    }
    for(int j=A.size()-1;j>=0;j--){
        B[C[cA[j]%10]]=A[j];
        C[cA[j]%10]--;
    }
    return B;
}
vector<int> RADIX_SORT(vector<int> A,int d){
    int n=A.size();
    vector<int> B(n+1);
    int k=10;
    for(int i=1;i<=d;i++){
        COUNTING_SORT(A,B,k,i);
        for(int j=0;j<n;j++){
            A[j]=B[j+1];
        }
    }
    return A;
}
int main() {
    vector<int> a={21,85,73,12,36,25,16,76};
    int n=a.size();
    int d=2;
    a=RADIX_SORT(a,d);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i==n];
    }
    return 0;
}