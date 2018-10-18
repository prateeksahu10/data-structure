#include <iostream>
#include <math.h>
#define Size 100
int top = -1;
int arr[Size];

using namespace std;

void push(int item)
{
    if(top >= Size-1)
    {
        cout<<"Overflow\n";
    }
    else
    {
        top++;
        arr[top] = item;
    }
}

int pop()
{
    int temp1 = arr[top];
    top--;
    return(temp1);
}

int main()
{
     char infix[Size],postfix[Size];
     int result,item,A,B;
    cout<<"\nEnter the infix expression\n";
    cin>>postfix;
    int i=0,j=0;
    while(postfix[i] != '\0')
    {
        item = postfix[i];
        if(isdigit(item))
        {
            result = item-48;
        }
        else
        {
            B=pop();
            A=pop();
            switch(item)
            {
               case '+':
                {
                    result = A+B;

                    break;
                }
                case '-':
                {
                    result = A-B;
                    break;
                }
                case '^':
                {
                    result = pow(A,B);
                    break;
                }
                case '*':
                {
                    result = A*B;
                    break;
                }
                case '/':
                {
                    result = A/B;
                    break;
                }
            }
        }
        push(result);
        i++;
    }

    cout<<arr[top];
}
