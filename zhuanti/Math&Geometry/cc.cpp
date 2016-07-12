#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
//从角的角度思考
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-15;
double iL,t,c,Ls;
bool C(double m){
    if(((iL/sin(m))/2)*m*2.0>=Ls)return true;
    return false;
}
int main(){
        #ifdef LOCAL
        freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
      //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
     #endif
while(~scanf("%lf%lf%lf",&iL,&t,&c)){
    if(iL<0||t<0||c<0)break;
    Ls=(1.0+t*c)*iL;
    double lb=0,ub=PI/2.0;
    while(ub-lb>eps){
        double mid=(ub+lb)/2.0;
        if(C(mid)){
            ub=mid;
        }
        else lb=mid;
    }
    printf("%.3f\n",(iL/2/sin(ub))-iL/2/tan(ub));
}

return 0;
}
