Floyd Warshall Algorithm

The Floyd Warshall Algorithm is for solving all pairs shortest path problems. The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed Graph. 
  
  
  Initialize the solution matrix same as the input graph matrix as a first step. 
Then update the solution matrix by considering all vertices as an intermediate vertex. 
The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. 
For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]

// in thsi algo if we are trying to findiung the shortest path betwenn every two node via all nodes including thwmselves.

The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.
  
  
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

  
  //code
  
  class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	   for(int i=0; i<n; i++){
	       for(int j=0; j<n; j++){
	           if(matrix[i][j]==-1){
	               matrix[i][j]=1e9;
	           }
	           if(i==j){
	               matrix[i][j]=0;
	           }
	       }
	   }
	   
	   for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
    	       for(int j=0; j<n; j++){
    	          matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
    	          
    	       }
    	   }
	   }
	   
	   
	   
	   
	   for(int i=0; i<n; i++){
	       for(int j=0; j<n; j++){
	           if(matrix[i][j]==1e9){
	               matrix[i][j]=-1;
	           }
	          
	       }
	   }
	}
};
