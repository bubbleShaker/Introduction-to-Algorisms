#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Stack {
private:
    vector<T> s;
    int top;
public:
    Stack():top(0) { s.resize(0); }
    Stack(int n):top(0) { s.resize(n+1); }
    bool EMPTY(){
        return top==0;
    }
    void PUSH(T x){
        top++;
        s[top]=x;
    }
    T POP(){
        if(EMPTY()){
            throw invalid_argument("underflow");
        }else{
            top--;
            return s[top+1];
        }
    }
    void print(){
        for(int i=1;i<=top;i++){
            cout<<s[i]<<" \n"[i==top];
        }
    }
};
int main() {
    try{
        Stack<int> stk(10);
        stk.PUSH(6);
        stk.PUSH(10);
        stk.print();
        stk.POP();
        stk.print();
    }catch(invalid_argument& e){
        cerr<<e.what()<<endl;
    }
    return 0;
}