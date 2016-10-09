#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> type;
void dij(vector<type > v[],int root,int n,int plen[])
{

    priority_queue<type, vector<type >, greater<type > >  pq;
    type t;
    int ve;
    int u;
    int w;
    int i;
    int d;

    for(i = 1; i <= n; i++) {
        plen[i] = 10000000;
    }

    plen[root] = 0;
    pq.push(type (0,root));

    while(!pq.empty()) {

        t = pq.top();
        u = t.second;
        d = t.first;
        pq.pop();




        for(i = 0; i < v[u].size();i++) {
            ve = v[u][i].first;
            w = v[u][i].second;


            if(plen[ve] > plen[u] + w) {
                 plen[ve] = plen[u] + w;
                 pq.push(type (plen[ve],ve));
            }
        }

    }
}
int main()
{
    int t;
    int m;
    int e;
    type d;
    int i;
    int n;
    int s;
    int count;
    count = 0;


    scanf("%d%d%d",&n,&e,&t);
    scanf("%d",&m);

    vector<type > v[n+5];
    int plen[n+5];



    for(i = 0; i < m; i++) {
        scanf("%d%d%d",&s,&d.first,&d.second);
        v[s].push_back(d);
    }



    for(i = 1; i <= n; i++) {
        dij(v,i,n,plen);
        if(plen[e] <= t) {
            count++;
        }
    }

    printf("%d\n",count);

    return 0;

}


