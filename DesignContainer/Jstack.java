import java.util.*;
public class Jstack<E> extends Vector<E> {
	public E push(E item){
		addElement(item);
		return item;
	}	

	public synchronized E peek(){
		int len = size();
		if(len==0){
		//	throw new EmptyStackException();
		}
		return elementAt(len-1);
	}

	public synchronized E pop(){
		E obj;
		int len = size();
		obj = peek();
		removeElementAt(len-1);
		return obj;
	}

};
