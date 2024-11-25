#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,vector<int>> g;
unordered_map<int,int> pv;
stack<int> st;
bool dfs(int nd)
{
  pv[nd]=2;
  st.push(nd);
  for(int i=0;i<g[nd].size();i++)
    {
      if(!pv[g[nd][i]])
      {
        if(dfs(g[nd][i])) return true;
      }
      else if(pv[g[nd][i]]==2)
      {
        st.push(g[nd][i]);
        return true;
      }
    }
  st.pop();
  pv[nd]=1;
  return false;
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
    }
  bool flag = false;
  for(int i=1;i<=n;i++)
    {
      if(!pv[i])
      {
        if(dfs(i))
        {
          flag = true;
          break;
        }
      }
    }
  if(flag)
  {
    vector<int> ans;
    int t = st.top();
    ans.push_back(t);
    st.pop();
    while(st.top()!=t)
      {
        ans.push_back(st.top());
        st.pop();
      }
    ans.push_back(st.top());
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      {
        cout<<ans[i]<<" ";
      }
    cout<<endl;
  }
  else cout<<"IMPOSSIBLE"<<endl;
}