#include<stdio.h>
#include<math.h>

#define SIZE 100

int main(){
	
	double A[SIZE][SIZE], r;
	int i,j,k,n;
	
	printf("Matrisinizin boyutunu  giriniz : ");
	scanf("%d",&n);
	
	printf("\nMatrisinizin elemanlarini giriniz : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			i=i+1,j=j+1;
			printf("A[%d][%d] : ",i,j);
			i=i-1,j=j-1;
			scanf("%lf",&A[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			if(i==(j-n)){
				A[i][j]=1;
			}
			else{
				A[i][j]=0;
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				r=A[j][i]/A[i][i];
				for(k=0;k<2*n;k++){
					A[j][k]=A[j][k]-(r*A[i][k]);
				}
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			A[i][j]=A[i][j]/A[i][i];
		}
	}
	
	printf("\nMatrisinizin Tersi : \n");
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			printf("%lf\t",A[i][j]);
	    }
	    printf("\n");
    }

	return 0;
}
