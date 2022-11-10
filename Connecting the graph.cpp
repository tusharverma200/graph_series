You are given a graph with n vertices and m edges.

You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operation that will be required to make the graph connected.

If it is not possible to make the graph connected, return -1.
  
  Example 1: 

Input:
n=4
m=3
Edge=[ [0, 1] , [0, 2] , [1, 2] ]

Output:
1

Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
  
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
    int Solve(int n, vector<vector<int>>& edge){
        Disjointset ds(n);
       int extraedg=0;
       for(auto it:edge){
           int u=it[0];
           int v=it[1];
           if(ds.findParent(u)==ds.findParent(v)){
               extraedg++;
           }
           else{
               ds.unionBysize(u, v);
           }
       }
       
       int cnt=0;
       for(int i=0; i<n; i++){
           if(ds.parent[i]==i){
               cnt++;
           }
       }
       
       int ans=cnt-1;
       if(extraedg>=ans){
           return ans;
       }
       return -1;
    }
};
