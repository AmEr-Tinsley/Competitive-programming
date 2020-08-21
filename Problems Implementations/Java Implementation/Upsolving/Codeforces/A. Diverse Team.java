import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;
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
			int k = in.nextInt();
			int[] seen = new int[105];
			ArrayList<Integer> ans = new ArrayList<Integer>();
			for(int i = 0;i<n;i++) {
				int x = in.nextInt();
				if(seen[x] == 0 && ans.size()<k)ans.add(i+1);
				seen[x] = 1;
			}
			
			if(ans.size() < k)System.out.println("NO");
			else {
				System.out.println("YES");
				for(int x : ans ) {
					System.out.print(x + " ");
				}
			}
				
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