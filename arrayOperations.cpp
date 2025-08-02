#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertElement(int arr[], int &n, int x, int ind)
{
  for(int i=n; i>ind; i--)
  {
      arr[i]=arr[i-1];
  }
  arr[ind]=x;
  n++;
}

void deleteElement(int arr[], int &n, int ind)
{
    for(int i=ind; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
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
    
    printArray(arr,s);
    insertElement(arr,s,6,2);
    printArray(arr,s);
    deleteElement(arr,s,0);
    printArray(arr,s);
    return 0;
}
