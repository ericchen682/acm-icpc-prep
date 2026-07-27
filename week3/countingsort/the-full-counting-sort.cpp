// https://www.hackerrank.com/challenges/countingsort4/problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ()
{
    int n; cin >> n;
    vector<pair<int, string>> arr(n);
    vector<int> cnt(100, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
        cnt[arr[i].first]++;
    }

    for(int i = 0; i < n/2; ++i)
    {
        arr[i].second = '-';
    }

    for(int i = 0; i < 99; ++i)
    {
        cnt[i+1] += cnt[i];
    }

    vector<pair<int, string>> res(n);
    for(int i = n - 1; i >= 0; --i)
    {
        res[cnt[arr[i].first] - 1] = arr[i];
        cnt[arr[i].first]--;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << res[i].second << ' ';
    }
}