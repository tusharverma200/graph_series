#include<bits/stdc++.h>

using namespace std;

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

int main() {
	
     Disjointset ds(7);
    //  ds.unionByrank(1,2);
    //   ds.unionByrank(2,3);
    //    ds.unionByrank(4,5);
    //     ds.unionByrank(6,7);
    //      ds.unionByrank(5,6);
         
    //      if(ds.findParent(3)==ds.findParent(7)){
    //          cout<<"Same"<<endl;
    //      }
    //      else{
    //           cout<<"Not Same"<<endl;
    //      }
         
    //       ds.unionByrank(3,7);
          
    //        if(ds.findParent(3)==ds.findParent(7)){
    //          cout<<"Same"<<endl;
    //      }
    //      else{
    //           cout<<"Not Same"<<endl;
    //      }
    
      ds.unionBysize(1,2);
      ds.unionBysize(2,3);
       ds.unionBysize(4,5);
        ds.unionBysize(6,7);
         ds.unionBysize(5,6);
         
         if(ds.findParent(3)==ds.findParent(7)){
             cout<<"Same"<<endl;
         }
         else{
              cout<<"Not Same"<<endl;
         }
         
          ds.unionBysize(3,7);
          
           if(ds.findParent(3)==ds.findParent(7)){
             cout<<"Same"<<endl;
         }
         else{
              cout<<"Not Same"<<endl;
         }

	return 0;
}
