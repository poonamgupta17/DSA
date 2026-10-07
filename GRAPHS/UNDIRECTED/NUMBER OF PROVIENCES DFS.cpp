//lc-547 
//DFS

//using adjacency list/unordered_map
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
        visited[u]=true;
        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }      
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //isConnected is a vector, and vectors use 0-based indexing.
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
                
            }
        }
        return count;
    }
};

//using matrix only 
class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected,int u,vector<bool>&visited){
        // if(visited[u]==true)return;
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1){
                dfs(isConnected,v,visited);
            }
        }      
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //isConnected is a vector, and vectors use 0-based indexing.
        n=isConnected.size();
        // unordered_map<int,vector<int>>adj;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        vector<bool>visited(n,false);
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(isConnected,i,visited);
                
            }
        }
        return count;
    }
};