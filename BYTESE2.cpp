#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct fnc {
    int atime;
    int dtime;

};
fnc t[105];
int compare(fnc x,fnc y)
{
   return(x.atime < y.atime);
}

int main()
{

    int c;


    int i;
    int max;
    int j;
    int temp1;
    int temp2;
    int n;
    int count;

    scanf("%d",&c);

    while(c--) {
        scanf("%d",&n);
        count = 1;
        max = 1;

        for(i = 0; i < n; i++) {
            scanf("%d",&(t[i].atime));
             scanf("%d",&t[i].dtime);
        }



        sort(t,t + n,compare);









        for(i = 1; i < n; i++) {
            for(j = i - 1; j >= 0; j--) {
                    if(t[j].dtime <= t[i].atime && t[j].dtime != 0) {
                        count--;
                        t[j].dtime  = 0;

                    }




            }

            count++;

            if(count > max) {
                max = count;
            }
        }

        printf("%d\n",max);








    }

    return 0;
}

