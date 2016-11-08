#include "route.h"
#include "lib_record.h"
#include "lp_lib.h"
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<ctime>	
#include<string>
#define pr(x)  //cout << #x << "   =   " << (x) << "   ";
#define prln(x) //cout << #x << " = " << (x) << '\n';
using namespace std;
const int maxn = 1000000;
const double INF = 6e5;
const int SIZE = 21234;
int edgenum;
 int T = 2;
 int S = 1;
 int start;
struct E{
	int u, v, c, eid;
	bool bridge;
	int nxt;
}edge[SIZE];
struct Ve{
	int nxt;
}vv[SIZE];
int head[SIZE], headv[SIZE], src, des;
int indx[610][610];
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;
	edge[edgenum].bridge = false;
	edge[edgenum].nxt = head[u];
	head[u] = edgenum;
	indx[u][v] = eid;
	vv[edgenum].nxt = headv[v];
	headv[v] = edgenum;
}

int neednode[SIZE],needNum,id[SIZE],tonode[SIZE],cnt;
bool vis[SIZE];
int to[SIZE];
int getid(int x) {
	//点从1开始编号
	if(!vis[x]){
		id[x] = ++cnt;
		tonode[cnt] = x;
		vis[x] = true;
		to[cnt] = x;
	}
	return id[x];
}
bool need[SIZE];
void input(char *topo[5000], int edge_num, char *demand) {
	int len = strlen(demand);
	memset(need, 0, 610*sizeof(bool));
	for (int i = 0; i < len; ++i) {
		if (demand[i] == ',' || demand[i] == '|')
			demand[i] = ' ';
	}
	stringstream ss(demand);
	int x;
	while (ss >> x) {
		getid(x);
		if (cnt > 2) {
			neednode[++needNum] = cnt;
			need[cnt] = true;
		}
		else if (cnt == 1) src = x;
		else 	des = x;
	}
	bool fd = false;
	int eid, u, v, w;
	for (int i = 0; i < edge_num; ++i) {
		sscanf(topo[i], "%d,%d,%d,%d", &eid, &u, &v, &w);
		int idu = getid(u);
		int idv = getid(v);
		fd = false;
		for(int j = head[idu]; ~j; j = edge[j].nxt){
			int vv = edge[j].v;
			if(vv == idv){
				fd = true;
				if(w < edge[j].c){
					edge[j].c = w;
					edge[j].eid = eid;
					indx[idu][idv] = eid;
				}
			}
		}
		if(!fd) addedge(idu,idv,w,eid);
	}
}

int sccno[SIZE], sccnt, ins[SIZE], in[SIZE],out[SIZE], dfn[SIZE], low[SIZE], dfnnum,  stk[maxn], top;
void tarjan(int fa, int u) {
    dfn[u] = low[u] = ++dfnnum;
    stk[top++] = u;
    ins[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(u, v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                edge[i].bridge = edge[i^1].bridge = true;
            }
        } else if(ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int v; ++sccnt;
        do{
            v = stk[--top];
            ins[v] = false;
            sccno[v] = sccnt;
        }while(u != v);
    }
}
bool ban[SIZE];
int bancnt, banedge;
void gettarjan(int n){
	memset(dfn, 0, (n+2)*sizeof(int));
    memset(ins, 0, (n+2)*sizeof(int));
    memset(in, 0, (n+2)*sizeof(int));
    memset(ban, 0, sizeof ban);
    sccnt = top = dfnnum = 0;
    //从开头开始tarjan，不与起点连接的ban掉
	tarjan(-1,1);
	for(int i = 1; i <= n; ++i){
		if(!sccno[i])  continue;
		for(int j = head[i]; ~j; j = edge[j].nxt){
			if(edge[j].bridge){
				int v= edge[j].v;
				in[sccno[v]]++;
				out[sccno[i]]++;
			}
		}
	}
	int s = sccno[1], t = sccno[2];
	for(int i = 1; i <= n; ++i)
	{
		int scc = sccno[i];
		if(!scc || (scc != s && scc != t && (in[scc] < 1 || out[scc] < 1))) ban[i] = true;
	}
	// for(int i = 1; i <= n; ++i){
	// 	if(ban[i]) bancnt++;
	// }
	// for(int u = 1; u <= n; ++u){
	// 	for(int i = head[u]; ~i; i = edge[i].nxt){
	// 		int v = edge[i].v;
	// 		if(ban[u]||ban[v]) banedge++;
	// 	}
	// }
}


