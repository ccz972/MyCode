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

struct Linear
{
  ll a,b,c,d;
  ll x0,y0;
  ll x1,y1;
  ll x2,y2;
  ll cnt = 0;
  Linear(ll _a,ll _b,ll _c): a(_a),b(_b),c(_c){};
  ll exgcd(ll a,ll b,ll &x,ll &y)
  {
    if(!b) 
    {
      x = 1,y = 0;
      return a;
    }
    ll d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
  }  
  
  int get()
  {
    ll x,y,k;
    d = exgcd(a,b,x,y);
    if(c%d!=0) return -1;
    x *= c/d,y *= c/d;
    a/=d,b/=d;
    x0 = (x%b + b)%b,y0 = (y%a + a)%a;
    if(x<0) k = ceil((1.0-x)/b),x += b&k,y -= a*k;
    else k = (x-1)/b,x -= b * k,y += a * k;
    int t = 0;
    if(y>0)
    {
      cnt = (y-1)/a + 1;
      x1 = x,y1 = (y-1)%a + 1;
      x2 = x + (y-1)/a*b,y2 = y;
      t = 1;
    }
    return t;
  }
};

void solve() {
  ll h,m,a;cin>>h>>m>>a;
  Linear t1(h-1,-m,a),t2(m,1-h,a);
  t1.get(),t2.get();
  // cout<<t1.x1<<" "<<t1.y1<<'\n';
  ll l1 = a/m + 1,l2 = a/(h-1) + 1;
  // cout<<l1<<" "<<l2<<'\n';
  cout<<t1.cnt*l1 + t2.cnt*l2<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}