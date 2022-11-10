class Disjointset{
    vector<int>rank;
    vector<int>parent;
    vector<int>size;
    public:
    Disjointset(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    
    void unionByrank(int u, int v){
        int ul_u = findParent(u);
        int ul_v=findParent(v);
        if(ul_u==ul_v)return ;
        
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }
        else if(rank[ul_u]>rank[ul_v]){
            parent[ul_v]=ul_u;
        }
        else{
            parent[ul_u]=ul_v;
            rank[ul_v]++;
        }
    }
    
     void unionBysize(int u, int v){
        int ul_u = findParent(u);
        int ul_v=findParent(v);
        if(ul_u==ul_v)return ;
        
        if(size[ul_u]<size[ul_v]){
            parent[ul_u]=ul_v;
            size[ul_u]+=size[ul_v];
        }
        else {
            parent[ul_v]=ul_u;
            size[ul_v]+=size[ul_u];
        }
       
    }
    
    
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      vector<pair<int , pair<int , int>>>edges;
      for(int i=0; i<V; i++){
          for(auto it:adj[i]){
              int adjnode=it[0];
              int wt=it[1];
              int node=i;
              edges.push_back({wt, {node, adjnode}});
              }
      }
      
      Disjointset ds(V);
      sort(edges.begin(), edges.end());
      int mstWt=0;
      
      for(auto it:edges){
          int wt=it.first;
          int u=it.second.first;
          int v=it.second.second;
          
          if(ds.findParent(u)!=ds.findParent(v)){
              mstWt+=wt;
              ds.unionBysize(u,v);
          }
      }
      return mstWt;
    }
