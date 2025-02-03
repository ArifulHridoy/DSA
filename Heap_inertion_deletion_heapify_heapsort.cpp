#include<iostream>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int n;

    MaxHeap()
    {
        arr[0]=-1;
        n=0;
    }

    void insertion(int x)
    {
        n+=1;
        int ind=n;
        arr[ind]=x;
        while(ind>1)
        {
            int parent=ind/2;

            if(arr[parent]<arr[ind])
            {
                swap(arr[parent],arr[ind]);
                ind=parent;
            }
            else return;
        }
    }

    void deletion()
    {
        if(n==0) return;

        arr[1]=arr[n];
        n--;

        int i=1;
        while(i<n)
        {
            int leftInd=2*i;
            int rightInd=2*i+1;

            if(leftInd<n && arr[i]<arr[leftInd])
            {
                swap(arr[i],arr[leftInd]);
                i=leftInd;
            }
            else if(rightInd<n && arr[i]<arr[rightInd])
            {
                swap(arr[i],arr[rightInd]);
                i=rightInd;
            }
            else return;
        }
    }

    void display()
    {
        for(int i=1; i<=n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;

    }
};

void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]) largest=left;
    if(right<=n && arr[largest]<arr[right]) largest=right;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    int t=n;
    while(t>1)
    {
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}

int main()
{
    MaxHeap h;
    h.insertion(1);
    h.insertion(10);
    h.insertion(100);
    h.insertion(1000);
    h.display();

    h.deletion();
    h.display();

    h.insertion(500);
    h.display();

    int arr[]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
     for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
