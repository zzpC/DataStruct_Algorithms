public class Jvector<E> {
	protected int elementCount;
	protected int capacityIncrement;
	protected Object[] elementData;
	public Jvector(){
		this(10);
	}
	public Jvector(int initialCapacity){
		this(initialCapacity,0);
	}
	public Jvector(int initialCapacity,int capacityIncrement){
		if(initialCapacity<0){
			// 抛异常
		}
		this.elementData=new Object[initialCapacity];
		this.capacityIncrement=capacityIncrement;
	}

}
