Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.
  
  E = [[0,1,9]]
S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
  
  //code
  
   vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
  
  // relax n-1 times to fill dist arry because it can not be filled in only one iteration
     vector<int>dist(V, 1e8);
     dist[S]=0;
     for(int i=0; i<V-1; i++){
         for(auto it:edges){
             int u=it[0];
             int v=it[1];
             int wt=it[2];
             if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                 dist[v]= dist[u]+wt;
             }
         }
     }
     
  // one more iteration to check if there is a negative cycle or not
      for(auto it:edges){
             int u=it[0];
             int v=it[1];
             int wt=it[2];
             if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                return {-1};
             }
         }
         return dist;
    }
};
