// https://www.hackerrank.com/challenges/icecream-parlor/problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// just 2 sum, using bin search on sorted array rather than hash map

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i].first + arr[i + 1].first > m)
            break;
        int l = i + 1;
        int r = n;
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(arr[mid].first + arr[i].first == m)
            {
                cout << min(arr[i].second, arr[mid].second) << ' ' << max(arr[i].second, arr[mid].second) << '\n';
                return;
            }
            if(arr[mid].first + arr[i].first > m)
                r = mid;
            else
                l = mid + 1;
        }
    }
}

int main ()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}