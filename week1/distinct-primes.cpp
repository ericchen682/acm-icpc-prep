#include <bits/stdc++.h>
using namespace std;

int main() {
    // we want to find the 1000 smallest product of 3 distinct prime numbers
    // not necessarily 3 distinct primes because 60 is product of 2, 2, 3, 5 and it counts
    vector<int> primes(3001, 0);
    vector<int> res;
    for(int i = 2; i <= 3000; i++)
    {
        if(primes[i] >= 3)
            res.push_back(i);
        if(primes[i] != 0)
            continue;
        for(int j = i; j <= 3000; j += i)
            primes[j]++;
    }
    int t; cin >> t;
    int n;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        n--;
        cout << res[n] << '\n';
    }
}