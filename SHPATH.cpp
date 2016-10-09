#include <bits/stdc++.h>
using namespace std;
#define max 100000000;
vector< pair<int,int> > v[10005];
int plen[10005];
int vis[10005];

void dij(int root)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pair<int,int> t;
    int ve;
    int u;
    int w;
    int i;
    int d;

    plen[root] = 0;
    pq.push(pair<int,int> (0,root));

    while(!pq.empty()) {

        t = pq.top();
        u = t.second;
        d = t.first;
        pq.pop();

        if(vis[u]) {
            continue;
        }

        vis[u] = 1;




        for(i = 0; i < v[u].size();i++) {
            ve = v[u][i].first;
            w = v[u][i].second;


            if(plen[ve] > plen[u] + w) {
                 plen[ve] = plen[u] + w;
                 pq.push(pair<int,int> (plen[ve],ve));
            }
        }

    }


}
int main()
{
    int i;
    pair<int,int> d;
    int s;
    int n;
    int e;
    int t;
    int p;
    int q;
    char c[50];
    char start[50];
    char end[50];
    map<string,int> m;

    scanf("%d",&t);


    while(t--) {
    scanf("%d",&n);
    for(i = 1; i <= n; i++) {
            v[i].clear();
        }


    m.clear();
    for(i = 1; i <= n; i++){

    scanf("%s",c);
    m[c] = i;
    scanf("%d",&p);
    while(p--) {
        scanf("%d%d",&d.first,&d.second);
        v[i].push_back(d);
    }
    }

    scanf("%d",&q);

    while(q--) {
        scanf("%s%s",start,end);
        for(i = 1; i <= n; i++) {
            plen[i] = max;
            vis[i] = 0;

        }
        dij(m[start]);
        printf("%d\n",plen[m[end]]);




    }
    }

    return 0;
}













