#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int state[100005];
void bfs(int s)
{
    int i;
    queue<int> q;
    q.push(s);
    state[s] = 1; //waiting state


    while(!q.empty()) {
        s = q.front();
        q.pop();
        state[s] = -1; //visited
        //cout<<s<<' ';

        for(i = 0; i < v[s].size(); i++) {
            if(state[v[s][i]] == 0) {
                q.push(v[s][i]);
                state[v[s][i]] = 1; // waiting
            }

        }
    }


}
int main()
{

    int e; //total number of edges
    int i;
    int s;
    int d;
    int n;
    int t;
    int st; //starting vetex for traversal
    int count;
    int b[100005];
    //int state[100005];

    scanf("%d",&t);



    while(t--) {
    count = 0;

    memset(state,0,sizeof(state));
    memset(b,0,sizeof(b));

    scanf("%d",&n);
    scanf("%d",&e);

    //vector<int> v[e+5];

    for(i = 0; i < e; i++) {
        scanf("%d%d",&s,&d);

        v[s].push_back(d);
        v[d].push_back(s);
    }

    for(i = 0; i < n; i++) {
        if(state[i] == 0) {
            count++;
            bfs(i);
        }
    }

    printf("%d\n",count);

    for(i = 0; i < n; i++) {
        v[i].clear();
    }







    }




}
















