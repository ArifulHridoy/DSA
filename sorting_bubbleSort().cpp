#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter array size : ";
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=n-1; i>=0; i--)
        for(int j=0; j<i; j++)
        if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);

        cout<<"Sorted array : ";
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}

