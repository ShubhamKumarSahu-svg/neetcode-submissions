class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto i: nums){
            if(hash[i] > 0) return true;
            hash[i]++;
        }
        return false;
    }
};
