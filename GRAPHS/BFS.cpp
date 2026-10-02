// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph.

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        queue<int>q;
        q.push(u);
        visited[u]=true;
        result.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    result.push_back(v);
                }
            }
        }   
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        // code here
        int n=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<n;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        vector<int>result;
        vector<bool>visited(n,false);
        bfs(adj,0,visited,result);
        return result;
    }
};