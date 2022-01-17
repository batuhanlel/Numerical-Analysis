#include<stdio.h>
#define SIZE 100
#include<math.h>

int main(){
	
	double a,b,c,E,D,F[SIZE];
	
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
	
	printf("\nEpsilon degerini giriniz :");
	scanf("%lf",&E);
	
	int n;
	printf("\nMaksimum iterasyon sayisini giriniz : ");
	scanf("%d",&n);
	
	c=0;
	if(a>b){
		c=b;
		b=a;
		a=c;
	}
	
	double u=D,Fa=0,Fb=0,Fc=0,top1=0,top2=0,muteps=1;
	
	for(i=0;i<=D;i++){
		top1=F[i]*(pow(a,u));
		Fa+=top1;
		
		top2=F[i]*(pow(b,u));
		Fb+=top2;
		
		u-=1;
	}
	u=D;


	printf("\nAdim\tX1\t    F(x1)\t   X2\t    F(x2)\t X3\t     F(x3)      Eps\n");	
 	printf("1       %lf    %lf    %lf    %lf    0.000000    0.000000   0.000000\n",a,Fa,b,Fb);

	int k=1,sayac=1;
	if(Fa*Fb<0){
		while(muteps>E && sayac<n && k==1){
			c=a-(Fa*((b-a)/(Fb-Fa)));
			for(i=0;i<=D;i++){
				top1=F[i]*(pow(c,u));
				Fc+=top1;
				u-=1;
			}
			u=D;
			if(Fa*Fc<0){
				b=c;
				Fb=Fc;
			}
			else if(Fb*Fc<0){
				a=c;
				Fa=Fc;
			}
			else{
				k=0;
			}
			muteps=fabs(Fc);
			sayac+=1;
		
			printf("%d       %lf    %lf    %lf    %lf    %lf    %lf   %lf\n",sayac,a,Fa,b,Fb,c,Fc,muteps);
		
			Fc=0;
		}
		
		if(sayac==n){
			printf("\nKok bulunamadý");
		}
		else if(k==0){
			printf("\nKok: %lf",c);
		}
		else{
			printf("\nKok : %0.3lf",a);
		}
	}
	else if(Fa*Fb==0){
		if(Fa==0){
			printf("\nKok : %lf",a);
		}
		else{
			printf("\nKok : %lf",b);
		}
	}
	else{
		printf("\nSectiginiz aralýkta kok bulunmamakta veya sectiginiz aralýk cok buyuk");
	}
	
	return 0;
}
