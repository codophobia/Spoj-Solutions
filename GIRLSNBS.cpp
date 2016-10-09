#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int b;
    int ans;

    while(1) {
        scanf("%d%d",&a,&b);

        if(a == -1 && b == -1) {
            break;
        }

        if(a < b) {
            swap(a,b);
        }



        

        if(a == 0 && b == 0) {

            printf("0\n");
        }
        else if(a == b) {
            printf("%d\n",1);
        }
        else {

            ans = ceil((double)a / (double)(b+1));
            printf("%d\n",ans);


        }



        }


    return 0;
}
