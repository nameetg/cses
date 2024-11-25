#include<bits/stdc++.h>
using namespace std;
int n,m,x=-1,y=-1;
string ans="";
bool isValid(int i, int j, vector<vector<char>> &g, vector<vector<int>> &v)
{
  if(i<0 || i>=n || j<0 || j>=m) return false;
  if(g[i][j]=='#' || v[i][j]) return false;
  return true;
}
bool bfs(vector<vector<char>> &g, vector<vector<int>> &v, vector<vector<char>> &p)
{
  queue<pair<int,int>> q;
  q.push({x,y});
  while(!q.empty())
    {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      v[i][j]=1;
      if(g[i][j]=='B')
      {
        while(1)
          {
            ans = p[i][j] + ans;
            if(ans[0] == 'L') j++;
            if(ans[0] == 'R') j--;
            if(ans[0] == 'U') i++;
            if(ans[0] == 'D') i--;

            if(i==x && j==y) break;
          }
        return true;
      }
      if(isValid(i,j-1,g,v)) 
      {
        p[i][j-1]='L';
        q.push({i,j-1});
      }
      if(isValid(i,j+1,g,v))
      {
        p[i][j+1] = 'R';
        q.push({i,j+1});
      }
      if(isValid(i-1,j,g,v))
      {
        p[i-1][j]='U';
        q.push({i-1,j});
      }
      if(isValid(i+1,j,g,v))
      {
        p[i+1][j]='D';
        q.push({i+1,j});
      }
    }
  return false;
}
int main()
{
  cin>>n>>m;
  vector<vector<char>> g(n,vector<char>(m));
  vector<vector<int>> v(n,vector<int>(m,0));
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        {
          cin>>g[i][j];
          if(g[i][j]=='A') x=i,y=j;
        }
    }
  vector<vector<char>> p(n,vector<char>(m));
  if(bfs(g,v,p)) 
  {
    cout<<"YES"<<endl;
    cout<<ans.length()<<endl;
    cout<<ans<<endl;
  }
  else cout<<"NO"<<endl;
}