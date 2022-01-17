#include<stdio.h>
#define SIZE 100
#include<math.h>

int main(){
	
	double A[SIZE][SIZE], X[SIZE], r;
	int i,j,k,n;
	
	printf("Denklem sisteminiziz bilinmeyen sayiysini giriniz : ");
	scanf("%d",&n);
	
	printf("\nSistemin Arttirilmis Katsayilar Matrisinin [ A : B ] elemanlarini giriniz : \n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			i=i+1,j=j+1;
			printf("A[%d][%d] : ",i,j);
			i=i-1,j=j-1;
			scanf("%lf",&A[i][j]);
		}
	}
	
	
	for(i=0;i<n;i++){
		
		if(A[i][i]==0){
			printf("Tanýmsýz Ýslem (payda 0)");
			return 0;
		}
		
		for(j=0;j<n;j++){
			if(i!=j){
				r=A[j][i]/A[i][i];
				for(k=0;k<=n;k++){
					A[j][k]=A[j][k]-(r*A[i][k]);
				}
			}
		}		
	}
	
	
	printf("\nThe Matrix after applying the method\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			i=i+1,j=j+1;
	//		printf("A[%d][%d] : ",i,j);
			i=i-1,j=j-1;
			printf("%0.3lf\t",A[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++){
		X[i]=A[i][n]/A[i][i];
	}
	
	int s=1;
	printf("\nKokler\n");
	for(i=0;i<n;i++){
		printf("X%d : %0.3lf\n",s,X[i]);
		s+=1;
	}
	
	return 0;
}
