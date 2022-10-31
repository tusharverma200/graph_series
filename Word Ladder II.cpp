Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
  
  Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
  
  
  class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(), wordList.end());
        vector<vector<string >>ans;
        vector<string>usedOnlevel;
        usedOnlevel.push_back(beginWord);
        queue<vector<string>>q;
        q.push({beginWord});
        int level=0;
        
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            
            if(vec.size()>level){
                level++;
               for(auto it:usedOnlevel){
                   st.erase(it);
               }
            }
            string word=vec.back();
            
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
               else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0; i<word.size(); i++){
                char original=word[i];
                for(char c='a'; c<='z'; c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                       
                        usedOnlevel.push_back(word);
                         vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|
