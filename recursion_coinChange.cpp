#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void coinChange(vector<int>&coins, int amount, int n, vector<int>&combinations)
{
    if(amount==0)
    {
        for(int i:combinations)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(amount<0 || (n<=0 && amount>0)) return;

        combinations.push_back(coins[n-1]);

    coinChange(coins, amount-coins[n-1],n,combinations);
    combinations.pop_back();
    coinChange(coins,amount,n-1,combinations);
}

int main()
{
    vector<int> coins;
    int n;
    cout<<"Enter number of coin denominations : ";
    cin>>n;
    cout<<"Enter the coins size : ";
    while(n--)
    {
        int x; cin>>x;
        coins.push_back(x);
    }
    cout<<"Enter amount to make : ";
    int amount; cin>>amount;

    vector<int> combinations;
    cout<<"Ways are :\n";

    coinChange(coins,amount,coins.size(),combinations);

    return 0;
}
