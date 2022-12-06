#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
constexpr int maxn = 1E5 + 10;
struct Suffix_Automaton{
  int len[maxn<<1],link[maxn<<1];//和说明中提到的意义相同
  int ch[maxn<<1][26];//每个结点开字符集大小的数组
  int siz,last;//siz 用来新建结点，last 同说明中的意义
  std::vector<int>v[maxn<<1];
  inline void init(){
    memset(len,0,sizeof len);
    memset(link,0,sizeof link);
    memset(ch,0,sizeof ch);
    // memset(mx,0,sizeof mx); 
    for(int i=0;i<200000;++i) v[i].clear();
    siz=last=0;//初始化不能忘
    link[0]=-1;//这一句很重要，我们要初始化 link(0) 为虚拟结点
  }
  inline void extend(const char *str){//在当前变量中建立 str 的 sam
    int n=std::strlen(str);
    for(int _=0;_<n;++_){
      int cur=++siz,p=last,c=str[_]-'a';//意义同证明中提到的
      len[cur]=len[p]+1;//初始化新结点的 len
      while(p!=-1 && !ch[p][c]){//跳 link 尝试添加边
        ch[p][c]=cur;
        p=link[p];
      }
      if(p==-1) link[cur]=0;//直接跳到了 0 （初始结点），赋值 link(cur)=0
      else{
        int q=ch[p][c];//找到了 q 为 p 的 c 出边
        if(len[q]==len[p]+1) link[cur]=q;//len(q)=len(p)+1 的情况
        else{//分裂结点的情况
          int copy=++siz;
          len[copy]=len[p]+1;
          link[copy]=link[q];
          for(int i=0;i<26;++i) ch[copy][i]=ch[q][i];//初始化分裂的结点 copy
          while(p!=-1 && ch[p][c]==q){
            ch[p][c]=copy;
            p=link[p];//重定向路径
          }
          link[q]=link[cur]=copy;//修改 q 和 cur 的 link 为 copy
        }
      }
      last=cur;//最后一步更新 last
    }
    for(int i=1;i<=siz;++i) v[link[i]].push_back(i);//建立后缀树
  }
}sam;
void solve() {
  
  string s; cin >> s;
  sam.init();
  sam.extend(s.c_str());
  // for(int i = 1; i <= 2; i ++ ) {
  //   // int x; char c; cin >> x >> c;
  //   // cout << sam.ch[]
  // }
  int p1 = sam.ch[0][1];
  int p2 = sam.ch[p1][0];
  int p3 = sam.ch[p2][0];
  
  debug(p1, p2, p3);
  debug(sam.siz);
  for(int i = 1; i <= 6; i ++ ) {
    debug(i, sam.link[i]);
  }
  // debug(sam.link[p2]);
  // cout << ;


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

