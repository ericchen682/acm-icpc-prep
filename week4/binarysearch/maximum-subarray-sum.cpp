// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> arr(n);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    long long res = 0;
    long long pfx[n + 1];
    pfx[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        pfx[i + 1] = pfx[i] + arr[i];
        pfx[i + 1] %= m;
    }

    set<long long> s;

    for(int i = 0; i < n; ++i)
    {
        s.insert(pfx[i]);
        auto it = s.upper_bound(pfx[i + 1]);
        if(it != s.end())
        {
            res = max(res, (m + pfx[i + 1] - *it)%m);
        }
        else
            res = max(res, pfx[i + 1]);
    }

    cout << res << '\n';
}

int main ()
{
    int t; cin >> t;
    while(t--)
        solve();
}
