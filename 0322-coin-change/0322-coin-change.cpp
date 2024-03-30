class Solution {
public:
    int solve(vector<int> &num, int x,vector<int> &dp){
    if(x ==0)
        return 0;
    if(x<0)
        return INT_MAX;

    if(dp[x] != -1)
        return dp[x];
    
    int mini = INT_MAX;

    for(int i =0; i<num.size(); i++){
        int ans = solve(num, x- num[i],dp);
        if(ans !=INT_MAX )
            mini = min(mini, 1+ans);
    }

    dp[x] = mini;
    return mini;
} 
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
    int ans = solve(coins,amount, dp);
    if(ans == INT_MAX)
        return -1;
    else
        return ans;
    }
};