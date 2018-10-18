#include <iostream>

using namespace std;

void sorting(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        int j = i;
        while(j>0 && temp < arr[j-1])
        {
            arr[j] = arr[j-1];
            j=j-1;
        }
        arr[j] = temp;
    }
}

void sorted_add(int arr[],int &num,int n)
{
    int pos;
    for(int i=0;i<num;i++)
    {
        if(n < arr[i])
        {
            pos = i;
            break;
        }
    }

    for(int j=n;j>=pos;j--)
    {
        arr[j] = arr[j-1];
    }
    arr[pos] = n;
    num++;
}

int main()
{
    int num,n;
    cout<<"\nEnter the number of elements to insert in the array\n";
    cin>>num;
    int arr[num];
    cout<<"\nEnter the numbers\n";
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    sorting(arr,num);
    cout<<"\nThe sorted array is as\n";
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"Enter the number to insert\n";
    cin>>n;
    sorted_add(arr,num,n);
    cout<<"\nThe sorted array is as\n";
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }

}
