#include <bits/stdc++.h>
using namespace std;
void RANDOMIZE_IN_PLACE(vector<int>& A){
    int n=A.size();
    random_device rnd; 
    mt19937 mt(rnd());
    for(int i=0;i<n;i++){
        uniform_int_distribution<> RANDOM(i,n-1);
        swap(A[i],A[RANDOM(mt)]);
    }
}
int main() {
    vector<int> a={1,2,3,4,5};
    int n=a.size();
    RANDOMIZE_IN_PLACE(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}