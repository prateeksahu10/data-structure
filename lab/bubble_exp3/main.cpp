#include <iostream>

using namespace std;

class arrop
{
private:
    int num,pos;
    int Flag = 0;
public:
    void sorta(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    inter(arr[j],arr[j+1]);
                }
            }
        }
    }

    int inter(int &a,int &b)
    {
        int temp = a;
        a = b;
        b= temp;
    }

    void bsearch(int arr[],int n,int snum)
    {
        int l=0;
        int r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(snum == arr[mid])
            {
                pos = mid;
                Flag = 1;
                break;
            }
            else if (snum > arr[mid])
            {
                    l=mid+1;
            }
            else{
                r=mid-1;
            }

        }

        if(Flag == 1)
        {
             cout<<"\nElement Found at index : "<<pos;
        }
        else
        {
            cout<<"\nNumber is not present in array...\n";
        }

    }
};

int main()
{
    arrop p1;
    int n,snum,pos;
    cout<<"\nEnter the number of elements to enter in the array\n";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    p1.sorta(arr,n);
    cout<<"\nEnter the number to search in the array\n";
    cin>>snum;
    p1.bsearch(arr,n-1,snum);
    /*if(pos == -1)
    {
        cout<<"\nNumber is not present in array...\n";
    }
    else
    {
        cout<<"\nElement Found...\n";
    }*/
}
