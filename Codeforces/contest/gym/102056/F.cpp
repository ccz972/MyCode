/*
* @Author: ISSAC
* @Date:   2022-07-16
* @File:   F.cpp
* @Last Modified time: 2022-07-16
*/

#include <bits/stdc++.h>
#define double long double
using namespace std;
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point3 { double x, y, z; };
struct line3 { point3 a, b; };
struct plane3 { point3 a, b, c;};
struct sphere3 { point3 o; double r; };

point3 xmult(point3 u, point3 v){
	point3 ret;
	ret.x = u.y * v.z - v.y * u.z;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return ret;
}
double dmult(point3 u, point3 v){
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
point3 subt(point3 u, point3 v){
	point3 ret;
	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	return ret;
}
double distance(point3 p1, point3 p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)
		+(p1.z-p2.z)*(p1.z-p2.z));
}
double vlen(point3 p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
double ptoline(point3 p, point3 l1, point3 l2){
	return vlen(xmult(subt(p, l1), subt(l2, l1))) / distance(l1, l2);
}
double pow(double x){
	return x * x;
}

point3 operator + (point3 &a, point3 &b) {
  point3 c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}

double p2seg3(point3 a, point3 b, point3 c) {
  point3 d, e;
  while (distance(b, c) > eps) {
    d = b + c; d.x *= 0.5; d.y *= 0.5; d.z *= 0.5;
    e = d + b; e.x *= 0.5; e.y *= 0.5; e.z *= 0.5;
    if (distance(a , d) <= distance(a , e)) b = e;
    else c = d;
  }
  return distance(a, b);
}

int sign(double x){return x < -eps ? -1 : x > eps;}
void solve(){
	double ox, oy, oz, r, sx, sy, sz, tx, ty, tz;
	cin >> ox >> oy >> oz >> r;
	cin >> sx >> sy >> sz >> tx >> ty >> tz;
	point3 O = {ox, oy, oz};
	point3 A = {sx, sy, sz};
	point3 B = {tx, ty, tz};
	double ans = 0;
	if(!sign(sx - tx) && !sign(sy - ty) && !sign(sz - tz)){
		cout << fixed << setprecision(10) << (double)0;
		return;
	}

  // if(sign(ptoline(O, A, B) - r) != -1){
	// 	cout << fixed << setprecision(10) << distance(A, B);
	// 	return;
	// }
  // cout << fixed << setprecision(10) << p2seg3(O, A, B) << "\n";

	if(sign(p2seg3(O, A, B) - r) != -1) {
		cout << fixed << setprecision(10) << distance(A, B);
		return;
	}

	double OA = distance(O, A);
	double OB = distance(O, B);
	double AC = sqrt(OA * OA - r * r);
	double BD = sqrt(OB * OB - r * r);
	double AB = distance(A, B);
	double AOB = acos((pow(OA) + pow(OB) - pow(AB)) / (2 * OA * OB)); 
	double AOC = acos(r / OA);
	double BOD = acos(r / OB);
	double COD = AOB - AOC - BOD;
	double l = r * COD + AC + BD;
	cout << fixed << setprecision(10) << l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int T; cin >> T;
    while(T --){
    	solve();
    	cout << "\n";
    }
    return 0;
}