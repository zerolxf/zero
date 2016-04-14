#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#include<strstream>
#include<sstream>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
char ss[maxn][100];
vector<string> s;
bool ok1(int pos, vector<string>& ans) {
    int l = max(pos - 2,0), r = min(pos+1,(int)(ans.size()-1));
    for(int i = l; i < pos; ++i) {
        if(ans[i] == "jiggle") return true;
    }
    for(int i = pos+1; i <= r; ++i) {
        if(ans[i] == "twirl") return true;
    }
    ans[pos] = "DIP";
    return false;
}
bool ok2() {
    int pos = s.size() ;
    if(pos < 3) return false;
    if(s[pos-2] == "stomp" && s[pos-1] == "clap" && s[pos-3] == "clap") return true;
    return false;
}
bool ok3() {
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == "hop") flag1 = true;
        if(s[i] == "twirl") flag2 = true;
    }
    if(flag2 && !flag1) return false;
    return true;
}
bool ok4() {
    int pos = min(0, (int)(s.size() - 1));
    if(pos < 0) return true;
    if(s[pos] == "jiggle") return false;
    return true;
}
bool ok5() {
    bool flag = false;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == "dip" || s[i] == "DIP") flag = true;
    }
    return flag;
}
void print(vector<string>& ans){
    for(int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << "\n";
}
bool vis[10];
//char str[maxn*10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    string  temp,str;
    while(getline(cin,str)) {
        stringstream ss(str);
        s.clear();
        while(ss >> temp) {
            s.push_back(temp);
        }
        vector<int> ans;
        for(int i = 0; i < 6; ++i) vis[i] = false;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == "dip" && !ok1(i,s))  vis[1] = true;
        }
        if(!ok2()) vis[2] = true;
        if(!ok3()) vis[3] = true;
        if(!ok4()) vis[4] = true;
        if(!ok5()) vis[5] = true;
        for(int i = 1; i < 6; ++i) {
            if(vis[i]) ans.push_back(i);
        }
        if(ans.size() == 0) {
                cout << "form ok: " ;print(s);
        }
        else {
            if(ans.size() == 1) {
                printf("form error %d: ",ans[0]);
                print(s);
            } else {
                printf("form errors %d",ans[0]);
                int l = 1, r = ans.size() - 2;
                for(int i = l; i <= r; ++i) {
                    printf(", %d",ans[i]);
                }
                printf(" and %d: ",ans[ans.size()-1]);
                print(s);
            }
        }
    }
    return 0;
}
