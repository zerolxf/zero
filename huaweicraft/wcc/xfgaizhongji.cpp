<<<<<<< HEAD
#include "route.h"
#include "lib_record.h"
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;
typedef pair<int, int>P;
const int maxn = 605;
const int inf = 120000;
int start, src, des, bestans, neednum;
bool haveans;
int head[maxn];
int desdis[maxn];
int bfstime[maxn][maxn];
int oridis[maxn][maxn];//原始图的距离
int indx[maxn][maxn];//两点之间的序号
bool iscity[maxn];
bool needcity[maxn];
int bfskey[maxn];
vector<int>city, needcitys;
vector<int>G[maxn];
struct Node
{
	int u, v, w, nxt;
}node[7000];
const int qsize = 5e6+100;
struct Path{
	int id, last;
}path[qsize*30];
int pathcnt, pos1, pos2;
struct Ant
{
	int pathid;
	//bool vis[maxn];
	int hash[31];
	int num, len, st;
	void addpath(int x) {
		path[pathcnt].id = x;
		path[pathcnt].last = pathid;
		pathid = pathcnt++;
		int pos1 = x/30, pos2 = x%30;
		hash[pos1] |= 1<<pos2;
	}
	bool vis(int x) {
		 pos1 = x/30, pos2 = x%30;
		return hash[pos1]&(1<<pos2);
	}
	void init()
	{
		//memset(vis, false, sizeof(vis));
		num = 0; len = 0;
		for(int i = 0; i < 31; ++i) hash[i] = 0;
		pathid = -1;
	}
	bool operator < (const Ant& r)const
	{
		/*if (num == r.num)
		{
			/*if (len == r.len)
			{
				int ans1 = inf, ans2 = inf;
				for (int i = 0; i < needcitys.size(); i++)
				{
					int v = needcitys[i];
					if (!vis[v])
						ans1 = min(ans1, bfstime[st][v]);
					if (!r.vis[v])
						ans2 = min(ans2, bfstime[r.st][v]);
				}
				return ans1 > ans2;
			}
			return len > r.len;
		}*/
		if (num == r.num) return len > r.len;
		return num < r.num;
	}
}finalant, qq[qsize];
int unqq[qsize];
int qcnt;
int newAnt() {
	return unqq[qcnt--];
}
void delAnt(int id) {
	unqq[++qcnt] = id;
	qq[id].init();
}
struct Antt{
	int id;
	bool operator < (const Antt& r)const
	{
		return qq[id] < qq[r.id];
	}
};
void add_edge(int u, int v, int w, int tot)
{
	node[tot].u = u; node[tot].v = v;
	node[tot].w = w;
	node[tot].nxt = head[u];
	head[u] = tot;
}
void checkcity(int x)
{
	if (iscity[x])return;
	iscity[x] = true;
	city.push_back(x);
}

