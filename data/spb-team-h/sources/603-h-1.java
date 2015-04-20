import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("names.in"));
		PrintWriter out = new PrintWriter("names.out");
		int n = sc.nextInt();
		String[] surname = new String[n];
		String[] name = new String[n];
		String[] ot = new String[n];
		for (int i = 0; i < n; i++) {
			surname[i] = sc.next();
			name[i] = sc.next();
			ot[i] = sc.next();
		}
		int arr[]=new int[n];
		
		for(int i=0; i<n; i++){
			if(arr[i]==0){
				for(int g=i+1; g<n; g++){
					if(surname[i].equals(surname[g])){
						arr[g]=1;
						String surn1=ot[i];
						String na1=surname[i];
						String ot1=name[i];
						surname[i]=surn1;
						name[i]=na1;
						ot[i]=ot1;
						String surn2=ot[g];
						String na2=surname[g];
						String ot2=name[g];
						surname[g]=surn2;
						name[g]=na2;
						ot[g]=ot2;
					}
				}
				for(int g=0; g<n; g++){
					if(surname[i].equals(name[g])){
						arr[g]=1;
						String surn1=ot[i];
						String na1=surname[i];
						String ot1=name[i];
						surname[i]=surn1;
						name[i]=na1;
						ot[i]=ot1;
					}
				}
				arr[i]=1;
			}
		}
		
		for(int i=0; i<n; i++){
			for(int g=i+1; g<n; g++){
				char ch1=surname[i].charAt(0);
				char ch2=surname[g].charAt(0);
				if(ch1>ch2){
					String t1=surname[i];
					surname[i]=surname[g];
					surname[g]=t1;
					String t2=name[i];
					name[i]=name[g];
					name[g]=t2;
					String t3=ot[i];
					ot[i]=ot[g];
					ot[g]=t3;
				}
				if(ch1==ch2){
					int l=1;
					while(ch1==ch2){
						if(surname[i].length()>=l+1){
							ch1=surname[i].charAt(l);
							ch2=surname[g].charAt(l);
							l++;
						}else{
							break;
						}
					}
					if(ch1==ch2){
						if(surname[i].length()>surname[g].length()){
							String t1=surname[i];
							surname[i]=surname[g];
							surname[g]=t1;
							String t2=name[i];
							name[i]=name[g];
							name[g]=t2;
							String t3=ot[i];
							ot[i]=ot[g];
							ot[g]=t3;
						}
					}else{
						if(ch1>ch2){
							String t1=surname[i];
							surname[i]=surname[g];
							surname[g]=t1;
							String t2=name[i];
							name[i]=name[g];
							name[g]=t2;
							String t3=ot[i];
							ot[i]=ot[g];
							ot[g]=t3;
						}
					}
				}
			}
		}
		
		for(int i=0; i<n; i++){
			out.println(surname[i]+" "+name[i]+" "+ot[i]);
		}
		
		sc.close();
		out.close();
	}
}