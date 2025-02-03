#include<iostream>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int n=0;

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
    void display()
    {
        for(int i=1; i<=n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;

    }
};

int main()
{
    MaxHeap h;
    h.insertion(1);
    h.insertion(10);
    h.insertion(100);
    h.insertion(1000);
    h.display();
    return 0;
}
