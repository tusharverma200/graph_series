class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
      
       vector<int>adjrev[V];
       int indegree[V]={0};
      // reversing the adges of the graph
       for(int i=0; i<V; i++){
           for(auto it:adj[i]){
               adjrev[it].push_back(i);
               indegree[i]++;
           }
       }
       
       queue<int>q;
       for(int i=0; i<V; i++){
           if(indegree[i]==0)q.push(i);
       }
       vector<int>safenodes;
       
       while(!q.empty()){
           int node=q.front();
           q.pop();
           safenodes.push_back(node);
           for(auto it:adjrev[node]){
               indegree[it]--;
               if(indegree[it]==0){
                   q.push(it);
               }
           }
       }
      // ans is required in ascending order
       sort(safenodes.begin(), safenodes.end());
       return safenodes;
    }
};
