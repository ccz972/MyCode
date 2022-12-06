#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n,c0 = 0; // 有几个 0
		scanf("%d",&n);
		vector<int> v;
		for(int i = 1;i <= n;++i){
			int x; scanf("%d",&x);
			if(x) v.push_back(x); else ++c0;
		}
    // debug(v);
		while(v.size() > 1){
			vector<int> u; u.swap(v);
			if(c0) v.push_back(u[0]),--c0;
      debug(u);
			for(int i = 0;i + 1 < (int)u.size();++i)
				if(u[i + 1] == u[i]) ++c0;
				else v.push_back(u[i + 1] - u[i]);
			sort(v.begin(),v.end());
      debug(v);
		}
		printf("%d\n",v.size() ? v[0] : 0);

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}