#include<stdio.h>
#include<math.h>
#define S 50

int main(){
	
	double XY[2][S],x,a,b,c,top;
	int i,j,n;
	
	printf("Elinizde bulunan (x,y) ikilisi sayisini giriniz : ");
	scanf("%d",&n);
	
	
	printf("\n(x,y) ikililerini once x'ler sonra y'ler olmak uzere sirayla giriniz\n");
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&XY[i][j]);
		}
	}
	
	
	printf("\nKarsiligini bulmak istediginiz x degerini giriniz : ");
	scanf("%lf",&x);
	
	
	b=1,top=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				a = (x-XY[0][j])/(XY[0][i]-XY[0][j]);
				b = b*a;
			}
		}
		c = b*XY[1][i];
		top = top+c;
		b=1;
	}
	
	printf("\n\nIstediginiz x degeri icin elde edilen y degeri\n y = %0.3lf",top);
	
	return 0;
}
