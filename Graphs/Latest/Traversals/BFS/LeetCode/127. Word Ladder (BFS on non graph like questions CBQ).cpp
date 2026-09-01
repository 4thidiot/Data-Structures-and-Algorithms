class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set <string> s;
        for(auto it : wordList)
            s.insert(it);

        queue <string> q;
        q.push(beginWord);

        int ans = 1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto top = q.front();
                q.pop();

                if(top == endWord)
                    return ans;

                for(int i=0; i<top.size(); i++)
                {
                    char original = top[i];
                    for(char c='a'; c<='z'; c++)
                    {
                        top[i] = c;

                        if(s.count(top))
                        {
                            q.push(top);
                            s.erase(top);
                        }
                    }
                    top[i] = original; //baaki indexes bhi to check karni hai
                }
            }
            ans++; // hit → hot → {dot, lot} → {dog, log} → cog : after processing one BFS level, move to the next level
        }
        return 0;
    }
};
