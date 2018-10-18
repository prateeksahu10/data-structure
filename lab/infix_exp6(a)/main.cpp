#include <iostream>
#define Size 100
int top = -1;
char arr[Size];

using namespace std;

void push(char item)
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

char pop()
{
    char temp1 = arr[top];
    top--;
    return(temp1);
}

int isoperator(char symbol)
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
    char infix[Size],postfix[Size],temp,item;
    cout<<"\nEnter the infix expression\n";
    cin>>infix;
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        item = infix[i];
        if(item == '(')
        {
            push(item);
        }
        else if(isalnum(item))
        {
           postfix[j] = item;
           j++;
        }
        else if(isoperator(item) == 1)
        {
            temp = pop();
            while(isoperator(temp) == 1 && precedence(temp)>=precedence(item))
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
            while(temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            cout<<"\nInvalid\n";
        }
        i++;
    }

    while(top > -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    cout<<postfix;
}
