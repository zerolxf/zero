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
const int maxn = 50000;
const double INF = 6e5;
int hashnode[maxn];
int edgenum;
struct E{
	int u, v, c, eid;
	bool bridge;
	int nxt;
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

int  rnum;
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;
	edge[edgenum].bridge = false;
	edge[edgenum].nxt = head1[u];

	uu[edgenum].nxt = head1[u];
	head1[u] = edgenum;

	vv[edgenum].nxt = head2[v];
	head2[v] = edgenum;
}
int needNum;
int sccno[maxn], sccnt, ins[maxn], in[maxn],out[maxn], dfn[maxn], low[maxn], dfnnum,  stk[maxn], top;
void tarjan(int fa, int u) {
    dfn[u] = low[u] = ++dfnnum;
    stk[top++] = u;
    ins[u] = true;
    for(int i = head1[u]; ~i; i = edge[i].nxt) {
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
	tarjan(-1,1);
	for(int i = 1; i <= n; ++i){
		if(!dfn[i]) ban[i] = true;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = head1[i]; ~j; j = edge[j].nxt){
			if(edge[j].bridge){
				int v= edge[j].v;
				in[sccno[v]]++;
				out[sccno[i]]++;
			}
		}
	}
	int ss = sccno[1], tt = sccno[2];
	for(int i = 1; i <= sccnt; ++i)
	{
		int scc = sccno[i];
		if(scc != ss && scc != tt && (in[scc] < 1 || out[scc] < 1)) ban[i] = true;
	}
	for(int i = 1; i <= n; ++i){
		if(ban[i]) bancnt++;
	}
	for(int u = 1; u <= n; ++u){
		for(int i = head1[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(ban[u]||ban[v]) banedge++;
		}
	}
}
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
	memset(ban, 0, sizeof ban);
	gettarjan(cnt);



	/*====================华丽的分割线==============================*/
	lprec *lp;
	lp = make_lp(0, edgenum+cnt);
	if(lp == NULL) ret = 1;
	int colno[1+edgenum+cnt];     /* must be 1 more than number of columns ! */
  	REAL sparserow[1+edgenum+cnt]; /* must be the number of non-zero values */
	for(int i = 1; i <= edgenum; ++i) {
		ret = set_binary(lp, i, TRUE);
	}
	for(int i = edgenum+2; i <= edgenum+cnt; ++i) {
		//set_int(lp, i, true);
    	//set_bounds(lp, i, 0,70000);
    	//set_upbo(lp,i,70000);
	}

	 set_add_rowmode(lp, TRUE);
	//条件2
	//除了起点s和终点t意外出度都等于入度
	for(int u = 1; u <= cnt; ++u) {
		if(ban[u]) continue;
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			int vv = edge[i].v;
			if(ban[vv]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = 1;
		}
		for(int i = head2[u]; ~i; i = vv[i].nxt) {
			int uuu = edge[i].u;
			if(ban[uuu]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = -1;
		}
		if(rnum) {
            if(u == 1) add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
			else if(u == 2) add_constraintex(lp, rnum, sparserow, colno, EQ, -1.0);
			else add_constraintex(lp, rnum, sparserow, colno, EQ, 0.0);
		}
	}

	//所有必经点和起点出度为1
	//neednode[++needNum] = 1;
	for(int j = 1; j <= needNum; ++j) {
		int u = neednode[j];
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			int vv = edge[i].v;
			if(ban[vv]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
	}


	//终点的入度为1
/*rnum = 0;
	for(int i = head2[2]; ~i; i = vv[i].nxt) {
		int vv = edge[i].u;
		if(ban[vv]) continue;
		colno[rnum] = i;
		sparserow[rnum++] = 1.0;
	}
	ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
	*/
	//针对不能存在环，所有边使得两边有差值
	rnum = 3;
	sparserow[0] = INF;sparserow[1] = 1.0;sparserow[2] = -1;
	for(int i = 1; i <= edgenum; ++i) {
		int vv = edge[i].v;
		if(ban[vv]) continue;
		int uu = edge[i].u;
		if(ban[uu]) continue;
		colno[0] = i;
		colno[1] = edge[i].v + edgenum;
		colno[2] = edge[i].u + edgenum;
		sparserow[1] = 1.0;sparserow[2] = -1;
		sparserow[0] = INF;
		// if(colno[1] > colno[2]){
		// 	swap(colno[1],colno[2]);
		// 	swap(sparserow[1],sparserow[2]);
		// }
		// pr(colno[0]);pr(colno[1]);prln(colno[2]);


		add_constraintex(lp, rnum, sparserow, colno, LE, edge[i].c*1.0+INF);
		sparserow[0] = -INF;
		add_constraintex(lp, rnum, sparserow, colno, GE, edge[i].c*1.0-INF);
	}
	colno[0] = edgenum + 1;
	sparserow[0] = 1;
	add_constraintex(lp, 1, sparserow, colno, EQ, 0);
	set_add_rowmode(lp, FALSE);

	rnum = 0;
	for(int i = 1; i <= edgenum; ++i) {
		int vv = edge[i].v;
		if(ban[vv]) continue;
		int uu = edge[i].u;


		if(ban[uu]) continue;
		colno[rnum] = i;
		sparserow[rnum++] = edge[i].c;
	}
	set_obj_fnex(lp, rnum, sparserow, colno);
	set_minim(lp);
	int snum = 0;
	//snum += (needNum+9) + (cnt+99)/100 + edgenum/1000;
	//set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS |PRESOLVE_LINDEP|PRESOLVE_SOS|PRESOLVE_ELIMEQ2|PRESOLVE_REDUCEMIP|PRESOLVE_IMPLIEDFREE|PRESOLVE_REDUCEGCD|PRESOLVE_PROBEREDUCE |PRESOLVE_ROWDOMINATE|PRESOLVE_COLDOMINATE|PRESOLVE_MERGEROWS|PRESOLVE_BOUNDS|PRESOLVE_DUALS|PRESOLVE_SENSDUALS , get_presolveloops(lp));
	//set_bb_floorfirst(lp,BRANCH_AUTOMATIC);
	//set_improve(lp,IMPROVE_SOLUTION|IMPROVE_THETAGAP| IMPROVE_DUALFEAS | IMPROVE_BBSIMPLEX);
//	set_anti_degen(lp, ANTIDEGEN_FIXEDVARS | ANTIDEGEN_PERTURB);
	/*set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS |PRESOLVE_LINDEP|PRESOLVE_REDUCEMIP|PRESOLVE_KNAPSACK|PRESOLVE_IMPLIEDFREE|PRESOLVE_REDUCEGCD|PRESOLVE_PROBEFIX|PRESOLVE_PROBEREDUCE |PRESOLVE_ROWDOMINATE|PRESOLVE_COLDOMINATE|PRESOLVE_MERGEROWS|PRESOLVE_COLFIXDUAL|PRESOLVE_BOUNDS|PRESOLVE_DUALS|PRESOLVE_SENSDUALS , get_presolveloops(lp));*/
//	set_presolve(lp, PRESOLVE_REDUCEMIP | PRESOLVE_COLS | PRESOLVE_LINDEP, get_presolveloops(lp));
	set_timeout(lp, 18);
	snum = 12;
	set_bb_depthlimit(lp,snum);
	//set_solutionlimit(lp, 1);

 // set_BFP(lp, "bfp_LUSOL");
	//set_scalelimit(lp, 5);
	 //set_scaling(lp,SCALE_DYNUPDATE);
	//  set_mip_gap(lp, TRUE, 1.0e-1);
	 // write_LP(lp, stdout);
	 // set_debug(lp, TRUE);
	//set_print_sol(lp, TRUE);
	     //set_verbose(lp, NEUTRAL);
	int minans = INF;
	// minans = get_presolve(lp);
	minans = solve(lp);
	//minans =  get_objective(lp);
	//prln(minans);

	int ans[edgenum+1+cnt];
	REAL row[edgenum+1+cnt];
	int ansnum = 0;
	int Ncolumns = get_Norig_columns(lp);
	int Nrows = get_Norig_rows(lp);
	for(int i = 0; i <=edgenum; ++i) {
		vis[i] = false;
	}
	//for(int i = 0; i <= 10; ++i) row[i] = 11;
	get_variables(lp, row);
	for(int i = 1; i <= edgenum; ++i){
		row[i-1] = get_var_primalresult(lp, Nrows + i);
	}
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
				result[anscnt++] = edge[i].eid;
				q.push(edge[i].v);
				break;
			}
		}
	}
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
const int maxn = 50000;
const double INF = 6e5;
int hashnode[maxn];
int edgenum;
struct E{
	int u, v, c, eid;
	bool bridge;
	int nxt;
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

int  rnum;
void addedge(int u, int v, int c, int eid) {
	++edgenum;
	edge[edgenum].u = u;
	edge[edgenum].v = v;
	edge[edgenum].c = c;
	edge[edgenum].eid = eid;
	edge[edgenum].bridge = false;
	edge[edgenum].nxt = head1[u];

	uu[edgenum].nxt = head1[u];
	head1[u] = edgenum;

	vv[edgenum].nxt = head2[v];
	head2[v] = edgenum;
}
int needNum;
int sccno[maxn], sccnt, ins[maxn], in[maxn],out[maxn], dfn[maxn], low[maxn], dfnnum,  stk[maxn], top;
void tarjan(int fa, int u) {
    dfn[u] = low[u] = ++dfnnum;
    stk[top++] = u;
    ins[u] = true;
    for(int i = head1[u]; ~i; i = edge[i].nxt) {
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
	tarjan(-1,1);
	for(int i = 1; i <= n; ++i){
		if(!dfn[i]) ban[i] = true;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = head1[i]; ~j; j = edge[j].nxt){
			if(edge[j].bridge){
				int v= edge[j].v;
				in[sccno[v]]++;
				out[sccno[i]]++;
			}
		}
	}
	int ss = sccno[1], tt = sccno[2];
	for(int i = 1; i <= sccnt; ++i)
	{
		int scc = sccno[i];
		if(scc != ss && scc != tt && (in[scc] < 1 || out[scc] < 1)) ban[i] = true;
	}
	for(int i = 1; i <= n; ++i){
		if(ban[i]) bancnt++;
	}
	for(int u = 1; u <= n; ++u){
		for(int i = head1[u]; ~i; i = edge[i].nxt){
			int v = edge[i].v;
			if(ban[u]||ban[v]) banedge++;
		}
	}
}
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
	memset(ban, 0, sizeof ban);
	gettarjan(cnt);



