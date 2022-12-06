constexpr int N = 1E5 + 10;
int a[N], h[N];
int lowbit(int x) { return x & (-x); }
void update(int x) {
  int lx = x;
  while (x < N) h[x] = max(h[x], a[lx]), x += lowbit(x);
}
int query(int x, int y) {
  int ans = 0;
  while (y >= x) {
    ans = max(a[y], ans), y--;
    for (; y - lowbit(y) >= x; y -= lowbit(y)) ans = max(h[y], ans);
  }
  return ans;
}
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums, int k) {
    memset(h, 0, sizeof h), memset(a, 0, sizeof a);
    for (auto& v : nums)
      a[v] = max(a[v], query(max(1, v - k), v - 1) + 1), update(v);
    return query(1, N - 1);
  }
};