#include<cstdio> 
#include<cmath> 
#include <algorithm> 
using namespace std; 
const int INF=0x3f3f3f3f; 
const int N=10000; 
 
int L, l, maxl, minl, ans, pcnt, w, t; 
struct node{ int x, y, l; }p[N<<1]; 
bool Can( int i, int j ) { 
    if( t*t==w && t<=l && p[i].l+p[j].l+t==L ) 
        if( p[i].x*p[j].y-p[i].y*p[j].x ) return 1; 
    return 0; 
} 
  
int Dis( node a, node b ) { 
    w=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); 
    return sqrt(w); 
} 
  
void Pre() { 
    ans=INF; l=L>>1; 
    for( int i=1; i<=L; i++ ) 
        for( int j=0; i*i+j*j<=l*l; j++ ) { 
            t=sqrt( i*i+j*j );
            if( t*t==i*i+j*j ) { 
                p[++pcnt].l=t; 
                p[pcnt].x=i; p[pcnt].y=j; 
            } 
        } 
} 
  
int main() {
    scanf( "%d", &L );
    if( L&1 || L<4 ){ printf( "-1.000000\n" ); return 0; } 
    Pre(); 
    for(int i = 1; i <= pcnt; i ++ ) {
      printf("%d %d %d\n", p[i].x, p[i].y , p[i].l);
    }
    printf("%d\n", pcnt);
    for( int i=1; i<=pcnt; i++ ) 
        for( int j=i+1; j<=pcnt && p[i].l+p[j].l < L; j++ ) { 
            t=Dis( p[i], p[j] );
            // printf("%.6f\n", t); 
            if( Can( i, j ) ) { 
                maxl=max( t, max( p[i].l, p[j].l ) ); 
                minl=min( t, min( p[i].l, p[j].l ) ); 
                ans=min( ans, maxl-minl ); 
            } 
        } 
    if( ans>=INF ) { 
        if( L%4 ) ans=1; 
        else ans=0; 
    } 
    printf( "%.6lf\n", (double)ans ); 
    return 0; 
}