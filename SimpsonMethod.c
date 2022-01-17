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
	printf("Alt sinir : ");
	scanf("%lf",&a);
	printf("Ust sinir : ");
	scanf("%lf",&b);
	
	printf("\n\nAralik sayisini giriniz (bu yontem icin cift sayi olmalidir) : ");
	scanf("%d",&n);
	
	double h,y0,yn,y,S1,S2,S3,S,top=0,c;
	
	h = (b-a)/n;
	y0 = fonk(a,F,D);
	yn = fonk(b,F,D);
	S1 = fabs(y0)+fabs(yn);
	
	
	for(i=1;i<n;i=i+2){
		c = a+(i*h);
		y= fonk(c,F,D);
		top = top+fabs(y);
	}
	
	S2 = top*4;
	top=0;
	
	for(i=2;i<n-1;i=i+2){
		c = a+(i*h);
		y= fonk(c,F,D);
		top = top+fabs(y);
	}
	
	S3 = top*2;
	S  = (S1+S2+S3)*h/3;
	
	printf("\n\nDenkleminizin [a,b] araliginda sectiginiz aralik sayisina bagli integral degeri : %lf",S);
	
	return 0;
}
