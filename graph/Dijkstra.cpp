const ll N = 1 * 1e5 + 5;
vector<pair<ll, ll>> adj[N];
vector<ll> vis(N);
vector<ll> dist(N);
//inside main n=1e5
 vector<ll> dist(n+1, INF);
    vector<int> parent(n+1, -1);
    vector<int> vis(n+1, 0);

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();
        if (vis[a]) continue;
        vis[a] = 1;

        for (auto [b, w] : adj[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                pq.push({dist[b], b});
            }
        }
    }

    // ---- reconstruct path from 1 to n ----
    if (dist[n] == INF) {
        cout << "-1\n"; // no path
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

//path finder 
