存图方式
1. 邻接表去存图

假设有n个点,然后我们要存每个点的所有出边的话

链表的思想:
首先我们如果需要存1号点的所有出边的话

int h[N], e[N], ne[N], idx;
h[i] 代表以i为起点的所有边的终点的链表的表头
e[idx] 可以访问 idx 这个节点编号所代表的那个节点的值是谁？
ne[idx] 可以访问 idx 这个节点编号的 next 所代表的那个节点编号是谁？

void add(int a, int b) {
  //  a->b  
  // idx
  e[idx] = b;
  ne[idx] = h[a]; //a这个点的的第一个出边的 编号
  h[a] = idx;
  idx ++;
  // h->x1->NULL
  //h->x2->x1->NULL
  // ne[idx] = idx(x1) (h[a])
}


//如果我们要存这条边的边权的话，那么我们要多存储的每条边的信息就是边的权值
w[idx] 表示idx这个编号所代表的这条边的权重


//如果我们需要加入双向边 a->b
//add(a, b)
//add(b, a)


int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;

h->next = NULL;
memset(h, -1, sizeof h);

//访问 a 的所有出边


//next 是个关键字，一般不作为变量名使用！

for(int i = h[a]; i != -1; i = ne[i]) {
  // i 遍历的就是a的所有出边的编号
  int j = e[i]; //表示一条 a -> j 的有向边
  int W = w[i]; //表示一条 a -> j 的有向边 的权重是 W
  // h->x2->x1->NULL
}

void add(int a, int b, int c) {
  //加入一条起点为a，终点为b 并且权重为c 的一条边
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx;
  idx ++;
  // h[a] = idx;
}



将 x1 加入链表中
x1->next = h->next
h->next = x1


//1->x
h->next = NULL



1->2->next

5->3

3->4

将 x2 加入链表中


h->x2->x1->NULL

x2->next = h->next
h->next = x2


int h;
h->next = x1;
x1->next = x2;
x2->next = x3;
x_end = NULL;


2. 用vector去存图

const int N = 1e5 + 10;

vector<int> son[N];

a->b 的有向边

son[a].push_back(b)

a->b 的双向边

son[a].push_back(b);
son[b].push_back(a);

//遍历a的所有出边
for(int i = 0; i < son[a].size(); i ++ ) {
  int j = son[a][i];
  //表示有一条边从 a->j 
}


// 如何存边的权重呢 ？  

vector<pair<int, int> > son[N];

a->b的有向边，权重为c

son[a].push_back(make_pair(b, c));

a->b的双向边，权重为c

son[a].push_back(make_pair(b, c));
son[b].push_back(make_pair(a, c));

//遍历a的所有出边
for(int i = 0; i < son[a].size(); i ++ ) {
  int b = son[a][i].first;
  int c = son[a][i].second; 
}
//C++ 11  以上的版本

//无权重
for(auto x: son[a]) {
  // x 表示a->x的一条有向边
}

//有权重
for(auto x: son[a]) {
  int b = x.first;
  int c = x.second;
  //jaskldjjaslkd
}




    确定一个起点，求其他的点到起点的最短距离

假设 1 号点是起点的话，那么 集合 S 就代表 最短距离已经确定过的 点的集合

memset(dist, 0x3f, sizeof dist)
memset(st, false, sizeof st)

st[i] = true; // 代表 i 这个点在集合 S 之中
for i = 0; i < n; i ++ :

  // t ： 找到一个没有用过的点，并且到起点的距离最小的一个点
  int t = 0; //st[t] = false;

  for(int j = 1; j <= n; j ++ ) {
    if(st[j] == false && (t == 0 || dist[j] < dist[t]) ) {
      t = j;
    }
  }

  st[t] = true;  // t 放入集合S中
  
  //1 -> x  dist[x]  1->t->x

  for j = 1; j <= n; j ++  : 
    if(dist[j] > dist[t] + g[t][j])  // g[t][j] 代表 一条 t -> j 的有向边，并且长度是 g[t][j] 的值
      dist[j] = dist[t] + g[t][j];



-----

堆优化版 迪杰斯特拉

// struct {
//   bool operator <
// }

#define PII pair<int, int> 

priority_queue<PII, vector<PII>, greater<PII> > q;
//.first 存的是距离， .second 存的是 编号

q.push(make_pair(0, 1));
while(!q.empty()) {
  PII t = q.top();    q.pop();

  int ver = t.second;

  if(st[ver]) continue;

  st[ver] = true;
  
  //邻接表存图

  for(int i = h[ver]; i != -1; i = ne[i]) {
    int j = e[i]; 
    int W = w[i];
    if(dist[j] > dist[ver] + W) {
      dist[j] = dist[ver] + W;
      q.push(make_pair(dist[j], j));
    }
  }


  //vertor 存图
  for(int i = 0; i < son[ver].size(); i ++ ) {
    int j = son[ver][i].first;
    int W = son[ver][i].second;
    if(dist[j] > dist[ver] + W) {
      dist[j] = dist[ver] + W;
      q.push(make_pair(dist[j], j));
    }
  }
  //C++ 11 |>
  for(auto x: son[ver]) {
    int j = x.first;
    int W = x.second;
    if(dist[j] > dist[ver] + W) {
      dist[j] = dist[ver] + W;
      q.push(make_pair(dist[j], j));
    }
  }

}



