/*
suffix arrays can be used :

Substring search (find a pattern in a text in O(m log n) instead of naive O(nm)).

Number of distinct substrings.

Longest repeated substring.

Longest common prefix (LCP) between suffixes.

Longest common substring between two strings.

Lexicographic order of substrings.

Problems in suffix/prefix overlaps (like DNA sequencing, compression).

⚡ In short: Whenever the problem is about substring queries, repeated substrings, or lexicographic string comparisons → suffix array (with LCP) is your friend.


*/

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
void solve()
{
    // O(NlogN)
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(all(a));
        for (int i = 0; i < n; i++)
            p[i] = a[i].ss;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].ff == a[i - 1].ff)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {

                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    //O(N) per query 
    vector<int> lcp(n);
    k = 0; // number of equals
    for (int i = 0; i < n - 1; i++)
    {
        int pi = c[i]; // pos of suffix i
        if (pi == 0)
        { // guard: no previous suffix
            k = 0;
            continue;
        }
        int j = p[pi - 1];
        // lcp[i]=lcp(s[i..],s[j..])
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[pi] = k;
        if (k)
            k--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        cout << lcp[i] << " ";
    }
}
// Substring search 
 while (q--)
    {
        string t;
        cin >> t;
        bool found = 0;
        ll l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cmp = s.compare(p[mid], t.size(), t);
            // compare function
            if (cmp == 0)
            {
                found = 1;
                break;
            }
            if (cmp < 0)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (found)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    cout << endl;

//To find how many substrings have t in them  (apply after suffix) per query = O(logn * Len) 

 while (q--)
    {
        string t;
        cin >> t;
        bool found = 0;
        ll l = 0, r = n - 1;
        int ub = n;
        int lb = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cmp = s.compare(p[mid], t.size(), t);
            if (cmp >= 0)
            {
                lb = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cmp = s.compare(p[mid], t.size(), t);
            if (cmp > 0)
            {
                ub = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ub - lb << endl;
    }
//number of distinct substrings 
 ll sum = 0;
    // i first need to count the first element length then add the second - lcp[i]
    sum += n - p[0] - 1;
    for (int i = 1; i < n; i++)
    {
        sum += n - p[i] - 1 - lcp[i];
        // cout << p[i] << " ";
    }
    cout << sum << endl;
// longest repeated substring 
 ll mx = 0;
    string st = "";
    for (int i = 0; i < n; i++)
    {
        if (lcp[i] > mx)
        {
            st = s.substr(p[i], lcp[i]);
            mx = lcp[i];
        }
    }
    if (st.empty())
    {
        cout << -1 << endl;
    }
    else
        cout << st << endl;



