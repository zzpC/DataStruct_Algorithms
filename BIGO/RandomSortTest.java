import java.util.*;
public class RandomSortTest{
	private int[] arr={1,2,3,4,5,6,7,8};
	private static final int SIZE=8;
	Random random=new Random();
	public void sort(){
		for(int i=0;i<SIZE;i++){
			int p=random.nextInt(i+1);
			int tmp=arr[i];
			arr[i]=arr[p];
			arr[p]=tmp;
		}
		printArr();
	}
	
	// 打印
	public void printArr(){
		for(int i=0;i<SIZE;i++){
			System.out.print(arr[i]+" ");
		}
	}

	public static void main(String[] args){
		RandomSortTest r=new RandomSortTest();
		for(int i=0;i<4;i++){
			r.sort();
			System.out.println();
		}
	}
}
