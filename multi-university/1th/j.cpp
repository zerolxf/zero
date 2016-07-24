/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月22日 星期五 22时51分01秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
#define print(x) //cout << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const ll base = 1e7+7;
const ll MOD = 794623899271;
map<string, int> mp1, mp2;
int cnt1, cnt2;
typedef pair<ll,int> Node;
vector<Node> G[maxn];
//vector<int> v[2][maxn];

string name1[maxn], name2[maxn];

int n, m;
int dis[maxn], vis[maxn];
int q[maxn];
ll siz[maxn], has[2][maxn];
struct Hashtree{
    int now;
    int root[3];
    int start;
    void init(int _start){
        memset(root, -1, sizeof root);
        start = _start;
        now = 0;
    }
   int dfs1(int u ){
        prln("dfs1");
        memset(vis, 0, sizeof vis);
        int qcnt = 0;
        for(int i = 0+start; i <= n+start; ++i){
            dis[i] = INF;
        }
        dis[u] = 0;
        vis[u] = true;
        q[++qcnt] = u;
        while(qcnt){
            u = q[qcnt--];
            prln(u);
            prln("1");
            int usize = G[u].size();
            for(int i = 0; i < usize; ++i){
                int v = G[u][i].second;
                if(v == u) continue;
                if(dis[v]<=dis[u]) continue;
                q[++qcnt] = v;
                dis[v] = dis[u] + 1;
            }
        }
        int ma = 0, id = 0;
        prln(start);
        for(int i = start; i <= start+n-1; ++i){
            if(dis[i] > ma){
                pr(i);pr(dis[i]);prln(ma);
                ma = dis[i];
                id = i;
            }
        }
        prln("dfs1 end");
        return id;
    }

