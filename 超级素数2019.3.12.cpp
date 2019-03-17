#include<stdio.h>
#include<string.h>

int main(){
	int count=0;//计超级素数个数
	int sum=0; //计超级素数之和 
	int a[999];//存普通素数 
	int max;//计最大超级素数 
	int m=0;
	char b[1000];
	memset(b, 1, sizeof(b));
	for (int i=2;i<1000;i++) {
		if (b[i]==0) continue;		
		for (int j=2*i;j<1000;j += i) {
			b[j]=0;
		}
		a[m++]=i;	
	}
	for(int k=25;k<m;k++){   //小于100的普通素数有25个 
		int c=(a[k]%100)%10;
		int e=(a[k]/10)%10;
		int h=a[k]/100;
		int nsum=h+e+c;
		int npod=h*e*c;
		int nssq=h*h+e*e+c*c;
		int s=0;
		for(int i=0;i<m;i++){
			if(nsum==a[i]){
				s++;
			}
			if(npod==a[i]){
				s++;
			}
			if(nssq==a[i]){
				s++;
			}
		}
		if(s==3){
			count++;
			sum += a[k];
			max=a[k];
			printf("%d ",a[k]);
		}
	}
	printf("\n");
	printf("最大的超级素数%d\n超级素数个数%d\n超级素数之和%d",max,count,sum);
	return 0;
}
