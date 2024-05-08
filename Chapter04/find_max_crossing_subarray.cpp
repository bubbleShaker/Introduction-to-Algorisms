#include <bits/stdc++.h>
using namespace std;
const int INF=(int)1e9;
tuple<int,int,int> FIND_MAX_CROSSING_SUBARRAY(vector<int> A,int low,int mid,int high){
    int left_sum=-INF;
    int sum=0;
    int max_left=0,max_right=0;
    for(int i=mid;i>=low;i--){
        sum=sum+A[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=-INF;
    sum=0;
    for(int j=mid+1;j<=high;j++){
        sum=sum+A[j];
        if(sum>right_sum){
            right_sum=sum;
            max_right=j;
        }
    }
    return {max_left,max_right,left_sum+right_sum};
}
int main() {
    vector<int> a={1,5,9,2,-3,4};
    int n=a.size();
    tuple<int,int,int> tpl=FIND_MAX_CROSSING_SUBARRAY(a,0,2,n-1);
    auto [li,ri,s]=tpl;
    cout<<li<<" "<<ri<<" "<<s<<endl;
    return 0;
}
