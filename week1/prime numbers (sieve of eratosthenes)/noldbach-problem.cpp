// https://codeforces.com/problemset/problem/17/A?locale=en

#include <bits/stdc++.h>
using namespace std;

int main() {
    // at least k prime numbers between 2 and n can be represented as the sum of 2 consecutive primes and 1
    int n, k; cin >> n >> k;
    vector<bool> prime(n+1, true);
    vector<int> primes;
    for(int i = 2; i <= n; i++)
    {
        if(!prime[i])
            continue;
        primes.push_back(i);
        for(int j = i * 2; j <= n; j += i)
            prime[j] = false;
    }
    for(int i = 0; i < primes.size() - 1; i++)
    {
        if(primes[i] + primes[i+1] + 1 > n)
            break;
        if(prime[primes[i] + primes[i+1] + 1])
            k--;
    }
    if(k <= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}