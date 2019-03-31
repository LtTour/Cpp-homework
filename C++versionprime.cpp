#include<iostream>
#include<cstring>

using namespace std;

class prime{
	private:
		int count,sum,max,m;
		int a[999];
		char b[1000];
		int c,e,h,nsum,npod,nssq,s;

	public:
		int set(int a){
			count=a;
			sum=a;
			m=a;
		}
		void setprime(int x){
			memset(b, 1, sizeof(b));
			for (int i=2;i<x;i++) {
				if (b[i]==0) continue;		
				for (int j=2*i;j<1000;j += i) {
					b[j]=0;
				}
				a[m++]=i;	
			}
			for(int k=25;k<m;k++){   //小于100的普通素数有25个 
				c=(a[k]%100)%10;
				e=(a[k]/10)%10;
				h=a[k]/100;
				nsum=h+e+c;
				npod=h*e*c;
				nssq=h*h+e*e+c*c;
				s=0;
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
					cout<<a[k]<<' ';
				}
			}
			cout<<endl;
			cout<<"最大的超级素数"<<max<<endl<<"超级素数个数"<<count<<endl<<"超级素数之和"<<sum<<endl;
	
		}

};

int main(){
	prime sp;
	sp.set(0);
	sp.setprime(1000);	
	return 0;
}
