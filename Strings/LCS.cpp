
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
