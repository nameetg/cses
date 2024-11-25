#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> src, desti;
string s="";
map<pair<int,int>,pair<int,int>> pt;
int shortestPath(vector<vector<char>> &g)
{
  if(src == desti) return 0;
  vector<vector<long long>> d(n,vector<long long>(m,LLONG_MAX));
  d[src.first][src.second]=0;
  queue<pair<int,pair<int,int>>> q;
  q.push({0,src});
  pt[src]= src;
  vector<int> dx = {-1,0,1,0};
  vector<int> dy = {0,1,0,-1};
  while(!q.empty())
    {
      auto it = q.front();
      q.pop();
      int dist = it.first;
      int x = it.second.first;
      int y = it.second.second;
      for(int i=0;i<4;i++)
        {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]=='.' && dist + 1 < d[nx][ny])
          {
            d[nx][ny] = dist+1;
            pt[{nx,ny}] = {x,y};
            if(nx == desti.first && ny == desti.second) return dist+1;
            q.push({dist+1,{nx,ny}});
          }
        }
    }
  return -1;
}
int main()
{
  cin>>n>>m;
  vector<vector<char>> g(n, vector<char>(m));
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        {
          cin>>g[i][j];
          if(g[i][j]=='A') {
            src = {i,j};
            g[i][j]='.';
          }
          if(g[i][j]=='B') {
            desti = {i,j};
            g[i][j]='.';
          }
        }
    }
  int minDis = shortestPath(g);
  if(minDis==-1) cout<<"NO"<<endl;
  else 
  {
    pair<int,int> nd = desti;
    while(pt[nd]!=nd)
      {
        int x = pt[nd].first;
        int y = pt[nd].second;
        if(x<nd.first) s='D'+s;
        if(x>nd.first) s='U'+s;
        if(y<nd.second) s='R'+s;
        if(y>nd.second) s='L'+s;
        nd = pt[nd];
      }
    cout<<"YES"<<endl;
    cout<<minDis<<endl;
    cout<<s<<endl;
  }
  
}