class Solution {
    private:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<pair<int, int>>&vec,vector<vector<int>>& grid , int i0, int j0 ){
     int n=grid.size();
     int m=grid[0].size();
     vis[i][j]=1;
     vec.push_back({i-i0, j-j0});
     int delr[]={0,1,0,-1};
     int delc[]={1,0,-1,0};
     
     for(int k=0; k<4; k++){
         int r=i+delr[k];
         int c=j+delc[k];
         
    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1){
        dfs(r,c,vis, vec, grid, i0, j0);
    }     
     }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
     
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>>vis(n, vector<int>(m,0));
     set<vector<pair<int , int>>>s;
     
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            
             if(!vis[i][j] && grid[i][j]==1){
                  vector<pair<int, int>>vec;
                 dfs(i, j, vis, vec, grid, i, j);
                  s.insert(vec);
             }
            
         }
     }
     return s.size();
    }
};
