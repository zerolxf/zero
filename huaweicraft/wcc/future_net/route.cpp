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
int start, src, des, bestans, neednum, antnum, scc_cnt;
bool haveans;
int head[maxn];
int sccno[maxn];
int indeg[maxn], outdeg[maxn];
int desdis[maxn];
int bfstime[maxn][maxn];
int oridis[maxn][maxn];//原始图的距离
int indx[maxn][maxn];//两点之间的序号
bool iscity[maxn];
bool needcity[maxn];
bool sccvis[maxn];
int bfskey[maxn];
vector<int>city, needcitys;
vector<int>G[maxn];
vector<int>S;
struct Node
{
	int u, v, w, nxt;
}node[7000];
struct Ant
{
	vector<int>path;
	bool vis[maxn];
	int num, len, st, keynear;
	void init()
	{
		memset(vis, false, sizeof(vis));
		num = 0; len = 0;
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
		if (num == r.num)
			return len > r.len;
		return num < r.num;
	}
}finalant;
vector<Ant>antvt;
struct iint
{
	int x;
	iint(int x = 0) :x(x){}
	bool operator < (const iint& r)const
	{
		Ant temp1 = antvt[x];
		Ant temp2 = antvt[r.x];
		if (temp1.num == temp2.num)
		{
			if (temp1.len == temp2.len)
			{
				int ans1 = inf, ans2 = inf;
				for (int i = 0; i < needcitys.size(); i++)
				{
					int v = needcitys[i];
					if (!temp1.vis[v])
						ans1 = min(ans1, bfstime[temp1.st][v]);
					if (!temp2.vis[v])
						ans2 = min(ans2, bfstime[temp2.st][v]);
				}
				return ans1 > ans2;
			}
			return temp1.len > temp2.len;
		}
		return temp1.num< temp2.num;
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
			des = x;
		else if (countnum == 2)
			src = x;
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
		sscanf(topo[i], "%d,%d,%d,%d", &id, &v, &u, &w);
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
void update(Ant clever)
{
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
			if (clever.vis[v])continue;
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
		clever.vis[v] = true;
		clever.path.push_back(v);
	}
	finalant = clever;
}
void init(priority_queue<iint>& p)
{
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
		Ant temp;
		vector<int>vt;
		int v = u;
		while (v != src)
		{
			vt.push_back(v);
			v = pre[v];
		}
		temp.init();
		temp.path.push_back(src); temp.vis[src] = true;
		temp.len = temp.num = 0;
		temp.st = src;
		for (int j = vt.size() - 1; j >= 0; j--)
		{
			int id = vt[j];
			temp.path.push_back(id);
			temp.vis[id] = true;
			temp.len += oridis[temp.st][id];
			temp.st = id;
			if (needcity[id])temp.num++;
		}
		temp.keynear = inf;
		for (int i = 0; i < needcitys.size(); i++)
		{
			int u = needcitys[i];
			if (temp.vis[u])continue;
			temp.keynear = min(temp.keynear, bfstime[temp.st][u]);
		}
		if (temp.keynear == inf)continue;
		antvt.push_back(temp);
		p.push(iint(antnum));
		antnum++;
	}
}
void prln(priority_queue<Ant>p)
{
	while (p.size())
	{
		Ant temp = p.top(); p.pop();
		cout << temp.num << endl;
	}
}
int nxtkey(Ant now)
{
	int ans = 0;
	bool leap[maxn], exleap[maxn];
	memset(leap, false, sizeof(leap));
	memset(exleap, false, sizeof(exleap));
	leap[now.st] = true;
	queue<int>p;
	p.push(now.st);
	while (p.size())
	{
		int u = p.front(); p.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (now.vis[v])continue;
			if (leap[v])continue;
			leap[v] = true;
			p.push(v);
		}
	}
	queue<int>pp;
	exleap[des] = true;
	pp.push(des);
	while (pp.size())
	{
		int u = pp.front(); pp.pop();
		for (int i = head[u]; i != -1; i = node[i].nxt)
		{
			int v = node[i].v;
			if (now.vis[v])continue;
			if (exleap[v])continue;
			exleap[v] = true;
			pp.push(v);
			if (needcity[v] && leap[v])ans++;
		}
	}
	return ans;
}
void bfs()
{
	priority_queue<iint>pq;
	init(pq);

	while (pq.size())
	{
		//if (haveans)return;
		if ((clock() - start) / CLOCKS_PER_SEC > 8)return;
		iint uu = pq.top(); pq.pop();
		Ant temp = antvt[uu.x];
		if (temp.num == neednum)
		{
			update(temp);
			continue;
		}
		int u = temp.st;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (temp.vis[v])continue;
			if (v == des)continue;

			if (temp.len + desdis[temp.st] > bestans)continue;

			Ant tempcopy = temp;
			tempcopy.path.push_back(v);
			tempcopy.vis[v] = true;
			tempcopy.st = v;
			tempcopy.len = tempcopy.len + oridis[u][v];
			if (needcity[v])tempcopy.num++;
			if (tempcopy.num + nxtkey(tempcopy) < neednum) continue;
			/*tempcopy.keynear = inf;
			for (int i = 0; i < needcitys.size(); i++)
			{
				int u = needcitys[i];
				if (tempcopy.vis[u])continue;
				tempcopy.keynear = min(tempcopy.keynear, bfstime[tempcopy.st][u]);
			}
			if (tempcopy.keynear == inf)continue;*/
			antvt.push_back(tempcopy);
			pq.push(iint(antnum));
			antnum++;
		}
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
void dfs1(int u)
{
	if (sccvis[u])return;
	sccvis[u] = 1;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		dfs1(v);
	}
	S.push_back(u);
}
void dfs2(int u)
{
	if (sccno[u])return;
	sccno[u] = scc_cnt;
	for (int i = head[u]; i != -1; i = node[i].nxt)
	{
		int v = node[i].v;
		dfs2(v);
	}
}
void find_scc()
{
	scc_cnt = 0;
	S.clear();
	memset(sccno, 0, sizeof(sccno));
	memset(sccvis, 0, sizeof(sccvis));
	for (int i = 0; i < city.size(); i++)dfs1(city[i]);
	for (int i = city.size() - 1; i >= 0; i--)
	{
		if (!sccno[S[i]])
		{
			scc_cnt++;
			dfs2(S[i]);
		}
	}
}
void tarjan()
{
	bool todel[maxn];
	scc_cnt = 0;
	find_scc();
	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));
	for (int i = 0; i < city.size(); i++)
	{
		int u = city[i];
		for (int j = 0; j < G[u].size(); j++)
		{
			int v = G[u][j];
			if (sccno[u] == sccno[v])continue;
			indeg[sccno[v]]++;
			outdeg[sccno[u]]++;
		}
	}
	memset(todel, false, sizeof(todel));
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (indeg[i] == 0 || outdeg[i] == 0)
			todel[i] = true;
	}
	todel[sccno[src]] = todel[sccno[des]] = false;
	for (int i = 0; i < city.size(); i++)
	{
		int u = city[i];
		if (todel[sccno[u]])
			delcity(u);
	}
}
void search_route(char *topo[5000], int edge_num, char *demand){
	start = clock();

	input(topo, edge_num, demand);

	workdesshortest();
	haveans = false; bestans = inf;
	antnum = 0;
	//tarjan();

	memset(bfstime, 0x3f, sizeof(bfstime));
	//memset(bfskey, 0, sizeof(bfskey));
	for (int i = 0; i < needcitys.size(); i++)
	{
		int id = needcitys[i];
		initbfstime(id);
	}
	bfs();
	double tt = (clock() - start)*1.0 / CLOCKS_PER_SEC;
	//cout<<tt<<endl;
	if (haveans)
	{
		for (int i = finalant.path.size()-1; i  > 0; i--)
			record_result(indx[finalant.path[i-1]][finalant.path[i ]]);
		//cout << finalant.len << endl;
	}
	//else
	//	cout << "NA" << endl;
}
