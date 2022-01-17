#include<math.h>
#include<stdio.h>

#define  SIZE 100

int main(){
	
	double D,F[SIZE],x;
	
	printf("Denkleminizin derecesini giriniz : ");
	scanf("%lf",&D);
	
	int i;
	printf("\n\nDenklemin katsayilarini en buyuk dereceli katsayidan baslayarak giriniz :\n");
	for(i=0;i<=D;i++){
		scanf("%lf",&F[i]);
	}
	
	printf("\nx degerini giriniz : ");
	scanf("%lf",&x);
	
	double H1=0,H2=0,a,top;
	a=D;
	x=x-0.00000001;
	
	
	for(i=0;i<=D;i++){
		top=F[i]*(pow(x,a));
		H1=H1+top;
		a=a-1;
	}
	
	a=D;
	x=x+0.00000002;
	
	for(i=0;i<=D;i++){
		top=F[i]*(pow(x,a));
		H2=H2+top;
		a=a-1;
	}
	
	double f;
	f=(H2-H1)/0.00000002;
	printf("\nF'(x) = %0.3lf",f);

	return 0;
}
