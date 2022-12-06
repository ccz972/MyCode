// 叉积: A(x1, y1) X B(x2, y2) = x1 y2 - x2 y1
// 通过外积正负号，可以判定两个向量的相对位置，也就是夹角。
// 夹角的性质，可以用来解决判别凸多边形，一个点在多边形内等问题。
//例如：判别凸多边形：
//  向量每个点相连接，假如是多边形 ABCD，则得到 AB，BC，CD，DA
//  四个向量，分别判定
// AB* BC
// BC*CD
// CD*DA
// DA*AB
// 四个叉乘同不同号，如果同号，证明是凸四边形。leetcode469

class Solution {
 public:
  bool isConvex(std::vector<std::vector<int>>& points) {
    int n = points.size();
    int xa, ya, xb, yb, xc, yc;
    int prevsign = 0;
    for (int i = 0; i < n; i++) {
      xa = points[i][0];
      ya = points[i][1];
      xb = points[(i + 1) % n][0];
      yb = points[(i + 1) % n][1];
      xc = points[(i + 2) % n][0];
      yc = points[(i + 2) % n][1];
      int cur = (xc - xb) * (yb - ya) - (yc - yb) * (xb - xa);
      if (prevsign == 0) {
        prevsign = cur;
      } else {
        if (prevsign < 0 && cur > 0) return false;
        if (prevsign > 0 && cur < 0) return false;
      }
    }
    return true;
  }
};