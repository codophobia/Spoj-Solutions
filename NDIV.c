#include <stdio.h>
#include <string.h>
int prime[10000];
int check[32000];

void sieve() {
	memset(check,0,sizeof(check));
	int i;
	int j;
	int k;
	
	for(i = 3; i <= 180; i= i + 2) {
		if(check[i] != 1) {
			for(j = i * i; j <= 32000;j = j + i) {
				check[j] = 1;
			}
		}
	}
	prime[0] = 2;
	k = 1;
	for(i = 3; i <= 32000; i = i + 2) {
		if(check[i] == 0) {
			prime[k] = i;
	
			k++;
			
		}
	}
}

int nodiv(int n) {
	
	
	int i;
	int k = 0;
	int count;
	int total;
	
	total = 1;
	for(i = prime[k]; i * i <= n; i = prime[k++]) {
		count = 0;
		while(n % i == 0) {
			count++;
			n = n / i;
		}
		total = total * (count + 1);
	}
	if(n != 1) {
		total = total * 2;
	}
	
		return total;
	
}
	
	
int main(void) {
	sieve();
	long int a;
	long int b;
	int n;
	long int i;
	int count;
	count = 0;
	scanf("%ld %ld %d",&a,&b,&n);
	
	for(i = a; i <= b; i++) {
		if(nodiv(i) == n) {
			count++;
		}
	} 
	
	printf("%d\n",count); 
	return 0;
}