void input(char *topo[5000], int edge_num, char *demand)
{
	int len = strlen(demand);
	for (int i = 0; i < len; i++)
	{
		if (demand[i] == '|' || demand[i] == ',')
			demand[i] = ' ';
	}
	stringstream ss(demand);
	int x, countnum = 0;
	neednum = 0;
	memset(iscity, false, sizeof(iscity));
	memset(needcity, false, sizeof(needcity));
	while (ss >> x)
	{
		checkcity(x);
		countnum++;
		if (countnum == 1)
			src = x;
		else if (countnum == 2)
			des = x;
		else
		{
			neednum++;
			needcity[x] = true;
			needcitys.push_back(x);
		}
	}
	memset(head, -1, sizeof(head));
	memset(oridis, 0x3f, sizeof(oridis));
	int tot = 0;
	for (int i = 0; i < edge_num; i++)
	{
		int id, u, v, w;
		sscanf(topo[i], "%d,%d,%d,%d", &id, &u, &v, &w);
		add_edge(v, u, w, tot++);
		if (oridis[u][v] > w)
		{
			if (oridis[u][v] > 100)
				G[u].push_back(v);
			checkcity(u); checkcity(v);
			oridis[u][v] = w;
			indx[u][v] = id;
		}
	}
}
void workdesshortest()
{
	memset(desdis, 0x3f, sizeof(desdis));
	desdis[des] = 0;
	priority_queue<P>pq;
	pq.push(P(0, des));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		if (desdis[u] < disu)continue;
		for (int i = head[u]; i != -1; i = node[i].nxt)
		{
			int v = node[i].v;
			if (desdis[v] > disu + node[i].w)
			{
				desdis[v] = disu + node[i].w;
				pq.push(P(desdis[v], v));
			}
		}
	}
}
void update(const Ant& cleve)
{
	int newid = newAnt();
	Ant& clever = qq[newid];
	clever = cleve;
	int dis[maxn], pre[maxn];
	memset(dis, 0x3f, sizeof(dis));
	dis[clever.st] = 0;
	priority_queue<P>pq;
	pq.push(P(0, clever.st));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		if (dis[u] < disu)continue;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (clever.vis(v))continue;
			if (dis[v] > disu + oridis[u][v])
			{
				pre[v] = u;
				dis[v] = disu + oridis[u][v];
				pq.push(P(dis[v], v));
			}
		}
	}
	if (dis[des] > inf)return;
	if (dis[des] + clever.len >= bestans)return;
	haveans = true;
	bestans = dis[des] + clever.len;
	int u = clever.st, v = des;
	vector<int>vt;
	while (v != u)
	{
		vt.push_back(v);
		v = pre[v];
	}
	clever.len += dis[des];
	for (int i = vt.size() - 1; i >= 0; i--)
	{
		int v = vt[i];
		//clever.vis[v] = true;
		clever.addpath(v);
	}
	finalant = clever;
	delAnt(newid);
}
void init(priority_queue<Antt>& p)
{
	qcnt = 0;
	for(int i = 0; i < qsize; ++i){
		unqq[++qcnt] = i;
	}
	int dis[maxn], pre[maxn];
	memset(dis, 0x3f, sizeof(dis));
	dis[src] = 0;
	priority_queue<P>pq;
	pq.push(P(0, src));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (dis[v] > disu + oridis[u][v])
			{
				pre[v] = u;
				dis[v] = disu + oridis[u][v];
				pq.push(P(dis[v], v));
			}
		}
	}
	for (int i = 0; i < needcitys.size(); i++)
	{
		int u = needcitys[i];
		int tempid = newAnt();
		Ant& temp = qq[tempid];
		vector<int>vt;
		int v = u;
		while (v != src)
		{
			vt.push_back(v);
			v = pre[v];
		}
		temp.init();
		temp.addpath(src); //temp.vis[src] = true;
		temp.len = temp.num = 0;
		temp.st = src;
		for (int j = vt.size() - 1; j >= 0; j--)
		{
			int id = vt[j];
			temp.addpath(id);
			//temp.vis[id] = true;
			temp.len += oridis[temp.st][id];
			temp.st = id;
			if (needcity[id])temp.num++;
		}
		p.push(Antt{tempid});
	}
}
void prln(priority_queue<Antt>p)
{
	while (p.size())
	{
		Ant temp = qq[p.top().id]; p.pop();
		cout << temp.num << endl;
	}
}

