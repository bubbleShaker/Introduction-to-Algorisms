#include <bits/stdc++.h>
using namespace std;
pair<int,int> MINIMUM_AND_MAXIMUM(vector<int> A){
    int n=A.size();
    int mi,ma;
    int i=0;
    if(n%2==0){
        if(A[i]<A[i+1]){
            mi=A[i];
            ma=A[i+1];
        }else{
            mi=A[i+1];
            ma=A[i];
        }
        i+=2;
    }else{
        mi=A[i];
        ma=A[i];
        i++;
    }
    for(int j=i;j<n;j+=2){
        if(A[j]<A[j+1]){
            if(A[j]<mi){
                mi=A[j];
            }
            if(ma<A[j+1]){
                ma=A[j+1];
            }
        }else{
            if(A[j+1]<mi){
                mi=A[j+1];
            }
            if(ma<A[j]){
                ma=A[j];
            }
        }
    }
    return {mi,ma};
}
int main() {
    vector<int> a={3,1,2,4,5,8};
    auto [mi,ma]=MINIMUM_AND_MAXIMUM(a);
    cout<<mi<<" "<<ma<<endl;
    return 0;
}