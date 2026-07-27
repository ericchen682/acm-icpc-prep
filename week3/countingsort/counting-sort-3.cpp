// https://www.hackerrank.com/challenges/countingsort3/problem

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

    cout << cnt[0];
    for(int i = 0; i < 99; ++i)
    {
        cnt[i+1] += cnt[i];
        cout << ' ' << cnt[i+1];
    }
}