#include<bits/stdc++.h>
using namespace std;


const int NN = 2e5 + 7 , MM = 2e6 + 7;
struct edge{
	int ed , up , f;
}Ed[MM];
int head[NN] , cur[NN] , dep[NN] , N , M , S , T , cntEd = 1;
queue < int > q;

 void merge_edge(int a , int b , int c){
	Ed[++cntEd].ed = b;
	Ed[cntEd].up = head[a];
	Ed[cntEd].f = c;
	head[a] = cntEd;
}

void add_edge_qwq(int a , int b , int c){merge_edge(a , b , c); merge_edge(b , a , 0);}

bool bfs();

 int dfs(int x , int mF){
	if(x == T)
		return mF;
	int sum = 0;
	for(int &i = cur[x] ; i ; i = Ed[i].up)
		if(Ed[i].f && dep[Ed[i].ed] == dep[x] + 1){
			int t = dfs(Ed[i].ed , min(mF - sum , Ed[i].f));
			if(t){
				Ed[i].f -= t;
				Ed[i ^ 1].f += t;
				sum += t;
				if(sum == mF)
					break;
			}
		}
	return sum;
}

char str[203][203];

#define id(i,j) (((i) - 1) * M + (j))
/*
5
PNNPN
PNPPP
NPPPP
PNNNP
PNNNP

5
P..P.
P.PPP
.PPPP
P...P
P...P

*/
void solve();

int main(){
	solve();
  return 0;
}


void solve() {
  cin >> N; M = N; 
  for(int i = 1 ; i <= N ; ++ i ) 
    for(int j = 1 ; j <= M ; ++ j ) 
      cin >> str[i][j];

	int cnt = N * M , num = 0 , qwq = 0; T = 4 * N * M + 1;

	for(int i = 1 ; i <= N ; i ++ )
		for(int j = 1 ; j <= M ; j ++ ){
			num += str[i][j] == 'P';
			if(str[i][j] == 'P' && str[i][j + 1] == 'P'){
				++qwq; ++cnt; 
        add_edge_qwq(S , cnt , 1); 
        add_edge_qwq(cnt , id(i , j) , 1); 
        add_edge_qwq(cnt , id(i , j + 1) , 1);
			}
			if(str[i][j] == 'P' && str[i + 1][j] == 'P'){
				++qwq; ++cnt; 
        add_edge_qwq(cnt , T , 1); 
        add_edge_qwq(id(i , j) , cnt , 1); 
        add_edge_qwq(id(i + 1 , j) , cnt , 1);
			}
		}

	while(bfs()) qwq -= dfs(S , 1E9);

	cout << num - qwq << "\n"; 

}

bool bfs() {
  while(!q.empty())
    q.pop();
  q.push(S);
  memset(dep , 0 , sizeof(int) * (T + 1));
  dep[S] = 1;
  while(!q.empty()){
    int t = q.front();
    q.pop();
    for(int i = head[t] ; i ; i = Ed[i].up)
      if(Ed[i].f && !dep[Ed[i].ed]){
        dep[Ed[i].ed] = dep[t] + 1;
        if(Ed[i].ed == T){
          memcpy(cur , head , sizeof(head));
          return 1;
        }
        q.push(Ed[i].ed);
      }
  }
  return 0;
}
