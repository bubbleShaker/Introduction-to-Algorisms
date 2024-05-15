#include <bits/stdc++.h>
using namespace std;
unordered_set<int> RANDOM_SAMPLE(int m,int n){
    random_device rnd; 
    mt19937 mt(rnd());
    uniform_int_distribution<> RANDOM(1,n);
    if(m==0){
        unordered_set<int> eS;
        return eS;
    }else{
        unordered_set<int> S=RANDOM_SAMPLE(m-1,n-1);
        int i=RANDOM(mt);
        if(S.count(i)){
            S.insert(n);
        }else{
            S.insert(i);
        }
        return S;
    }
}
int main() {
    unordered_set<int> st=RANDOM_SAMPLE(5,10);
    int n=st.size();
    int i=0;
    for(auto v:st){
        cout<<v<<" \n"[i+1==n];
        i++;
    }
    return 0;
}