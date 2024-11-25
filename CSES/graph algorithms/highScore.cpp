#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<vector<ll>> g;
int main()
{
  cin>>n>>m;
  for(ll i=1;i<=m;i++)
    {
      ll a,b,x;
      cin>>a>>b>>x;
      g.push_back({a,b,-x});
    }
  vector<ll> d(n+1, 1e17);
  d[1]=0;
  ll nif = -1 * 1e17;
  for(ll i=1;i<n;i++)
    {
      for(ll j=0;j<g.size();j++)
        {
          ll u = g[j][0];
          ll v = g[j][1];
          ll w = g[j][2];
          if(d[u]!=1e17 && d[u]+w < d[v])
          {
            d[v] = d[u]+w;
          }
          d[v] = max(d[v],nif);
        }
    }
  for(ll i=1;i<n;i++)
    {
      for(ll j=0;j<g.size();j++)
        {
          ll u = g[j][0];
          ll v = g[j][1];
          ll w = g[j][2];
          d[v] = max(d[v],nif);
          if(d[u]!=LLONG_MAX && d[u]+w < d[v])
          {
            d[v] = nif;
          }
        }
    }
  if(1==n || d[n]==nif) cout<<-1<<endl;
  else cout<<-d[n]<<endl;
}