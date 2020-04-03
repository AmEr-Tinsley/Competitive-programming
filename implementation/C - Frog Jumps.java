import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class Main {
 
	public static void main(String[] args) {
			InputStream inputStream = System.in;
	        OutputStream outputStream = System.out;
	        InputReader in = new InputReader(inputStream);
	        PrintWriter out = new PrintWriter(outputStream);
	        Solver solver = new Solver();
	        int tc = 1;
	        tc = in.nextInt();
	        while(tc-->0)solver.solve(in, out);;
	        
	        out.close();
	}
	
	static class Solver{
		public void solve(InputReader in, PrintWriter out) {
			
			String a = in.next();
			a+='R';
			int n = a.length();
			int l = 1 , r = n+1 , ans = 0;
			while(l<=r) {
				int mid = (l+r)/2;
				int lst = -1;
				boolean yes = true;
				for(int i=0;i<n;i++) {
					if(a.charAt(i)=='R') {
						if((i-lst)>mid) {
							yes = false;
						}
						lst = i;
					}
				}
				if(yes){
					ans = mid;
					r = mid-1;
				}
				else	l = mid+1;
			}
			
			out.println(ans);
			
		}
	}
	
	
	
	
	
	
	
	
	
 
	static class InputReader {
	        public BufferedReader reader;
	        public StringTokenizer tokenizer;
	 
	        public InputReader(InputStream stream) {
	            reader = new BufferedReader(new InputStreamReader(stream), 32768);
	            tokenizer = null;
	        }
	 
	        public String next() {
	            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	                try {
	                    tokenizer = new StringTokenizer(reader.readLine());
	                } catch (IOException e) {
	                    throw new RuntimeException(e);
	                }
	            }
	            return tokenizer.nextToken();
	        }
	 
	        public int nextInt() {
	            return Integer.parseInt(next());
	        }
	 
	        public long nextLong() {
	            return Long.parseLong(next());
	        }
	        public Double nextDouble(){
	            return Double.parseDouble(next());
	        }
	        
	 
	    }
}