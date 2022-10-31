Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0
  
  Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".
  
  Approach:
Let’s first understand the Brute force approach to this problem. In Brute force, we just simply replace the startingWord character by character and then check whether the transformed word is present in the wordList. If a word is present in the wordList, we try replacing another character in that word by again following similar steps as above, in order to attain the targetWord. We do this for all the characters in the startWord and then eventually return the minimum length of transforming the startWord to targetWord.
  Now, to make this algorithm a little less time-consuming and easier, we implement this using a BFS traversal technique.
  
  Initial configuration:

Queue: Define a queue data structure to store the BFS traversal.
Hash set: Create a hash set to store the elements present in the word list to carry out the search and delete operations in O(1) time. 
The Algorithm involves the following steps:

Firstly, we start by creating a queue data structure in order to store the word and the length of the sequence to reach that word as a pair. We store them in form of {word, steps}. 
Then, we push the startWord into the queue with length as ‘1’ indicating that this is the word from which the sequence needs to start from.
We now create a hash set wherein, we put all the elements in wordList to keep a check on if we’ve visited that word before or not. In order to mark a word as visited here, we simply delete the word from the hash set. There is no point in visiting someone multiple times during the algorithm. 
Now, we pop the first element out of the queue and carry out the BFS traversal where, for each word popped out of the queue, we try to replace every character with ‘a’ – ‘z’, and we get a transformed word. We check if the transformed word is present in the wordList or not.
If the word is present, we push it in the queue and increase the count of the sequence by 1 and if not, we simply move on to replacing the original character with the next character.
Remember, we also need to delete the word from the wordList if it matches with the transformed word to ensure that we do not reach the same point again in the transformation which would only increase our sequence length. 
Now, we pop the next element out of the queue ds and if at any point in time, the transformed word becomes the same as the targetWord, we return the count of the steps taken to reach that word. Here, we’re only concerned about the first occurrence of the targetWord because after that it would only lead to an increase in the sequence length which is for sure not minimum.
If a transformation sequence is not possible, return 0.
Intuition:
The intuition behind using the BFS traversal technique for this particular problem is that if we notice carefully, we go on replacing the characters one by one which seems just like we’re moving level-wise in order to reach the destination i.e. the targetWord.
  
  n level-order traversal, when we reach the destination, we stop the traversal. Similar to that, when we reach our targetWord, we terminate the algorithm and return the counted steps.

We no longer continue the algorithm after that because that would only increase the step count to reach the targetWord.
  
  
  #include <bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};
 
int main()
{
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
}
Output: 

3 

Time Complexity: O(N * M * 26)

Where N = size of wordList Array and M = word length of words present in the wordList..

Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }

Where N = size of wordList Array.
