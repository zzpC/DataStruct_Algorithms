// 树状数组
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100010
int c[MAX],a[MAX],ans[MAX],n;
 
int Lowbit(int x)      //返回二进制最后一个1所表示的数,负数是补码
{
	return x&(-x);
}

void Updata(int x){
	while(x<=n){
		c[x]++;
		x+=Lowbit(x);	
	}
}

int Sum(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=Lowbit(x);
	}
	return sum;
}

int main(){
	int i;
	int t;
	int k;
	scanf("%d",&t);
	while(t--){
        	scanf("%d",&n);
        	for(i=1;i<=n;i++){
			scanf("%d",&ans[i]);
		}
		memset(c,0,sizeof(c));        //初始化树状数组
		for(i=1,k=0;i<=n;i++){
			Updata(ans[i]);         //向后更新节点ans[i].k
			k=k+(i-Sum(ans[i]));    //向前查询节点ans[i].k
		}
		printf("%d\n",k);
	}
	return 0;
}
