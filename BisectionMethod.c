#include<stdio.h>
#include<math.h>

#define SIZE 100

int main(){
	
	double a,b,D,F[SIZE],eps;
	
	
	printf("Denkleminizin derecesini giriniz : ");
	scanf("%lf",&D);
	
	int i;
	printf("\nDenklemin katsayilarini en buyuk dereceli katsayidan baslayarak giriniz\n");
	for(i=0;i<=D;i++){
		scanf("%lf",&F[i]);
	}
	
	printf("\nX1 degerini giriniz : ");
	scanf("%lf",&a);
	
	printf("X2 degerini giriniz : ");
	scanf("%lf",&b);
	
	printf("\nEpsilon degerini giriniz : ");
	scanf("%lf",&eps);
	
	int n;
	
	printf("\nMaksimum iterasyon sayisini giriniz : ");
	scanf("%d",&n);
	
	double Fa,Fb,top,x;
	x=D;
	for(i=0;i<=D;i++){
		top=F[i]*(pow(a,x));
		Fa=Fa+top;
		x=x-1;
	}
	x=D;
	for(i=0;i<=D;i++){
		top=F[i]*(pow(b,x));
		Fb=Fb+top;
		x=x-1;
	}
	x=D;
	
 	double muteps=1; //işlem sırasında kontrol edilen epsilon değerin mutlak değeri
 	double c,Fc;     
 	
 	printf("\nAdim\tX1\t    F(x1)\tX2\t    F(x2)\t X3\t     F(x3)      Eps\n");
 	printf("1       %lf    %lf    %lf    %lf    0.000000    0.000000   0.000000\n",a,Fa,b,Fb);
 	
 	int k=1,sayac=1;
 	if(Fa*Fb<0){
 		while(muteps>eps  && sayac<n){
 			c=(a+b)/2;

 			for(i=0;i<=D;i++){
 				top=F[i]*(pow(c,x));
 				Fc=Fc+top;
 				x=x-1;
			 }
			 x=D;

			if(Fa*Fc<0){
			 	b=c;
			}
			else{
			 	a=c;
			}
			muteps=fabs(a-b);
			sayac=sayac+1;
			
			printf("%d       %lf    %lf    %lf    %lf    %lf    %lf   %lf\n",sayac,a,Fa,b,Fb,c,Fc,muteps);
			 
			Fc=0;	 
		}
		if(sayac<n){
			printf("\nDenklemin koku : %lf",a);
		}
	 }
	else if(Fa*Fb==0){
		if(Fa==0){
			printf("\nDenklemin koku : %lf",a);
		}
		else{
			printf("\nDenklemin koku : %lf",b);
		}
	}
	else{
		printf("Bu aralikta kok bulunmamakta veya sectiginiz aralik cok buyuk");
	}
	
	
	getch();
	return 0;
}
