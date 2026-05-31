class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()){
            return false;
        }
        unordered_map<char,pair<int,int>> charMap;
        for(int i = 0;i < n;i++){
            charMap[s[i]].first++;
            charMap[t[i]].second++;
        }
        for(auto &i:charMap){
            if(i.second.first != i.second.second){
                return false;
            }
        }
    return true;
    }
};
