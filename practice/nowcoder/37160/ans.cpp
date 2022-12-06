#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std ;

using ll = long long ;
using pii = pair<int,int> ;

const int N = 2e6 + 100 ;

int n,m ;
int a[N],b[N] ;

int RTO(int a,int x){  // 计算左边R到达最近时间
	if(!a) return n ;
	if(a <= x) return x - a ;
	return n - (a - x) ;
}

int LTO(int b,int x){  // 计算右边的L到达最近时间
	if(!b) return n ;
	if(b >= x) return b - x ;
	return n - (x - b) ;
}

int calc(int a,int b,int x){
	return min(RTO(a,x),LTO(b,x)) ;
}

int main(){
	scanf("%d%d",&n,&m) ;
	for(int i = 1 ; i <= m ; i ++){
		char op ;
		int x ;
		scanf("%d %c",&x,&op) ;

		if(op == 'L') b[x] = x ;
		else a[x] = x ;
	}

	// a 记录这个位置最近的的前一个R是那个位置，包含本身，包括环形
	for(int i = 1 ; i <= n ; i ++)
		a[i] = max(a[i-1],a[i]) ;
	for(int i = 1 ; i <= n ; i ++)  // 处理环形
		if(!a[i]) a[i] = a[n] ;

	// b 记录这个位置的后面第一个L是那个位置，包括环形
	for(int i = n ; i >= 1 ; i --)
		if(!b[i]) b[i] =  b[i + 1] ;
	for(int i = n ; i >= 1 ; i --)
		if(!b[i]) b[i] = b[1] ;

	int ans = 0 ;
	for(int i = 1 ; i <= n ; i ++)  // 对于每个位置来说
		ans = max(ans,calc(a[i],b[i],i)) ;  // 计算出R到达和L到达的最近
	printf("%d\n",ans) ;
	return 0 ;
}