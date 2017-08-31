#include <cstdio>
#define G_L 4
#define G_H 3




/*7890
1234
2345
*/
int Data[G_H-1][G_L-1];

int main(){
	
	
	for (int IPL=0,IPH=0;IPH<G_H;){
		
		for (;IPL<G_L;){
			scanf("%d",&Data[IPH][IPL]);
			IPL++;
		}
		IPL=0;
		IPH++;
	}
	
	int SaveData;
	int SaveDataPosL;
	int SaveDataPosH;
	int SaveMax;
	int SaveMin;
	
	int First_Data_ORN=0;
	int First_Data_ORN1=0;
	
	
	
	
	for (int L=0,H=0;H<G_H;){
		First_Data_ORN=0;
		for (L=0;L<G_L;){
			if (First_Data_ORN==0){
				SaveMin=Data[H][L];
				First_Data_ORN=1;
				SaveDataPosL=L;
			}else {
				if (Data[H][L]<SaveMin){
					SaveMin=Data[H][L];
					SaveDataPosL=L;
				}
				
			}
			L++;
		}
		SaveMax=Data[0][SaveDataPosL];
		for (int T_H=0;T_H<G_H;){
			
			if (Data[T_H][SaveDataPosL]>SaveMax){
				SaveMax=Data[T_H][SaveDataPosL];
				SaveDataPosH=T_H;
			}
			T_H++;
			
		}
		
		H++;
	
	if (SaveMax==SaveMin){
		SaveData=SaveMax;
		printf("\n%d\n",SaveData);
		printf("%d\n",SaveDataPosL);
		printf("%d",SaveDataPosH);
	}else {
		printf("没有了");
		printf ("%d,%d",SaveMax,SaveMin);
	}
	}
	
	return 0;
}


/*#include<cstdio>
#define N 3 //N---多少行//
#define M 4 //M---多少列//
int main()
{
	int a[N][M],i,j,t,k,max,min,l=0;
	for (int IPL=0,IPH=0;IPH<N;){
		
		for (;IPL<M;){
			scanf("%d",&a[IPH][IPL]);
			IPL++;
		}
		IPL=0;
		IPH++;
	}
	
	
	
	for (i=0;i<N;i++)
	{ 
	max=a[i][0];k=0;
	for (j=1;j<M;j++){
	if (a[i][j]>max)
	{
		max=a[i][j];k=j;
		}
		}
		min=a[0][k];
		for (t=1;t<N;t++)
		if (a[t][k]<min)
		min=a[t][k];
		if (max==min)
		{printf("所要的数在数组中的%d行%d列值为%d\n",i,t,max);
		l++;
		}
		}
		if(l==0)
		printf("there is no such number.\n");

}*/