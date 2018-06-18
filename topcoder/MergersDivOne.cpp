
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
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
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int INF = 1e9+7;
const int maxn = 1e5+100;

class MergersDivOne{
	public: double findMaximum(vector <int> revenues){
		sort(revenues.begin(), revenues.end());
		double ans = 0;
		int sz = revenues.size();
		priority_queue<double, vector <double>, greater<double> > pq;
		for(int i = 0; i < sz; ++i){
			pq.push(revenues[i]);
		}
		while(pq.size() > 1){
			double x= pq.top(); pq.pop();
			double y = pq.top();pq.pop();
			x = (x+y)/2.0;
			pq.push(x);
		}
		ans = pq.top();
		return ans;
	}
};
