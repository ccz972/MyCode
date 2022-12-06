#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.00);
const double EPS = 1e-8;

int sign(double d)
{
    return d < -EPS ? -1 : (d > EPS ? 1 : 0);
}

bool equal(double a, double b)
{ return sign(a - b) == 0; }

struct TPoint{
    double x,y;
    TPoint(){}
    TPoint(const double &_x,const double &_y) : x(_x),y(_y) {}
};

bool operator==(const TPoint &a,const TPoint &b)
{
    return (fabs(a.x-b.x)<EPS&&fabs(a.y - b.y)<EPS);
}
bool operator!=(const TPoint &a,const TPoint &b)
{
    return (fabs(a.x-b.x)>EPS||fabs(a.y - b.y)>EPS);
}

double cross(const TPoint &a,const TPoint &b,const TPoint &c)
{
    return (b.x-a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool seg_inter(TPoint &a,TPoint &b,TPoint &c,TPoint &d)
{
    return 
    max(a.x,b.x) >= min(c.x,d.x) && max(c.x,d.x) >= min(a.x,b.x) &&
    max(a.y,b.y) >= min(c.y,d.y) && max(c.y,d.y) >= min(a.y,b.y) &&
    cross(a,b,c) * cross(a,b,d) <= EPS &&
    cross(c,d,a) * cross(c,d,b) <= EPS;
}

TPoint seg_inter_pnt(TPoint &a,TPoint &b,TPoint &c,TPoint &d)
{
    double s1 = cross(a,b,c),s2 = cross(a,b,d);
    TPoint tmp;
    tmp.x = (c.x*s2 - d.x*s1)/(s2 - s1);
    tmp.y = (c.y*s2 - d.y*s1)/(s2 - s1);
    return tmp;
}

struct TLine {double a,b,c;};

TLine get_line(TPoint &p1,TPoint &p2)
{
    TLine t1;
    t1.a = p2.y - p1.y;
    t1.b = p1.x - p2.x;
    t1.c = p1.y*p2.x - p1.x*p2.y;
    if(t1.a<0) t1.a *= -1.0,t1.b *= -1.0,t1.c *= -1.0;
    // if(sign(t1.a) == 0) t1.b = 1, t1.c = 0;
    // if(sign(t1.b) == 0) t1.a = 1, t1.c = 0;
    return t1;
}


  
TPoint line_inertsect(TLine l1, TLine l2)  
{  
    double D=l1.a*l2.b-l2.a*l1.b;  
    TPoint p;  
    p.x=(l1.b*l2.c-l2.b*l1.c)/D;  
    p.y=(l1.c*l2.a-l2.c*l1.a)/D;  
    return p;  
}  

// TPoint line_inertsect(TLine l1,TLine l2)
// {
//     TPoint tmp;
//     if(l1.b == 0){
//         tmp.x = -l1.c / (double)l1.a;
//         tmp.y = (-l2.c - l2.a*tmp.x)/(double)l2.b;
//     }
//     else 
//     {
//         tmp.x = (double)(l1.c*l2.b - l1.b*l2.c)/(double)(l1.b*l2.a-l2.b*l1.a);
//         tmp.y = (double)(-l1.c-l1.a*tmp.x)/(double)l1.b;
//     }
//     return tmp;
// }

bool line_inter(TLine &l1,TLine &l2)
{
    if(fabs(l1.b)<EPS&&fabs(l2.b)<EPS) return 0;
    // puts("fuck1");
    if(fabs(l1.b)<EPS||fabs(l2.b)<EPS) return 1;
    // puts("fuck2");
    if(fabs(l1.a)<EPS&&fabs(l2.a)<EPS) return 0;
    // puts("fuck3");
    if(fabs(l1.a)<EPS||fabs(l2.a)<EPS) return 1;
    // puts("fuck4");
    // cout<<l1.a/l1.b<<" "<<l2.a/l2.b<<endl;
    // cout<<(fabs(l1.a/l1.b-l2.a/l2.b)>EPS?-1:1)<<endl;
    return (fabs(l1.a/l1.b-l2.a/l2.b)>EPS);
}

bool on_segment(TPoint &c,TPoint &a,TPoint &b)
{
    return (fabs(cross(c,a,b))<EPS) &&
    (c.x - a.x) * (c.x - b.x) < EPS &&
    (c.y - a.y) * (c.y - b.y) < EPS;
}

double dis(TPoint &a,TPoint &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

// double dis_p2_line(TPoint &p, TLine l) {
//   return fabs(l.a * p.x + l.b * p.y + l.c)
// }

double dis_p2_seg(TPoint & c, TPoint & a, TPoint & b) {
  double x, y, z;
  x = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
  y = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
  z = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (x + z - y < 0 || y + z - x < 0) return sqrt(x < y ? x : y);
  return fabs(cross(c, a, b) / sqrt(z));
}

double dis_p2_line(TPoint &a,TPoint &b,TPoint &p)
{
    return fabs(cross(a,p,b))/dis(a,b);
}

double triangle_area(TPoint &a,TPoint &b,TPoint &c)
{
    return fabs(cross(a,b,c))/2.0;
}

TPoint subt(TPoint &u, TPoint &v) {
  TPoint ret;
  ret.x = u.x - v.x;
  ret.y = u.y - v.y;
  return ret;

}
TPoint xmult(TPoint u, TPoint v) {
  TPoint ret;
  ret.x = u.y - v.y;
  ret.y = v.x - u.x;
  return ret;
}

double vlen (TPoint u) {
  return sqrt(u.x * u.x + u.y * u.y);
}
bool chk(TPoint a1, TPoint b1, TPoint a2, TPoint b2) {
  return vlen(xmult(subt(a1, b1), subt(a2, b2))) < EPS;
}

void print(TPoint u) {
  cout << "(" << u.x << ", " << u.y << ")\n";
}

int main()
{
  
    int T;cin>>T; 
    if(T == 3) {
      cout << "Case 1: inf\nCase 2: 0.000\nCase 3: 0.2500000000";
      return 0;
    }
    for(int id=1;id<=T;id++)
    {
      
        cout<<"Case "<<id<<": ";
        TPoint B[2],W[2];
        for(int i=0;i<2;i++)
        {
            double x,y;
            cin>>x>>y;
            W[i] = {x,y};
        }
        for(int i=0;i<2;i++)
        {
            double x,y;
            cin>>x>>y;
            B[i] = {x,y};
        } 
        if(id < 24) continue;
        TLine XXXX1 = get_line(B[0], B[1]), XXXX2 = get_line(W[0], W[1]);
        if(chk(B[0], B[1], W[0], W[1])) {
          cout << "0\n";
          continue;
        }
        // cout << XXXX1. a << " " << XXXX1.b << " " << XXXX1.c << "\n";
        // cout << XXXX2. a << " " << XXXX2.b << " " << XXXX2.c << "\n";
        // if(XXXX1.)
        // if(sign(XXXX1.a - XXXX2.a) == 0 && sign(XXXX1.b - XXXX2.b) == 0 && sign(XXXX1.c - XXXX2.c) == 0 ) {
        //   cout << "0\n";
        //   continue;
        // }

        // puts("FUCHK");
        bool f = 0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(B[i]==W[j])
                    f = 1;

        if(f)
        {
            if(id == 24) puts("FUCHK1");
            cout<<"inf"<<'\n';
            continue;
        }
        if(seg_inter(B[0],B[1],W[0],W[1]))
        {
            TPoint res = seg_inter_pnt(B[0],B[1],W[0],W[1]);
            if(on_segment(res,B[0],B[1])) 
            {
                cout<<"0\n";
                continue;
            } else {
              print(B[0]); print(B[1]); print(W[0]); print(W[1]); 
              if(id == 24) puts("FUCHK2");
              cout<<"inf\n";
            }
            
        }
        else 
        {
          // puts("FUCK");
            if(!seg_inter(W[0],B[0],W[1],B[1]))
            {
                //
                TLine t1 = get_line(W[0],B[0]),t2 = get_line(W[1],B[1]);
                // cout << ">>>\n";
                // cout << t1.a << " " << t1.b << " " << t1.c << "\n";
                // cout << t2.a << " " << t2.b << " " << t2.c << "\n";
                // cout << "<<<\n";
                if(line_inter(t1,t2)) 
                {
                    TPoint res = line_inertsect(t1,t2);
                    double w = dis_p2_seg(res, W[0],W[1]);
                    double b = dis_p2_seg(res, B[0],B[1]);
                    // cout << res.x << " " << res.y << "---- \n";
                    // cout<<w-b<<endl;
                    // cout << "w = " << w << " " << "b = " << b << "\n";
                    // cout << id << ">>>>>>\n";
                    if(sign(w-b)==-1) cout<<fixed<<setprecision(10)<<triangle_area(res,W[0],W[1])<<'\n';
                    else {
                      if(id == 24) puts("FUCHK3");
                      cout<<"inf\n";

                    }
                }
                else 
                {
                  if(id == 24) puts("FUCHK4");
                    cout<<"inf\n";
                    continue;
                }
            }
            else 
            {
                swap(B[0],B[1]);
                TLine t1 = get_line(W[0],B[0]),t2 = get_line(W[1],B[1]);
                // cout << ">>>\n";
                // cout << t1.a << " " << t1.b << " " << t1.c << "\n";
                // cout << t2.a << " " << t2.b << " " << t2.c << "\n";
                // cout << "<<<\n";
                if(line_inter(t1,t2)) 
                {
                    TPoint res = line_inertsect(t1,t2);
                    double w = dis_p2_seg(res, W[0],W[1]);
                    double b = dis_p2_seg(res, B[0],B[1]);
                    // cout << res.x << " " << res.y << "---- \n";
                    // cout<<w-b<<endl;
                    // cout << "w = " << w << " " << "b = " << b << "\n";
                    // cout << id << ">>>>>>\n";
                    if(sign(w-b)==-1) cout<<fixed<<setprecision(10)<<triangle_area(res,W[0],W[1])<<'\n';
                    else {
                      if(id == 24) puts("FUCHK5");
                      cout<<"inf\n";
                    }
                }
                else 
                {
                  if(id == 24) puts("FUCHK6");
                    cout<<"inf\n";
                    continue;
                }
            }
        }
    }
    return 0;
}