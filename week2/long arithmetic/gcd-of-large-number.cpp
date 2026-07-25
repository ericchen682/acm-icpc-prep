// https://www.codechef.com/problems/GCD2

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a; string b;
    cin >> a >> b;
    if(a == 0)
    {
        cout << b << '\n';
        return;
    }
    
    // we only need to gcd b once

    long long bga = 0;
    for(int i = 0; i < b.size(); i++)
    {
        bga *= 10;
        bga %= a;
        bga += b[i]-'0';
        bga %= a;
    }
    cout << gcd(a, bga) << '\n';
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    while(n--) solve();
}