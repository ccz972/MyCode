#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

const int N=2e5;
 
int n,a[N+10],b[N+10],pos[N+10],ptr;
int L[N+10],R[N+10];
 
int solve(int l,int r){
  if(l==r){
    if(pos[a[++ptr]]!=l){
      puts("-1");
      exit(0);
    }
    return a[ptr];
  }
  int rt=a[++ ptr],p=pos[rt];
  if(l<=p-1)L[rt]=solve(l,p-1);
  if(p+1<=r)R[rt]=solve(p+1,r);
  return rt;
}
 
void solve(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",a+i);
  for(int i=1;i<=n;i++)
    scanf("%d",b+i),pos[b[i]]=i;
  if(a[1]!=1)return puts("-1"),void();
  solve(1,n);
  // for(int i = 1; i <= n; i ++ ) {
  	// cout << pos[a[i]] << " ";
  // }
  for(int i=1;i<=n;i++)
    printf("%d %d\n",L[i],R[i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	solve();
  return 0;
}
/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
