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

string infix2prefix(stack<char> &s, const string& infix)
{
    string prefix;
    for(int i=0; i<infix.length(); i++)
    {
        char c=infix[i];

        if(isalnum(c)) prefix+=c;
        else if(c=='(') s.push(c);

        else if(c==')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                prefix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(c))
        {
            while(!s.empty() && precedence(c)<precedence(s.top()) && !(c=='^' && s.top()=='^'))
            {
                prefix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
        while(!s.empty())
        {
            prefix+=s.top();
            s.pop();
        }
        return prefix;
}

int main()
{
    ios::sync_with_stdio(false);
    string infix,prefix;
    cin>>infix;
    stack <char> s;
    reverse(infix.begin(),infix.end());

    for(int i=0; i<infix.length(); i++)
    {
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }

    prefix=infix2prefix(s,infix);
    reverse(prefix.begin(),prefix.end());

    cout<<prefix<<endl;
    return 0;
}
