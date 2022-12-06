// https://ac.nowcoder.com/acm/contest/41745/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, L = 20;

int n, m, p, rk[N], oldrk[N << 1], cnt[N], id[N], sa[N], f[N][L];
int Log[N], height[N];
int s[N], ans[N];

/** 一些约定
*  下标从 1 开始，长度为 n
*  后缀 i 表示以第 i 个字符 开头的后缀，存储时用 i 表示字符串 s 的后缀 s[i...n]
*  sa[i] 表示将所有后缀排序后第 i 小的后缀的编号，也是所说的后缀数组，后文也称编号数组 sa
*  rk[i] 表示 后缀 i 的排名，也是重要的辅助数组，后文也称排名数组 rk 
*  这两个数组满足性质： sa[rk[i]] = rk[sa[i]] = i
*/

/**
* height[i] = lcp(sa[i], sa[i - 1]) 即第i名的后缀与它前一名的后缀的最长公共前缀 
* height[1] 可视为 0
*/

/**
* 引理: height[rk[i]] >= height[rk[i - 1]] - 1 
* lcp(sa[i], sa[j]) = min{height[i + 1, .. j]}
* 有了这个定理，求两子串最长公共前缀就转化为了 RMQ 问题。 
*/

/**
* 假设需要比较 A = S[a...b],和 B = S[c...d] 的大小关系 
* 若lcp(a,c) >= min(|A|, |B|), A < B  <==> |A| < |B|
* 否则: A < B <==> rk[a] < rk[c]
*/

/** 不同子串的数目
*  子串就是后缀的前缀，所以可以枚举每个后缀，计算前缀总数，再减掉重复。
* “前缀总数” 其实就是子串个数，为 n * (n + 1) / 2 。
* 如果按后缀排序的顺序枚举后缀，每次新增的子串就是除了与上一个后缀的 LCP 剩下的前缀。
* 这些前缀一定是新增的，否则会破坏 lcp(sa[i], sa[j]) = min{height[i + 1, .. j]} 的性质
* 只有这些前缀是新增的，因为 LCP 部分在枚举上一个前缀时计算过了。
* 因此答案为： n * (n + 1) / 2 - \sum_{i=2}^{n} height[i]
*/

/** 出现至少 k 次的子串的最大长度
*  出现至少 k 次意味着后缀排序后有至少连续  个后缀以这个子串作为公共前缀。
*  所以，求出每相邻 k-1 个 height 的最小值，再求这些最小值的最大值就是答案。
*  可以使用单调队列 O(n)  解决，但使用其它方式 (multiset<int> ) 也足以 AC。 
* 
*/

/** 是否有某字符串在文本串中至少不重叠地出现了两次
*  可以二分目标串的长度 |s| ，将 h 数组划分成若干个连续 LCP 大于等于 |s|  的段
*  利用 RMQ 对每个段求其中出现的数中最大和最小的下标，若这两个下标的距离满足条件
*  则一定有长度为 |s| 的字符串不重叠地出现了两次。
*/

bool inline cmp(int i, int j, int k) {
  return oldrk[i] == oldrk[j] && oldrk[i + k] == oldrk[j + k];
}

void inline SA() {
  m = 1E5 + 5; // 字符集大小
  for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n; i++) sa[cnt[rk[i]]--] = i;
  for (int w = 1; w < n; w <<= 1, m = p) {
  p = 0;
  for (int i = 1; i <= n; i++)
    if (sa[i] > w) id[++p] = sa[i] - w;
  for (int i = n; i > n - w; i--) id[++p] = i;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) cnt[rk[i]]++, oldrk[i] = rk[i];
  for (int i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i; i--) sa[cnt[rk[id[i]]]--] = id[i];
  p = 0;
  for (int i = 1; i <= n; i++)
    rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  if (p == n) break;
  }
  for (int i = 1; i <= n; i++) {
    int j = sa[rk[i] - 1], k = max(0, height[rk[i - 1]] - 1);
    while (s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++ ) scanf("%d", s + i);
  reverse(s + 1, s + 1 + n);
  s[++ n] = 1E5 + 1;
  SA(); 
  int p = n, idx = 1;
  
  for (int i = n - 1; i >= 1; i -- ) {
    if (sa[i] < p) {
      debug(sa[i], p);
      for (int j = sa[i]; j < p; j ++ ) ans[idx ++ ] = s[j];
      p = sa[i];
    }
  }

  for (int i = 1; i < idx; i ++ ) cout << ans[i] << " ";
  cout << "\n";

}
int main() {
  solve();
  return 0;
}

