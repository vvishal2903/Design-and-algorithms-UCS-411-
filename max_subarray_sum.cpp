#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b)
{
    if(a>b)
    return a;
    else 
    return b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c); 
}

int maxCrossingSum(int arr[], int l, int mid, int r)
{
    int sum=0;
    int left_sum=INT_MIN;

    for (int i = mid; i >= l; i--) { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
            left_sum = sum; 
    } 

    sum=0;
    int right_sum=INT_MIN;
    for (int i = mid; i <= r; i++) { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
            left_sum = sum; 
    } 
    return ; 
} 

    