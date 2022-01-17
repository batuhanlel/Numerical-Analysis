#include<stdio.h>
#include<math.h>
#define SIZE 100

double fonk(double x,double dizi[],int size){
	double Y=0,top=0;
	int i,a;
	
	a = size;
	for(i = 0; i <= size; i++){
		top = dizi[i] * pow(x,a);
		Y = Y + top;
		a -= 1;
	}
	
	return Y;
}



int main(){
	
	double F[SIZE],a,b;
	int D,n;
	
	printf("Denkleminizin derecesini giriniz : ");
	scanf("%d",&D);
	
	int i;
	printf("\n\nDenklemin katsayilarini en buyuk dereceli katsayidan baslayarak giriniz\n");
	for(i=0;i<=D;i++){
		scanf("%lf",&F[i]);
	}
	
	printf("\nIntegralini almak istediginiz araligin degerlerini giriniz [a,b]\n\n");
	printf("Alt siniri giriniz : ");
	scanf("%lf",&a);
	printf("Ust siniri giriniz : ");
	scanf("%lf",&b);
	
	printf("\n\nIntegraliniz kac adet dortgen kullanarak hesaplansin : ");
	scanf("%d",&n);
	
	double h,y0,yn,y,S1,S2,S,top;
	top=0;
	h=(b-a)/n;
	
	y0 = fonk(a,F,D);
	yn = fonk(b,F,D);
	y0 = fabs(y0);
	yn = fabs(yn);
	S1 = ((y0+yn)/2)*h;
	
	
	double c;
	for(i=1; i<n ; i++){
		c = a+(i*h);
		y= fonk(c,F,D);
		top = top+fabs(y);
	}
	
	S2 = top*h;
	
	
	S = S1+S2;
	
	printf("\n\nDenkleminizin [a,b] araliginda sectiginiz dortgen sayisina bagli integral degeri : %lf",S);

	return 0;
}
