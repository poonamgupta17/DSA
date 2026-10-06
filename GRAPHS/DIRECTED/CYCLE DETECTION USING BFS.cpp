// using kahn's algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }

        // 1. find indegree
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }

        // 2. add 0 indegree to queue
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }

        // 3. bfs
        int count=0;
        while(!q.empty()){
            count++;
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        if(count==V)return false; //we visited all states, hence no cycle so return false
        return true;

    }
};