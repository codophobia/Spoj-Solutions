#include <stdio.h>
#include <string.h>
 
int gcd(int a, int b) {
	
	if(b == 0) {
		return a;
	}
	
	else {
		return gcd(b,a % b);
	}
}
 
 
int main(void) {
	char b[251];
	int t;
	int a;
	int i;
	int num;
	
	scanf("%d",&t);
	
	while(t--) {
		
		scanf("%d %s",&a,b);
		
		
	if(a == 0) {
		printf("%s\n",b);
		continue;
	}	
	num = 0;
	
	for(i = 0; i < strlen(b); i++) {
		num = (num * 10 + (b[i] - '0')) % a;
	}
	
		printf("%d\n",gcd(a,num));
		
		
		
	}
	return 0;
}
 