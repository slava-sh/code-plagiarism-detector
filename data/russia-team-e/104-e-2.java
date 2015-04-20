import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: orspc
 * Date: 25.11.13
 * Time: 11:26
 * To change this template use File | Settings | File Templates.
 */
public class E {

    public static int[] a;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader("numbers.in"));
        PrintWriter pw = new PrintWriter("numbers.out");
        int n = scan.nextInt();
        HashMap<Integer, int[]> numbers = new HashMap<Integer, int[]>();
        a = new int[n];
        Arrays.fill(a, 0);
        for(int i = 0; i < n; i++) {
            int z = scan.nextInt();
            add(z);
            int x = scan.nextInt();
            int[] nums = new int[x];
            for(int j = 0; j < x; j++) {
                nums[j] = scan.nextInt();
            }
            Arrays.sort(nums);
            numbers.put(z, nums);
        }
        Arrays.sort(a);
        n = scan.nextInt();
        for(int i = 0; i < n; i++) {
            String number = scan.next();
            if(number.startsWith("0")) {
                pw.println("Incorrect");
                continue;
            }
            boolean work1 = false, work2 = false;
            for(int j = a.length - 1; j >= 0; j--) {
                if(number.startsWith(String.valueOf(a[j]))) {
                    work1 = true;
                    int[] nums = numbers.get(a[j]);
                    int len = String.valueOf(a[j]).length();
                    String another = number.substring(len, number.length());
                    if(another.startsWith("0")) {
                        pw.println("Incorrect");
                        break;
                    }
                    for(int k = nums.length - 1; k >= 0; k--) {
                        if(another.startsWith(String.valueOf(nums[k]))) {
                            work2 = true;
                            String phone = another.substring(String.valueOf(nums[k]).length(), another.length());
                            if(phone.startsWith("0")) {
                                pw.println("Incorrect");
                                break;
                            }
                            phone = make(phone);
                            pw.println("+" + a[j] + "(" + nums[k] + ")" + phone);
                            break;
                        }
                    }
                    if(work2) break;
                }
            }
            if(!work1) pw.println("Incorrect");
        }
        pw.close();
    }

    public static void add(int b) {
        for(int i = 0; i < a.length; i++) {
            if(a[i] == 0) {
                a[i] = b;
                break;
            }
        }
    }

    public static String make(String s) {
        int l = s.length();
        if(l == 3) return s;
        if(l == 4) return s.substring(0, 2) + "-" + s.substring(2, 4);
        if(l == 5) return s.substring(0, 3) + "-" + s.substring(3, 5);
        if(l == 6) return s.substring(0, 2) + "-" + s.substring(2, 4) + "-" + s.substring(4, 6);
        return s.substring(0, 3) + "-" + s.substring(3, 5) + "-" + s.substring(5, 7);
    }

}
