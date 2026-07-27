// https://www.hackerrank.com/challenges/countingsort1/problem

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<int> res(100, 0);
    int curr;
    for(int i = 0; i < n; i++)
    {
        cin >> curr;
        res[curr]++;
    }
    for(int i = 0; i < 100; i++)
    {
        cout << res[i] << ' ';
    }
}