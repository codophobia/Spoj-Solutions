
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
struct point1
{
    int x;
    int y;
};

struct point2
{
    int x;
    int y;
    int p;
};

int possible(int x1,int y1,int x2,int y2,int r)
{
    double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    d = sqrt(d);

    if(d <= r) {
            //printf("possible\n");
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    point1 r[30];
    point2 s[105];

    int rd;
    int c;
    int i;
    int k;
    int psum;
    psum = 0;

    int n;
    int m;




    scanf("%d%d",&c,&rd);
    scanf("%d",&m);

    

    for(i = 0; i < m; i++) {
        scanf("%d%d",&r[i].x,&r[i].y);
    }

    scanf("%d",&n);
    int b[n + 5];

    int sum;
    int max;
    int j;

    for(i = 0; i < n; i++) {
        scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].p);
        psum = psum + s[i].p;
    }
    max = 1;

    for(i = 1; i < pow(2,m); i++) {
        if(__builtin_popcount(i) == c) {
                sum = 0;

            memset(b,0,sizeof(b));

            for(j = 0; j < m; j++) {
                if(i & (1 << j)) {
                   for(k = 0; k < n; k++) {

                        if(possible(r[j].x,r[j].y,s[k].x,s[k].y,rd)) {
                           // printf("r = %d %d s =  %d %d\n",r[j].x,r[j].y,s[k].x,s[k].y);
                            if(b[k] != -1) {
                               // printf("%d %d\n",s[k].x,s[k].y);
                            sum = sum + s[k].p;
                            b[k] = -1;
                        }
                        }
                   }
                }
            }
            

                if(sum > max) {
                max = sum;
            }
            if(sum == psum) {
            	break;
            }
            }
    }

    printf("%d\n",max);
}

