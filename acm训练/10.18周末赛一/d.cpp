
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 3e5+100;
const double ep = 1e-5;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
struct node{
    int score;
    int id;
    bool operator < (const node& rhs)const{
        return score > rhs.score || (score == rhs.score&& id < rhs.id);
    }
    node();
    node(double score, int id):score(score), id(id){}
};
int p[maxn];
int s[10];
vector<node> ans;
double a,b,c;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, id;
    int x;
    int kase = 0;
    while(cin >> n && n) {
        ans.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", &a,&b,&c);
            s[1] = (int)round(a*100);
            s[2] = (int)round(b*100);
            s[3] = (int)round(c*100);
            for(int j = 0; j < 8; ++j) {
                 x = (j&1)*s[1] + (j>>1 & 1)*s[2] + (j>>2 & 1)*s[3];
                ans.push_back((node){x,i});
            }
        }
        sort(ans.begin(), ans.end());
        int j = 0;
        x = -1;
        bool ok = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &id);
            while(j < ans.size()) {
                if(ans[j].id == id ){
                    if(i == n-1) {
                        x = ans[j].score;
                        ok = true;
                    }
                    ++j;
                    break;
                } else ++j;
            }

        }
        cout << x << endl;
        printf("Case %d: ",++kase);
        if(ok) printf("%.2f\n", x/100.0);
        else cout << "No solution\n";
    }
    return 0;
}
