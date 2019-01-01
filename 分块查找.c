#define INDEX_NUM 3
#define BLOCK_LEN 6
#define NULL 0
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct index {
	int start;
	int key;
}index;

index indexs[INDEX_NUM];
int cmp(const void *a,const void* b){
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}

void initDatas(int* datas,int length){
	for(int i=0;i<length;i++){
		datas[i]=rand()%50;
	}
}

void initIndexTable(int*  datas){
	for(int i=0;i<INDEX_NUM;i++){
		indexs[i].key=-1;
	}
	int j=-1;
	for(int i=0;i<INDEX_NUM;i++){
		indexs[i].start=j+1;
		j+=BLOCK_LEN;
		for(int k=indexs[i].start;k<=j;k++){
			if(indexs[i].key<datas[k]){
				indexs[i].key=datas[k];
			}
		}
	}
}

// 可使用二分查找优化
int search(int key, int a[]){
	int i=0;
	while(i<INDEX_NUM && key>indexs[i].key){
		++i;
	}
	if(i>=3){
		return -1;
	}
	int startValue=indexs[i].start;
	while(startValue<=indexs[i].start+5 && a[startValue]!=key){
		++startValue;
	}
	if(startValue>indexs[i].start+5){
		return -1;
	}else{
		return startValue;
	}

}

int main(){
	srand((unsigned)(time(NULL)));
	qsort(indexs,3, sizeof(indexs[0]), cmp);
	int key;
	int datas[BLOCK_LEN*INDEX_NUM];
	//initDatas(datas,BLOCK_LEN*INDEX_NUM);
	for(int i=0;i<18;i++){
		datas[i]=rand()%50;
	}

	initIndexTable(datas);


	printf("请输入您想要查找的数：\n");
	getchar();
	scanf("%d", &key);
	int k = search(key,datas);//输出查找的结果
	if (k>0) {
		printf("查找成功！您要找的数在数组中的位置是：%d\n",k+1);
	}else{
		printf("查找失败！您要找的数不在数组中。\n");
	}
	return 0;
}
