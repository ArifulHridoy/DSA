#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n, int data)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==data)
            return mid;

        else if(arr[mid]<data)
        left=mid+1;

        else if(arr[mid]>data)
            right=mid-1;
    }
    return -1;
}
int main()
{
    int s;
    cin>>s;
    int arr[100];

    for(int i=0; i<s; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+s);

    cout<<"Your search value : ";
    int data;
    cin>>data;

    int ind=binarySearch(arr,s,data);

    if(ind>=0)
    cout<<"Data found at ind : "<<ind<<endl;

    else cout<<"Not found"<<endl;
    return 0;
}
