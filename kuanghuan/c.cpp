/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 09时30分28秒
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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
struct Node{
    string name;
    int num;
    bool operator < (const Node& rhs)const{
        return name < rhs.name;
    }
    bool operator == (const Node& rhs)const{
        return name == rhs.name;
    }
    Node(){}
    Node(string x, int y){
        name = x;
        num = y;
    }
}a[maxn], b[maxn];
vector<Node> file, folder;
typedef pair<int,int> C;
map<string,C> aa, bb;
typedef set<string> D;
map<string,D> E,F;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    string str, ss;
        file.clear();
        folder.clear();
        int ans1 = 0, ans2 = 0;
        int cnta = 0;
        int cntb = 0;
        aa.clear();
        bb.clear();
        E.clear();
        F.clear();
    while(cin >> str){
        //prln(str);

        ss = "";
        int num = 0;
        int len = str.size();
        string temp ="" ;
        string xx = "\\\\";
        int x = xx[0];
        //cout << x << "\n";
        for(int i = 0; i < len; ++i){
            temp += str[i];
            if(i == len-1&&num>=2){
                //if(num<2) continue;
                //b[cntb++] = Node(temp, num);
                E[ss].insert(temp);
                //prln(ss);
                //file.push_back(Node(temp,num));
                continue;
            }
            if(str[i+1] == 92&&num>=2){
                //if(num<2) continue;
                //a[cnta++] = Node(temp, num);
                F[ss].insert(temp);
                //prln(ss);
                //folder.push_back(Node(temp, num));
            }
            if(str[i] == 92) num++;
            //pr(num);prln(str[i+1]);
            //prln(str[i]);
            if(num == 1 && str[i+1] == 92){
                ss = temp;
                //prln(ss);
            }
        }
    }
    
    //int ans1 = 0, ans2 = 0;
    for(auto itr:F){
        int x = itr.second.size();
        //prln(itr.first);
        ans1 = max(ans1, x);
    }
    for(auto itr:E){
        int x = itr.second.size();
        //prln(itr.first);
        ans2 = max(ans2, x);
    }
    //if(aa.count(ss) == 0) aa[ss] = C(0,0);
    //ans1 = 0, ans2 = 0;
    //sort(a, a+cnta);
    //cnta = unique(a, a+cnta) - a;
    //sort(b, b+cntb);
    //cntb = unique(b, b+cntb) - b;
    //for(int i = 0; i < cnta; ++i){
        //if(a[i].num < 2) continue;
        //ans1++;
    //}
    //for(int i = 0; i<cntb; ++i)
    //{
        //if(b[i].num < 3) continue;
        //ans2++;
    //}
    cout << ans1 << " " << ans2 << "\n";

	return 0;
}
