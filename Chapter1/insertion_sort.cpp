#include <bits/stdc++.h>
using namespace std;
vector<int> insertion_sort(vector<int> a){
    int n=a.size();
    for(int j=1;j<n;j++){
        int key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    return a;
}

int main() {
    vector<int> a={5,2,4,6,1,3};
    a=insertion_sort(a);
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i+1==n];
    }
    return 0;
}
