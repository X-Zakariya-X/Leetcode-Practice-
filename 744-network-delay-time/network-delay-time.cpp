class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

    // build graph
    for (auto &it : times) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 vector<int> dist(n+1, INT_MAX);

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int node = it.second;

        if (d > dist[node]) continue;

        for (auto &nbr : adj[node]) {
            int adjNode = nbr.first;
            int wt = nbr.second;

            if (d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1; // unreachable
        maxi = max(maxi, dist[i]);
    }

    return maxi;
}
};