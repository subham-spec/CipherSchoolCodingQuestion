#include <bits/stdc++.h>
using namespace std;
stack<int> st;
stack<int> insertAtBottom(stack<int> st,int x){
    if(st.empty()){
        st.push(x);
        return st;
    }
    int t=st.top();
    st.pop();
    st=insertAtBottom(st,x);
    st.push(t);
    return st;
}

stack<int> reverse(stack<int> st){
    if(st.empty())
        return st;
    int t=st.top();
    st.pop();
    st=reverse(st);
    st=insertAtBottom(st,t);
    return st;
}    
void push(int x) {
    st.push(x);
}
int pop() {
    st=reverse(st);
    int t=st.top();
    st.pop();
    
    st=reverse(st);
    return t;
}
    
int peek() {
    st=reverse(st);
    int t=st.top();
    st=reverse(st);
    return t;
}
bool empty() {
    return st.empty();
}