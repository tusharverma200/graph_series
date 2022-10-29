Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
  
  
  Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
  
//code

class Solution{
   private:
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
    
    
    
  
    string findOrder(string dict[], int N, int K) {
       vector<int>adj[K];
       
       for(int i=0; i<N-1; i++){
           string s1=dict[i];
           string s2=dict[i+1];
           int len=min(s1.length(), s2.length());
         // if both strings till len will be same, then there will be no answer
         // oR if there is some cyclic dependency in the order then als there will also be not any answer
           for(int j=0; j<len; j++){
               if(s1[j]!=s2[j]){
                   adj[s1[j]-'a'].push_back(s2[j]-'a');
                   break;
               }
           }
       }
       
       vector<int>topo=topoSort(K, adj);
       string ans="";
       for(auto it:topo){
           ans+=char(it+'a');
       }
       return ans;
    }
