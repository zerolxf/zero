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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
struct Node
{
	int l, r;
	bool operator <(const Node& rhs)const{
		return l < rhs.l || (l == rhs.l && r < rhs.r);
	}
}a[maxn],b[maxn];
bool cmpmin(const Node& a1,const Node& a2){
    return a1.r < a2.r || (a1.r==a2.r&&a1.l<a2.l);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, l, pos, lpos, k;
    while(cin >> n >> l) {
    	for(int i = 0; i < n; ++i) {
    		scanf("%d%d", &a[i].l, &a[i].r);
    	}
    	sort(a, a+n);
    	for(int i = 0; i < l; ++i) {
    		scanf("%d%d", &b[i].l, &b[i].r);
    	}
    	sort(b,b+l);
        Node temp = {0,INF};
        priority_queue<int,vector<int>,greater<int> > q;
        int ans = 0;lpos = 0;
        int num;
        for(int i = 0; i < l; ++i) {
            temp.l = b[i].l;
            num = b[i].r;
            k = b[i].l;
            pos = upper_bound(a,a+n,temp) - a;
            //pr(pos);prln(lpos);
            for(int j = lpos; j < pos; ++j) {
                q.push(a[j].r);
                //pr(a[j].r);
            } 
            lpos = pos;
            while(num){
                while(q.size()) {
                    int x = q.top();
                    if(x < k) {
                        q.pop();
                       // pr(x);
                    }
                    else break;
                }
                if(q.size()) {
                    //Node x = q.top();
                    q.pop();
                    num--;++ans;
                }
                if(q.empty()) {
                    num = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}