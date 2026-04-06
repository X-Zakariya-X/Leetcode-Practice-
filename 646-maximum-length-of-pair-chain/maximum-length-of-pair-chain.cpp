class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end());
        int n = pairs.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = n; prev >= 0; prev--){

                int ans = dp[prev][curr+1];

                if(prev == n || pairs[curr][0] > pairs[prev][1]){
                    ans = max(ans, 1 + dp[curr][curr+1]);
                }

                dp[prev][curr] = ans;
            }
        }

        return dp[n][0];
    }
};