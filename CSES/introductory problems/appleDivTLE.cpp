#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
    {
      int a,b;
      cin>>a>>b;
      while(a && b)
        {
          if(a>b)
          {
            a-=2;
            b--;
          }
          else{
            a--;
            b-=2;
          }
        }
      if(a==0 && b==0) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
}