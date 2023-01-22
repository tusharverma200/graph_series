Strongly Connected Components – Kosaraju’s Algorithm:

Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
  
  Algorithm: 

The algorithm steps are as follows:

Sort all the nodes according to their finishing time:

To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.
Reverse all the edges of the entire graph:
Now, we will create another adjacency list and store the information of the graph in a reversed manner.
Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.
Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.
Note: 

The first step is to know, from which node we should start the DFS call.
The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.
The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.
Note: The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.

Note: If you wish to see the dry run of the above approach, you can watch the video attached to this article.
  
  
  
  //// code
  
  
  
  #include<bits/stdc++.h>
void dfs(int node, stack<int>&st, vector<int>adj[], vector<int>&vis){

vis[node]=1;

for(auto it:adj[node]){
    if(!vis[it]){
        dfs(it, st, adj, vis);
    }
}
st.push(node);
}

void dfs2(vector<int>&vis, vector<int>&temp, int node,  vector<int>transpose[]){
    vis[node]=1;
    temp.push_back(node);

    for(auto it:transpose[node]){
        if(!vis[it]){
            dfs2(vis, temp, it, transpose);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
   vector<int>adj[n];
   int m=edges.size();
   for(int i=0; i<m; i++){
       adj[edges[i][0]].push_back(edges[i][1]);
   }
    
    stack<int>st;

    vector<int>vis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, st,adj , vis);
        }
    }

      vector<int>transpose[n];
    
    for(int i=0; i<n; i++){
        vis[i]=0;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }
    vector<vector<int>>ans;

    while(!st.empty()){
        int node=st.top();
        st.pop();
        vector<int>temp;
        if(!vis[node]){
      dfs2(vis, temp, node, transpose);
      ans.push_back(temp);
        }
    }

return ans;
}
