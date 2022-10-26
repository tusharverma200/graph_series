Problem Statement: Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at locations just below, just above just left, and just right of it.
  
  Examples:

Example 1:

Input: n = 5, m = 4
  
 X X X X
 X O X X
 X O O X
 X O X X 
 X X O O
 
 OUTPUT
    
 X X X X
 X X X X
 X X X X
 X X X X 
 X X O O
 
 Intuition:.
The boundary elements in the matrix cannot be replaced with ‘X’ as they are not surrounded by ‘X’ from all 4 directions. This means if ‘O’ (or a set of ‘O’) is connected to a boundary ‘O’ then it can’t be replaced with ‘X’. 

The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’. 

Approach:

We can follow either of the traversal techniques as long as we are starting with a boundary element and marking all those Os connected to it. We will be solving it using DFS traversal, but you can apply BFS traversal as well. 

DFS is a traversal technique that involves the idea of recursion.. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes.

The algorithm steps are as follows:

Create a corresponding visited matrix and initialize it to 0.
Start with boundary elements, once ‘O’ is found, call the DFS function for that element and mark it as visited. In order to traverse for boundary elements, you can traverse through the first row, last row, first column, and last column. 
DFS function call will run through all the unvisited neighboring ‘O’s in all 4 directions and mark them as visited so that they are not converted to ‘X’ in the future. The DFS function will not be called for the already visited elements to save time, as they have already been traversed. 
When all the boundaries are traversed and corresponding sets of ‘O’s are marked as visited, they cannot be replaced with ‘X’. All the other remaining unvisited ‘O’s are replaced with ‘X’. This can be done in the same input matrix as the problem talks about replacing the values, otherwise tampering with data is not advised. 
Consider the following illustration to understand how DFS traverses the matrix and replaces O’s with X’s.

CODE


#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &mat, int delrow[], int delcol[]) {
        vis[row][col] = 1; 
        int n = mat.size();
        int m = mat[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, 
    vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vector<vector<int>> vis(n, vector<int>(m,0)); 
        // traverse first row and last row 
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol); 
            }
            
            // last row 
            if(!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1,j,vis,mat, delrow, delcol); 
            }
        }
        
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol); 
            }
            
            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat, delrow, delcol); 
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return mat; 
    }
};

int main(){
    
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
Output:

X X X X
X X X X
X X X X
X X X X
X X O O

Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 
 
 
 
