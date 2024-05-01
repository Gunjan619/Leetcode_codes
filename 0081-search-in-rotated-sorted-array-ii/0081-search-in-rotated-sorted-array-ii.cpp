class Solution {
public:
    int findPivot(vector<int> &nums) {
    int s = 0;
    int e = nums.size() - 1;
    
    while (s < e) {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] > nums[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    
    return s; // Return the index of the pivot
}


bool binarySearch(vector<int>& nums, int s, int e, int target) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if(nums[mid] == target) {
            return true;
        } else if (nums[mid] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return false;
}

bool search(vector<int>& nums, int target) {
     int s = 0;
    int e = nums.size() - 1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == target) {
            return true;
        }
        
        // Handle the case where elements at s, mid, and e are all the same
        if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
            // Move both s and e inward to skip duplicates
            s++;
            e--;
        } else if (nums[s] <= nums[mid]) { // Left half is sorted
            if (nums[s] <= target && target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    
    return false;
}
    
};