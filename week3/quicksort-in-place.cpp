// https://www.hackerrank.com/challenges/quicksort3/problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // always pick last element in subarray as pivot
    // parition left then right
    // print out whole array at end of each partition
    // an array of length 1 or less will be considered sorted

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<pair<int, int>> s;
    s.push({0, n - 1});

    while(!s.empty())
    {
        auto [ l, r ] = s.top();
        s.pop();
        int pivot = arr[r];
        if(l >= r)
            continue;
        if(r-l == 1)
        {
            if(arr[l] > pivot)
                swap(arr[l], arr[r]);
            for(int i = 0; i < n; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        
        int ltPivot = 0;
        for(int i = l; i < r; i++)
        {
            if(arr[i] < pivot)
            {
                ltPivot++;
                if(i-l != ltPivot-1)
                    swap(arr[l + ltPivot-1], arr[i]);
            }
        }
        swap(arr[l + ltPivot], arr[r]);
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        s.push({l + ltPivot + 1, r});
        s.push({l, l + ltPivot - 1});
    }
}