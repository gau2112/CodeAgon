/*
codeagon5.cpp
This new file Created on 26-01-2017 at 23:48:23
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
ll fact[1000005];
struct pqr{

ll con;
ll var;
}num[1000005],den[1000005];
int main()
{

	fact[0] = 1;
	fact[1] = 1;
	ll res = 1;
	ll i,j,k;
	for(i=2;i<1000005;i++)
	{
		res *= i;
		res %= mod;
		fact[i] = res;
	}
	num[1].con = 1;
	num[1].var = 0;
	den[1].con = 0;
	den[1].var = 1;
	num[2].con = 0;
	num[2].var = 2;
	den[2].con = 1;
	den[2].var = 1;
	for(i=3;i<1000005;i++)
	{
        ll p,q,r,s;
        p = i;
        p *= den[i-1].con;
        q = i;
        q *= den[i-1].var;
        p %= mod;
        q %= mod;
        num[i].con = p;
        num[i].var = q;
        den[i].con = (num[i-1].con + den[i-1].con) % mod;
        den[i].var = (num[i-1].var + den[i-1].var) % mod;
	}
    int t;
	cin>>t;
	while(t--)
	{
		ll p,q,r,s;
		cin>>p>>q>>r>>s;
        s = s%mod;
        
		if(p==1)
		{
			ll r1 = fact[q];
			ll r2 = fact[r+1];
			ll r3 = modpow(r1,mod-2,mod);
			r3 *= r2;
			r3 %= mod;
			ll r4 = den[r+1].con;
			ll r5 = den[r+1].var;
			ll r6 = num[q+1].con/(q+1);
			ll r7 = num[q+1].var/(q+1);
			r7 *= s;
			r7 %= mod;
			r7 += r6;
			r7 %= mod;
			r5 *= s;
			r5 %= mod;
			r5 += r4;
			r5 %= mod;
			//cout<<r3<<" "<<r5<<" "<<r7<<endl;
			r5 = modpow(r5,mod-2,mod);
			r3 *= r5;
			r3 %= mod;
			r3 *= r7;
			r3 %= mod;
			cout<<r3<<endl;
			continue;
			//r3 %= mod;


		}
		else
		{
            ll u,v,z,res=1;
            for(i=0;i<=r;i++)
			{
                ll val = (s+i);
                ll r1 = 1;//(q+1);
                ll r2 = (num[q+1].con);
                ll r3 = (num[q+1].var);
                ll r4 = (den[q+1].con);
                ll r5 = (den[q+1].var);
                //cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<r5<<endl;
                r3 *= val;
                r5 *= val;
                r3 %= mod;
                r5 %= mod;
                r3 += r2;
                r5 += r4;
                r3 %= mod;
                r5 %= mod;
                ll invr5 = modpow(r5,mod-2,mod);
                res *= invr5;
                res %= mod;
                res *= r3;
                res %= mod;

			}
			res %= mod;
			cout<<res<<endl;
		}
	}
	return 0;
}

