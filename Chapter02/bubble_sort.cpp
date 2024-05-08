#include <bits/stdc++.h>
using namespace std;
void BUBBLESORT(vector<int>& A){
    int n=A.size();
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
            }
        }
    }
}
int main() {
    vector<int> a={5,2,4,7,1,3,2,6};
    int n=a.size();
    BUBBLESORT(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}
