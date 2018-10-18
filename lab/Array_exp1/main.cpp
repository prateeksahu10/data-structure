#include <iostream>

using namespace std;

class arrop
{
private:
    int num,pos,dnum,fnum,fpos;
    int flag =0;
public:
    void inserta(int arr[],int &n)
    {
        cout<<"\nEnter the number to insert in the array\n";
        cin>>num;
        cout<<"Enter at which position to insert\n";
        cin>>pos;
        pos=pos-1;
        for(int i=n;i>=pos;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[pos] = num;
        n=n+1;
        cout<<"\nElement Inserted....\n";
    }

    void print(int arr[],int n)
    {
        cout<<"\nElement in the array are: ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void deletea(int arr[],int &n)
    {
        cout<<"\nEnter the number to delete from the array\n";
        cin>>dnum;
        for(int i=0;i<n;i++)
        {
            if(dnum == arr[i])
            {
                flag = 1;
                pos = i;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1)
        {
            for(int j=pos;j<n;j++)
            {
                arr[j] = arr[j+1];
            }
            n=n-1;
            cout<<"\nElement Deleted...\n";
        }
        else
        {
            cout<<"\nNumber not found...\n";
        }
    }

    void finda(int arr[],int n)
    {
        cout<<"\nEnter the element to find in the array\n";
        cin>>fnum;
        for(int i=0;i<n;i++)
        {
            if(fnum == arr[i])
            {
                flag = 1;
                fpos = i;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1)
        {
            cout<<"\nNumber Found at index : "<<fpos<<"\n";
        }
        else
        {
            cout<<"\nNumber not found...\n";
        }
    }
};

int main()
{
    arrop p1;
    int n;
    int ch;
    int exit=1;
    cout<<"\n\nEnter the number of elements to enter in the array\n";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    do
    {
        cout<<"\n1 to Insert a new element at a specified position\n2 Delete an element either whose value is given or whose position is given\n3 To find the location of a given element\n4 To display the elements of the linear array\n5 to Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            p1.inserta(arr,n);
            break;
        case 2:
            p1.deletea(arr,n);
            break;
        case 3:
            p1.finda(arr,n);
            break;
        case 4:
            p1.print(arr,n);
            break;
        case 5:
            exit=0;
            break;
        }

    }while(exit);

}
