#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited,stack<int>&s){
        visited[u]=true;
        
        for(int &v:adj[u]){
            if(!visited[v]){
                // s.push(v);
                dfs(adj,v,visited,s);
            }
        }
        s.push(u);
        
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                adj[u].push_back(v);
            }
    
        vector<bool>visited(V,false);
        vector<int>result;
        stack<int>s;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,s);
            }
        }
       
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};