	/*====================华丽的分割线==============================*/
	lprec *lp;
	lp = make_lp(0, edgenum+cnt);
	if(lp == NULL) ret = 1;
	int colno[1+edgenum+cnt];     /* must be 1 more than number of columns ! */
  	REAL sparserow[1+edgenum+cnt]; /* must be the number of non-zero values */
	for(int i = 1; i <= edgenum; ++i) {
		ret = set_binary(lp, i, TRUE);
	}
	for(int i = edgenum+2; i <= edgenum+cnt; ++i) {
		//set_int(lp, i, true);
    	//set_bounds(lp, i, 0,70000);
    	//set_upbo(lp,i,70000);
	}

	 set_add_rowmode(lp, TRUE);
	//条件2
	//除了起点s和终点t意外出度都等于入度
	for(int u = 1; u <= cnt; ++u) {
		if(ban[u]) continue;
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			int vv = edge[i].v;
			if(ban[vv]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = 1;
		}
		for(int i = head2[u]; ~i; i = vv[i].nxt) {
			int uuu = edge[i].u;
			if(ban[uuu]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = -1;
		}
		if(rnum) {
            if(u == 1) add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
			else if(u == 2) add_constraintex(lp, rnum, sparserow, colno, EQ, -1.0);
			else add_constraintex(lp, rnum, sparserow, colno, EQ, 0.0);
		}
	}

	//所有必经点和起点出度为1
	//neednode[++needNum] = 1;
	for(int j = 1; j <= needNum; ++j) {
		int u = neednode[j];
		rnum = 0;
		for(int i = head1[u]; ~i; i = uu[i].nxt) {
			int vv = edge[i].v;
			if(ban[vv]) continue;
			colno[rnum] = i;
			sparserow[rnum++] = 1.0;
		}
		ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
	}


	//终点的入度为1
/*rnum = 0;
	for(int i = head2[2]; ~i; i = vv[i].nxt) {
		int vv = edge[i].u;
		if(ban[vv]) continue;
		colno[rnum] = i;
		sparserow[rnum++] = 1.0;
	}
	ret = add_constraintex(lp, rnum, sparserow, colno, EQ, 1.0);
	*/
	//针对不能存在环，所有边使得两边有差值
	rnum = 3;
	sparserow[0] = INF;sparserow[1] = 1.0;sparserow[2] = -1;
	for(int i = 1; i <= edgenum; ++i) {
		int vv = edge[i].v;
		if(ban[vv]) continue;
		int uu = edge[i].u;
		if(ban[uu]) continue;
		colno[0] = i;
		colno[1] = edge[i].v + edgenum;
		colno[2] = edge[i].u + edgenum;
		sparserow[1] = 1.0;sparserow[2] = -1;
		sparserow[0] = INF;
		// if(colno[1] > colno[2]){
		// 	swap(colno[1],colno[2]);
		// 	swap(sparserow[1],sparserow[2]);
		// }
		// pr(colno[0]);pr(colno[1]);prln(colno[2]);


		add_constraintex(lp, rnum, sparserow, colno, LE, edge[i].c*1.0+INF);
		sparserow[0] = -INF;
		add_constraintex(lp, rnum, sparserow, colno, GE, edge[i].c*1.0-INF);
	}
	colno[0] = edgenum + 1;
	sparserow[0] = 1;
	add_constraintex(lp, 1, sparserow, colno, EQ, 0);
	set_add_rowmode(lp, FALSE);

	rnum = 0;
	for(int i = 1; i <= edgenum; ++i) {
		int vv = edge[i].v;
		if(ban[vv]) continue;
		int uu = edge[i].u;


		if(ban[uu]) continue;
		colno[rnum] = i;
		sparserow[rnum++] = edge[i].c;
	}
	set_obj_fnex(lp, rnum, sparserow, colno);
	set_minim(lp);
	int snum = 0;
	//snum += (needNum+9) + (cnt+99)/100 + edgenum/1000;
	//set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS |PRESOLVE_LINDEP|PRESOLVE_SOS|PRESOLVE_ELIMEQ2|PRESOLVE_REDUCEMIP|PRESOLVE_IMPLIEDFREE|PRESOLVE_REDUCEGCD|PRESOLVE_PROBEREDUCE |PRESOLVE_ROWDOMINATE|PRESOLVE_COLDOMINATE|PRESOLVE_MERGEROWS|PRESOLVE_BOUNDS|PRESOLVE_DUALS|PRESOLVE_SENSDUALS , get_presolveloops(lp));
	//set_bb_floorfirst(lp,BRANCH_AUTOMATIC);
	//set_improve(lp,IMPROVE_SOLUTION|IMPROVE_THETAGAP| IMPROVE_DUALFEAS | IMPROVE_BBSIMPLEX);
//	set_anti_degen(lp, ANTIDEGEN_FIXEDVARS | ANTIDEGEN_PERTURB);
	/*set_presolve(lp, PRESOLVE_ROWS | PRESOLVE_COLS |PRESOLVE_LINDEP|PRESOLVE_REDUCEMIP|PRESOLVE_KNAPSACK|PRESOLVE_IMPLIEDFREE|PRESOLVE_REDUCEGCD|PRESOLVE_PROBEFIX|PRESOLVE_PROBEREDUCE |PRESOLVE_ROWDOMINATE|PRESOLVE_COLDOMINATE|PRESOLVE_MERGEROWS|PRESOLVE_COLFIXDUAL|PRESOLVE_BOUNDS|PRESOLVE_DUALS|PRESOLVE_SENSDUALS , get_presolveloops(lp));*/
//	set_presolve(lp, PRESOLVE_REDUCEMIP | PRESOLVE_COLS | PRESOLVE_LINDEP, get_presolveloops(lp));
	set_timeout(lp, 18);
	snum = 12;
	set_bb_depthlimit(lp,snum);
	//set_solutionlimit(lp, 1);

 // set_BFP(lp, "bfp_LUSOL");
	//set_scalelimit(lp, 5);
	 //set_scaling(lp,SCALE_DYNUPDATE);
	//  set_mip_gap(lp, TRUE, 1.0e-1);
	 // write_LP(lp, stdout);
	 // set_debug(lp, TRUE);
	//set_print_sol(lp, TRUE);
	     //set_verbose(lp, NEUTRAL);
	int minans = INF;
	// minans = get_presolve(lp);
	minans = solve(lp);
	//minans =  get_objective(lp);
	//prln(minans);

	int ans[edgenum+1+cnt];
	REAL row[edgenum+1+cnt];
	int ansnum = 0;
	int Ncolumns = get_Norig_columns(lp);
	int Nrows = get_Norig_rows(lp);
	for(int i = 0; i <=edgenum; ++i) {
		vis[i] = false;
	}
	//for(int i = 0; i <= 10; ++i) row[i] = 11;
	get_variables(lp, row);
	for(int i = 1; i <= edgenum; ++i){
		row[i-1] = get_var_primalresult(lp, Nrows + i);
	}
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
				result[anscnt++] = edge[i].eid;
				q.push(edge[i].v);
				break;
			}
		}
	}
	for (int i = 0; i < anscnt; ++i) {
		record_result(result[i]);
	}

}
>>>>>>> 4901d01dade82e9ddbde37faaa241353454056fa
