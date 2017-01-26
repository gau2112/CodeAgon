/*
codeagon1.cpp
This new file Created on 26-01-2017 at 20:51:53
Created By Gautam Kumar
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int


ll modpow(ll a,ll b, ll c)
{
	if(b==0)
	return 1;
	if(b==1)
	return a;
	ll temp = modpow(a,b/2,c);
	temp*=temp;
	temp%=c;
	if(b%2==1)
		temp*=a;
	temp%=c;
	return temp;
}

int main()
{
	ll x,y;
	cin>>x>>y;
	ll t,u,v,sumx=0,sumy=0;
	cin>>t;
	while(t--)
	{
		cin>>u>>v;
		sumx += u;
		sumy += v;
	}
	x = x - sumx;
	y = y - sumy;
	cout<<x<<" "<<y<<endl;
	return 0;
}
