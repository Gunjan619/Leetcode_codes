class Solution {
public:
    int solve( vector<int>& days, vector<int>& cost, int index, vector<int>& dp){
    int n=days.size();
    if(index >= n)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];
        
    //1 Day Pass
    int option1 = cost[0] + solve(days, cost, index+1,dp);

    //7 Days Pass
    int i;
    for(i =index; i<n && days[i] < days[index] +7; i++);
    int option2 = cost[1] +  solve(days, cost, i,dp);

    //30 Days Pass
   
    for(i =index; i<n && days[i] < days[index] +30; i++);
    int option3 = cost[2] +  solve(days, cost, i,dp);

    dp[index] = min(option1, min(option2, option3));
        return dp[index];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(days,costs,0,dp);
    }
};