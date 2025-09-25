string s, t;
    cin >> s >> t;
    int a = s.size(), b = t.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
    dp[0][0] = 0;
    // if match dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})
    // else dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1})
    for (int i = 0; i <= a; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= b; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                // match
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    cout << dp[a][b] << endl;
