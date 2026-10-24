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
        vector<vector<int>> adj(V); //contains V empty adjacency lists, one for each vertex from 0 to V-1, Otherwise,"vector<vector<int>> adj;" contains 0 vertices initially.

                for (auto &edge : edges) {
                    int u = edge[0];
                    int v = edge[1];

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
        vector<bool>visited(V,false);
        
        for(int u=0;u<V;u++){//for loop → Ensures disconnected components are also checked.

            if(!visited[u] && isCycleDFS(adj,u,-1,visited)){ //This ensures that every connected component is checked.
                //!visited[u] means vertex u has not been visited yet. We use this condition because the graph might be disconnected.
                //ex: The graph has two disconnected components. Vertices 0, 1, 2 form a cycle, while 3 and 4 form a separate component. If DFS starts at vertex 0, it will visit 0, 1, and 2, but it won't reach 3 or 4 as cycle is formed before reaching 3.
                return true;
            }
            //We use !visited[u] && isCycleDFS(...) to start DFS only for unvisited vertices, avoiding redundant traversals and ensuring cycle detection works correctly across disconnected components.
        }
        return false;
    }
};