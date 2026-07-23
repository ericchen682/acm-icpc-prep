// https://www.spoj.com/problems/FACTCG2/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    // precompute
    vector<int> pf(10000001, 1);
    for(int i = 2; i <= 10000000; i++)
    {
        if(pf[i] != 1)
            continue;
        for(int j = i; j <= 10000000; j += i)
            if(pf[j] == 1)
                pf[j] = i;
    }
    int n;
    while(scanf("%i", &n) != EOF)
    {
        vector<int> res;
        while(n != 1)
        {
            res.push_back(pf[n]);
            n/=pf[n];
        }
        cout << "1";
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++)
        {
            cout << " x " << res[i];
        }
        cout << '\n';
    }
}