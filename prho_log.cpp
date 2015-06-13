 #include <stdio.h>
 
 const int n = 126, N = n + 1;  /* N = 1019 -- prime     */
 const int alpha = 3;            /* generator             */
 const int beta = 50;             /* 2^{10} = 1024 = 5 (N) */
 
 void new_xab( int& x, int& a, int& b ) {
   switch( x%3 ) {
   case 0: x = x*x     % N;  a =  a*2  % n;  b =  b*2  % n;  break;
   case 1: x = x*alpha % N;  a = (a+1) % n;                  break;
   case 2: x = x*beta  % N;                  b = (b+1) % n;  break;
   }
 }

 /*void new_xab(int& x, int& a, int& b){
	int bound = N/3;
	x = x+3 / 3;

	if(x < bound && x >= 1){
   		x = x*x     % N;  a =  a*2  % n;  b =  b*2  % n;
	}else if(x > bound && x <= (2*bound)){
   		x = x*alpha % N;  a = (a+1) % n;            
	}else if(x > (2*bound) && x <= n){
   		x = x*beta  % N;                  b = (b+1) % n; 
	}
 }*/
  
 int main(void) {
   char hi   = "hi";
   char test = "test";
   
   int x=1, a=0, b=0;
   int X=x, A=a, B=b;
   for(int i = 1; i < n; ++i ) {
     new_xab( x, a, b );
     new_xab( X, A, B ); new_xab( X, A, B );
     printf( "%3d  %4d %3d %3d  %4d %3d %3d\n", i, x, a, b, X, A, B );
     if( x == X ){
		printf("x is %d\n", x);
		break;
	 }
   }
   return 0;
 }