int nxtkey( Ant& now)
{

	//bool nowvis[610];
	//getvis(nowvis[], now);
	int ans = 0;
	bool leap[maxn];
	memset(leap, false, sizeof(leap));
	leap[now.st] = true;
	queue<int>p;
	p.push(now.st);
	while (p.size())
	{
		int u = p.front(); p.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (now.vis(v))continue;
			if (leap[v])continue;
			leap[v] = true;
			p.push(v);
			if (needcity[v] || v == des)ans++;
		}
	}
	return ans;
}
const int sz = 15000;
void bfs()
{
	priority_queue<Antt>pq;
	init(pq);
	/*Ant stant;
	stant.init();
	stant.path[0] = src;
	stant.vis[src] = true;
	stant.num = 0; stant.len = 0;
	stant.st = src; stant.tot = 1;
	pq.push(stant);*/
	int pp[sz];
	while (pq.size())
	{

		//if ((clock() - start) / CLOCKS_PER_SEC > 8)return;
		if(pq.size() > sz*3) 
		{
			for(int i = 0; i < sz; ++i) {
				pp[i] = pq.top().id;pq.pop();
			}
			while(pq.size()) {
				int pqid = pq.top().id;
				delAnt(pqid);
				pq.pop();
			}
			for(int i = 0; i < sz; ++i) {
				pq.push(Antt{pp[i]});
			}
		}
		if(haveans) return;
		int tempid = pq.top().id; 
		Ant& temp = qq[tempid];
		pq.pop();
		if (temp.num == neednum)
		{
			update(temp);
			continue;
		}
		int u = temp.st;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (temp.vis(v))continue;
			if (v == des)continue;

			if (temp.len + desdis[temp.st] > bestans)continue;
			int tempcopyid = unqq[qcnt--];
			Ant& tempcopy = qq[tempcopyid];
			tempcopy = temp;
			tempcopy.addpath(v);
			//tempcopy.vis[v] = true;
			tempcopy.st = v;
			tempcopy.len = tempcopy.len + oridis[u][v];
			if (needcity[v])tempcopy.num++;
			if (tempcopy.num + nxtkey(tempcopy) <= neednum)continue;
			pq.push(Antt{tempcopyid});
		}
		delAnt(tempid);		
	}
}
void initbfstime(int st)
{
	bool leap[maxn];
	memset(leap, false, sizeof(leap));
	queue<int>p;
	p.push(st);
	leap[st] = true;
	bfstime[st][st] = 0;
	while (p.size())
	{
		int u = p.front(); p.pop();
		for (int i = head[u]; i != -1; i = node[i].nxt)
		{
			int v = node[i].v;
			if (!leap[v])
			{
				leap[v] = true;
				//bfskey[v]++;
				bfstime[v][st] = bfstime[u][st] + 1;
				p.push(v);
			}
		}
	}
}
void delcity(int x)
{
	vector<int>::iterator it;
	for (it = city.begin(); it != city.end(); ++it) 
	{
		if (*it == x)
		{
			city.erase(it);
			return;
		}
	}
}
void del()
{
	bool leap[maxn];
	vector<int>ddd;
	for (int i = 0; i < city.size(); i++)
	{
		if (needcity[i])continue;
		memset(leap, false, sizeof(leap));
		queue<int>p;
		leap[city[i]] = true;
		p.push(city[i]);
		bool ok = false;
		while (p.size())
		{
			int u = p.front(); p.pop();
			for (int j = 0; j < G[u].size(); j++)
			{
				int v = G[u][j];
				if (leap[v])continue;
				leap[v] = true;
				if (needcity[v] || v == des)
				{
					ok = true; break;
				}
				p.push(v);
			}
		}
		if (ok)continue;
		ddd.push_back(i);
	}
	for (int i = 0; i < ddd.size(); i++)
		delcity(ddd[i]);
}
void search_route(char *topo[5000], int edge_num, char *demand){
	start = clock();
	
	input(topo, edge_num, demand);
	workdesshortest();
	del();
	haveans = false; bestans = inf;

	memset(bfstime, 0x3f, sizeof(bfstime));
	//memset(bfskey, 0, sizeof(bfskey));
	for (int i = 0; i < needcitys.size(); i++)
	{
		int id = needcitys[i];
		initbfstime(id);
	}
	bfs();
	if (haveans)
	{
		int finalcnt = 0;
		int finalantpath[610];
		int pathid = finalant.pathid;
		while(pathid != -1) {
			Path& x = path[pathid];
			finalantpath[finalcnt++] = x.id;
			pathid = x.last;
		}
		for (int i = finalcnt-1; i > 0; --i)
			record_result(indx[finalantpath[i]][finalantpath[i - 1]]);
	}
=======
#include "route.h"
#include "lib_record.h"
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;
typedef pair<int, int>P;
const int maxn = 605;
const int inf = 120000;
int start, src, des, bestans, neednum;
bool haveans;
int head[maxn];
int desdis[maxn];
int bfstime[maxn][maxn];
int oridis[maxn][maxn];//原始图的距离
int indx[maxn][maxn];//两点之间的序号
bool iscity[maxn];
bool needcity[maxn];
int bfskey[maxn];
vector<int>city, needcitys;
vector<int>G[maxn];
struct Node
{
	int u, v, w, nxt;
}node[7000];
const int qsize = 5e6+100;
struct Path{
	int id, last;
}path[qsize*30];
int pathcnt, pos1, pos2;
struct Ant
{
	int pathid;
	//bool vis[maxn];
	int hash[31];
	int num, len, st;
	void addpath(int x) {
		path[pathcnt].id = x;
		path[pathcnt].last = pathid;
		pathid = pathcnt++;
		int pos1 = x/30, pos2 = x%30;
		hash[pos1] |= 1<<pos2;
	}
	bool vis(int x) {
		 pos1 = x/30, pos2 = x%30;
		return hash[pos1]&(1<<pos2);
	}
	void init()
	{
		//memset(vis, false, sizeof(vis));
		num = 0; len = 0;
		for(int i = 0; i < 31; ++i) hash[i] = 0;
		pathid = -1;
	}
	bool operator < (const Ant& r)const
	{
		/*if (num == r.num)
		{
			/*if (len == r.len)
			{
				int ans1 = inf, ans2 = inf;
				for (int i = 0; i < needcitys.size(); i++)
				{
					int v = needcitys[i];
					if (!vis[v])
						ans1 = min(ans1, bfstime[st][v]);
					if (!r.vis[v])
						ans2 = min(ans2, bfstime[r.st][v]);
				}
				return ans1 > ans2;
			}
			return len > r.len;
		}*/
		if (num == r.num) return len > r.len;
		return num < r.num;
	}
}finalant, qq[qsize];
int unqq[qsize];
int qcnt;
int newAnt() {
	return unqq[qcnt--];
}
void delAnt(int id) {
	unqq[++qcnt] = id;
	qq[id].init();
}
struct Antt{
	int id;
	bool operator < (const Antt& r)const
	{
		return qq[id] < qq[r.id];
	}
};
void add_edge(int u, int v, int w, int tot)
{
	node[tot].u = u; node[tot].v = v;
	node[tot].w = w;
	node[tot].nxt = head[u];
	head[u] = tot;
}
void checkcity(int x)
{
	if (iscity[x])return;
	iscity[x] = true;
	city.push_back(x);
}

void input(char *topo[5000], int edge_num, char *demand)
{
	int len = strlen(demand);
	for (int i = 0; i < len; i++)
	{
		if (demand[i] == '|' || demand[i] == ',')
			demand[i] = ' ';
	}
	stringstream ss(demand);
	int x, countnum = 0;
	neednum = 0;
	memset(iscity, false, sizeof(iscity));
	memset(needcity, false, sizeof(needcity));
	while (ss >> x)
	{
		checkcity(x);
		countnum++;
		if (countnum == 1)
			src = x;
		else if (countnum == 2)
			des = x;
		else
		{
			neednum++;
			needcity[x] = true;
			needcitys.push_back(x);
		}
	}
	memset(head, -1, sizeof(head));
	memset(oridis, 0x3f, sizeof(oridis));
	int tot = 0;
	for (int i = 0; i < edge_num; i++)
	{
		int id, u, v, w;
		sscanf(topo[i], "%d,%d,%d,%d", &id, &u, &v, &w);
		add_edge(v, u, w, tot++);
		if (oridis[u][v] > w)
		{
			if (oridis[u][v] > 100)
				G[u].push_back(v);
			checkcity(u); checkcity(v);
			oridis[u][v] = w;
			indx[u][v] = id;
		}
	}
}
void workdesshortest()
{
	memset(desdis, 0x3f, sizeof(desdis));
	desdis[des] = 0;
	priority_queue<P>pq;
	pq.push(P(0, des));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		if (desdis[u] < disu)continue;
		for (int i = head[u]; i != -1; i = node[i].nxt)
		{
			int v = node[i].v;
			if (desdis[v] > disu + node[i].w)
			{
				desdis[v] = disu + node[i].w;
				pq.push(P(desdis[v], v));
			}
		}
	}
}
void update(const Ant& cleve)
{
	int newid = newAnt();
	Ant& clever = qq[newid];
	clever = cleve;
	int dis[maxn], pre[maxn];
	memset(dis, 0x3f, sizeof(dis));
	dis[clever.st] = 0;
	priority_queue<P>pq;
	pq.push(P(0, clever.st));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		if (dis[u] < disu)continue;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (clever.vis(v))continue;
			if (dis[v] > disu + oridis[u][v])
			{
				pre[v] = u;
				dis[v] = disu + oridis[u][v];
				pq.push(P(dis[v], v));
			}
		}
	}
	if (dis[des] > inf)return;
	if (dis[des] + clever.len >= bestans)return;
	haveans = true;
	bestans = dis[des] + clever.len;
	int u = clever.st, v = des;
	vector<int>vt;
	while (v != u)
	{
		vt.push_back(v);
		v = pre[v];
	}
	clever.len += dis[des];
	for (int i = vt.size() - 1; i >= 0; i--)
	{
		int v = vt[i];
		//clever.vis[v] = true;
		clever.addpath(v);
	}
	finalant = clever;
	delAnt(newid);
}
void init(priority_queue<Antt>& p)
{
	qcnt = 0;
	for(int i = 0; i < qsize; ++i){
		unqq[++qcnt] = i;
	}
	int dis[maxn], pre[maxn];
	memset(dis, 0x3f, sizeof(dis));
	dis[src] = 0;
	priority_queue<P>pq;
	pq.push(P(0, src));
	while (pq.size())
	{
		P temp = pq.top(); pq.pop();
		int u = temp.second;
		int disu = temp.first;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (dis[v] > disu + oridis[u][v])
			{
				pre[v] = u;
				dis[v] = disu + oridis[u][v];
				pq.push(P(dis[v], v));
			}
		}
	}
	for (int i = 0; i < needcitys.size(); i++)
	{
		int u = needcitys[i];
		int tempid = newAnt();
		Ant& temp = qq[tempid];
		vector<int>vt;
		int v = u;
		while (v != src)
		{
			vt.push_back(v);
			v = pre[v];
		}
		temp.init();
		temp.addpath(src); //temp.vis[src] = true;
		temp.len = temp.num = 0;
		temp.st = src;
		for (int j = vt.size() - 1; j >= 0; j--)
		{
			int id = vt[j];
			temp.addpath(id);
			//temp.vis[id] = true;
			temp.len += oridis[temp.st][id];
			temp.st = id;
			if (needcity[id])temp.num++;
		}
		p.push(Antt{tempid});
	}
}
void prln(priority_queue<Antt>p)
{
	while (p.size())
	{
		Ant temp = qq[p.top().id]; p.pop();
		cout << temp.num << endl;
	}
}

