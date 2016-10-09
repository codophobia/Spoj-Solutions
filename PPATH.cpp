#include <bits/stdc++.h>
using namespace std;
int prime[100006];
int dis[100000];
int mark[100000];
int find(int p,queue<int> &q)
{
    int i;
    int a[5];
    int b;
    int p1;
    p1 = p;

    for(i = 4; i >= 1; i--) {
        a[i] = p1 % 10;
        p1 = p1 / 10;

    }


    for(i = 1; i <= 9; i++) {
        if(i != a[1]) {
            b = (i*1000)+(a[2]*100)+(a[3]*10)+a[4];
            if(prime[b] == 0 && mark[b] == 0) {
                mark[b] = 1;
                q.push(b);
                dis[b] = dis[p] + 1;
            }
        }
    }

     for(i = 0; i <= 9; i++) {
        if(i != a[2]) {
            b = (a[1]*1000)+(i*100)+(a[3]*10)+a[4];
            if(prime[b] == 0 && mark[b] == 0) {
                    mark[b] = 1;
                    q.push(b);
                    dis[b] = dis[p] + 1;

            }
        }
    }

     for(i = 0; i <= 9; i++) {
        if(i != a[3]) {
            b = (a[1]*1000)+(a[2]*100)+(i*10)+a[4];
            if(prime[b] == 0 && mark[b] == 0) {
                mark[b] = 1;
                q.push(b);
                dis[b] = dis[p] + 1;
            }
        }
    }

     for(i = 0; i <= 9; i++) {
        if(i != a[4]) {
            b = (a[1]*1000)+(a[2]*100)+(a[3]*10)+i;
            if(prime[b] == 0 && mark[b] == 0) {
                mark[b] = 1;
                q.push(b);
                dis[b] = dis[p] + 1;
            }
        }
    }





}
void bfs(int s,int b)
{
    queue<int> q;
    q.push(s);
    int flag;
    flag = 0;


    while(!q.empty()) {
        s = q.front();
        q.pop();
        if(s == b) {
            cout<<dis[s]<<endl;
            flag = 1;
            break;
        }
        find(s,q);


}
if(flag == 0) {
    cout<<"Impossible"<<endl;
}
}
void sieve()
{
    int i;
    int j;
    prime[1] = 1;

    for(i = 2; i <= sqrt(100005);i++) {
        if(prime[i] == 0) {
            for(j = i * i; j < 100005; j = j + i) {
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    int t;
    int a;
    int b;
    int i;
    int p;
    int flag;
    sieve();


    scanf("%d",&t);

    while(t--) {
        for(i = 999; i < 100000;i++) {

            dis[i] = 0;
            mark[i] = 0;
        }
        

        scanf("%d%d",&a,&b);
        bfs(a,b);
    }
}











