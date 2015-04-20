import java.io.*;
import java.util.*;
public class problemF {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File ("gcm.in"));
		PrintWriter out = new PrintWriter(new File("gcm.out"));
		int a = in.nextInt();
		int b = in.nextInt();
		int count = 0;
		for (int i = a; i <= b; i++) {
			for (int i1 = a; i1 <= b; i1++) {
				if (nod(i1,i) == nod(a,b) && nok(i1,i) == nok(a,b)) {
				count++;	
				}
			}
		}
		int[] para = new int [count];
		int m = 0;
		for (int i = a; i <= b; i++) {
			for (int i1 = a; i1 <= b; i1++) {
				if (nod(i1,i) == nod(a,b) && nok(i1,i) == nok(a,b)) {
		        para[m] = Math.abs(i1 - i);
		        m++;
				}
			}
		}
		int min = 1000000000;
		for (int i = 0;i < para.length; i++){
			min = Math.min(min, para[i]);
		}
		int i = 1;
		while((nod(i,i+min) != nod(a,b)) || ((nok(i,i+min) != nok (a,b)))) {
			i++;
		}
		out.println(i + " " + (i + min));
		in.close();
        out.close();
	}
	public static int nod(int a, int b) {
	int m = 0;
		for(int i = Math.min(a, b); i>0; i--) {
			if((a % i) == 0 && (b % i) == 0) {
				m = i;
				break;
			}
		}
		return m;
	}
	     
    public static int nok(int a, int b) {
    	   	return ((a * b) / (nod (a,b)));
    }
//    public static int[] buble(int[] arr){
//    	for (int i =0; i< arr.length - 1; i++){
//    		for (int j = 0; j< arr.length - 1; j++){
//    			if (arr[j] > arr [j+1]){
//    				int t = arr[j];
//    				arr[j] = arr[j+1];
//    				arr[j+1] = t;
//    			}
//    		}
//    	}
//    	return arr;
//    }
   
}