/*

#include<bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define lowbit(x) ((x)&-(x))
#define SZ(x) (int)x.size()
using namespace std;
using ll=long long;
using ld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<ld,ld>;
const int INF=0x3f3f3f3f,N=1e5+10;
struct SA{
    int sa[N],rk[N],c[N],height[N],x[N],y[N];
    //int mi[N][M];
    int n,m;
    int s[N];//字符不要从0开始
    //sa:排名对应编号
    //rk:编号对应排名
    //c:桶
    //height:排名为i的后缀与它前一名的lcp
    //x:编号对应排名
    //y:排名对应编号
    void init(){//最多只会越界1个位置
        x[n+1]=y[n+1]=0;
    }
    void sort(){//x为第一关键字,y为第二关键字排序
        for(int i=1;i<=m;i++) c[i]=0;
        for(int i=1;i<=n;i++) c[x[i]]++;
        for(int i=1;i<=m;i++) c[i]+=c[i-1];
        for(int i=n;i;i--) sa[c[x[y[i]]]--]=y[i];
    }
    bool check(int i,int k){//这里可能会越界,因此多测要清空x和y数组
        return y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k];
    }
    void get_sa(){
        for(int i=1;i<=n;i++) x[i]=s[i],y[i]=i;
        sort();
        for(int k=1,num=0;num<n;k<<=1,m=num){
            num=0;
            //2k长度的第二关键字排序
            for(int i=1;i<=k;i++) y[++num]=n-k+i;
            for(int i=1;i<=n;i++)
                if(sa[i]>k)
                    y[++num]=sa[i]-k;
            //上一轮的x就是这一轮的第一关键字
            sort();
            swap(x,y);
            //后面的x是2k长度的排序
            x[sa[1]]=num=1;
            for(int i=2;i<=n;i++) x[sa[i]]=check(i,k)?num:++num;
        }
    }
    void get_height(){
        for(int i=1;i<=n;i++) rk[sa[i]]=i;
        //设h[i]为height[rk[i]],即编号为i的后缀与它前一名的lcp,h[i]>=h[i-1]-1;
        for(int i=1,k=0;i<=n;i++){
            if(rk[i]==1) continue;
            if(k) k--;
            int j=sa[rk[i]-1];
            while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
            height[rk[i]]=k;
        }
    }
    //void buildST(){
    //  for(int i=1;i<=n;i++) mi[i][0]=height[i];
    //  for(int i=1;i<16;i++)
    //      for(int j=1;j+(1<<i)-1<=n;j++)
    //          mi[j][i]=min(mi[j][i-1],mi[j+(1<<i-1)][i-1]);
    //}
    //int query(int l,int r){//查询l开头的后缀和r开头的后缀的lcp
    //  int a=rk[l],b=rk[r];
    //  l=min(a,b)+1;
    //  r=max(a,b);
    //  int len=log_2[r-l+1];
    //  return min(mi[l][len],mi[r-(1<<len)+1][len]);
    //}
}sa;
int s[N],n;
void solve(){
    cin>>n;
    sa.n=n;
    for(int i=1;i<=n;i++) cin>>s[i],sa.s[n-i+1]=s[i];
    sa.s[++sa.n]=1e5+10;
    sa.m=1e5+10;
    sa.get_sa();
    int ale=n+1;
    for(int i=sa.n;i;i--){
        if(sa.sa[i]>=ale) continue;
        reverse(s+n+2-ale,s+n+2-sa.sa[i]);
        ale=sa.sa[i];
    }
    for(int i=1;i<=n;i++) cout<<s[i]<<" \n"[i==n];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

*/

