/*
codeagon4.cpp
This new file Created on 26-01-2017 at 21:49:19
Created By Gautam Kumar
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

vector<ll>a[30005];
vector<ll>b[30005];
vector<ll>task;
ll vis[300005];
ll indegree[30005];// task[30005];
set<ll>val;
vector<ll>topo;
void topological()
{
	vector<ll>::iterator itr;
    while(!val.empty())
	{
		set<ll>::iterator pqr=val.begin();
		ll f = *pqr;
		if(vis[f]==1)
        topo.push_back(f);
        val.erase(f);
		itr = a[f].begin();
        for(;itr!=a[f].end();++itr)
		{
            ll k = *itr;
            indegree[k]--;
            if(indegree[k]==0)
				val.insert(k);
		}
	}
	itr = topo.begin();
	cout<<topo.size()<<endl;
	for(;itr!=topo.end();++itr)
		cout<<*itr<<" ";
	cout<<endl;
}
void dfs(ll src)
{
	vis[src] = 1;
	vector<ll>::iterator itr = b[src].begin();
	for(;itr!=b[src].end();++itr)
	{
		if(vis[*itr]==0)
            dfs(*itr);
	}

}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i,j,k,l;
		task.clear();
		topo.clear();
		val.clear();
		for(i=0;i<30004;i++)
		{
			indegree[i] = 0;
			vis[i] = 0;
			a[i].clear();
			b[i].clear();
		}

		for(i=1;i<=n;i++)
		{
            ll d;
            cin>>d;
            if(d==0)
			{
				indegree[i] = 0;
				continue;
			}
            for(j=1;j<=d;j++)
			{
				cin>>l;
                a[l].push_back(i);
                b[i].push_back(l);
                indegree[i]++;
			}

		}
		for(i=1;i<=m;i++)
		{
			cin>>l;
			task.push_back(l);
		}
		for(i=0;i<m;i++)
		{
			if(vis[task[i]]==0)
				dfs(task[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(indegree[i]==0)
				val.insert(i);
		}
		//for(i=1;i<=n;i++)
			//cout<<vis[i]<<" ";
		//cout<<n<<endl;
		topological();

	}
	return 0;
}
