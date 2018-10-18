#include <iostream>

using namespace std;

int main()
{
    int A[10],n;
    cout<<"Enter the number of elements to enter\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for (int i=0;i<n;i++)
    {
        cin>>A[i];

        for (int j=0;j<=i;j++)
        {
            int temp = A[j];
            int k = j;

            while(k>0 && temp<A[k-1])
            {
                A[k] = A[k-1];
                k--;
            }

            A[k] = temp;
        }
    }

    cout<<"\nPrint\n";

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
