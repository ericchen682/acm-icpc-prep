// https://www.hackerrank.com/challenges/quicksort1/problem

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;
    int num; cin >> num;
    vector<int> left, right;
    int temp;
    for(int i = 1; i < n; i++)
    {
        cin >> temp;
        if(num >= temp)
            left.push_back(temp);
        else
            right.push_back(temp);
    }

    for(auto x : left)
        cout << x << ' ';
    cout << num;
    for(auto x : right)
        cout << ' ' << x;
}