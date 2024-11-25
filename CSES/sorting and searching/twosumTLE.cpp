#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> twoSum(vector<ll> &numbers, ll target)
{
	unordered_map<ll, ll> hash;
	ll n = numbers.size();
	vector<ll> result;
	for (ll i = 0; i <n; i++) {
		ll numberToFind = target - numbers[i];
		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);
			return result;
		}
		hash[numbers[i]] = i;
	}
	return result;
}
int main()
{
  ll n,x;
  cin>>n>>x;
  vector<ll> v(n);
  for(int i=0;i<n;i++)
    {
      ll num;
      cin>>num;
      v[i] = num;
    }
    vector<ll> ans = twoSum(v,x);
    cout<<v[0]<<" "<<v[1];
}