int pre[SIZE], dis[SIZE], cntneed[SIZE];
bool can[SIZE];
int q[SIZE];
void dfs(int s) {
	bool inq[maxn];
	for(int i = 0; i <= cnt; ++i){
		dis[i] = INF;
		inq[i] = false;
		pre[i] = -1;
		cntneed[i] = 0;
	}
	dis[s] = 0;inq[s] = true;
	int tail = 0;
	q[++tail] = s;
	while(tail) {
		int u = q[tail--];inq[u] = false;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			//if(!can[v]) continue;
			if(dis[v] > dis[u] + edge[i].c){
				pre[v] = u;
				dis[v] = dis[u] + edge[i].c;
				if(need[v]) cntneed[v] = 1;
				else cntneed[v] = 0;
				cntneed[v] += cntneed[u];
				if(!inq[v]) {
					q[++tail] = v;
					inq[v] = true;
				}
			}
		}
	}
}



const int N = 2e6+3e5;
struct State{
	int neednum, dis, now, pres;
	bool operator < (const State& rhs)const{
		return neednum < rhs.neednum || (neednum == rhs.neednum && dis > rhs.dis);
	}
	bool vis[610];
}state[N];
void init(State& now,int a, int b, int c, int dd){
	now.neednum = a;now.dis = b;now.now = c; now.pres = dd;
	for(int i = 0; i <= 600; ++i){
		now.vis[i] = false;
	}
	now.vis[now.now] = true;
	int last = now.now, p = now.pres;
	while(p != -1) {
		last = state[p].now;
		now.vis[last] = true;
		p = state[p].pres;
	}
	while(last != -1){
		now.vis[last] = true;
		last = pre[last];
	}
}
int statenum;



int getstate(){

	return statenum++;
}

struct Stateid{
	int id;
	bool operator < (const Stateid& rhs)const{
		return state[id] < state[rhs.id];
	}
};

