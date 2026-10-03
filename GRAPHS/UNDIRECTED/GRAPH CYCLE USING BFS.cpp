#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCycleBFS(vector<vector<int>>& adj,int u,vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({u,-1});
        visited[u]=true;
        
        while(!q.empty()){
            pair<int,int>P=q.front();
            q.pop();
            int source=P.first;
            int parent=P.second;
            for(int &v:adj[source]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push({v,source});
                }
                else{
                    if(v!=parent)return true;
                }
            }
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
            if(!visited[u] && isCycleBFS(adj,u,visited)){
                return true;
            }
        }
        return false;
    }
};