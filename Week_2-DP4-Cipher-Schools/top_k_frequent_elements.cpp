#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>ans;
    int count=0;
    unordered_map<int,int>map;
    for(auto x:nums)
        map[x]++;
    multimap<int,int,greater<int>>map2;
    for(auto it:map)
        map2.insert({it.second,it.first});
    for(auto temp:map2){
        count++;
        if(count > k) return ans;
        ans.push_back(temp.second);
    }
    return ans;
}
int main(){
    vector<int> nums = {1,4,5,2,6,3,1,5,8,3,6};
    int k = 2;

    vector<int> ans;
    ans = topKFrequent(nums, k);
}