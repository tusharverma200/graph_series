You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
  
  heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explaination: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
  
  //code
  
  
  class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
      
priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
int n=heights.size();
int m=heights[0].size();

vector<vector<int>>dist(n, vector<int>(m, 1e9));
dist[0][0]=0;
pq.push({0,{0,0}});
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int diff=it.first;
    int row=it.second.first;
    int col=it.second.second;
    
    if(row==n-1 && col==m-1){
        return diff;
    }
    
    for(int i=0; i<4; i++){
        int newr=row+dr[i];
        int newc=col+dc[i];
        
        if(newr>=0 && newc>=0 && newr<n && newc<m){
            int absdiff=max(abs(heights[row][col]-heights[newr][newc]), diff);
            if(absdiff<dist[newr][newc]){
                dist[newr][newc]=absdiff;
                pq.push({absdiff,{newr,newc}});
            }
        }
    }
}
return 0;
    }
};
