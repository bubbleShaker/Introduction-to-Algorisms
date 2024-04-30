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
tuple<int,int,int> FIND_MAXIMUM_SUBARRAY(vector<int> A,int low,int high){
    if(high==low){
        return {low,high,A[low]};
    }else{
        int mid=(low+high)/2;
        auto [left_low,left_high,left_sum]=FIND_MAXIMUM_SUBARRAY(A,low,mid);
        auto [right_low,right_high,right_sum]=FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
        auto [cross_low,cross_high,cross_sum]=FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);
        if(left_sum>=right_sum&&left_sum>=cross_sum){
            return {left_low,left_high,left_sum};
        }else if(right_sum>=left_sum&&right_sum>=cross_sum){
            return {right_low,right_high,right_sum};
        }else{
            return {cross_low,cross_high,cross_sum};
        }
    }
}
int main() {
    vector<int> a={1,-5,9,-2,-3,-4};
    int n=a.size();
    auto [li,ri,s]=FIND_MAXIMUM_SUBARRAY(a,0,n-1);
    cout<<li<<" "<<ri<<" "<<s<<endl;
    return 0;
}