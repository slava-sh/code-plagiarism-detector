import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;
 



public class C {
        
        final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE")!=null;
        BufferedReader in;
        PrintWriter out;
        StringTokenizer tok = new StringTokenizer("");
        
        void init() throws FileNotFoundException{
                if (ONLINE_JUDGE){
                        in = new BufferedReader(new InputStreamReader(System.in));
                        out = new PrintWriter(System.out);
                }else{
                        in = new BufferedReader(new FileReader("input.txt"));
                        out = new PrintWriter("output.txt");
                }
        }
        
        String readString() throws IOException{
                while(!tok.hasMoreTokens()){
                        tok = new StringTokenizer(in.readLine());
                }
                return tok.nextToken();
        }
        
        int readInt() throws IOException{
                return Integer.parseInt(readString());
        }
        
        long readLong() throws IOException{
                return Long.parseLong(readString());
        }
        
        double readDouble() throws IOException{
                return Double.parseDouble(readString());
        }
        
        int[] readArr(int n) throws IOException{
        	int[] res = new int[n];
        	for(int i = 0; i < n; i++){
        		res[i] = readInt();
        	}
        	return res;
        }
        
        long[] readArrL(int n) throws IOException{
        	long[] res = new long[n];
        	for(int i = 0; i < n; i++){
        		res[i] = readLong();
        	}
        	return res;
        }
        
        public static void main(String[] args){
                new C().run();
        }
        
        public void run(){
                try{
                        long t1 = System.currentTimeMillis();
                        init();
                        solve();
                        out.close();
                        long t2 = System.currentTimeMillis();
                        System.err.println("Time = "+(t2-t1));
                }catch (Exception e){
                        e.printStackTrace(System.err);
                        System.exit(-1);
                }
        }
        
          
        class Kom implements Comparable<Kom>{
        	@Override
        	public int compareTo(Kom o) {
        		return -this.c + o.c;
        	}
        	public int w;
        	public int c;
        	public Kom(int w, int c){
        		this.w = w;
        		this.c = c;
        	}
        }
        
        
        void solve() throws IOException{
        	int n = readInt();
        	int[] a = readArr(n);
        	Utils.mergeSort(a);
        	PriorityQueue<Kom> k = new PriorityQueue<Kom>();
        	Kom current = new Kom(0,0);
        	int countCur = 1;
        	for(int i = 1; i < n; i++){
        		if(a[i] == a[i-1]) countCur++;
        		else{
        			current = new Kom(a[i-1], countCur);
        			countCur = 1;
        			k.add(current);
        		}
        	}
        	k.add(new Kom(a[n-1], countCur));
        	int i = 0;
        	ArrayList<Integer> res = new ArrayList<Integer>();
        	Kom m1, m2, m3;
        	while(true){
        		if(k.isEmpty()) break;
        		m1 = k.poll();
        		if(k.isEmpty()) break;
        		m2 = k.poll();
        		if(k.isEmpty()) break;
        		m3 = k.poll();
        		i++;
        		res.add(m1.w);
        		res.add(m2.w);
        		res.add(m3.w);
        		m1.c--;
        		m2.c--;
        		m3.c--;
        		if(m3.c > 0) k.add(m3);
        		if(m2.c > 0) k.add(m2);
        		if(m1.c > 0) k.add(m1);
        	}
        	out.println(i);
        	int[] r = new int[3];
        	for(int j = 0; j < i; j++){
        		r[0] = res.get(j*3);
        		r[1] = res.get(j*3+1);
        		r[2] = res.get(j*3+2);
        		Arrays.sort(r);
        		out.print(r[2] + " ");
        		out.print(r[1] + " ");
        		out.println(r[0] + " ");
        	}
        }
        
        void maxHepify(int[] a, int i, int length){
        	int l = (i<<1) + 1;
        	int r = (i<<1) + 2;
        	int largest = i;
        	if(l < length && a[l] > a[largest])
        		largest = l;
        	if(r < length && a[r] > a[largest])
        		largest = r;
        	if(largest != i){
        		a[largest] += a[i];
        		a[i] = a[largest] - a[i];
        		a[largest] -= a[i];
        		maxHepify(a, largest, length);
        	}
        }
        
