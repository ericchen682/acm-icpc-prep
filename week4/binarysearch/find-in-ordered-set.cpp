// https://www.interviewcake.com/question/python/find-in-ordered-set

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; int target;
    cin >> n >> target;
    vector<int> res(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> res[i];
    }
    sort(res.begin(), res.end());

    int l = 0, r = n;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(mid == target)
        {
            cout << mid << '\n';
            return 0;
        }
        if(mid > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << -1 << '\n';
    return 0;
}