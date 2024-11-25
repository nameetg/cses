#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
unordered_map<ll,vector<pair<ll,ll>>> g;
vector<vector<ll>> paths;
unordered_map<ll,ll> v;
void dfs(vector<ll> &p, int node)
{
  if(node==n)
  {
    p.push_back(node);
    paths.push_back(p);
    return ;
  }
  v[node]=1;
  p.push_back(node);
  for(ll i=0;i<g[node].size();i++)
    {
    if (!v[g[node][i].first]) dfs(p,g[node][i].first);
    }
  p.pop_back();
    v[node]=0;
}
int main()
{
  cin>>n>>m;
  for(ll i=1;i<=m;i++)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
    }
  vector<ll> p;
  dfs(p,1);
  ll ans = INT_MAX;
  for(ll i=0;i<paths.size();i++)
    {
      ll dist = 0;
      ll mx = INT_MIN;
      for(ll j=1;j<paths[i].size();j++)
        {
          ll u = paths[i][j-1];
          ll v= paths[i][j];
          for(ll k=0;k<g[u].size();k++)
            {
              if(g[u][k].first == v)
              {
                dist += g[u][k].second;
                mx = max(g[u][k].second, mx);
                break;
              }
            }
        }
      ans = min(ans, dist - mx + mx/2);
    }
  cout<<ans<<endl;
}