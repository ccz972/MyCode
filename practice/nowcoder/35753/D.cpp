// Problem: 弗林戒指
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/35753/D
// Memory Limit: 262144 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

void solve() {
  int n, m, H; cin >> n >> m >> H;
  //最多装备n个武器，有m个武器选择
  //H为boss血量 
  //求最短的t杀死boss
  //无论如何杀不死就输出 YOU DIED
  vector<array<int, 3> > a(m);
  //重量之和不超过100
  //伤害为a[1]
  //t为a[2]
  int l = 1, r = 1;
  for(int i = 0; i < m; i ++ ) {
  	cin >> a[i][0] >> a[i][1] >> a[i][2];
  	chkmax(r, a[i][2]);
  }
  
  auto chk = [&] (int x) {
  	vector<int> f(101);
  	for(int i = 0; i < m; i ++ ) {
  		if(a[i][2] > x) continue;
  		for(int j = 100; j >= a[i][0]; j -- ) {
  			chkmax(f[j], f[j - a[i][0]] + a[i][1]);
  		}
  	}
  	//只需要对小于28的选择进行重新计算即可 女少口阿
  	for(int i = 1; i <= 28; i ++ ) {
  		f[i] = floor(1.15 * f[i]);z
  	}
  	int mx = *max_element(f.begin(), f.end());
  	return mx >= H;
  	
  };
  
  while(l < r) {
  	int mid = (l + r) / 2;
  	if(chk(mid)) r = mid;
  	else l = mid + 1;
  }
  
  if(chk(l)) cout << l << "\n";
  else cout << "YOU DIED\n";
  
  
  
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
