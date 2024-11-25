#include<bits/stdc++.h>
using namespace std;
int n,m,q;
// cin>>n>>m>>q;
unordered_map<int,vector<pair<int,int>>> g;
unordered_map<int,int> v;
void dfs(int s, int e, int a, int &ans)
{
  if(s==e)
  {
    ans = min(ans,a);
    return;
  }
  v[s]++;
  for(auto x:g[s])
    {
      if(!v[x.first]) dfs(x.first,e,a+x.second,ans);
    }
}
int main()
{
  cin>>n>>m>>q;
  for(int i=1;i<=m;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
    }
  vector<int> ans;
  for(int i=1;i<=q;i++)
    {
      int x,y;
      cin>>x>>y;
      int md = INT_MAX;
      dfs(x,y,0,md);
      if(md==INT_MAX) md = -1;
      ans.push_back(md);
      v.clear();
    }
  for(int i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<endl;
    }
}