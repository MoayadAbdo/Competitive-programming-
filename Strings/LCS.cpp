
int dp[1001][1001]; //O(N*M)
int lcs(const string &s, const string &t)
{
    int m = s.size(), n = t.size();
    if (m == 0 || n == 0)
        return 0;
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

    return dp[m][n];
}

// to construct it
//O(M+N)
    string lcs = "";
    int i = s.size(), j = t.size(); // n=s.size(),m=t.size();
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs += s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(all(lcs));
    cout << lcs << endl;
// LCS OF TWO ARRAYS 1..N O(NlogN)
int lcs_distinct_positions(const vector<int> &a, const vector<int> &b)
{
    int n = (int)a.size();
    unordered_map<int, int> pos;
    pos.reserve(n * 2);
    pos.max_load_factor(0.7f);
    for (int i = 0; i < n; ++i)
        pos[a[i]] = i;

    vector<int> seq;
    seq.reserve(n);
    for (int x : b)
    {
        auto it = pos.find(x);
        if (it != pos.end())
            seq.push_back(it->second);
        // if x not in 'a', we just skip it (doesn't contribute to LCS)
    }
    // LIS (strictly increasing)
    vector<int> tail;
    tail.reserve(seq.size());
    for (int v : seq)
    {
        auto it = lower_bound(tail.begin(), tail.end(), v);
        if (it == tail.end())
            tail.push_back(v);
        else
            *it = v;
    }
    return (int)tail.size();
}
