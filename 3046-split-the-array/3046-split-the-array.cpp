class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        if(n%2!=0){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto a: mp){
            if(a.second>2){
                return false;
            }
        }
        return true;
    }
};