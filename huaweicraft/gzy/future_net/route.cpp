<<<<<<< HEAD
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
const int maxn = 5000;
double INF = 1e7;
int hashnode[maxn];
int edgenum;
struct E{
	int u, v, c, eid;
}edge[maxn];
struct Edge{
	int nxt;
}uu[maxn], vv[maxn];
int src, des;
bool vis[maxn], need[maxn];
int head1[maxn], head2[maxn], neednode[maxn];
//你要完成的功能总入口
int result[maxn];
int xhash[maxn];
int cnt;
void print() {
    cout << "\n";
    for(int i = 1; i <= cnt; ++i) {
        pr(i);prln(head1[i]);prln(head2[i])
    }
    for(int  u = 1; u <= cnt; ++u) {
        prln(u);prln(xhash[u]);
        for(int i = head1[u]; ~i; i = uu[i].nxt) {
                int v = edge[i].v;
                int c = edge[i].c;
            pr(i);pr(v);pr(xhash[v]);prln(c);
        }
        cout << "rubian\n";
        for(int i = head2[u]; ~i; i = vv[i].nxt) {
              int v = edge[i].u;
                int c = edge[i].c;
            pr(i);pr(v);pr(xhash[v]);prln(c);
        }
    }
}
int  rnum;
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;

	uu[edgenum].nxt = head1[u];
	head1[u] = edgenum;

	vv[edgenum].nxt = head2[v];
	head2[v] = edgenum;
}
int needNum;
void search_route(char *topo[5000], int edge_num, char *demand){
	//start = clock();
	needNum = 0;cnt = 0;
	for(int i = 0; i <= 700; ++i) {
		head2[i] = head1[i] = -1;
	}
	int len = strlen(demand);
	for (int i = 0; i < len; ++i) {
		if (demand[i] == ',' || demand[i] == '|')
			demand[i] = ' ';
	}
	stringstream ss(demand);
	int x;
	while (ss >> x) {
		++cnt;
		vis[x] = true;
		hashnode[x] = cnt;
		xhash[cnt] = x;
		if (cnt > 2) {
			need[x] = 1, ++needNum;
			neednode[needNum] = cnt;
		}
		else if (cnt == 1) {
			src = x;
		}
		else {
			des = x;
		}
	}
	int id, u, v, w, hu, hv, eid, ret = 0;
	bool fd;

	for (int i = 0; i < edge_num; ++i) {
		sscanf(topo[i], "%d,%d,%d,%d", &id, &u, &v, &w);
		if(!vis[u]){
			hashnode[u] = ++cnt;
			xhash[cnt] = u;
			vis[u] = true;
		}
		if(!vis[v]) {
			hashnode[v] = ++cnt;
			xhash[cnt] = v;
			vis[v] = true;
		}
		hu = hashnode[u];hv = hashnode[v];
		fd = false;
		for(int i = head1[hu]; ~i; i = uu[i].nxt) {
			if(edge[i].v == hv) {
				fd = true;
				if(w < edge[i].c) {
					edge[i].c = w;
					edge[i].eid = id;
				}
			}
		}
		if(!fd) {
			addedge(hu,hv,w,id);
		}
	}


	/*====================华丽的分割线==============================*/

	INF = 1e6;
	lprec *lp;
	lp = make_lp(0, edgenum+cnt);
	if(lp == NULL) ret = 1;
	int colno[1+edgenum+cnt];     /* must be 1 more than number of columns ! */
  	REAL sparserow[1+edgenum+cnt]; /* must be the number of non-zero values */
	for(int i = 1; i <= edgenum; ++i) {
		ret = set_binary(lp, i, TRUE);
	}
	for(int i = edgenum+1; i <= edgenum+cnt; ++i) {
		set_int(lp, i, true);
        	set_bounds(lp, i, 0, 13000);
	}

	 set_add_rowmode(lp, TRUE);
	//条件2
	//除了起点s和终点t意外出度都等于入度
	for(int u = 1; u <= cnt; ++u) {
		rnum = 0;
		//if(u==1||u==2) continue;
		//if(u == 2) continue;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			colno[rnum] = i;pr(i);
			sparserow[rnum++] = 1;
		}
		//if(u == 1) continue;
		for(int i = head2[u]; ~i; i = vv[i].nxt) {
			colno[rnum] = i;pr(i);
			sparserow[rnum++] = -1;
		}
		if(rnum) {
                	if(u == 1) add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
			else if(u == 2) add_constraintex(lp, rnum, sparserow, colno, EQ, -1.0);
			else add_constraintex(lp, rnum, sparserow, colno, EQ, 0.0);
		}
		//prln(rnum);
	}
    //prln(needNum);
	neednode[++needNum] = 1;
	for(int j = 1; j <= needNum; ++j) {
		int u = neednode[j];
		pr(u);
		prln(xhash[u]);
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			colno[rnum] = i;
			pr(i);
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
		prln(ret);prln(rnum);
	}

		rnum = 0;
		for(int i = head2[2]; ~i; i = vv[i].nxt) {
			colno[rnum] = i;
			pr(i);
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
		prln(ret);prln(rnum);


	rnum = 3;

	sparserow[0] = INF;sparserow[1] = 1.0;sparserow[2] = -1;
	for(int i = 1; i <= edgenum; ++i) {
		colno[0] = i;
		colno[1] = edge[i].v + edgenum;
		colno[2] = edge[i].u + edgenum;
		sparserow[1] = 1.0;sparserow[2] = -1;
		sparserow[0] = INF;
		if(colno[1] > colno[2]){
			swap(colno[1],colno[2]);
			swap(sparserow[1],sparserow[2]);
		}
		//pr(colno[0]);pr(colno[1]);prln(colno[2]);

		add_constraintex(lp, rnum, sparserow, colno, LE, edge[i].c*1.0+INF);
		sparserow[0] = -INF;
		add_constraintex(lp, rnum, sparserow, colno, GE, edge[i].c*1.0-INF);
	}
	colno[0] = edgenum + 1;
	sparserow[0] = 1;
	add_constraintex(lp, 1, sparserow, colno, EQ, 0);
	set_add_rowmode(lp, FALSE);
	//write_LP(lp, stdout);

for(int i = 1; i <= edgenum; ++i) {
		colno[i-1] = i;
		sparserow[i-1] = edge[i].c;
	}
	int Ncolumns = get_Ncolumns(lp);
	prln(Ncolumns);
	set_obj_fnex(lp, edgenum, sparserow, colno);
	set_minim(lp);
	int snum = 15;
	snum += (needNum)/5;
	 //set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS | PRESOLVE_LINDEP, get_presolveloops(lp));
	set_timeout(lp, 8.5);
	//set_bb_depthlimit(lp,20);
	//set_solutionlimit(lp, 5);
	 //set_scalelimit(lp, 3);
	  //set_mip_gap(lp, TRUE, 1.0e-2);
	int minans = INF;
	 minans = get_presolve(lp);
	minans = solve(lp);
	minans =  get_objective(lp);
	prln(minans);

	int ans[edgenum+1+cnt];
	REAL row[edgenum+1+cnt];
	int ansnum = 0;
	for(int i = 0; i <=edgenum; ++i) {
		vis[i] = false;
	}
	//for(int i = 0; i <= 10; ++i) row[i] = 11;
	get_variables(lp, row);
	int fuck = 0;
	for(int i = 0; i < edgenum; ++i) {
        	//pr(i);prln(row[i]);prln(edge[i+1].eid);
		if(row[i] > 0) {
			vis[i+1] = 1;
			fuck++;
		}
	}
	prln(fuck);
 delete_lp(lp);
	queue<int> q;
	q.push(1);
	int anscnt = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			if(vis[i]) {
				//prln(i);prln(edge[i].eid);
				result[anscnt++] = edge[i].eid;
				q.push(edge[i].v);
				break;
			}
		}
	}
	prln(anscnt);
	for (int i = 0; i < anscnt; ++i) {
			record_result(result[i]);
		}

}
=======
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
const int maxn = 5000;
double INF = 1e7;
int hashnode[maxn];
int edgenum;
struct E{
	int u, v, c, eid;
}edge[maxn];
struct Edge{
	int nxt;
}uu[maxn], vv[maxn];
int src, des;
bool vis[maxn], need[maxn];
int head1[maxn], head2[maxn], neednode[maxn];
//你要完成的功能总入口
int result[maxn];
int xhash[maxn];
int cnt;
void print() {
    cout << "\n";
    for(int i = 1; i <= cnt; ++i) {
        pr(i);prln(head1[i]);prln(head2[i])
    }
    for(int  u = 1; u <= cnt; ++u) {
        prln(u);prln(xhash[u]);
        for(int i = head1[u]; ~i; i = uu[i].nxt) {
                int v = edge[i].v;
                int c = edge[i].c;
            pr(i);pr(v);pr(xhash[v]);prln(c);
        }
        cout << "rubian\n";
        for(int i = head2[u]; ~i; i = vv[i].nxt) {
              int v = edge[i].u;
                int c = edge[i].c;
            pr(i);pr(v);pr(xhash[v]);prln(c);
        }
    }
}
int  rnum;
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;

	uu[edgenum].nxt = head1[u];
	head1[u] = edgenum;

	vv[edgenum].nxt = head2[v];
	head2[v] = edgenum;
}
int needNum;
void search_route(char *topo[5000], int edge_num, char *demand){
	//start = clock();
	needNum = 0;cnt = 0;
	for(int i = 0; i <= 700; ++i) {
		head2[i] = head1[i] = -1;
	}
	int len = strlen(demand);
	for (int i = 0; i < len; ++i) {
		if (demand[i] == ',' || demand[i] == '|')
			demand[i] = ' ';
	}
	stringstream ss(demand);
	int x;
	while (ss >> x) {
		++cnt;
		vis[x] = true;
		hashnode[x] = cnt;
		xhash[cnt] = x;
		if (cnt > 2) {
			need[x] = 1, ++needNum;
			neednode[needNum] = cnt;
		}
		else if (cnt == 1) {
			src = x;
		}
		else {
			des = x;
		}
	}
	int id, u, v, w, hu, hv, eid, ret = 0;
	bool fd;

	for (int i = 0; i < edge_num; ++i) {
		sscanf(topo[i], "%d,%d,%d,%d", &id, &u, &v, &w);
		if(!vis[u]){
			hashnode[u] = ++cnt;
			xhash[cnt] = u;
			vis[u] = true;
		}
		if(!vis[v]) {
			hashnode[v] = ++cnt;
			xhash[cnt] = v;
			vis[v] = true;
		}
		hu = hashnode[u];hv = hashnode[v];
		fd = false;
		for(int i = head1[hu]; ~i; i = uu[i].nxt) {
			if(edge[i].v == hv) {
				fd = true;
				if(w < edge[i].c) {
					edge[i].c = w;
					edge[i].eid = id;
				}
			}
		}
		if(!fd) {
			addedge(hu,hv,w,id);
		}
	}


	/*====================华丽的分割线==============================*/

	INF = 1e6;
	lprec *lp;
	lp = make_lp(0, edgenum+cnt);
	if(lp == NULL) ret = 1;
	int colno[1+edgenum+cnt];     /* must be 1 more than number of columns ! */
  	REAL sparserow[1+edgenum+cnt]; /* must be the number of non-zero values */
	for(int i = 1; i <= edgenum; ++i) {
		ret = set_binary(lp, i, TRUE);
	}
	for(int i = edgenum+1; i <= edgenum+cnt; ++i) {
		set_int(lp, i, true);
        	set_bounds(lp, i, 0, 13000);
	}

	 set_add_rowmode(lp, TRUE);
	//条件2
	//除了起点s和终点t意外出度都等于入度
	for(int u = 1; u <= cnt; ++u) {
		rnum = 0;
		//if(u==1||u==2) continue;
		//if(u == 2) continue;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			colno[rnum] = i;pr(i);
			sparserow[rnum++] = 1;
		}
		//if(u == 1) continue;
		for(int i = head2[u]; ~i; i = vv[i].nxt) {
			colno[rnum] = i;pr(i);
			sparserow[rnum++] = -1;
		}
		if(rnum) {
                	if(u == 1) add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
			else if(u == 2) add_constraintex(lp, rnum, sparserow, colno, EQ, -1.0);
			else add_constraintex(lp, rnum, sparserow, colno, EQ, 0.0);
		}
		//prln(rnum);
	}
    //prln(needNum);
	neednode[++needNum] = 1;
	for(int j = 1; j <= needNum; ++j) {
		int u = neednode[j];
		pr(u);
		prln(xhash[u]);
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			colno[rnum] = i;
			pr(i);
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
		prln(ret);prln(rnum);
	}

		rnum = 0;
		for(int i = head2[2]; ~i; i = vv[i].nxt) {
			colno[rnum] = i;
			pr(i);
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
		prln(ret);prln(rnum);


	rnum = 3;

	sparserow[0] = INF;sparserow[1] = 1.0;sparserow[2] = -1;
	for(int i = 1; i <= edgenum; ++i) {
		colno[0] = i;
		colno[1] = edge[i].v + edgenum;
		colno[2] = edge[i].u + edgenum;
		sparserow[1] = 1.0;sparserow[2] = -1;
		sparserow[0] = INF;
		if(colno[1] > colno[2]){
			swap(colno[1],colno[2]);
			swap(sparserow[1],sparserow[2]);
		}
		//pr(colno[0]);pr(colno[1]);prln(colno[2]);

		add_constraintex(lp, rnum, sparserow, colno, LE, edge[i].c*1.0+INF);
		sparserow[0] = -INF;
		add_constraintex(lp, rnum, sparserow, colno, GE, edge[i].c*1.0-INF);
	}
	colno[0] = edgenum + 1;
	sparserow[0] = 1;
	add_constraintex(lp, 1, sparserow, colno, EQ, 0);
	set_add_rowmode(lp, FALSE);
	//write_LP(lp, stdout);

for(int i = 1; i <= edgenum; ++i) {
		colno[i-1] = i;
		sparserow[i-1] = edge[i].c;
	}
	int Ncolumns = get_Ncolumns(lp);
	prln(Ncolumns);
	set_obj_fnex(lp, edgenum, sparserow, colno);
	set_minim(lp);
	int snum = 15;
	snum += (needNum)/5;
	 //set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS | PRESOLVE_LINDEP, get_presolveloops(lp));
	set_timeout(lp, 8.5);
	//set_bb_depthlimit(lp,20);
	//set_solutionlimit(lp, 5);
	 //set_scalelimit(lp, 3);
	  //set_mip_gap(lp, TRUE, 1.0e-2);
	int minans = INF;
	 minans = get_presolve(lp);
	minans = solve(lp);
	minans =  get_objective(lp);
	prln(minans);

	int ans[edgenum+1+cnt];
	REAL row[edgenum+1+cnt];
	int ansnum = 0;
	for(int i = 0; i <=edgenum; ++i) {
		vis[i] = false;
	}
	//for(int i = 0; i <= 10; ++i) row[i] = 11;
	get_variables(lp, row);
	int fuck = 0;
	for(int i = 0; i < edgenum; ++i) {
        	//pr(i);prln(row[i]);prln(edge[i+1].eid);
		if(row[i] > 0) {
			vis[i+1] = 1;
			fuck++;
		}
	}
	prln(fuck);
 delete_lp(lp);
	queue<int> q;
	q.push(1);
	int anscnt = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			if(vis[i]) {
				//prln(i);prln(edge[i].eid);
				result[anscnt++] = edge[i].eid;
				q.push(edge[i].v);
				break;
			}
		}
	}
	prln(anscnt);
	for (int i = 0; i < anscnt; ++i) {
			record_result(result[i]);
		}

}
>>>>>>> 4901d01dade82e9ddbde37faaa241353454056fa
