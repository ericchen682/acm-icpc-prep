// https://leetcode.com/problems/search-insert-position/description/

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
int n; int target;
    cin >> n >> target;
    vector<int> res(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> res[i];
    }

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
    if(l < n && res[l] < target)
    {
        cout << l + 1 << '\n';
        return 0;
    }
    cout << l << '\n';
    return 0;
}