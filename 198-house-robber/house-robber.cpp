class Solution {
public:
    int rob(vector<int>& nums) {
       vector<int>dp (nums.size()+1,-1);
       dp[0]=0;
       dp[1]=nums[0];

       for(int i=2;i<=nums.size();i++){
        int steal =nums[i-1]+dp[i-2];
        int skip=dp[i-1];
        dp[i]=max(steal,skip);
       }
       return dp[nums.size()];
    }
};