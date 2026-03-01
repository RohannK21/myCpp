class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> cunt;
        for(int i:nums){ cunt[i]++;
        if(cunt[i]>1)return true;};
        return false;
        
    }
};