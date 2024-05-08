#include <bits/stdc++.h>
using namespace std;
vector<int> INSERTION_SORT(vector<int>& A){
    int n=A.size();
    for(int j=1;j<n;j++){
        int key=A[j];
        int i=j-1;
        while(i>=0&&A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

int main() {
    vector<int> a={5,2,4,6,1,3};
    a=INSERTION_SORT(a);
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}
