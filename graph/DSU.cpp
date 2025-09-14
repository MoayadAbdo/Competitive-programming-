/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


ordered_set s;
s.insert(8);
*(s.find_by_order(0)
s.order_of_key(8)
if (s.find(2) != s.end()) 
    s.erase(s.find(2)); 
*/

struct DSU {
   vector<int> p, sz, sum, mx, mn;
    int n;
 
    DSU(int _n) : n(_n) {
       p.resize(n);
        sz.resize(n, 1);
        mx.resize(n);
        mn.resize(n);
        iota(all(mx), 0);
        iota(all(mn), 0);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y); 
            }
            p[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    }
 
    int size(int x) { return sz[get(x)]; }
    int summ(int x) { return sum[get(x)]; }
    int mnn(int x) { return mn[get(x)]; }
    int mxx(int x) { return mx[get(x)]; }
};

// DSU WITH ROLLBACK
struct DSU {
    vector<int> p, sz;
    stack<tuple<int, int, int, int>> history;
    int components;

    DSU(int n){
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        sz.assign(n + 1, 1);
        components = n;
    }

    int get(int x){
        return x == p[x] ? x : get(p[x]);
    }

    void unite(int x, int y){
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]){
                swap(x, y);
            }
            history.push({x, sz[x], y, p[y]});

            p[y] = x;
            sz[x] += sz[y];
            components--;
        }
    }

    void rollback(){
        auto [root_x, old_sz_x, root_y, old_p_y] = history.top();
        history.pop();
        
        p[root_y] = old_p_y;
        sz[root_x] = old_sz_x;
        components++;
    }
};


//thats how you run it (zero based) 
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--)
    {
        string s;
        int x, y;
        cin >> s >> x >> y;
        x--, y--;
        if (s == "union")
        {
            dsu.unite(x, y);
        }
        else
        {
            cout << (dsu.get(x) == dsu.get(y) ? "YES" : "NO") << endl;
        }
    }
}
