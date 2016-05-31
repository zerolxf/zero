/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月28日 星期六 14时49分39秒
 ************************************************************************/
#include <stdio.h>
unsigned long long ret( unsigned long long  x,  unsigned long long  y,  unsigned long long  z){
     unsigned long long  base = x;
     unsigned long long  ans = 1;
    while(y){
        if(y&1) ans = (ans*base)%z;
        base = base*base%z;
        y >>= 1;
    }
    return ans;
}
int mod[4], base[4];
unsigned int ed[10];
struct Hhash{
    unsigned long long a[3];
    void clear(){
        for(int i = 0; i < 3; ++i) a[i] = 0;
    }
    void insert(int l, int r) {
        for(int i = 0; i < 3; ++i){
             unsigned long long  x = ret(base[i], l-1, mod[i]);
            for(int j = l; j <= r; ++j){
                x = (x*base[i])%mod[i];
                 unsigned long long  temp = x*j%mod[i];
                a[i] = (a[i] + temp)%mod[i];
            }
        }
    }
    bool ok( unsigned long long  x1,  unsigned long long  x2) {
         unsigned long long  b[4];
        for(int i = 0; i < 3; ++i){
             unsigned long long  x = ret(base[i], x1, mod[i]);
            b[i] = (a[i] + (x*x1)%mod[i])%mod[i];
            x = ret(base[i], x2, mod[i]);
            b[i] = (b[i] + (x*x2)%mod[i])%mod[i];
        }
        return b[0] == ed[0]&&b[1]==ed[1]&&b[2]==ed[2];
    }
}hhash;
int cnt[8][10];
int ans1, ans2;
void dfs(int pos, int num1, int num2){
    int b1 = 0, b2 = 0;
    for(int i = 0; i < 10; ++i){
        if(cnt[pos][i] == 1) {
            b2 = b1;
            b1 = i;
        }else if(cnt[pos][i] == 2){
            b1 = b2 = i;

        }
    }
    if(pos == 0) {
         int  c1 = num1*10+b1, c2 = num2*10+b2;
        if(hhash.ok(c1,c2)) {
            ans1 = c1, ans2 = c2;
        }
        c1 = num1*10+b2, c2 = num2*10+b1;
        if(hhash.ok(c1,c2)) {
            ans1 = c1, ans2 = c2;
        }
        return;
    }
    dfs(pos-1, num1*10+b1,num2*10+b2);
    dfs(pos-1, num1*10+b2,num2*10+b1);
}
int main(){
    int n ;
    mod[0] = 1e9+7;
    mod[1] = 1e8+7;
    mod[2] = 1e7+13;
    base[0] = 399031;
    base[1] = 1e6 + 99;
    base[2] = 1e6+3;
    base[3] = 1e6+39;
    int l, r, mi, ma;
    int a[10];
    a[0] = 1;
    for(int i = 0;i<10; ++i){
        for(int j = 0; j < 10; ++j){
            cnt[i][j] = 0;
        }
    }
    for(int i = 1; i <= 6; ++i){
        a[i] = a[i-1]*10;
    }
    scanf("%d", &n);
        scanf("%d%d", &mi, &ma);
         unsigned long long  bb[4];
        for(int i = 0; i < 3; ++i){
            bb[i] = ret(base[i], mi-1, mod[i]);
            ed[i] = 0;
        }
        for(int i = mi; i <= ma; ++i){
            for(int j = 0; j < 6; ++j){
                cnt[j][(i/a[j])%10]++;
            }
            for(int j = 0; j < 3; ++j){
                bb[j] = (bb[j]*base[j])%mod[j];
                ed[j] = (ed[j] + (bb[j]*i)%mod[j])%mod[j];    
            }
        }
        hhash.clear();
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &l, &r);
            hhash.insert(l,r);
            for(int j = l; j <= r; ++j){
                for(int k = 0; k < 6; ++k){
                    cnt[k][(j/a[k])%10]--;
                }
            }
        }
        dfs(5,0,0);
        if(ans1 > ans2) {
            printf("%d %d", ans2, ans1);
        }
        else printf("%d %d\n", ans1, ans2);
	return 0;
}
