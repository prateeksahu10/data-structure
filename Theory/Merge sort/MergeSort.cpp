#include<iostream>
using namespace std;
void merging(int a[],int p,int q,int r)
{
    int n1,n2,x;
    n1=q-p+1;
    n2=r-q;
    x =p;
    int l[100],ri[100];
    for(int i=0;i<n1;i++)
    {
        l[i]=a[x];
        x++;
    }
    for(int j=0;j<n2;j++)
    {
        ri[j]=a[q+1];
        q++;
    }
    int i,j,k=p;
    i=j=0;
    while(i<n1 && j <n2)
    {
        if(l[i]<=ri[j])
        {
            a[k]=l[i];
            i++;
            k++;
        }
        else
        {
            a[k]=ri[j];
            j++;
            k++;
        }
    }
        if(j==n2)
        {

            while(i<n1)
        {
            a[k]=l[i];
            k++;
            i++;
        }
        }

        else if(i==n1)
          {

          while(j<n2)
        {
            a[k]=ri[j];
            k++;
            j++;
        }
          }

}
void ms(int a[],int p,int r)
{
    if(p<r)
    {
     int q=(p+r)/2;
     ms(a,p,q);
     ms(a,q+1,r);
     merging(a,p,q,r);
    }
}

int main()
{
	int n;
	cout<<"Enter the size of array\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    ms(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
