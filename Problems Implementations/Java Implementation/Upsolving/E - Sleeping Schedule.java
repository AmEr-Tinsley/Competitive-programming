import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		int[][] memo = new int[3000][3000];
		int[] a = new int[3000];
		int n,h,l,r;
		int solve(int indx,int curr) {
				if(indx == n)return 0;
				int ret = memo[indx][curr];
				if(ret!=-1)return ret;
				int add = ((a[indx]+curr)%h <= r && (a[indx]+curr)%h >=l) ? 1 : 0;
				ret = solve(indx+1,(a[indx]+curr)%h) + add;
				add = ((a[indx]-1+curr + h)%h <= r && (a[indx]+curr-1 + h)%h >=l) ? 1 : 0;
				ret = Math.max(ret, solve(indx+1,(a[indx]-1+curr + h)%h)+add);
				return memo[indx][curr]=ret;
		}
		public void solve(InputReader in, PrintWriter out) {
			for(int[] x : memo)Arrays.fill(x,-1);
			 n = in.nextInt(); 
			 h = in.nextInt();
			 l = in.nextInt();
			 r = in.nextInt();
			 
			 for(int i=0;i<n;i++)a[i]=in.nextInt();
			 out.println(solve(0,0));
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