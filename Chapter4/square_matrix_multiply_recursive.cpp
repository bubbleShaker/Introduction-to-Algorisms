#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct SquareMatrix {
    vector<vector<T>> data;
    int size;
    SquareMatrix():size(0) {}
    SquareMatrix(int n):size(n) {
        data.resize(n,vector<T>(n));
    }

    T& operator()(int i,int j) {
        return data[i][j];
    }

    const T& operator()(int i,int j) const {
        return data[i][j];
    }
    
    void setMatrix(vector<vector<T>> v){
        data=v;
    }

    int getSize() const {
        return size;
    }

    SquareMatrix<T> operator+(const SquareMatrix<T>& other) const {
        if (size!=other.size) {
            throw invalid_argument("Matrix sizes are not equal");
        }

        SquareMatrix<T> result(size);
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                result(i,j)=(*this)(i,j)+other(i,j);
            }
        }
        return result;
    }
};
SquareMatrix<int> SQUARE_MATRIX_MULTIPLY(SquareMatrix<int> A,SquareMatrix<int> B){
    int n=A.getSize();
    SquareMatrix<int> C(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C(i,j)=C(i,j)+A(i,k)*B(k,j);
            }
        }
    }
    return C;
}
SquareMatrix<int> SQUARE_MATRIX_MULTIPLY_RECURSIVE(SquareMatrix<int> A,SquareMatrix<int> B){
    int n=A.getSize();
    SquareMatrix<int> C(n);
    if(n==1){
        C(0,0)=A(0,0)*B(0,0);
    }else{
        vector nA(2,vector<SquareMatrix<int>>(2,SquareMatrix<int>(n/2)));
        vector nB(2,vector<SquareMatrix<int>>(2,SquareMatrix<int>(n/2)));
        vector nC(2,vector<SquareMatrix<int>>(2,SquareMatrix<int>(n/2)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nA[i/(n/2)][j/(n/2)](i%(n/2),j%(n/2))=A(i,j);
                nB[i/(n/2)][j/(n/2)](i%(n/2),j%(n/2))=B(i,j);
            }
        }
        nC[0][0]=SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[0][0],nB[0][0])+SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[0][1],nB[1][0]);
        nC[0][1]=SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[0][0],nB[0][1])+SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[0][1],nB[1][1]);
        nC[1][0]=SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[1][0],nB[0][0])+SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[1][1],nB[1][0]);
        nC[1][1]=SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[1][0],nB[0][1])+SQUARE_MATRIX_MULTIPLY_RECURSIVE(nA[1][1],nB[1][1]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                C(i,j)=nC[i/(n/2)][j/(n/2)](i%(n/2),j%(n/2));
            }
        }
    }
    return C;
}
int main() {
    vector<vector<int>> a={
        {1,5},
        {3,9}
    };
    vector<vector<int>> b={
        {2,3},
        {2,4}
    };
    int n=a.size();
    SquareMatrix<int> sa(n),sb(n),sc(n);
    sa.setMatrix(a);
    sb.setMatrix(b);
    sc=SQUARE_MATRIX_MULTIPLY_RECURSIVE(sa,sb);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sc.data[i][j]<<" \n"[j+1==n];
        }
    }
    return 0;
}