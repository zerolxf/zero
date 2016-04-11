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
#define pr(x) // cout << #x << "   =   " << (x) << "   ";
#define prln(x)//cout << #x << " = " << (x) << '\n';
using namespace std;
const int maxn = 50000;
const double INF = 6e5;
int edgenum;
 int T = 2;
 int S = 1;
struct E{
	int u, v, c, eid;
	bool bridge;
	int nxt;
}edge[maxn];
int head[maxn], headv[maxn];
int index[610][610];
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;
	edge[edgenum].bridge = false;
	edge[edgenum].nxt = head[u];
	head[u] = edgenum;
	index[u][v] = eid;
	vv[edgenum].nxt = headv[v];
	headv[v] = edgenum;
}

int neednode[maxn], needNum， id[maxn], tonode[maxn], cnt;
bool vis[maxn];
int getid(int x) {
	//点从1开始编号
	if(!vis[x]){
		id[x] = ++cnt;
		tonode[cnt] = x;
		vis[x] = true;
	}
	return id[x];
}
bool need[maxn];
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
					index[idu][idv] = eid;
				}
			}
		}
		if(!fd) addedge(idu,idv,w,eid);
	}
}

int sccno[maxn], sccnt, ins[maxn], in[maxn],out[maxn], dfn[maxn], low[maxn], dfnnum,  stk[maxn], top;
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
bool ban[maxn];
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

const int N = 1e6;
struct State{
	int neednum, dis, now, pres;
	bool operator < (const State& rhs)const{
		return neednum < rhs.neednum || (neednum == rhs.neednum && dis > rhs.dis);
	}
	void init(int a, int b, int c, int d){
		neednum = a;dis = b;now = c; pres = d;
		for(int i = 0; i <= 600; ++i){
			vis[i] = false;
		}
		vis[now] = true;
		int last = now, p = pres;
		while(p != -1) {
			last = state[p].now;
			vis[last] = true;
			p = state[p].pres;
		}
		while(last != -1){
			vis[last] = true;
			last = pre[last];
		}
	}
	bool vis[610];
}state[maxn];
int statenum;

int pre[maxn], dis[maxn], cntneed[maxn];
bool can[maxn];

void dfs(int s) {
	bool inq[maxn];
	for(int i = 0; i <= n; ++i){
		dis[i] = INF;
		inq[i] = false;
		pre[i] = -1;
		cntneed[i] = 0;
	}
	dis[s] = 0;inq[s] = true;
	queue<int> q;
	q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();inq[u] = false;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			//if(!can[v]) continue;
			if(dis[v] > dis[u] + edge[i].c){
				pre[v] = u;
				dis[v] = dis[u] + edge[i].c;
				if(need[x]) cntneed[v] = 1;
				cntneed[v] += cntneed[u];
				if(!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}

int getstate(){

	return statenum++;
}

struct Stateid{
	int id;
	bool operator < （const Stateid& rhs)const{
		return state[id] < state[rhs.id];
	}
}stateid[maxn];

int path[maxn], finaldis, pathnum;
bool haveans;
void spfa(int s, int d[], int p[], const State& now){
	bool inq[maxn];
	for(int i = 0; i <= cnt; ++i){
		d[i] = INF;
		p[i] = -1;
		inq[i] = 0;
	}
	d[s] = 0;
	inq[s] = true;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u = q.front(); q.pop();inq[u] = false;
		for(int i = headp[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(now.vis[v]) continue;
			if(dis[v] > dis[u] + edge[i].c){
				dis[v] = dis[u] + edge[i].c;
				pre[v] = u;
				if(!inq[v]){
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}
int tempd[maxn], tempp[maxn];
void update(int nowid, int temppath[], int& tempnum){
	int now = state[nowid].now;
	dfs(state[nowid].now, tempd, tempp, state[nowid]);
	if(tempd[T] + state[nowid].id >= finaldis) continue;
	haveans = true;
	finaldis = tempd[T] + state[nowid].dis;
	tempnum = 0; int p = T;
	while(p != now){
		temppath[tempnum++] = p; 
		p = tempp[p];
	}
	p = nowid;
	while(state[p].pres != -1){
		temppath[tempnum++] = state[p].now;
		p = state[p].pres;
	}
	p = state[p].now;
	while(p != -1){
		temppath[tempnum++] = p;
		p = pre[p];
	}
}
int getnxt(int s, const State& now){
	int ans = 0;
	bool arrive = false;
	queue<int> q;
	q.push(s);
	bool leap[610];
	for(int i = 0; i <= cnt; ++i) leap[i] = false;
	while(q.size()){
		int u = q.front(); q.pop();
		if(need[v]) ans++;
		if(v == T) arrive = true;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(ban[v] || now.vis[v] || leap[v]) continue;
			leap[v] = true;
			q.push(v);
		}
	}
	if(!arrive) return -1;
	return ans;
}
void bfs(int s, int t){
	dfs(s);
	priority_queue<Stateid> pq;
	for(int i = 1; i <= needNum; ++i){
		int u = neednode[i];
		 int temp = getstate();
		 state[temp].init(cntneed[u],dis[u],u,-1);
		 pq.push(Stateid{temp});
	}
	while(pq.size()) {
		//time
		if(haveans) return;
		int nowid = pq.top().id; pq.pop();
		if(state[nowid].neednum == needNum){
			update(nowid);
		}
		const State& now = state[nowid];
		int u = now.now;
		for(int i = head[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(now.vis[v] || ban[v]) continue;
			int nxtkey = getnxt(v, state[nowid]);
			if(now.neednum + nxtkey < needNum) continue;
			int temp = getstate();
			state[temp].init(cntneed[u]+need[v],now.dis+edge[i].c,v,nowid);
			pq.push(Stateid{temp});
		}
	}
}

void search_route(char *topo[5000], int edge_num, char *demand){
	start = clock();
	memset(head, -1, sizeof head);
	memset(headv, -1, sizeof headv);
	memset(ban, 0, sizeof ban);
	input(topo, edge_num, demand);
	gettarjan(cnt);

	bfs(S,T);

	if(haveans){
		for(int i = pathnum-1; i >= 0; --i){
			record_result(indx[path[i]][path[i-1]]);
		}
	}
	
}