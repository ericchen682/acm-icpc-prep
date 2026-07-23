// https://www.hackerrank.com/challenges/power-of-large-numbers/problem
// note doesn't actually solve as doesn't handle ridiculously large inputs

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, res = 1;
    cin >> x >> y;
    const long long MOD = 10e8 + 7;
    x = x % MOD;
    while(y > 0)
    {
        if(y % 2 == 1)
            res = (res*x)%MOD;
        y /= 2;
        x = (x*x)%MOD;
    }
    cout << res << '\n';
}