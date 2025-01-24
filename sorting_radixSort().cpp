#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int div)
{
    int ans[n];
    int cnt[10]={0};
    for(int i=0; i<n; i++) cnt[(arr[i]/div)%10]++;
    for(int i=1; i<10; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)
    {
        ans[cnt[(arr[i]/div)%10]-1]=arr[i];
        cnt[(arr[i]/div)%10]--;
    }
    for(int i=0; i<n; i++) arr[i]=ans[i];
}

int getMax(int arr[], int n)
{
    int Max=0;
    for(int i=0; i<n; i++)
        if(arr[i]>Max) Max=arr[i];
    return Max;
}

void radixSort(int arr[], int n)
{
    int m=getMax(arr,n);
    for(int div=1; m/div>0; div*=10) countSort(arr,n,div);
}

int main()
{
    cout<<"Enter array size : ";
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    radixSort(arr,n);

        cout<<"Sorted array : ";
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}