int nxtkey( Ant& now)
{

	//bool nowvis[610];
	//getvis(nowvis[], now);
	int ans = 0;
	bool leap[maxn];
	memset(leap, false, sizeof(leap));
	leap[now.st] = true;
	queue<int>p;
	p.push(now.st);
	while (p.size())
	{
		int u = p.front(); p.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (now.vis(v))continue;
			if (leap[v])continue;
			leap[v] = true;
			p.push(v);
			if (needcity[v] || v == des)ans++;
		}
	}
	return ans;
}
const int sz = 15000;
void bfs()
{
	priority_queue<Antt>pq;
	init(pq);
	/*Ant stant;
	stant.init();
	stant.path[0] = src;
	stant.vis[src] = true;
	stant.num = 0; stant.len = 0;
	stant.st = src; stant.tot = 1;
	pq.push(stant);*/
	int pp[sz];
	while (pq.size())
	{

		//if ((clock() - start) / CLOCKS_PER_SEC > 8)return;
		if(pq.size() > sz*3) 
		{
			for(int i = 0; i < sz; ++i) {
				pp[i] = pq.top().id;pq.pop();
			}
			while(pq.size()) {
				int pqid = pq.top().id;
				delAnt(pqid);
				pq.pop();
			}
			for(int i = 0; i < sz; ++i) {
				pq.push(Antt{pp[i]});
			}
		}
		if(haveans) return;
		int tempid = pq.top().id; 
		Ant& temp = qq[tempid];
		pq.pop();
		if (temp.num == neednum)
		{
			update(temp);
			continue;
		}
		int u = temp.st;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (temp.vis(v))continue;
			if (v == des)continue;

			if (temp.len + desdis[temp.st] > bestans)continue;
			int tempcopyid = unqq[qcnt--];
			Ant& tempcopy = qq[tempcopyid];
			tempcopy = temp;
			tempcopy.addpath(v);
			//tempcopy.vis[v] = true;
			tempcopy.st = v;
			tempcopy.len = tempcopy.len + oridis[u][v];
			if (needcity[v])tempcopy.num++;
			if (tempcopy.num + nxtkey(tempcopy) <= neednum)continue;
			pq.push(Antt{tempcopyid});
		}
		delAnt(tempid);		
	}
}
void initbfstime(int st)
{
	bool leap[maxn];
	memset(leap, false, sizeof(leap));
	queue<int>p;
	p.push(st);
	leap[st] = true;
	bfstime[st][st] = 0;
	while (p.size())
	{
		int u = p.front(); p.pop();
		for (int i = head[u]; i != -1; i = node[i].nxt)
		{
			int v = node[i].v;
			if (!leap[v])
			{
				leap[v] = true;
				//bfskey[v]++;
				bfstime[v][st] = bfstime[u][st] + 1;
				p.push(v);
			}
		}
	}
}
void delcity(int x)
{
	vector<int>::iterator it;
	for (it = city.begin(); it != city.end(); ++it) 
	{
		if (*it == x)
		{
			city.erase(it);
			return;
		}
	}
}
void del()
{
	bool leap[maxn];
	vector<int>ddd;
	for (int i = 0; i < city.size(); i++)
	{
		if (needcity[i])continue;
		memset(leap, false, sizeof(leap));
		queue<int>p;
		leap[city[i]] = true;
		p.push(city[i]);
		bool ok = false;
		while (p.size())
		{
			int u = p.front(); p.pop();
			for (int j = 0; j < G[u].size(); j++)
			{
				int v = G[u][j];
				if (leap[v])continue;
				leap[v] = true;
				if (needcity[v] || v == des)
				{
					ok = true; break;
				}
				p.push(v);
			}
		}
		if (ok)continue;
		ddd.push_back(i);
	}
	for (int i = 0; i < ddd.size(); i++)
		delcity(ddd[i]);
}
void search_route(char *topo[5000], int edge_num, char *demand){
	start = clock();
	
	input(topo, edge_num, demand);
	workdesshortest();
	del();
	haveans = false; bestans = inf;

	memset(bfstime, 0x3f, sizeof(bfstime));
	//memset(bfskey, 0, sizeof(bfskey));
	for (int i = 0; i < needcitys.size(); i++)
	{
		int id = needcitys[i];
		initbfstime(id);
	}
	bfs();
	if (haveans)
	{
		int finalcnt = 0;
		int finalantpath[610];
		int pathid = finalant.pathid;
		while(pathid != -1) {
			Path& x = path[pathid];
			finalantpath[finalcnt++] = x.id;
			pathid = x.last;
		}
		for (int i = finalcnt-1; i > 0; --i)
			record_result(indx[finalantpath[i]][finalantpath[i - 1]]);
	}
>>>>>>> 4901d01dade82e9ddbde37faaa241353454056fa
}