    void dfs2(int u, int fa){
        prln("dfs2");
        siz[u] = 1;
        int usize = G[u].size();
        for(int i = 0; i < usize; ++i){
            //int v  = G[u][i].second;
            int v = G[u][i].second;
            if(v == fa) continue;
            dfs2(v, u);
            siz[u] += siz[v];
        }
        has[now][u] = siz[u];
        vector<ll> vt;
        for(int i = 0; i < usize; ++i){
            //int v= G[u][i];
            int v = G[u][i].second;
            if(v == fa) continue;
            vt.push_back(has[now][v]);
        }
        sort(vt.begin(), vt.end());
        int vtsize = vt.size();
        for(int i = 0; i < vtsize; ++i){
            has[now][u] = (has[now][u]*base + vt[i])%MOD;
        }
    }
   void gethash(){
       prln("get hash start");
       int root1 = dfs1(start);
       int root2 = dfs1(root1);
       int qcnt = 0;
       q[++qcnt] = root2;
       memset(vis, 0, sizeof vis);
       vis[root2] = true;
       //pr(root1);prln(root2);
       while(!vis[root1]){
            int u = q[qcnt];
            int usize = G[u].size();
            prln(u);
            prln("1");
            prln(usize);
            for(int i = 0; i < usize; ++i){
                //int v = G[u][i];
                int v = G[u][i].second;
                pr(v);pr(u);pr(dis[v]);prln(dis[u]);
               pr(root1);prln(root2);
                if(dis[v]>=dis[u]) continue;
                q[++qcnt] = v;
                vis[v] = true;
            }
       }
       memset(root, -1, sizeof root);
       if(qcnt&1){
           root[0] = q[(qcnt+1)/2];
       }else{
           root[0] = q[(qcnt)/2];
           root[1] = q[(qcnt)/2+1];
       }
       now = 0;
       pr(root[0]);prln(root[1]);
       dfs2(root[0], root[0]);
       if(~root[1]){
           now = 1;
           dfs2(root[1], root[1]);
           if(has[0][root[0]] < has[1][root[1]]){
               ll t;

               for(int i = start; i <= start+n-1; ++i){
                    t = has[0][i];
                    has[0][i] = has[1][i];
                    has[1][i] = t;
               }
               swap(root[0], root[1]);
           }
       }
       prln("get hash end");
    }
}hh, hw;
int ans[maxn];
int coun;
bool in[maxn];
void prname(int id){
    //pr(id);prln(name1[id]);
}
bool dfs(int u, int v){
    pr(u);prln(v);
    in[u] = true;
    in[v] = true;
    if(G[u].size() != G[v].size()){
        in[u] = false;
        in[v] = false;
        return false;
    }
    int usize = G[u].size();
    int last = 0;
    int oknum = 0;
    for(int i = 0; i < usize; ++i){
        int uu = G[u][i].second;
        if(uu==u) continue;
        for(int j = last; j < usize; ++j){
            int vv = G[v][i].second;
            pr(u);pr(uu);pr(v);prln(vv);
            prname(u);prname(v);
            prname(uu);
            prname(vv);
            int temp = coun++;
            prln(temp);prln("start");
            if(vv==v) continue;
            prln(temp);prln("vv==v");
            if(in[uu]||in[vv]) continue;
            prln(temp);prln("!in[uu]&&!in[vv]");
            if(has[hh.now][uu] != has[hw.now][vv]) {

                prln(temp);prln("has!=");
                return false;
            }

            prln(temp);prln("dfs");
            if(!dfs(uu, vv)){
                ++j;
                continue;
            }
            prln(temp);prln("end");
            swap(G[v][j], G[v][last]);
            oknum++;
            last = last+1;
            break;
        }
    }
    ans[u] = v;
    return true;
}
void printhash(){
    for(int i = 1; i <= n*2; ++i){
        pr(i);pr(name1[i]);pr(has[0][i]);prln(has[1][i]);
    }
}
void solve(){

    //prln("hh")
    hh.init(1);
    hh.gethash();
    //prln("hw");
    hw.init(n+1);
    hw.gethash();
    bool ok = true;
    hh.now = hw.now = 0;
    prln("dfs start");
    memset(ans, 0, sizeof ans);
    for(int i = 1; i <= 2*n; ++i){
        int usize = G[i].size();
        for(int j = 0; j < usize; ++j){
            Node& x = G[i][j];
            x.first = has[0][x.second];
            //pr(u);pr(v);prln(G[i][j].second);
        }
        sort(G[i].begin(), G[i].end());
        for(int j = 0; j < usize; ++j){
            pr(i);pr(G[i][j].second);prln(G[i][j].first);
            //Node& x = G[i][j];
            //x.first = has[0][x.first];
            //pr(u);pr(v);prln(G[i][j].second);
        }
    }

    memset(in, 0, sizeof in);
    pr(hw.root[0]);prln(name1[hw.root[0]]);
    pr(hw.root[1]);prln(name1[hw.root[1]]);
    pr(hh.root[0]);prln(name1[hh.root[0]]);
    pr(hh.root[1]);prln(name1[hh.root[1]]);
    ll h1 = has[0][hh.root[0]];
    ll h2 = has[0][hw.root[0]];
    pr(h1);prln(h2);
    h1 = has[1][hh.root[1]];
    h2 = has[1][hw.root[1]];
    pr(h1);prln(h2);
    prln("第一次匹配");
    if(h1!=h2||!dfs(hh.root[0], hw.root[0])){
        pr("hh1");prname(hh.root[1]);
        pr("hw1")prname(hw.root[1]);
        pr("hh0");prname(hh.root[0]);
        pr("hw0")prname(hw.root[0]);
        if(hh.root[1]!=-1){
            hh.now = 0;
            hw.now = 1;
            for(int i = n+1; i <= 2*n; ++i){
                int usize = G[i].size();
                for(int j = 0; j < usize; ++j){
                    Node& x = G[i][j];
                    x.first = has[1][x.second];
                    //pr(u);pr(v);prln(G[i][j].second);
                }
                sort(G[i].begin(), G[i].end());
            }
            memset(in, 0, sizeof in);
            h1 = has[0][hh.root[0]];
            h2 = has[1][hw.root[1]];
            pr(h1);prln(h2);
            prln("第二次匹配hh0和hw1");
            ok = ok || dfs(hh.root[0], hw.root[1]);
        }
    }else ok = true;
    for(int i = 1; i <= n; ++i){
        pr(i);prln(ans[i]);
        cout << name1[i] << " " << name1[ans[i]] << "\n";
    }
    printhash();

    prln("dfs end");
    prln("solve end");

}
int getid1(const string& str){
    if(mp1.count(str)) return mp1[str];
    mp1[str] = ++cnt1;
    name1[cnt1] = str;
    //pr(cnt1);prln(name1[cnt1]);
    return cnt1;
}
int getid2(const string& str){
    if(mp2.count(str)) return mp2[str];
    mp2[str] = ++cnt1;
    name1[cnt1] = str;
    //pr(cnt1);prln(name1[cnt1]);
    return cnt1;
}
//struct Node{
    //ll hash, id;
    //Node(){}
    //Node(ll _hash, ll _id){
        //hash = _hash;
        //id = _id;
    //}
    //bool operator < (const Node& rhs)const{
        //return hash < rhs.hash;
    //}
//}node[maxn];

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    //scanf("%d", &t);
    while(scanf("%d", &n) != EOF){
        //scanf("%d", &n);
        string stra, strb;
        int u, v;
        mp1.clear();
        mp2.clear();
        cnt1 = 0;
        for(int i = 0; i <= 2*n; ++i){
            G[i].clear();
        }
        for(int i = 1; i < n; ++i){
            cin >> stra >> strb;
            pr(stra);prln(strb);
            u = getid1(stra);
            v = getid1(strb);
            pr(u);prln(v);
            G[u].push_back(Node(0,v));
            G[v].push_back(Node(0,u));
        }

        for(int i = 1; i < n; ++i){
            cin >> stra >> strb;
            pr(stra);prln(strb);
            u = getid2(stra);
            v = getid2(strb);
            pr(u);prln(v);
            G[u].push_back(Node(0,v));
            G[v].push_back(Node(0,u));
        }

        solve();

    }
	return 0;
}
