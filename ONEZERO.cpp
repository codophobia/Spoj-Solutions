#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> type;
int vis[20005];
void bfs(int n)
{
    queue<type > q;
    type t,t1,t2;
    int i;

    for(i = 0; i < 20005; i++) {
        vis[i] = 0;
    }
    t.first.append("1");
    t.second = 1 % n;
    vis[t.second] = 1;
    q.push(t);

    while(!q.empty()) {
        t = q.front();

        if(t.second == 0) {
            cout<<t.first<<endl;
            break;
        }
        q.pop();

        vis[t.second] = 1;

        t1 = t;
        t2 = t;

        t1.first.append("0");
        t1.second = ((t.second)*10) % n;
        //cout<<t1.first<<' '<<t1.second<<endl;

        t2.first.append("1");
        t2.second = (t.second*10 + 1) % n;
        //cout<<t2.first<<' '<<t2.second<<endl;

        if(vis[t1.second] == 0) {
            q.push(t1);
        }
        if(vis[t2.second] == 0) {
            q.push(t2);
        }

    }

}

int main()
{
    int t;
    int n;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        bfs(n);
    }
}
