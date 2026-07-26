// https://www.codechef.com/AUG18B/problems/GCDMOD

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, n; cin >> a >> b >> n;
    // gcd of a^n + b^n and a - b (a always >= b)
    // let diff = a - b

    // because we have a % diff = b % diff
    // we also have a^n % diff = b^n % diff
    // thus we have (a^n + b^n) mod diff = 2*(b^n) mod diff

    // thus our result is gcd(2*b^n mod diff, diff)
    // find 2*b^n mod diff through modular exponentiation

    // requires casting to 128 bit int due to 10^24 not fitting within long long type

    long long diff = a-b;

    const long long MOD = 1e9 + 7;
    // handle a = b edge case, simply calculate a^n + b^n mod 1e9 + 7
    if(diff == 0)
    {
        long long resA = 1, resB = 1;
        while(n > 0)
        {
            if(n % 2 == 1)
            {
                resA = (__int128(resA) * __int128(a)) % MOD;
                resB = (__int128(resB) * __int128(b)) % MOD;
            }
            
            n /= 2;
            a = (__int128(a) * __int128(a)) % MOD;
            b = (__int128(b) * __int128(b)) % MOD;
        }
        cout << (resA + resB) % MOD << '\n';
        return;
    }

    // calculate 2*b^n mod diff

    long long res = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
            res = (__int128(res) * __int128(b)) % diff;
        n /= 2;
        b = (__int128(b) * __int128(b)) % diff;
    }
    
    res *= 2;

    cout << gcd(res, diff) % MOD << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}