#include<stdio.h>
#include<string.h>

int main(){
	int r,s,n;
	char a[2]={0};
	int rs[100][100]={0};
	scanf("%d %d",&r,&s);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=s;j++){
			scanf("%d",&rs[i][j]);
		}
	}
	scanf("%d",&n);
	
	int x,y,tem;
	int h=0;int l=0;
	int counth=0;int countl=0;
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c%c",&a[0],&a[1]);
		if(a[0]=='S') scanf("%d %d",&x,&y);
		else if(a[0]=='I'&&a[1]=='R') scanf("%d",&h);
		else if(a[0]=='I'&&a[1]=='C') scanf("%d",&l);
		else scanf("%d",&x);
		if(a[0]=='S'&&a[1]=='R'){
			for(int j=1;j<=s;j++){
				tem=rs[x][j];
				rs[x][j]=rs[y][j];
				rs[y][j]=tem;
			}
		}
		
		if(a[0]=='S'&&a[1]=='C'){
			for(int j=1;j<=s;j++){
				tem=rs[j][x];
				rs[j][x]=rs[j][y];
				rs[j][y]=tem;
			}
		}
		
		if(a[0]=='D'&&a[1]=='R'){
			for(int j=x;j<r+counth;j++){
				for(int k=1;k<=s+countl;k++){ 
					rs[j][k]=rs[j+1][k];	
				}
			} 
			counth--;
		}
		if(a[0]=='D'&&a[1]=='C'){
			for(int j=x;j<s+countl;j++){
				for(int k=1;k<=r+counth;k++){ 
					rs[k][j]=rs[k][j+1];	
				}
			} 
			countl--;
		}
		
		if(a[0]=='I'&&a[1]=='R'){
			for(int j=r+counth;j>=h;j--){
				for(int k=1;k<=s;k++){ 
					rs[j+1][k]=rs[j][k];	
				}
			} 
			memset(rs[h],0,sizeof(rs[h]));
			counth++;
		}
		if(a[0]=='I'&&a[1]=='C'){
			for(int j=s+countl;j>=l;j--){
				for(int k=1;k<=r;k++){ 
					rs[k][j+1]=rs[k][j];	
				}
			} 
			for(int k=1;k<=r+countl;k++){
				rs[k][l]=0;
			}
			countl++;
		}	
	}
	for(int i=1;i<=r+counth;i++){
		for(int j=1;j<=s+countl;j++){
			printf("%d ",rs[i][j]);
		}
		printf("\n");
	}
	return 0;
}



