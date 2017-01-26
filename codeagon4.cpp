/*
codeagon4.cpp
This new file Created on 26-01-2017 at 22:56:02
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
int a[2005],b[2005],n,e,sum=0;
void call(int cur,int last)
{
	if(cur==n)
	{
		sum++;
		return;
	}
	int i;
	for(i=0;i<e;i++)
	{
		if(last==-1)
		{
			b[i] = b[i]-1;
			call(cur+1,i);
		}
		else if(last==i)
		{
			if(b[i]!=0)
			{
				b[i]=b[i]-1;
				call(cur+1,i);
			}
			else
			{
				continue;
			}
		}
		else if(last!=i)
		{
			for(int j=0;j<e;j++)
				b[j] = a[j];
			b[i] = b[i]-1;
			call(cur+1,i);
		}

	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		//int n,e;
		cin>>n>>e;
		sum = 0;
		int i,j;
		for(i=0;i<e;i++)
			{
				cin>>a[i];
				b[i] = a[i];
			}
		call(0,-1);
		cout<<sum<<endl;

	}
	return 0;
}
