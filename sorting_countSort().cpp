#include<iostream>
using namespace std;

int main()
{
    int Max=0;
    cout<<"Enter array size : ";
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>Max) Max=arr[i];
    }
    cout<<"Max="<<Max<<endl;
    int cnt[Max+1]={0};

    for(int i=0; i<n; i++) cnt[arr[i]]++;

    cout<<"Count array : ";
    for(int i=0; i<=Max; i++) cout<<cnt[i]<<" ";
    cout<<endl;

    for(int i=1; i<=Max; i++) cnt[i]=cnt[i]+cnt[i-1];
    cout<<endl;

    cout<<"Prefix sum array : ";
    for(int i=0; i<Max+1; i++) cout<<cnt[i]<<" ";
        cout<<endl;

        int brr[n];
        for(int i=n-1; i>=0; i--) brr[--cnt[arr[i]]]=arr[i];

        cout<<"Sorted array : ";
        for(int i=0; i<n; i++) cout<<brr[i]<<" ";
        cout<<endl;

    return 0;
}
