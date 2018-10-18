#include <iostream>
#define size 100
char stack_[size];
int top=-1;

using namespace std;

void push(char item)
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
char pop()
{
    char item;
    item = stack_[top];
    top--;
    return(item);
}
int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
    {
        return 1;
    }
}
int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}


int main()
{
    char infix[size],postfix[size],item,temp;
    int i=0,j=0;
    cout<<"Enter the expression\n";
    cin>>infix;
    while(infix[i] != '\0')
    {
        item = infix[i];

        if(item == '(')
        {
            push(item);
        }
        else if(isalnum(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            temp = pop();
            while(is_operator(temp) == 1 &&precedence(temp)>=precedence(item)) //here temp = top
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(item);
        }
        else if(item == ')')
        {
            temp = pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            cout<<"Invalid";
        }
        i++;
    }

    while(top > -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    cout<<"Airthmetic expression\n";
    cout<<postfix;

}
