class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    map<pair<int,int>, bool> dp;

    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump) {
        if(curr_stone_idx == n - 1) {
            return true;
        }

        if(dp.count({curr_stone_idx, prevJump}))
            return dp[{curr_stone_idx, prevJump}];

        bool result = false;

        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_idx] + nextJump;

                if(mp.find(next_stone) != mp.end()) {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
        }

        return dp[{curr_stone_idx, prevJump}] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        return solve(stones, 0, 0);
    }
};