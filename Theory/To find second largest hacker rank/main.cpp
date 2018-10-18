#include <iostream>

using namespace std;

int main()
{
    int n,num,flag = 0,count=1,j=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>num;
        arr[i] = num;
        j++;
    }

    int max_e = arr[0];

    if(j==1)
    {
        cout<<"Invalid i/p";
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
               {
                   if(arr[i] != arr[j])
                   {
                       flag = 1;
                       break;
                   }
               }
        }
        if(flag == 1)
        {
                    for(int i=0;i<n;i++)
                        {
                            if(arr[i] > max_e)
                            {
                                max_e = arr[i];
                            }
                        }

                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n-1-i;j++)
                        {
                            if(arr[j] < arr[j+1])
                            {
                                int temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                            }
                        }
                    }

                                    cout<<endl;
                    for(int i=0;i<n;i++)
                    {
                       cout<<arr[i];
                    }

                    int s;
                    for(int i=0;i<n;i++)
                    {
                        if(max_e > arr[i])
                        {
                          s = arr[i];
                          break;
                        }
                    }
                    cout<<endl<<s;
        }
        else
        {
            cout<<"Invalid i/p";
        }

    }




}
