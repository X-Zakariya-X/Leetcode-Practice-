class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> rev(n);   // reverse graph
        vector<int> outdegree(n, 0);
        
        // Step 1: build reverse graph + outdegree
        for(int i = 0; i < n; i++) {
            
            for(auto &v : graph[i]) {
            outdegree[i] = graph[i].size();
                rev[v].push_back(i);  // reverse edge
            }
        }
        
        // Step 2: queue for BFS
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0) {
                q.push(i);  // terminal nodes
            }
        }
        
        vector<int> safe;
        
        // Step 3: BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            safe.push_back(node);
            
            for(auto &parent : rev[node]) {
                outdegree[parent]--;
                
                if(outdegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }
        
        // result sorted hona chahiye
        sort(safe.begin(), safe.end());
        
        return safe;
    }
};