#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter array size : ";
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=1; i<n; i++)
    {
        int val=arr[i];
        int j=i;

        while(j && arr[j-1]>val)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=val;
    }

        cout<<"Sorted array : ";
        for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}
