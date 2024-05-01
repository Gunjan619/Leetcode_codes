class Solution {
public:
    int firstOccu(vector<int>& nums, int n, int target){
        int s=0;
        int e = n-1;
        int mid = s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            
            else if(nums[mid] < target)
                s=mid+1;
            else
                e=mid-1;
            mid = s+(e-s)/2;
        }
        return ans;
        }
    
    int lastOccu(vector<int>& nums, int n, int target){
        int s=0;
        int e = n-1;
        int mid = s+(e-s)/2;
        int ans=-1;
        
        while(s<=e){
            if(nums[mid] == target){
                ans = mid;
                s = mid+ 1;
            }
            
            else if(nums[mid] < target)
                s=mid+1;
            else
                e=mid-1;
            mid = s+(e-s)/2;
        }
        return ans;
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = firstOccu(nums,nums.size(),target);
        int last = lastOccu(nums,nums.size(),target);
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        }
};