#include <iostream>
#define size_ 5
using namespace std;

class circular
{
    int front_,rare,num;
    int arr[size_];
public:
    circular()
    {
        front_ = -1;
        rare = -1;
    }
    void enqueue()
    {
        if((front_ == 0 && rare == size_-1) || (front_ == rare+1))
        {
            cout<<"\nThe Que is full\n";
        }
        else if(front_ == -1 && rare == -1)
        {
            cout<<"\nEnter the number\n";
            cin>>num;
            front_ = 0;
            rare = 0;
            arr[rare] = num;
        }
        else if(rare == size_-1)
        {
            cout<<"Enter the number\n";
            cin>>num;
            rare = 0;
            arr[rare]=num;
        }
        else
        {
            cout<<"Enter the number\n";
            cin>>num;
            rare++;
            arr[rare] = num;
        }
    }
    int dequeue()
    {
        int temp = 0;
        if(front_ == -1 && rare == -1)
        {
            temp = -1;
        }
        else if(front_ == rare)
        {
            temp = arr[front_];
            front_ = -1;
            rare = -1;
        }
        else if(front_ == size_-1)
        {
            temp = arr[front_];
            front_ = 0;
        }
        else
        {
            temp = arr[front_];
            front_++;
        }
        return temp;
    }
};

int main()
{
    circular c1;
    int exit = 1,ch,r;
    do
    {
        cout<<"\n1 to enqueue\n2 to dequeue\n3 to exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            {
                c1.enqueue();
                break;
            }
        case 2:
            {
                r=c1.dequeue();
                if(r == -1)
                {
                    cout<<"Que is empty\n";
                }
                else
                {
                    cout<<r<<" Is dequeued\n";
                }
                break;
            }
        case 3:
            {
                exit = 0;
                break;
            }
        }
    }while(exit);

    cout<<"\nFinished\n";
}

