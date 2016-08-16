/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月23日 星期六 17时47分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const double esp = 1e-6;
struct Point{
    double x, y, z;
    Point(){}
    Point(double _x, double _y, double _z){
        x = _x;
        y = _y;
        z = _z;
    }
    Point operator - (const Point& rhs)const{
        return Point(x-rhs.x,y-rhs.y,z-rhs.z);
    }
    Point operator *(const Point& rhs)const{
        return Point(x*rhs.x,y*rhs.y,z*rhs.z);
    }
    double mul(const Point& rhs)const{
        return x*rhs.x + y*rhs.y + z*rhs.z;
    }
    double getdis(){
        return sqrt(x*x+y*y+z*z);
    }
}A, B, C, D;
double getdis(const Point& a, const Point& b){
    return (a-b).getdis();
}
Point Cross(Point a, Point b){
    Point c;
    c.x = a.y*b.z - b.y*a.z;
    c.y = a.z*b.x - b.z*a.x;
    c.z = a.x*b.y - b.x*a.y;
    return c;
}
struct V{
    Point st, ed;
    Point v;
    V(){}
    V(Point a, Point b){
        st = a;
        ed = b;
        v = ed-st;
    }
    double getdis(){
        return v.getdis();
    }
};
double x[10], y[10];
double z[10];
double getsum(double a, double b, double c){
    double sum = 0;
    sum = (a+b+c)/2;
    sum = sqrt((sum-a)*(sum-b)*(sum-c)*sum);
    return sum;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> x[1] >> y[1] >> z[1]){
        for(int i = 2; i <= 4; ++i){
            cin >> x[i] >> y[i] >> z[i];
        }
        Point a(x[1], y[1], z[1]);
        Point b(x[2], y[2], z[2]);
        Point c(x[3], y[3], z[3]);
        Point d(x[4], y[4], z[4]);
        double A = (y[2] - y[1])*(z[3] - z[1]) - (z[2] - z[1])*(y[3] - y[1]);
        double B = (z[2] - z[1])*(x[3] - x[1]) - (x[2] - x[1])*(z[3] - z[1]);
        double C = (x[2] - x[1])*(y[3] - y[1]) - (y[2] - y[1])*(x[3] - x[1]);
        Point M = Point(A, B, C);
        double D = -M.mul(a);
        //prln(A);prln(B);prln(C);prln(D);
        //prln(abs(M.mul(d)+D));
        if(abs(M.mul(d)+D) < esp) {
            printf("O O O O\n");
            continue;
        }
        V AB = V(a,b);
        V AC = V(a,c);
        V AD = V(a,d);
        V BC = V(b,c);
        V BD = V(b,d);
        V CD = V(c,d);
        double abc = getsum(AB.getdis(), AC.getdis(), BC.getdis());
        double acd = getsum(AC.getdis(), AD.getdis(), CD.getdis());
        double abd = getsum(AB.getdis(), AD.getdis(), BD.getdis());
        double bcd = getsum(BC.getdis(), BD.getdis(), CD.getdis());
        double sum = abc+acd+abd+bcd;

        double r =  abs(Cross(AD.v,BD.v).mul(CD.v))/2/sum;

        double xx = (abc*x[4] + acd*x[2] + abd*x[3] + bcd*x[1])/sum;
        double yy = (abc*y[4] + acd*y[2] + abd*y[3] + bcd*y[1])/sum;
        double zz = (abc*z[4] + acd*z[2] + abd*z[3] + bcd*z[1])/sum;
        printf("%.4f %.4f %.4f %.4f\n", xx, yy, zz, r);



    }
	return 0;
}
