#include <iostream>

using namespace std;

int part(int arr[],int p,int r)
{
    int j = p-1;
    int pivot = arr[r];

    for(int i = p;i<r;i++)
    {
        if(arr[i] <= pivot)
        {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp1 = arr[j+1];
    arr[j+1] = arr[r];
    arr[r] = temp1;
    return j+1;
}

void QS(int arr[],int p,int r)
{
    if(p<r)
    {
        int q;
        q = part(arr,p,r);
        QS(arr,p,q-1);
        QS(arr,q+1,r);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    QS(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