        void buildMaxHeap(int[] a){
        	for(int i = a.length/2 - 1; i >= 0; i--){
        		maxHepify(a, i, a.length);
        	}
        }
        
        void heapSort(int[] a){
        	buildMaxHeap(a);
        	for(int i = a.length - 1; i > 0; i--){
        		a[i] += a[0];
        		a[0] = a[i] - a[0];
        		a[i] -= a[0];
        		maxHepify(a, 0, i);
        	}
        }

        
        int[] zFunction(char[] s){
        	int[] z = new int[s.length];
        	z[0] = 0;
        	for (int i=1, l=0, r=0; i<s.length; ++i) {
        		if (i <= r)
        			z[i] = min (r-i+1, z[i-l]);
        		while (i+z[i] < s.length && s[z[i]] == s[i+z[i]])
        			++z[i];
        		if (i+z[i]-1 > r){
        			l = i; 
        			r = i+z[i]-1;
        		}
        	}	
        	return z;
        }
        
        int[] prefixFunction(char[] s){
        	int[] pr = new int[s.length];
        	for (int i = 1; i< s.length; ++i) {
        		int j = pr[i-1];
        		while (j > 0 && s[i] != s[j])
        			j = pr[j-1];
        		if (s[i] == s[j])  ++j;
        		pr[i] = j;
        	}
        	return pr;
        }
        
        int ModExp(int a, int n, int mod){
        	int res = 1;
        	while (n!=0)
        		if ((n & 1) != 0) {
        			res = (res*a)%mod;
        			--n;
        		}
        		else {
        			a = (a*a)%mod;
        			n >>= 1;
        		}
        	return res;
        }
        
        
        static class Utils {
 
                private Utils() {}
 
                public static void mergeSort(int[] a) {
                        mergeSort(a, 0, a.length - 1);
                }
 
                private static void mergeSort(int[] a, int leftIndex, int rightIndex) {
                        final int MAGIC_VALUE = 50;
                        if (leftIndex < rightIndex) {
                                if (rightIndex - leftIndex <= MAGIC_VALUE) {
                                        insertionSort(a, leftIndex, rightIndex);
                                } else {
                                        int middleIndex = (leftIndex + rightIndex) / 2;
                                        mergeSort(a, leftIndex, middleIndex);
                                        mergeSort(a, middleIndex + 1, rightIndex);
                                        merge(a, leftIndex, middleIndex, rightIndex);
                                }
                        }
                }
 
                private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
                        int length1 = middleIndex - leftIndex + 1;
                        int length2 = rightIndex - middleIndex;
                        int[] leftArray = new int[length1];
                        int[] rightArray = new int[length2];
                        System.arraycopy(a, leftIndex, leftArray, 0, length1);
                        System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
                        for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
                                if (i == length1) {
                                        a[k] = rightArray[j++];
                                } else if (j == length2) {
                                        a[k] = leftArray[i++];
                                } else {
                                        a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
                                }
                        }
                }
 
                private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
                        for (int i = leftIndex + 1; i <= rightIndex; i++) {
                                int current = a[i];
                                int j = i - 1;
                                while (j >= leftIndex && a[j] > current) {
                                        a[j + 1] = a[j];
                                        j--;
                                }
                                a[j + 1] = current;
                        }
                } 
        }
        
       
        
        boolean isPrime(int a){
        	for(int i = 2; i <= sqrt(a); i++)
        		if(a % i == 0) return false;
        	return true;
        }
        
        static double distance(long x1, long y1, long x2, long y2){
        	return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
        
        static long gcd(long a, long b){
        	if(min(a,b) == 0) return max(a,b);
        	return gcd(max(a, b) % min(a,b), min(a,b));
        }
        
        static long lcm(long a, long b){
        	return a * b /gcd(a, b);
        }
}