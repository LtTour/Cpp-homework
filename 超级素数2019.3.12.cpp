#include<stdio.h>
#include<string.h>

int main(){
	int count=0;//�Ƴ�����������
	int sum=0; //�Ƴ�������֮�� 
	int a[999];//����ͨ���� 
	int max;//����󳬼����� 
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
	for(int k=25;k<m;k++){   //С��100����ͨ������25�� 
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
	printf("���ĳ�������%d\n������������%d\n��������֮��%d",max,count,sum);
	return 0;
}
