There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
  
  Example 1:
Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1
Output:
700
Explaination:
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
  
  //code
  
  // implementation of dikjastra algorithm
  // here we have used a queue not a priority queue because stops are inscreasing in a linear order by amount of only 1 but not as distance which increase int random fashion.
  
  class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
      vector<pair<int , int>>adj[n];
      for(auto it:flights){
          adj[it[0]].push_back({it[1],it[2]});
      }
      vector<int>dist(n, 1e9);
      dist[src]=0;
      queue<pair<int , pair<int , int>>>q;
      q.push({0,{src,0}});
      while(!q.empty()){
          auto it=q.front();
          q.pop();
          int stops=it.first;
          int node=it.second.first;
          int dis=it.second.second;
          
          if(stops>K)continue;
          
          for(auto it:adj[node]){
              int adjnode=it.first;
              int adjw=it.second;
              if(dis+adjw<dist[adjnode] && stops<=K){
                  dist[adjnode]=dis+adjw;
                  q.push({ stops+1,{adjnode, dist[adjnode]}});
                  
              }
          }
      }
      
      if(dist[dst]==1e9)return -1;
      return dist[dst];
    }
};
