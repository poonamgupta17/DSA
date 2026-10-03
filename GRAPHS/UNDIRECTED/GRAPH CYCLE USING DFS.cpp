//time complexity: O(V+E)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj,int u, int parent,vector<bool>&visited){
        visited[u]=true;
        for(int &v:adj[u]){
            if(v==parent)continue;

            if(visited[v])return true;
            
            if(isCycleDFS(adj,v,u,visited))return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //unordered_map<int,vector<int>>adj; //same as vector<vector<int>>& edges
        vector<vector<int>> adj(V);

                for (auto &edge : edges) {
                    int u = edge[0];
                    int v = edge[1];

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
        vector<bool>visited(V,false);
        
        for(int u=0;u<V;u++){
            if(!visited[u] && isCycleDFS(adj,u,-1,visited)){
                return true;
            }
        }
        return false;
    }
};