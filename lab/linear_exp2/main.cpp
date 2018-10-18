#include <iostream>

using namespace std;

class arop
{
private:
    int num;
    int Flag=0;
public:
    int searche(int arr[],int n)
    {
        cout<<"\nEnter the element to search in the array\n";
        cin>>num;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == num)
            {
                Flag = 1;
                break;
            }
            else
            {
                Flag = 0;
            }
        }

        if(Flag == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
   arop a1;
   int n,res;
   cout<<"\nEnter the number of elements to enter in the array\n";
   cin>>n;
   int arr[n];
   cout<<"\nEnter the elements\n";
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   res = a1.searche(arr,n);
   if(res == 1)
   {
       cout<<"\nNumber Found....\n";
   }
   else
   {
       cout<<"\nNumber not Found....\n";
   }
}
