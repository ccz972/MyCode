#include <cstdio>
// #include "testlib.h"
#include <testlib.h>
#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++ )

//下面是生成一棵树的主要代码，它接受两个参数——顶点数和伸展度
//例如，当 n = 10, t = 1000 时，可能会生成链；
//     当 n = 10, t = -1000 时，可能会生成菊花。
int main(int argc, char* argv[]) {

  //freopen("in.txt", "w", stdout);

  registerGen(argc, argv, 1);

  // int n = atoi(argv[1]);
  // int t = atoi(argv[2]);
  int n, t;
  scanf("%d%d", &n, &t);
  // int n = 10, t = 1000;
  vector<int> p(n);

  /* 为节点 1..n-1 设置父亲 */
  forn(i, n) if (i > 0) p[i] = rnd.wnext(i, t);

  printf("%d\n", n);

  /* 打乱节点 1..n-1 */
  vector<int> perm(n);
  forn(i, n) perm[i] = i;
  shuffle(perm.begin() + 1, perm.end());

  /* 根据打乱的节点顺序加边 */
  vector<pair<int, int> > edges;
  for (int i = 1; i < n; i++)
    if (rnd.next(2))
      edges.push_back(make_pair(perm[i], perm[p[i]]));
    else
      edges.push_back(make_pair(perm[p[i]], perm[i]));

  /* 打乱边 */
  shuffle(edges.begin(), edges.end());

  for (int i = 0; i + 1 < n; i++)
    printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);

  return 0;
}

