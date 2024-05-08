#include <bits/stdc++.h>
using namespace std;
void INSERTION_SORT(vector<int>& A){
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
int RANDOM(int p,int r){
    random_device rnd; 
    mt19937 mt(rnd());
    uniform_int_distribution<> RAND(p,r);
    return RAND(mt);
}
int PARTITION(vector<int>& A,int p,int r,int tx){
    for(int i=p;i<=r;i++){
        if(A[i]==tx){
            swap(A[i],A[r]);
            break;
        }
    }
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int ceili(int a,int b){
    return (a+(b-1))/b;
}
int SELECT(vector<int> A,int p,int r,int i){
    int n=r-p+1;
    if(n==1){
        return A[p];
    }
    int gsize=ceili(n,5);
    vector<vector<int>> group(gsize);
    for(int i=0;i<n;i++){
        group[i/5].push_back(A[p+i]);
    }
    vector<int> med(gsize);
    for(int i=0;i<gsize;i++){
        int m=group[i].size();
        group[i].push_back(-1);//-1 is a sentinel
        INSERTION_SORT(group[i]);
        med[i]=group[i][ceili(m,2)];
    }
    reverse(med.begin(),med.end());
    med.push_back(-1);//-1 is a sentinel
    reverse(med.begin(),med.end());
    int x=SELECT(med,1,gsize,ceili(gsize,2));
    int q=PARTITION(A,p,r,x);
    int k=q-p+1;
    if(i==k){
        return x;
    }else if(i<k){
        return SELECT(A,p,q-1,i);
    }else{
        return SELECT(A,q+1,r,i-k);
    }
}
int main() {
    vector<int> a={-1,3,1,2,4,5,8};
    int n=a.size();
    n--;//-1 is a sentinel
    cout<<SELECT(a,1,n,6)<<endl;
    return 0;
}
