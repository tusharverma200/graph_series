You are given a weighted undirected graph having n vertices and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.
  
  Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int, int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
    priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
    
    pq.push({0,1});
    vector<int>dist(n+1, 1e9), parent(n+1);
    for(int i=1; i<=n; i++)parent[i]=i;
    dist[1]=0;
    while(!pq.empty()){
        int prevdist=pq.top().first;
        int prevnode=pq.top().second;
        pq.pop();
        
        for(auto it:adj[prevnode]){
            int nextnode=it.first;
            int nextdist=it.second;
            if(nextdist+prevdist<dist[nextnode]){
                dist[nextnode]=nextdist+prevdist;
                pq.push({dist[nextnode], nextnode});
                parent[nextnode]=prevnode;
            }
        }
    }
    if(dist[n]==1e9)return {-1};
    
    vector<int>ans;
    int node=n;
    while(parent[node]!=node){
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
     return ans;
    }
};
