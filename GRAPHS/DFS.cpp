// dfs using adjacency list
// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph.

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(unordered_map<int,vector<int>>& adj,int u,vector<bool>&visited, vector<int>&result){
        if(visited[u]==true){
            return;
        }        
        visited[u]=true;
        result.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& mp) {
        // Code here
        int n=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<n;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){ //v is an iterator; something that points to an element inside a container. For example, if: mp[u] = {2, 5, 7}; initially v points to 2.
                adj[u].push_back(*v); //* is called the dereference operator; It means: "Give me the value that v is pointing to."
            }
        }
        //v= iterator/pointer to the element ; *v=actual element/value.
        vector<int>result;
        vector<bool>visited(n,false);
        dfs(adj,0,visited,result);
        return result;
    }
};
