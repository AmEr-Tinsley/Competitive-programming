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
			
			int n = in.nextInt();
			ArrayList<Integer> vis = new ArrayList<Integer>(Collections.nCopies(n+1, -1));
			boolean yes = false;
			for(int i=0;i<n;i++) {
				int x = in.nextInt();
				if(vis.get(x)!=-1)yes |= ((i-vis.get(x))>1);
				if(vis.get(x)==-1)
					vis.set(x,i);
			}
			out.println(yes?"YES":"NO");
			
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