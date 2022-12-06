// // Problem: J. IHI's Magic String
// // Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// // URL: https://codeforces.com/gym/103736/problem/J
// // Memory Limit: 256 MB
// // Time Limit: 1000 ms
// // 
// // Powered by CP Editor (https://cpeditor.org)
// 
// #include  <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// 
// #define rep(i, a, b) for(int i(a); i <= b; i ++)
// #define dec(i, a, b) for(int i(a); i >= b; i --)
// 
// #ifdef LOCAL
// #include <debugger>
// #else
// #define debug(...) 42
// #endif
// 
// 
// template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
// template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }
// 
// void solve() {
	// int q; cin >> q;
	// string s; 
	// vector<int> f(26), g(26);
// 	
	// for(int i = 0; i < 26; i ++ ) {
		// f[i] = g[i] = i;
	// } 
// 	
	// //f[x] 表示 x 这个字符对应的下标是多少
// 	
	// //g[x] 表示 x 下标对应的字符是多少
// 	
	// //son[x] 表示 x 这个下标在原字符串对应的位置都有谁
	// vector<vector<int> > son(26);
	// int n = 0;
	// auto merge = [&] (int x, int y) {
		// // for(int i: son[x]) {
			// // s[i] = (char)('a' + g[x]);
		// // }
		// for(int i: son[x]) {
			// if(i < n)
				// son[y].push_back(i);
		// }
		// if(son[x].size())
			// son[x].clear();
	// };
// 	
	// while(q -- ) {
		// int op; cin >> op;
		// if(op == 1) {
			// char c; cin >> c;
			// s.push_back(c); ++ n;
			// son[f[c - 'a']].push_back(n - 1);
		// } else if(op == 2) {
			// if(n) {
				// s.pop_back();
				// -- n;
			// }
// 				
		// } else {
			// char cx, cy; cin >> cx >> cy;
			// int x = cx - 'a', y = cy - 'a';
// 			
			// if((int)son[x].size() > (int)son[y].size()) {
				// g[f[y]] = x;
				// g[f[x]] = y;
				// swap(f[x], f[y]);
				// //1 -> 2   3 -> 1
				// //1 -> 1   3 -> 2
				// // swap(g[x], g[y]);
				// //2 -> 1  1 -> 3
				// //
				// //x -> f[x]  y -> f[y]
				// //x -> f[y]  y -> f[x] 
// 				
			// }
			// if(son[y].empty() || s on[x].empty()) {
				// continue;
			// }
			// merge(f[x], f[y]);
// 			
// 			
// 			
		// }
	// }
// 	
	// if(s.empty()) {
		// cout << "The final string is empty";
		// return ;
	// }
	// vector<int> vis(26);
	// for(int i = 0; i < 26; i ++ ) {
		// assert(f[g[i]] == i);
	// }
// 	
	// for(int i = 0; i < 26; i ++ ) { 
		// for(int j: son[i]) {
			// if(j < n)
			// s[j] = (char)('a' + g[i]);
		// }
	// }
	// cout << s; 
// 	
// }
// 
// int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // solve();
// 
	// // }
  // return 0;
// }
// /*
 // *
 // *　　┏┓　　　┏┓+ +
 // *　┏┛┻━━━┛┻┓ + +
 // *　┃　　　　　　　┃
 // *　┃　　　━　　　┃ ++ + + +
 // *  ████━████+
 // *  ◥██◤　◥██◤ +
 // *　┃　　　┻　　　┃
 // *　┃　　　　　　　┃ + +
 // *　┗━┓　　　┏━┛
 // *　　　┃　　　┃ + + + +Code is far away from 　
 // *　　　┃　　　┃ + bug with the animal protecting
 // *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 // *　　　┃ 　　　　　　 ┣┓
 // *　　  ┃ 　　　　　 　┏┛
 // *　    ┗┓┓┏━┳┓┏┛ + + + +
 // *　　　　┃┫┫　┃┫┫
 // *　　　　┗┻┛　┗┻┛+ + + +
 // */
//  


// Problem: I. IHI's Homework
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

constexpr int N = 1e5 + 10000;
char s[N];
struct node {
	int op; 
	char x, y;
}a[N];

void solve() {
	int q; cin >> q;
	string s;
	for(int i = 0; i < q; i ++ ) {
		int op; cin >> op;
		a[i].op = op;
		if(op == 1) {
			cin >> a[i].x;
			s.push_back(a[i].x);
		} 
		if(op == 3) {
			cin >> a[i].x >> a[i].y;
		}
	}
	vector<int> now(30);
	iota(now.begin(), now.end(), 0);
	for(int i = q - 1; i >= 0; i -- ) {
		if(a[i].op == 1) {
			a[i].x = 'a' + now[a[i].x - 'a'];
			
		} else if(a[i].op == 2) {
			continue;
		} else {
			now[a[i].x -'a'] = now[a[i].y - 'a'];
		}
	}
	string ans;
	for(int i = 0; i < q; i ++ ) {
		if(a[i].op == 1) {
			ans.push_back(a[i].x);
		} else if(a[i].op == 2) {
			if(ans.size()) {
				ans.pop_back();
			}
		} else {
			continue;
		}
	} 
	if(ans.size()) {
		cout << ans;
	} else {
		cout << "The final string is empty";
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T --) solve();

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
