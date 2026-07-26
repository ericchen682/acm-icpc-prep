// https://www.hackerrank.com/challenges/quicksort1/problem

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr)
{
    if(arr.size() <= 1)
        return;
    if(arr.size() == 2)
    {
        if(arr[0] > arr[1])
            swap(arr[0], arr[1]);
        cout << arr[0] << ' ' << arr[1] << '\n';
        return;
    }
    // otherwise pick pivot and figure out
    int pivot = arr[0];
    vector<int> left, right;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] <= pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    solve(left);
    solve(right);
    int i = 0;
    for(auto num : left)
    {
        cout << num << ' ';
        arr[i] = num;
        i++;
    }
    arr[i] = pivot;
    cout << pivot;
    i++;
    for(auto num : right)
    {
        cout << ' ' << num;
        arr[i] = num;
        i++;
    }   
    cout << '\n';
}

int main ()
{
    int n; cin >> n;
    vector<int> arr;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    solve(arr);
}