int path[N], finaldis, pathnum;
bool haveans;
void spfa(int s, int d[], int p[], const State& now){
	bool inq[SIZE];
	for(int i = 0; i <= cnt; ++i){
		d[i] = INF;
		p[i] = -1;
		inq[i] = 0;
	}
	d[s] = 0;
	inq[s] = true;
	int tail = 0;
	q[++tail] = s;
	while(tail){
		int u = q[tail--];inq[u] = false;
		prln(u);
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(now.vis[v]) continue;
			if(d[v] > d[u] + edge[i].c){
				d[v] = d[u] + edge[i].c;
				p[v] = u;
				if(!inq[v]){
					q[++tail] = v;
					vis[v] = true;
				}
			}
		}
	}
	prln("spfa end");
}
int tempd[SIZE], tempp[SIZE];
void printstate(const State& a){
	return;
	int p = a.pres, now = a.now;
	pr(a.neednum);prln(now);prln(a.dis);
	while(p != -1){
		now = state[p].now;
		pr(now);
		p = state[p].pres;
	}
	while(pre[now] != -1){
		now = pre[now];
		pr(now);
	}
	//cout << "\n";
}
void update(int nowid, int temppath[], int& tempnum){
	int now = state[nowid].now;
	prln("******************");
	pr(nowid);printstate(state[nowid]);
	spfa(state[nowid].now, tempd, tempp, state[nowid]);
	//prln(tempd[T]);prln(state[nowid].dis);
	if(tempd[T] + state[nowid].dis >= finaldis) return;
	prln("T to now");
	haveans = true;
	finaldis = tempd[T] + state[nowid].dis;
	tempnum = 0; int p = T;
	prln("T to now");
	while(p != now){
		temppath[tempnum++] = p; 
		p = tempp[p];
	}
	p = nowid;
	prln("now to first neednode");
	while(state[p].pres != -1){
		temppath[tempnum++] = state[p].now;
		p = state[p].pres;
	}
	p = state[p].now;
	prln("to source");
	while(p != -1){
		temppath[tempnum++] = p;
		p = pre[p];
	}
	prln("update end");
}
int getnxt(int s, int t,const State& now){
	int ans = 0;
	bool arrive = false;
	int tail = 0;
	q[++tail] = s;
	bool leap[610];
	for(int i = 0; i <= cnt; ++i) leap[i] = false;
	leap[s] = true;
	while(tail){
		int u = q[tail--];
		if(need[u]) ans++;
		if(u == T) arrive = true;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(ban[v] || now.vis[v] || leap[v]) continue;
			leap[v] = true;
			q[++tail] = v;
		}
	}
	tail = 0;
	q[++tail] = t;
	for(int i = 0; i <= cnt; ++i) leap[i] = false;
	leap[t] = true;
	int ans1 = 0;
	while(tail){
		int u = q[tail--];
		if(need[u]) ans1++;
		//if(u == T) arrive = true;
		for(int i = headv[u]; ~i; i = vv[i].nxt){
			int v = edge[i].u;
			if(ban[v] || now.vis[v] || leap[v]) continue;
			leap[v] = true;
			q[++tail] = v;
		}
	}
	if(!arrive) return -1;
	if(ans1 < ans) ans = ans1;
	return ans;
}
 int pq[N];
 int pqtail;
 void updatepq(int pos) {
 	int pa = pos>>1;
 	int temp;
 	while(pos) {
 		pa = pos>>1;
 		if(state[pa] < state[pos]){
 			temp = pos;
 			pos = pa;
 			pa = temp;
 		} else return;
 	}
 }
 void push(int x) {
 	if(N - pqtail < 20){
 		pq[pqtail-1] = x;
 	} else pq[pqtail++] = x;
 	updatepq(pqtail-1);
 }
void bfs(int s, int t){
	pr(s);prln(t);
	dfs(s);
	pqtail = 0;
	for(int i = 1; i <= needNum; ++i){
		int u = neednode[i];
		 int temp = getstate();
		 init(state[temp], cntneed[u],dis[u],u,-1);
		 push(temp);
	}
	prln(needNum);
	int kk = 0;
	while(pqtail) {
		//if(N-statenum < 1) return;
	//	if(haveans) return;
	//	if(kk%10000==0) cout << clock() << "  " << statenum << "\n";
		if ((clock() - start) / CLOCKS_PER_SEC > 8)return;
		int nowid = pq[--pqtail];
	//	printstate(state[nowid]);
		if(state[nowid].neednum == needNum){
			update(nowid,path,pathnum);
			continue;
		}
		const State& now = state[nowid];
		int u = now.now;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(now.vis[v] || ban[v]) continue;
			int nxtkey = getnxt(v,T,state[nowid]);
			if(now.neednum + nxtkey < needNum) continue;
			int temp = getstate();
			init(state[temp],now.neednum+need[v],now.dis+edge[i].c,v,nowid);

			push(temp);
		}
	}
}

void search_route(char *topo[5000], int edge_num, char *demand){
	start = clock();
	// cout << start << "\n";
	memset(head, -1, sizeof head);
	memset(headv, -1, sizeof headv);
	memset(ban, 0, sizeof ban);
	input(topo, edge_num, demand);
	gettarjan(cnt);
	finaldis = INF;
	bfs(S,T);

	if(haveans){
		prln(haveans);
		for(int i = pathnum-1; i > 0; --i){
			record_result(indx[path[i]][path[i-1]]);
		}
		// for(int i = pathnum-1; i >= 0; --i){
		// 	prln(path[i]);prln(to[path[i]]);
		// }
	}
}