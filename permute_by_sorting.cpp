#include <bits/stdc++.h>
using namespace std;
void PERMUTE_BY_SORTING(vector<int>& A){
    int n=A.size();
    vector<pair<int,int>> P(n);
    random_device rnd; 
    mt19937 mt(rnd());
    uniform_int_distribution<> RANDOM(1, n*n*n);
    for(int i=0;i<n;i++){
        P[i].first=RANDOM(mt);
        P[i].second=A[i];
    }
    sort(P.begin(),P.end());
    for(int i=0;i<n;i++){
        A[i]=P[i].second;
    }
}
int main() {
    vector<int> a={1,2,3,4,5};
    int n=a.size();
    PERMUTE_BY_SORTING(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}