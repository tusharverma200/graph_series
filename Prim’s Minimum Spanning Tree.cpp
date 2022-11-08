Prim’s Minimum Spanning Tree (MST) | Greedy Algo

Prim’s algorithm always starts with a single node and it moves through several adjacent nodes, in order to explore all of the connected edges along the way.

It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
  
  A group of edges that connects two sets of vertices in a graph is called cut in graph theory. So, at every step of Prim’s algorithm, find a cut (of two sets, one contains the vertices already included in MST and the other contains the rest of the vertices), pick the minimum weight edge from the cut, and include this vertex to MST Set (the set that contains already included vertices).
  
  How does Prim’s Algorithm Work? 
The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

Follow the given steps to find MST using Prim’s Algorithm:
Create a set mstSet that keeps track of vertices already included in MST. 
Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign the key value as 0 for the first vertex so that it is picked first. 
While mstSet doesn’t include all vertices 
Pick a vertex u which is not there in mstSet and has a minimum key value. 
Include u in the mstSet. 
Update the key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if the weight of edge u-v is less than the previous key value of v, update the key value as the weight of u-v
The idea of using key values is to pick the minimum weight edge from the cut. The key values are used only for vertices that are not yet included in MST, the key value for these vertices indicates the minimum weight edges connecting them to the set of vertices included in MST. 
  
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
  
   int spanningTree(int V, vector<vector<int>> adj[])
    {
      int sum=0;
    
     priority_queue< pair<int , int>, vector< pair<int , int>>, greater< pair<int , int>>>pq;
     pq.push({0,0});
     vector<int>vis(V,0);
     
     while(!pq.empty()){
         int node=pq.top().second;
         int dis=pq.top().first;
         pq.pop();
         
         if(vis[node]==1)continue;
         
         vis[node]=1;
         sum+=dis;
         for(auto it:adj[node]){
             int adjnode=it[0];
             int wt=it[1];
             if(!vis[adjnode]){
                 pq.push({wt, adjnode});
             }
         }
     }
     return sum;
    }
