// KAHN'S ALGORITHM
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V,0);
        queue<int>q;
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        //1. find indegree
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }
        //2.add 0 indegree to queue
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        //3.BFS
        vector<int>result;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);    
                }
            }
        }
        return result;
}
};