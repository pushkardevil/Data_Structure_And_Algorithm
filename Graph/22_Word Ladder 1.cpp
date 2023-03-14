//////////////////////////////    BY USING BFS   //////////////////////////////

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord , 1});
        
        unordered_set<string>set(wordList.begin() , wordList.end());
        set.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(word == targetWord){
                return steps;
            }
            
            for(int i=0;i<word.size();i++){
                char Original_char=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(set.find(word) != set.end()){
                        set.erase(word);
                        q.push({word , steps+1});
                    }
                }
                word[i]=Original_char;
            }
        }
        return 0;
    }
};
