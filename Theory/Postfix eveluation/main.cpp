#include <iostream>
#include <math.h>
#define size 100
int stack_[size];
int top=-1;

using namespace std;

void push(int item)
{
    if(top >= size-1)
    {
        cout<<"Overflow\n";
    }
    else
    {
        top++;
        stack_[top] = item;
    }
}
int pop()
{
    int item;
    item = stack_[top];
    top--;
    return(item);
}
/*int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
    {
        return 1;
    }
}*/
/*int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}*/


int main()
{
    char infix[size],postfix[size],item,temp;
    int i=0,j=0,A,B,result;
    cout<<"Enter the expression\n";
    cin>>postfix;
    while(postfix[i] != '\0')
    {
        item = postfix[i];

        if(isdigit(item))
        {
            result = item-48;
        }
        else
        {
            B = pop();
            A = pop();
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

    cout<<stack_[top];

}
