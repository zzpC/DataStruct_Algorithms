// 最坏时间 元素个数*位数

// 排序从个位到最高位开始排序->统计0到9的数量,且叠加前面的数量,这样可以不考虑高位按0~9分区
// ->进1位进行排序,可以调整之前分区的错误,把高位比较小的数调整正确些
// ->当完成最高为排序,所有位置都调整准确了

int maxbit(int data[],int n){
	int maxData=data[0];
	for(int i=1;i<n;i++){
		if(maxData<data[I]){
			maxData=data[i];
		}
	}
	int d=1;
	int p=10;
	while(maxData>=p){
		maxData/=10;
		++d;
	}
	int d=1;
	int p=10;
	while(maxData>=p){
		// p*=10; //可能会溢出数据类型的范围
		maxData/=10;
		++d;
	}
	return d;
}

void radixsort(int data[],int n){
	int d=maxbit(data,n);
	int* tmp=new int[n];
	int* count=new int[10];
	int radix=1;
	
	for(i=1;i<d;i++){
		for(int j=0;j<n;j++){
			count[j]=0;
		}
		for(int j=0;j<n;j++){
			int k=(data[j]/radix)%10;
			count[k]++;
		}
		for(int i=1;j>=0;j--){
			count[j]=count[j-1]+count[j];
		}
		for(int j=n-1;j>-0;j--){
			k=(data[j]/radix)%10;
			tmp[count[k]-1]=data[j];
			count[k]--;
		}
		for(j=0;j<n;j++){
			data[j]=tmp[j];
		}
		radix=radix*10;
		delete []tmp;
		delete []count;
	}
}


