#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> type;
typedef pair<double,int> pos;

void dij(vector<type > v[],int root,int n,double plen[],int vis[])
{

    priority_queue<pos, vector<pos > >  pq;
    pos t;

    int ve;
    int u;
    double w;
    int i;
    double d;

    for(i = 1; i <= n; i++) {
        plen[i] = 0;
        vis[i]= 0;
    }

    plen[root] = 1;
    pq.push(pos (1,root));

    while(!pq.empty()) {

        t = pq.top();
        u = t.second;
        d = t.first;
        pq.pop();
        vis[u] = 1;








        for(i = 0; i < v[u].size();i++) {
            ve = v[u][i].first;
            w = v[u][i].second / 100.0;


            if(vis[ve] == 0) {
            if(plen[ve] < plen[u] * w) {
                 plen[ve] = plen[u] * w;
                 //cout<<u<<' '<<ve<<' '<<plen[ve]<<endl;
                 pq.push(pos (plen[ve],ve));

            }
            }
        }



    }
}
int main()
{
    int t;
    int m;
    int e;
    type d,k;
    int i;
    int n;
    int s;
    int count;
    count = 0;


    while(1) {
    scanf("%d",&n);
    if(n == 0) {
        break;
    }
    scanf("%d",&m);

    vector<type > v[n+5];
    double plen[n+5];
    int vis[n+5];
    int j;



    for(i = 0; i < m; i++) {
        scanf("%d%d%d",&s,&d.first,&d.second);
        v[s].push_back(d);
        k.first = s;
        k.second = d.second;
        v[d.first].push_back(k);
    }




    dij(v,1,n,plen,vis);

    printf("%.6lf percent\n",plen[n]*100);







    }

    return 0;

}


