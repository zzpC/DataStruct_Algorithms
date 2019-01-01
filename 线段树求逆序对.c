
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 51000
#define MID(a,b) (a+b)>>1
// 乘2+1
#define R(a) (a<<1|1)
#define L(a) a<<1
typedef struct{
	int num;
	int left;
	int right;
}Node;
int ans[MAX];
Node Tree[MAX<<2];
int n;

void Build(int t,int l,int r){
	int mid;
	Tree[t].left=l;
	Tree[t].right=r;
	if(Tree[t].left==Tree[t].right){
		Tree[t].num=0;
		return;
	}
	mid=MID(Tree[t].left,Tree[t].right);
	Build(L(t),l,mid);
	Build(R(t),mid+1,r);
}

void Insert(int t,int l,int r,int x){
	int mid;
	if(Tree[t].left==l&&Tree[t].right==r){
       		Tree[t].num+=x;
        	return ;
    	}
	mid=MID(Tree[t].left,Tree[t].right);
    	if(l>mid){
        	Insert(R(t),l,r,x);
   	}else if(r<=mid){
        	Insert(L(t),l,r,x);
    	}else{
        	Insert(L(t),l,mid,x);
        	Insert(R(t),mid+1,r,x);
    	}
    	Tree[t].num=Tree[L(t)].num+Tree[R(t)].num;
}


int Query(int t,int l,int r)           //查询以1为根节点，区间[l,r]的和
{
     	int mid;
    	if(Tree[t].left==l&&Tree[t].right==r)
        return Tree[t].num;
	mid=MID(Tree[t].left,Tree[t].right);
    	if(l>mid){
        	return Query(R(t),l,r);
    	}
    	else if(r<=mid){
        	return Query(L(t),l,r);
    	}
    	else{
        	return Query(L(t),l,mid)+Query(R(t),mid+1,r);
    	}
}


int main(){
	int a,n,i,t;
    	scanf("%d",&t);
    	long long int k;
    	while(t--){
        	scanf("%d",&n);
        	memset(Tree,0,sizeof(Tree));  //初始化线段树
		Build(1,1,n);
        	for(i=1;i<=n;i++){
            		scanf("%d",&ans[i]);
        	}
        	for(i=1,k=0;i<=n;i++){
           		a=ans[i];
            		Insert(1,a,a,1);          //把线段树[ans[i],ans[i]]区间的值插入为1
            		k=k+(i-Query(1,1,a));     //查询区间[1,ans[i]]值的总和,逆序数等于i-[1,ans[i]]
        	}
        	printf("%lld\n",k);
	}
	return 0;
}
