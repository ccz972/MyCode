//使用的时候注意判断如果 多个最值 取左边下标还是右边下标
//分别对应 >= >   <= <
template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    lg.resize(n + 1); lg[1] = 0; 
    for (int i = 2; i <= n; i ++ ) lg[i] = lg[i >> 1] + 1;
    int m = lg[n] + 1;
    maxv.resize(m); minv.resize(m);
    maxvid.resize(m); minvid.resize(m);
    for (int i = 0; i < m; i ++ ) maxv[i].resize(n), minv[i].resize(n),maxvid[i].resize(n), minvid[i].resize(n);
    for (int i = 0; i < n; i ++ ) maxv[0][i] = minv[0][i] = a[i], maxvid[0][i] = minvid[0][i] = i;
    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        maxv[i][j] = max(maxv[i - 1][j], maxv[i - 1][j + (1 << (i - 1))]);
        minv[i][j] = min(minv[i - 1][j], minv[i - 1][j + (1 << (i - 1))]);
        maxvid[i][j] = a[maxvid[i - 1][j]] > a[maxvid[i - 1][j + (1 << (i - 1))]] ? maxvid[i - 1][j] : maxvid[i - 1][j + (1 << (i - 1))];
        minvid[i][j] = a[minvid[i - 1][j]] < a[minvid[i - 1][j + (1 << (i - 1))]] ? minvid[i - 1][j] : minvid[i - 1][j + (1 << (i - 1))];
      }
    }

  }
  T getmax(int l,int r){
    int k = lg[r - l + 1];
    return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }    
  T getmin(int l,int r){
    int k = lg[r - l + 1];
    return min(minv[k][l], minv[k][r - (1 << k) + 1]);
  }    
  T getmaxid(int l,int r){
    int k = lg[r - l + 1];
    return a[maxvid[k][l]] > a[maxvid[k][r - (1 << k) + 1]] ? maxvid[k][l] : maxvid[k][r - (1 << k) + 1];
  }    
  T getminid(int l,int r){
    int k = lg[r - l + 1];
    return a[minvid[k][l]] < a[minvid[k][r - (1 << k) + 1]] ? minvid[k][l] : minvid[k][r - (1 << k) + 1];
  }    
private:
  int n;
  vector<T> a;
  vector<int> lg;
  vector<vector<T>> maxv, minv;
  vector<vector<T>> maxvid, minvid;
};

