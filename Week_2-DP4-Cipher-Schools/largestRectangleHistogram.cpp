#include <bits/stdc++.H>
using namespace std;
int largestRectangleArea(vector<int>& arr) {
int n = arr.size();
    vector<int> lm(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(!st.empty())
            lm[i] = st.top();
        else
            lm[i] = -1;
        st.push(i);
    }
    stack<int> st2;
    vector<int> rm(n);
    for(int i=n-1; i>=0; i--){
        while(!st2.empty() && arr[st2.top()] >= arr[i])
            st2.pop();
        if(!st2.empty())
            rm[i] = st2.top();
        else
            rm[i] = n;
        st2.push(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, (rm[i]-lm[i]-1) * arr[i]);
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,1,7,4,7,4,6};
    cout<<largestRectangleArea(arr)<<endl;
}