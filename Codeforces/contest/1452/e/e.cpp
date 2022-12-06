#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>   // 用tree
#include<ext/pb_ds/hash_policy.hpp>   // 用hash
#include<ext/pb_ds/trie_policy.hpp>   // 用trie
#include<ext/pb_ds/priority_queue.hpp>// 用priority_queue

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

using TREE = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;
//从0开始，自动去重
#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  TREE tr;
  tr.insert(1);
  tr.insert(2);
  tr.insert(3);
  tr.insert(4);
  cout << tr.size() << "\n";
  auto idx = tr.find(-1);
  if(idx == tr.end()) {
    cout << "FUCK\n";
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
