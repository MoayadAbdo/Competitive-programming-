//check for a cycle in a DIRECTED GRAPH
//O(N)
int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
//UNDIRECT 
int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
//Bellman-Ford algorithm for a cycle with value (if asked about positive values *-1 to weights)
struct Edge
{
    int u, v;
    ll w;
};

int n, m;
vector<Edge> edges;

void solve()
{
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto &e : edges)
        {
            if (dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = max(-INF, dist[e.u] + e.w);
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }
    if (x == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int y = x;
        for (int i = 0; i < n; i++)
            y = parent[y];

        vector<int> cycle;
        for (int cur = y;; cur = parent[cur])
        {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
//to find a cycle of length k+1 <= len 
const int N = 1e5 + 5;
vector<int> adj[N];
int n, m, k;
vector<int> parent(N, -1), depth(N, 0);
vector<bool> visited(N, false);

void printt(int u, int v)
{
    vector<int> cycle;
    while (u != v)
    {
        cycle.push_back(u);
        u = parent[u];
    }
    cycle.push_back(v);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle)
        cout << x << " ";
    cout << "\n";
    exit(0);
}

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (u == parent[v])
            continue;
        if (!visited[u])
        {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            dfs(u);
        }
        else if (depth[v] - depth[u] + 1 >= k + 1)
        {

            printt(v, u);
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    while(m--){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i])dfs(i);
    }
}
/*
Positive cycle detection → negate weights + Bellman–Ford.

Maximum-weight simple cycle → NP-hard (only small graphs possible).

Maximum mean-weight cycle → use Karp’s algorithm.
*/
