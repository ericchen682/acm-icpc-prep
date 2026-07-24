// https://www.hackerrank.com/challenges/sherlock-and-gcd/problem?h_r=internal-search

#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
    if(a == 0)
        return b;
    return findGCD(b%a, a);
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        // if the entire array has gcd = 1
        // if the entire array is duplicates, return false;
        int n; cin >> n;
        bool allDupes = true;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] != arr[0]) allDupes = false;
        }

        if(allDupes)
        {
            cout << "NO\n";
            continue;
        }

        sort(arr, arr+n);
        // calc gcd of 1, 2, then 2, 3, then so on so forth
        for(int i = 0; i < n-1; i++)
        {
            arr[i+1] = findGCD(arr[i+1], arr[i]);
        }
        if(arr[n-1] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}