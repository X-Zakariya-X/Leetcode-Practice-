class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

for(auto & p : prerequisites){
    int a = p[0];
    int b =p[1];

    adj[b].push_back(a);
    indegree[a]++;
}

queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;

        // Step 3: BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return count == numCourses;
    }
}
;