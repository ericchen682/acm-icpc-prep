// https://www.hackerrank.com/challenges/extra-long-factorials/problem?h_r=internal-search

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<int> res;
    res.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        for(int j = res.size() - 1; j >= 0; j--)
        {
            res[j] *= i;
            if(res.size() == j + 1 && res[j] >= 10)
            {
                res.push_back(res[j]/10);
            }
            else
            {
                res[j+1] += res[j]/10;
            }
            res[j] %= 10;
        }

        for(int j = 0; j < res.size() - 1; j++)
        {
            res[j+1] += res[j]/10;
            res[j] %= 10;
        }

        while(res[res.size() - 1] >= 10)
        {
            res.push_back(res[res.size()-1]/10);
            res[res.size() - 2] %= 10;
        }
    }
    for(int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}