// https://www.hackerrank.com/challenges/countingsort2/problem

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> cnt(100, 0);

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for(int i = 0; i < 99; ++i)
    {
        cnt[i + 1] += cnt[i];
    }

    vector<int> res(n);
    for(int i = n - 1; i >= 0; --i)
    {
        res[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << res[i] << ' ';
    }
}