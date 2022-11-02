Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.
  
  Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
  
  CODE
  
 class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
   set<pair<int , int>>st;
   st.insert({0,S});
   vector<int>dist(V, 1e9);
   dist[S]=0;
   
   while(!st.empty()){
       auto it=*(st.begin());
       int node=it.second;
       int dis=it.first;
       st.erase(it);
       
       for(auto x:adj[node]){
           int w=x[1];
           int adjnode=x[0];
           if(dis+w<dist[adjnode]){
               if(dist[adjnode]!=1e9){
                   st.erase({dist[adjnode], adjnode});
               }
             dist[adjnode]=dis+w;
             st.insert({dist[adjnode], adjnode});
           }
       }
   }
   return dist;
    }
};
  
  
