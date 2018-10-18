#include <iostream>

using namespace std;
class stackm
{
private:
    int arr[20];
    int top;
    int maxcap,num;
public:
    stackm(int cap)
    {
        top = -1;
        maxcap = cap;
    }
    void push()
    {
        if(top == maxcap-1)
        {
            cout<<"\nStack is full\n";
        }
        else
        {
            cout<<"\nEnter the number to push in stack\n";
            cin>>num;
            top++;
            arr[top] = num;
        }
    }
    int pop()
    {
        if(top == -1)
        {
            return -1;
        }
        else
        {
            int temp  = arr[top];
            top--;
            return temp;
        }
    }
    int topp()
    {
      if(top == -1)
      {
          return -1;
      }
      else
      {
        int temp = arr[top];
        return temp;
      }
    }
};

int main()
{
    int cap;
    cout<<"\nEnter the capacity of stack\n";
    cin>>cap;
    stackm s1(cap);
    int num,ch,res;
    int exit = 1;
    do
    {
        cout<<"\n1 to push the element in stack\n2 to pop the element\n3 to display top of stack\n4 to exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            /*cout<<"\nEnter the number to push in stack\n";
            cin>>num;*/
            s1.push();
            break;
        case 2:
            res = s1.pop();
            if(res == -1)
            {
                cout<<"\nStack is empty\n";
            }
            else
            {
                cout<<"\n"<<res<<" is pop out\n";
            }
            break;
        case 3:
            res = s1.topp();
            if(res == -1)
            {
                cout<<"\nNo element at top\n";
            }
            else
            {
                cout<<"\n"<<res<<" is at top\n";
            }
            break;
        case 4:
            exit = 0;
            break;
        }
    }while(exit);
}
