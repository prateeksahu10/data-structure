#include <iostream>

using namespace std;
void insertion_sort ( int A[ ] , int n)
{
     for( int i = 0 ;i < n ; i++ ) {

      int temp = A[ i ];
      int j = i;

          while(  j > 0  && temp < A[ j -1]) {
                A[ j ] = A[ j-1];
                j= j - 1;

           }
           A[ j ] = temp;
     }
}

int main()
{
    int A[10],n;
    cout<<"Enter the number of elements to enter\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    insertion_sort(A,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
