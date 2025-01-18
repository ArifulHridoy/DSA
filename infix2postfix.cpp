#include <iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int precedence(char c)
{
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infix2postfix(stack<char> &s, const string& infix)
{
    string postfix;
    for(int i=0; i<infix.length(); i++)
    {
        char c=infix[i];
        if(isalnum(c))
        {
            postfix+=c;
        }
        else if(c=='(')
        {
            s.push(c);
        }
        else if(c==')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(c))
        {
            while(!s.empty() && precedence(c)<=precedence(s.top()) && !(c=='^' && s.top()=='^'))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
        while(!s.empty())
        {
            postfix+=s.top();
            s.pop();
        }
        return postfix;
}

int main()
{
    ios::sync_with_stdio(false);
    string infix,postfix;
    cin>>infix;
    stack <char> s;
    postfix=infix2postfix(s,infix);
    cout<<postfix<<endl;
    return 0;
}

