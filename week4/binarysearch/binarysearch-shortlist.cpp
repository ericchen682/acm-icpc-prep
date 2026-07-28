// https://www.infoarena.ro/blog/binary-search-shortlist

#include <iostream>
#include <vector>
#include <math>
using namespace std;

int p1(vector<int>& arr, int x)
{
    // find first occurence of x in arr and last occurence of x in arr
    // what we do is:
    // binsearch for any occurence of x
    // then binsearch for smallest occurence of x and largest occurence of x

    // we want to make sure we account for 0, 1, 2 occurences of x

    int l = 0, r = arr.size();
    int ind = -1;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] == x)
        {
            ind = mid;
            break;
        }
        if(arr[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    if(ind == -1)
        return 0;
    
    int res = 0;
    l = 0;
    r = ind;
    // we want to find largest st != x
    // treat arr[mid] = x as decrease r
    // treat arr[mid] != x as increase l
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] == x)
            r = mid;
        else
            l = mid + 1;
    }
    // index of l is the smallest value s.t. arr[l] = x;
    // now we want to find max value s.t. arr[r] = x;
    res -= l;

    l = ind;
    r = arr.size();
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] == x)
            l = mid + 1;
        else
            r = mid;
    }
    
    res += r;
    return res;
}

int p2(int x)
{
    int l = 0, r = sqrt(x) + 1;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        int cube = mid * mid * mid;
        if(cube == x)
            return mid;
        if(cube > x)
            r = mid;
        else
            l = mid + 1;
    }
    return -1;
}