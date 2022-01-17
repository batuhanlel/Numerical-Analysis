#include<math.h>
#include<stdio.h>

#define  SIZE 100

//Function for calculating derivative 
double tureval(double x,double dizi[],double size){
	double H1=0,H2=0,a,top;
	a=size;
	x=x-0.00000001;
	
	int i;
	for(i=0;i<=size;i++){
		top=dizi[i]*(pow(x,a));
		H1=H1+top;
		a=a-1;
	}
	
	a=size;
	x=x+0.00000002;
	
	for(i=0;i<=size;i++){
		top=dizi[i]*(pow(x,a));
		H2=H2+top;
		a=a-1;
	}
	
	return (H2-H1)/0.00000002;
}

int main(){
	double D,F[SIZE],E,x0,x1;
	
	printf("Denkleminizin derecesini giriniz : ");
	scanf("%lf",&D);
	
	int i;
	printf("\nDenklemin katsayilarini en buyuk dereceli katsayidan baslayarak giriniz\n");
	for(i=0;i<=D;i++){
		scanf("%lf",&F[i]);
	}
	
	printf("\nx0 degerini giriniz : ");
	scanf("%lf",&x0);
	
	printf("\nEpsilon degerini giriniz : ");
	scanf("%lf",&E);
	
	double muteps=1;  //iþlem sýrasýnda kontrol edilen epsilon deðerin mutlak deðeri
	int sayac=1;
	double a=D,top; 
	double F0,F1;
	
	printf("\nAdim\tX0\t\tF(x)\t\tF'(x)\t\tX1\t\tEpsilon\n");
	
	while(muteps>E && sayac<1000){
		for(i=0;i<=D;i++){
			top=F[i]*(pow(x0,a));
			F0=F0+top;
			a=a-1;
		}
		a=D;		
		F1=tureval(x0,F,D);	
		x1=x0-(F0/F1);		
		muteps=fabs(x1-x0);
	
		printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",sayac,x0,F0,F1,x1,muteps);
		F0=0,F1=0;
		x0=x1;
		sayac=sayac+1;
	}
	
	if(muteps<=E){
		printf("\nDenklemin koku : %0.3lf",x0);
	}
	else{
		printf("Kok bulunamadý");
	}

	return 0;
}
