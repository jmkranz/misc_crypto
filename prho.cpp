#include <stdio.h>
#include <stdlib.h>

int function(int x){
	int c = 1;

	return (x*x + c);
}

int gcd(int u, int v){
	while(v != 0){
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}

int prho(int n){
	int x, y, c;

	x = 2;
	y = 2;

	while(1){
		x = function(x) % n;
		y = function(function(y)) % n;
		c = gcd(y-x,n);

		printf("x is %d, y is %d, c is %d\n", x, y, c); 
		
		if(c > 1 && c < n){	
			return c;
		}

		if(c == n){
			printf("FAILURE\n");
			return -1;
		}
	}
}

int main(){
	int n = 94134947;
	int p = prho(n);
	
	if(p == -1)
		printf("COULD NOT FACTOR\n");
	else{
		int q = n / p;
		printf("%d factors as %d x %d\n", n, p, q);
	}

}
