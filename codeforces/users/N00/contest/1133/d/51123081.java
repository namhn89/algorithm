import java.util.*;
import java.io.*; 
import java.lang.*;
 
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out; 
        InputReader in = new InputReader(inputStream) ; 
        PrintWriter out = new PrintWriter(outputStream) ; 
        Task task = new Task(in , out) ;  
        task.solve(); 
        out.close(); 
    }
    
    static public class Task {

        int n , result , ans ; 
        int[] a , b ; 
        Map <Point , Integer> countMap ; 
        InputReader in ; 
        PrintWriter out ; 

        Task (InputReader in , PrintWriter out) {
            this.in = in ; 
            this.out = out ; 
        }
        
        public int gcd (int a , int b) {
            if (b == 0 || a == 0) return a + b ; 
            return gcd(b % a , a) ;  
        }

        Point nomarlize (int x , int y) {
            if (x < 0) {
                x *= -1 ; 
                y *= -1 ; 
            }
            int _gcd = gcd(Math.abs(x) , Math.abs(y)) ; 
            x /= _gcd ; 
            y /= _gcd ;
            Point ans = new Point(x , y) ;  
            return ans ; 
        }
        public void solve () {
            countMap = new HashMap() ; 
            n = in.nextInt() ; 
            a = new int[n + 1] ; 
            b = new int[n + 1] ; 
            ans = 0 ; 
            result = 0 ;
            for (int i = 0 ; i < n ; ++i ) {
                a[i] = in.nextInt() ; 
            }
            for (int i = 0 ; i < n ; ++i ) {
                b[i] = in.nextInt() ; 
            }
            for (int i = 0 ; i < n ; ++i ) {
                if (a[i] == 0) {
                    if (b[i] == 0) {
                        ans ++ ; 
                    }
                }
                else {
                    Point point = nomarlize(a[i] , b[i]) ; 
                    if (countMap.containsKey(point)) countMap.put(point , countMap.get(point) + 1) ; 
                    else countMap.put(point , 1) ; 
                    result = Math.max(result , countMap.get(point)) ; 
                }
            }
            ans += result ; 
            out.println(ans);
        }
    }

    static public class Point {
        int x , y ; 
        Point (int x , int y) {
            this.x = x ; 
            this.y = y ; 
        }
        @Override
        public boolean equals (Object o) {
			Point p = (Point) o;
			return x == p.x && y == p.y;
		}
        @Override
		public int hashCode() {
			return (this.x + " " + this.y).hashCode();
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
 
    }
} 