#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q;
vector<vector<ll>> g;
ll minPath(ll src, ll desti)
{
  vector<ll> d(n+1, 1e17);
  d[src]=0;
  for(int i=1;i<n;i++)
    {
      for(int i=0;i<g.size();i++)
        {
          int u = g[i][0];
          int v = g[i][1];
          int w = g[i][2];
          if(d[u] != 1e17 && d[u] + w < d[v])
          {
            d[v] = d[u]+w;
          }
        }
    }
  return d[desti] >= 1e17 ? -1 : d[desti];
}
int main()
{
  cin>>n>>m>>q;
  for(int i=1;i<=m;i++)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      g.push_back({a,b,c});
      g.push_back({b,a,c});
    }
  vector<ll> ans;
  for(int i=1;i<=q;i++)
    {
      ll a,b;
      cin>>a>>b;
      ans.push_back(minPath(a,b));
    }
  for(int i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<endl;
    }
}