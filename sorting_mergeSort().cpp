#include<iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int size1=mid-l+1;
    int size2=r-mid;
    int a[size1];
    int b[size2];

    for(int i=0; i<size1; i++)
        a[i]=arr[l+i];
    for(int i=0; i<size2; i++)
        b[i]=arr[mid+1+i];

        int ptr1=0;
        int ptr2=0;
        int k=l;

        while(ptr1<size1 && ptr2<size2)
        {
            if(a[ptr1]<b[ptr2])
            {
                arr[k]=a[ptr1];
                k++;
                ptr1++;
            }
            else
            {
                arr[k]=b[ptr2];
                k++;
                ptr2++;
            }
        }
            while(ptr1<size1)
            {
                arr[k]=a[ptr1];
                k++;
                ptr1++;
            }
            while(ptr2<size2)
            {
                arr[k]=b[ptr2];
                k++;
                ptr2++;
            }
}

void mergeSort(int arr[],int l, int r)
{
    if(l<r)
        {
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    Merge(arr,l,mid,r);
        }
}

int main()
{
    int s;
    cout<<"Enter array size : ";
    cin>>s;
    int arr[s];

    for(int i=0; i<s; i++)
        cin>>arr[i];

        mergeSort(arr,0,s-1);
        cout<<"After merge sort : ";

        for(int i=0; i<s; i++)
        cout<<arr[i]<<" ";
    return 0;
}
