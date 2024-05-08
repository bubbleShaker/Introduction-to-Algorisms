#include <bits/stdc++.h>
using namespace std;
int MINIMUM(vector<int> A){
    int n=A.size();
    int mi=A[0];
    for(int i=1;i<n;i++){
        if(mi>A[i]){
            mi=A[i];
        }
    }
    return mi;
}
int main() {
    vector<int> a={3,1,2,8,5,4};
    cout<<MINIMUM(a)<<endl;
    return 0;
}