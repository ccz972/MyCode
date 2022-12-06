#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define PII pair<int, int>
#define debug(x) cout << #x << " > " << x << "\n"
#define all(a) a.begin(), a.end()

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

int cnt1,cnt2,sum;
string s;
vector<string> ans;
int n;

void dfs()
{
  if(cnt2>(n+2)/2) return ;
  if(cnt1>(n+1)/2) return ;
  for(int i=0;i<=1;i++)
  {
    sum += i;
    if(sum&1) cnt1++;
    else cnt2++;
    s.push_back(i?'r':'b');
    if(cnt2==(n + 2)/2)
    {
      string tmp = s;tmp.push_back('r');
      for(int j=tmp.size();j<n;j++) tmp.push_back('b');
      ans.push_back(tmp);
      if(sum&1) cnt1--;
      else cnt2--;
      sum -= i;
      s.pop_back(); 
      continue;
    }
    if(cnt1==(n+1)/2)
    {
      string tmp = s;
      for(int i=s.size();i<n;i++) tmp.push_back('b');
      ans.push_back(tmp);
      if(sum&1) cnt1--;
      else cnt2--;
      sum -= i;
      s.pop_back();
      continue;
    }
    dfs();
    if(sum&1) cnt1--;
    else cnt2--;
    sum -= i;
    s.pop_back();
  }
}

void solve() {
  cin>>n;
  cnt2 = 1;
  dfs();
  cout<<1ll*((n+1)/2)*((n+2)/2)<<'\n';
  for(auto x:ans) cout<<x<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}