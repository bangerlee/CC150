/*
8.11 Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        dp[0][0]=1;
        for(int i=1;i<=coins.size();i++){
            dp[i][0]=1;
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j]+(j>=coins[i-1]?dp[i][j-coins[i-1]]:0);
            }
        }
        return dp[coins.size()][amount];
    }
};
