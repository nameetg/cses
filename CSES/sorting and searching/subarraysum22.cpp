#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> twoSum(vector<int> v, int x)
{
  unordered_map<int, int> m;
  for(int i=0;i<v.size();i++)
    {
      m[v[i]] = i;
    }
    sort(v.begin(), v.end());
  vector<int> ans;
  int i=0, j=v.size()-1;
  while(i < j)
    {
      long long sum = v[i]+v[j];
      if(sum < x) i++;
      else if(sum > x) j--;
      else 
      {
        ans.push_back(m[v[i]]);
        ans.push_back(m[v[j]]);
        break;
      }
    }
  sort(ans.begin(), ans.end());
  return ans;
}
int main()
{
  int n;
  int x;
  cin>>n;
  cin>>x;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    {
      int temp;
      cin>>temp;
      v[i] = temp;
    }

  vector<int> ans = twoSum(v,x);
  if(ans.size()==0) cout<<"IMPOSSIBLE";
  else
  {
    for(int i=0;i<ans.size();i++)
      {
        cout<<ans[i]+1<<" ";
      }
  }
}