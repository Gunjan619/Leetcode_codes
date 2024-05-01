class Solution {
public:
    bool isPerfectSquare(int num) {
      int s=1;
        int e =num;
        long long int mid = s+(e-s)/2;
        long long int ans=-1;
        
        while(s<=e){
            long long int sqrt = mid*mid;
            
            if(sqrt == num)
                return true;
            else if(sqrt < num){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return false;  
    }
};