#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countSort(string arr[], int n, int pos)
{
    string ans[n];
    int cnt[256]={0};

    for(int i=0; i<n; i++) cnt[(arr[i][pos])]++;

    for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];

    for(int i=n-1; i>=0; i--)
    {
        ans[cnt[(arr[i][pos])]-1]=arr[i];
        cnt[(arr[i][pos])]--;
    }
    for(int i=0; i<n; i++) arr[i]=ans[i];
}

int getMax(string arr[], int n)
{
    int Max=0;
    for(int i=0; i<n; i++)
        Max=max(Max,(int)arr[i].length());
    return Max;
}

void radixSort(string arr[], int n)
{
    int maxLen=getMax(arr,n);
    for(int i=maxLen-1; i>=0; i--) countSort(arr,n,i);
}

int main()
{
    cout<<"Enter array size : ";
    int n; cin>>n;
    string arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    radixSort(arr,n);

        cout<<"Sorted array : ";
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}

