#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  string ans="";
  int len = 0;
  for(int i=0;i<s.length();i++)
    {
      int j=i,k=i;
      while(j>=0 && k<s.length())
        {
          if(s[j]==s[k] && len < k-j+1)
            {
              ans = s.substr(j,k-j+1);
              len = k-j+1;
            }
            else if(s[j] != s[k]) break;
            j--;
            k++;
        }
        j=i,k=i+1;
      while(j>=0 && k<s.length())
        {
          if(s[j]==s[k] && len < k-j+1)
          {
            ans = s.substr(j,k-j+1);
            len = k-j+1;
          }
          else if(s[j] != s[k]) break;
          j--;
          k++;
        }
    }
  cout<<ans;
}