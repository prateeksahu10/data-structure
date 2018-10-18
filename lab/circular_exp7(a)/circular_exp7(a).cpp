#include <iostream>
#define Size 5

using namespace std;

class circular
{
private:
    int arr[Size];
    int Front,rare,num,temp;
public:
    circular()
    {
        Front = -1;
        rare = -1;
    }
    void enq()
    {
        if((Front == 0 && rare == Size-1)||(Front == rare+1))
        {
            cout<<"\nQueue is full\n";
        }
        else if(Front == -1 && rare == -1)
        {
            cout<<"\nEnter the number to insert\n";
            cin>>num;
            Front = 0;
            rare = 0;
            arr[rare] = num;
        }
        else if(rare == Size-1)
        {
            cout<<"\nEnter the number to insert\n";
            cin>>num;
            rare = 0;
            arr[rare] = num;
        }
        else
        {
            cout<<"\nEnter the number to insert\n";
            cin>>num;
            rare++;
            arr[rare] = num;
        }
    }

    int deq()
    {
        if(Front == -1 && rare == -1)
        {
            temp = -1;
        }
        else if(Front == rare)
        {
            temp = arr[Front];
            Front = -1;
            rare = -1;
        }
        else if(Front == Size-1)
        {
            temp = arr[Front];
            Front = 0;
        }
        else
        {
            temp = arr[Front];
            Front++;
        }
        return temp;
    }
};

int main()
{
    circular c1;
    int num,r;
    int exit = 1;
    do
    {
        cout<<"\n1 to enqueue\n2 to dequeue\n3 to exit\n";
        cin>>num;
        switch(num)
        {
        case 1:
            c1.enq();
            break;
        case 2:
            r = c1.deq();
            if(r == -1)
            {
                cout<<"\nQueue is empty\n";
            }
            else
            {
                cout<<"\n"<<r<<" is dequeued\n";
            }
            break;
        case 3:
            exit = 0;
            break;
        }
    }while(exit);
}
