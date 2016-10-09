#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
//psyduck
#define ll long long
#define S(x) scanf("%d",&x)
#define Sf(x) scanf("%f",&x)
#define Slf(x) scanf("%lf",&x)
#define Sl(x) scanf("%lld",&x)
#define P(x)  printf("%d\n", x)
#define Pf(x)  printf("%f\n", x)
#define Plf(x)  printf("%lf\n", x)
#define Pl(x)  printf("%lld\n", x)
#define mem(x,i) memset(x,i,sizeof(x))
#define initial 1
#define visited 2
#define INF 100000000
using namespace std;
typedef  pair<int,pair<int,int> > pairdef;
int state[10][10];
int dis[10][10];
int x[] = {1,2,2,1,-1,-2,-2,-1};
int y[] = {2,1,-1,-2,-2,-1,1,2};
void djikstra(pair<int,int>source,pair<int,int>destination);
priority_queue<pairdef, vector<pairdef>, greater<pairdef> >pq;
int main()
{
    int sx,sy,dx,dy;
    pair<int,int>source,destination;
    while(scanf("%d%d%d%d",&source.first,&source.second,&destination.first,&destination.second) > 0){;
    djikstra(source,destination);
    }
}
void djikstra(pair<int,int>source,pair<int,int>destination){
    int i,j,ax,ay;
    pairdef p;
    pair<int,int>current,tmp;
    for(i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            state[i][j] = initial;
            dis[i][j] = INF;
        }
    }
    dis[source.first][source.second] = 0;
    pq.push(pairdef(0,source));
    while(!pq.empty()){
        p = pq.top();
        current = p.second;
        pq.pop();
        if(current == destination){
            cout << dis[current.first][current.second]<<endl;
            break;
        }
       // cout << current.first <<" "<<current.second<<endl;
        state[current.first][current.second] = visited;
        for (i = 0; i < 8; i++){
            ax = current.first + x[i];
            ay = current.second + y[i];
            if(ax < 8 && ay < 8 && ax >= 0 && ay >= 0 && state[ax][ay] == initial){
                    //cout << ax<<" "<<ay<<endl;
                if(dis[current.first][current.second] + (((current.first)*(ax))+((current.second)*(ay))) < dis[ax][ay]){
                    dis[ax][ay] = dis[current.first][current.second] + (((current.first)*(ax))+((current.second)*(ay)));
                    pq.push(make_pair(dis[ax][ay],make_pair(ax,ay)));
                }
            }
        }
    }
}
