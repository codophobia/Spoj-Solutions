#include <bits/stdc++.h>
using namespace std;
int bsearch(int array[], int number_of_elements, int key)
{
        int low = 0, high = number_of_elements-1, mid;
        while(low <= high)
        {
                mid = (low + high)/2;
                if(array[mid] < key)
                {
                        low = mid + 1;
                }
                else if(array[mid] == key)
                {
                        return mid;
                }
                else if(array[mid] > key)
                {
                        high = mid-1;
                }

        }
        return -1;
}
int main()
{
    int n;
    int m;
    int a[10005];
    int b[10005];
    int i;
    int j;
    int sum1;
    int sum2;
    int total;
    int start;
    int found;

    while(1) {
        scanf("%d",&n);
        if(n == 0) {
            break;
        }
        sum1 = 0;
        sum2 = 0;
        start = 0;
        total = 0;

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        for(i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        scanf("%d",&m);
        int j;
        int s;
        s = 0;


        for(i = 0; i < m; i++) {
            scanf("%d",&b[i]);
        }

        i = 0;

        while(i < n || s < m) {
            sum1 = sum1 + a[i];

            sum2 = sum2 + b[s];



            found = bsearch(b,m,a[i]);
            if(found != -1) {
                sum2 = 0;
                for(j = start; j <= found;j++) {
                    sum2 = sum2 + b[j];
                }
                //cout<<found<<endl;
                start = found + 1;
                s = found;

                if(sum1 > sum2) {
                    total = total + sum1;
                }
                else {
                    total = total + sum2;
                }
                sum1 = 0;
                sum2 = 0;
            }
            s++;
            i++;
        }
        //cout<<sum1<<' '<<sum2<<endl;

         if(sum1 > sum2) {
            total = total + sum1;
         }

        else {
            total = total + sum2;
        }
         cout<<total<<endl;





    }
}
