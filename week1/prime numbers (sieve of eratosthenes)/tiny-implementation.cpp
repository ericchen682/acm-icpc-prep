// https://wiki.haskell.org/99_questions/Solutions/39

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int l, r;
    cin >> l >> r;
    vector<bool> res(r + 1, true);
    res[0] = false;
    res[1] = false;
    for(int i = 2; i <= r; i++)
    {
        if(!res[i]) 
            continue;
        
        for(int j = i * 2; j <= r; j += i)
            res[j] = false;
    }
    for(int i = l; i <= r; i++)
    {
        if(res[i])
            cout << i << ' ';
    }
}