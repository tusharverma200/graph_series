Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

  
  
  //code
  class Disjointset{
  
    public:
    
      vector<int>rank;
    vector<int>parent;
    vector<int>size;
    
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

class Solution {
  public:
 
    int numProvinces(vector<vector<int>> ad, int V) {
       Disjointset ds(V);
       for(int i=0; i<V; i++){
           for(int j=0; j<V; j++){
               if(ad[i][j]==1){
                 ds.unionBysize(i,j);  
               }
           }
       }
       int count=0;
       for(int i=0; i<V; i++){
           if(ds.parent[i]==i){
               count++;
           }
       }
        
     return count;
    }
};
