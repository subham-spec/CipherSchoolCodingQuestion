#include <bits/stdc++.h>
using namespace std;
map<vector<int>, vector<vector<int>>> graph;
map<int, vector<vector<int>>> nodes_in_comp;
set<vector<int>> visited;

bool overlap(vector<int>& a, vector<int>& b) {
    return a[0] <= b[1] and b[0] <= a[1];
}

void buildGraph(vector<vector<int>>& intervals) {
    for (auto interval1 : intervals) {
        for (auto interval2 : intervals) {
            if (overlap(interval1, interval2)) {
                graph[interval1].push_back(interval2);
                graph[interval2].push_back(interval1);
            }
        }
    }
}

vector<int> mergeNodes(vector<vector<int>>& nodes) {
    int min_start = nodes[0][0];
    for (auto node : nodes) {
        min_start = min(min_start, node[0]);
    }

    int max_end = nodes[0][1];
    for (auto node : nodes) {
        max_end = max(max_end, node[1]);
    }

    return {min_start, max_end};
}
void markComponentDFS(vector<int>& start, int comp_number) {
    stack<vector<int>> stk;
    stk.push(start);

    while (!stk.empty()) {
        vector<int> node = stk.top();
        stk.pop();

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            nodes_in_comp[comp_number].push_back(node);

            for (auto child : graph[node])
                stk.push(child);
        }
    }
}

void buildComponents(vector<vector<int>>& intervals) {
    int comp_number = 0;
    for (auto interval : intervals) {
        if (visited.find(interval) == visited.end()) {
            markComponentDFS(interval, comp_number);
            comp_number++;
        }
    }
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    buildGraph(intervals);
    buildComponents(intervals);

    vector<vector<int>> merged;
    for (size_t comp = 0; comp < nodes_in_comp.size(); comp++) 
            merged.push_back(mergeNodes(nodes_in_comp[comp]));

    return merged;
}
int main(){
    vector<vector<int>> vp = {{1,3},{2,6},{8,10},{15,18}};

    merge(vp);
}