/*
codeagon2.cpp
This new file Created on 26-01-2017 at 20:53:38
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
struct crate{
ll s;
ll nos;
}a[105];
bool compare(const crate& p, const crate& q)
{
	return p.nos > q.nos;
}

int main()
{
	ll m,c;
	cin>>m>>c;
	ll i,j,k;
	for(i=0;i<c;i++)
		cin>>a[i].s>>a[i].nos;
	sort(a,a+c,compare);
    ll sum = 0;
    i = 0;
    while(1)
	{
		if(i==c)
			break;
		if(m<=0)
			break;
		if(m >= a[i].s)
		{
			m = m - a[i].s;
			ll res = a[i].s;
			res *= a[i].nos;
			sum += res;
			i++;
		}
		else
		{
			ll res = m;
			res *= a[i].nos;
			sum += res;
			i++;
			m = 0;
		}
	}
	cout<<sum<<endl;
	return 0;
}
