#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int link[200][200], n, num;
int work(int x, int y){
	if(link[x][y]) return 0;
	if(link[y][x]) return -1;
	link[x][y] = 1;
	num++;
	prln(num);
	int flag = 1;
	prln(n);
	for(int i = 0; i < n; ++i) {
		pr(i);pr(x);prln(y);
		if(i==x||i==y) continue;
		prln("lxf");
		pr(i);pr(x);pr(y);pr(link[i][x]);prln(link[i][y]);
		if(link[i][x]&&!link[i][y]) {
			flag = 1;
			if(work(i,y)==-1) return -1;
		}
		if(link[i][x]&&link[y][i]) {
			return -1;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(i==x||i==y) continue;
		if(link[y][i]&&!link[x][i]) {
			flag = 1;
			if(work(x,i)==-1) return -1;
		}
		if(link[y][i]&&link[i][x]) {
			return -1;
		}
	}
	return flag;
}
int vis[maxn];
queue<int> q;
bool dfs(int u) {
	vis[u] = -1;
	for(int i = 0; i < n;++i) {
		if(i==u) continue;
		if(link[u][i]) {
			if(vis[i] < 0) return false;
			if(vis[i] > 0 && !dfs(i)) return false;
		}
	}
	vis[u] = 1;
	q.push(u);
	return true;
}
struct Node
{
	int id, sum;
	bool operator < (const Node& rhs)const{
		return sum > rhs.sum;
	}
};
vector<Node> ch;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m;
    char x[10],s[10],y[10];
    while(scanf("%d%d", &n,&m) !=EOF &&(n||m)) {
    	memset(link,0,sizeof link);
    	//getchar();
    	ch.clear();
    	int ans = 0, haveans, flag;
    	haveans = 0;
    	num = 0;
    	bool huan = false;
    	for(int i = 1; i <= m; ++i) {
	    	scanf("%s", s);
	    	if(huan) continue;
	    	prln(s);
	    	flag = work(s[0]-'A',s[2]-'A');
	    	if(flag == 0) continue;
	    	if(haveans) continue;
	    	if(num==n*(n-1)/2&&!haveans) {
	    		haveans = 1;
	    		ans = i;
	    		continue;
	    	}
	    	ans = i;
	    	if(flag == -1) huan = true; 
	    }
	    while(q.size()) q.pop();
	    if(huan) {
	    	printf("Inconsistency found after %d relations.\n",ans);
	    } else {
	    	pr(num);prln(n);
	    	if(num==n*(n-1)/2) {
	    		printf("Sorted sequence determined after %d relations: ",ans);
	    		for(int i = 0; i < n; ++i) {
	    			int sum = 0;
	    			for(int j = 0; j < n; ++j) {
	    				sum +=link[i][j];
	    			}
	    			ch.push_back(Node{i,sum});
	    		}
	    		sort(ch.begin(),ch.end());
	    		for(int i = 0; i < ch.size(); ++i) {
	    			printf("%c",ch[i].id+'A');
	    		}
	    		printf(".\n");
	    	} else {
	    		printf("Sorted sequence cannot be determined.\n");
	    	}

	    }
    }
    return 0;
}