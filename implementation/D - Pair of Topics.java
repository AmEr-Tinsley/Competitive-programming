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
	        //tc = in.nextInt();
	        while(tc-->0)solver.solve(in, out);;
	        
	        out.close();
	}
	
	static class Solver{
		public void solve(InputReader in, PrintWriter out) {
			
			int n = in.nextInt();
			ArrayList<Integer> a = new ArrayList<Integer>(Collections.nCopies(n, 0));
			ArrayList<Integer> b = new ArrayList<Integer>(Collections.nCopies(n, 0));
			ArrayList<Integer> c= new ArrayList<Integer>(Collections.nCopies(n, 0));
			for(int i = 0;i<n;i++)a.set(i,in.nextInt());
			for(int i=0;i<n;i++)b.set(i,in.nextInt());
			for(int i=0;i<n;i++)c.set(i, a.get(i)-b.get(i));
			Collections.sort(c);
			Long ans = 0L;
			for(int i = 0;i<n;i++) {
					if(c.get(i)<=0)continue;
					int pos = meh(c,-c.get(i)+1);
					ans+=(i-pos);
			}
			out.println(ans);
		}
		int meh(ArrayList<Integer>a , int x) {
			int l = 0,r=a.size(),ret = 0;
			
			while(l<=r) {
				int mid = (l+r)/2;
				if(a.get(mid)<x) {
					l = mid + 1;
				}
				else {
					r = mid-1;
					ret = mid;
				}
			}
			return ret;
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