/*************************************************************************
    > File Name: e.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月12日 星期五 13时42分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int N = 1024;
struct Node{
    public:
    int x, y;
    Node *nxtr, *nxtc;
    int a;
    int posx, posy;
    void setpos(int _x, int _y){
        posx = _x;
        posy = _y;
    }
    //Node(){}
    Node(int x = 0, int y = 0, Node* _nxtr=NULL, Node* _nxtc=NULL,int _a =0):
        x(x), y(y), nxtr(_nxtr), nxtc(_nxtc),a(_a){
    }
    Node* getnxtr(){
        return nxtr;
    }
    Node* getnxtc(){
        return nxtc;
    }
    void print(){
        cout << "x: " << posx << " y: "<<posy<<"\n ";
    }
}node[1100][1100];
struct Rec{
    int x, y, w, h;
    Node *prec[N], *prer[N], *nxtr[N], *nxtc[N];
    Node *pre, *nxt;
    //Rec(){}
    Rec(int _x, int _y, int _w, int _h):x(_x), y(_y), w(_w), h(_h){

        
    }
    void init(){

        Node *temp = NULL;
        Node *c = &node[x][0];
        for(int i = 1; i < y; ++i){
            c = c->nxtc;
        }

        prec[x] = c;
        for(int i = x+1; i < x+h; ++i){
            c = c->getnxtr();
            prec[i] = c;
        }

        for(int i = y; i < y+w; ++i){
            c = c->getnxtc();
            nxtr[i] = c;
        }

        c = &node[0][y];

        for(int i = 1; i < x; ++i){
            c = c->getnxtr();
        }
        
        prer[y] = c;

        for(int i = y+1; i < y+w; ++i){
            c = c->getnxtc();
            prer[i] = c;
        }

        //c = c->getnxtc();
        for(int i = x; i < x+h; ++i){
            c = c->getnxtr();
            nxtc[i] = c;
        }
    }

    void set(int _x, int _y, int _h, int _w){
        x = _x;
        y = _y;
        w = _w;
        h = _h;
        init();
    }
    void getswap(Rec& rhs){
        int xx = rhs.x;
        int yy = rhs.y;
        for(int i = 0; i < h; ++i){
            //prln(i);
            //prec[x+i]->print();
            //rhs.prec[xx+i]->print();
            swap(prec[x+i]->nxtc, rhs.prec[xx+i]->nxtc);
            swap(nxtc[x+i]->nxtc, rhs.nxtc[xx+i]->nxtc);
        }
        for(int i = 0; i < w; ++i){
            swap(prer[y+i]->nxtr, rhs.prer[yy+i]->nxtr);
            swap(nxtr[y+i]->nxtr, rhs.nxtr[yy+i]->nxtr);
        }

    }
};
int a[1100][1100];
template <class T>
inline bool scan_d(T &ret) {
char c; int sgn;
if(c=getchar(),c==EOF) return 0; //EOF
while(c!='-'&&(c<'0'||c>'9')) c=getchar();
sgn=(c=='-')?-1:1;
ret=(c=='-')?0:(c-'0');
while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
ret*=sgn;
return 1;
}
inline void out(int x) {
if(x>9) out(x/10);
putchar(x%10+'0');
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m, q;
    //scanf("%d", &t);
    //while(t--){
        scan_d(n);
        scan_d(m);
        scan_d(q);
        for(int i = 0; i <= n+2; ++i){
            for(int j = 0; j <= m+2; ++j){
                node[i][j].setpos(i,j);
                node[i][j].nxtc = &node[i][j+1];
                node[i][j].nxtr = &node[i+1][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                scan_d(a[i][j]);
                //pr(i);pr(j);prln(a[i][j]);
                node[i][j].a = a[i][j];
                node[i][j].setpos(i,j);
                //node[i][j-1].nxtc = &node[i][j];
                //node[i-1][j].nxtr = &node[i][j];
            }
        }

        Rec aa(0,0,0,0), bb(0,0,0,0);
        int x, y, xx, yy, w, h;
        int cnt = 0;
        for(int i = 0; i < q; ++i){
            scan_d(x);scan_d(y);
            scan_d(xx);scan_d(yy);
            scan_d(h);scan_d(w);
            aa.set(x,y,h,w);
            bb.set(xx,yy,h,w);
            aa.getswap(bb);
        }
        Node *c = NULL;
        for(int i = 1; i <= n; ++i){
            c = node[i][0].getnxtc();
            for(int j = 1; j <= m; ++j){
                printf("%d ",c->a);
                c = c->getnxtc();
            }
            printf("\n");
        }
    //}

	return 0;
}
