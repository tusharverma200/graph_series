Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.
  
  Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
  
  The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
  
//   CODE
  
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
    
    pq.push({0,S});
    vector<int>dist(V);
    for(int i=0; i<V; i++)dist[i]=1e9;
    dist[S]=0;
    while(!pq.empty()){
        int prevdist=pq.top().first;
        int prevnode=pq.top().second;
        pq.pop();
        
        for(auto it:adj[prevnode]){
            int nextnode=it[0];
            int nextdist=it[1];
            if(nextdist+prevdist<dist[nextnode]){
                dist[nextnode]=nextdist+prevdist;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }
     return dist;
    }
};
