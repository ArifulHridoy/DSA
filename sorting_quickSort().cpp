#include<iostream>
using namespace std;

void swapp(int arr[], int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int Partition(int arr[],int l,int r)
{
    int piv=arr[r];
    int i=l-1;
    for(int j=l; j<r; j++)
    {
        if(arr[j]<piv)
        {
            i++;
            swapp(arr,i,j);
        }
    }
    swapp(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int ind=Partition(arr,l,r);
        quickSort(arr,l,ind-1);
        quickSort(arr,ind+1,r);
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

    quickSort(arr,0,s-1);
    cout<<"After quick sort : ";

    for(int i=0; i<s; i++)
        cout<<arr[i]<<" ";
    return 0;
}
