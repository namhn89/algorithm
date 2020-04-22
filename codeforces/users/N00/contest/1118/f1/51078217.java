import java.util.*;
import java.util.List; 
import java.io.*; 
import java.math.*; 
 
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out; 
        InputReader in = new InputReader(inputStream) ; 
        PrintWriter out = new PrintWriter(outputStream) ; 
        Task1118F1 task = new Task1118F1(in , out) ;  
        task.solve(); 
        out.close(); 
    }
    
    static public class Task1118F1 {

        public static final int maxn = 100005  ;
        static int n ; 
        private int[] color ; 
        private int[] sumColor ; 
        private int[][] treeColor ; 
        private List <Integer>[] adj ; 
        private int ans = 0 ; 

        InputReader in ; 
        PrintWriter out ; 

        Task1118F1 (InputReader in , PrintWriter out) {
            this.in = in ; 
            this.out = out ; 
        }

        public void dfs (int u , int parent) {
            for (int v : adj[u]) {
                if (v != parent) {
                    dfs(v , u); 
                    treeColor[u][1] += treeColor[v][1] ; 
                    treeColor[u][2] += treeColor[v][2] ; 
                }
            } 
            treeColor[u][color[u]] += 1 ; 
            if ( (treeColor[u][1] == 0 || treeColor[u][2] == 0) && (sumColor[1] == treeColor[u][1] || sumColor[2] == treeColor[u][2]) ){
                ans++ ; 
            } 
        }

        public void solve() {
            n = in.nextInt() ; 
            color = new int[n + 1] ; 
            treeColor = new int[n + 1][3] ; 
            adj = new List[n + 1] ; 
            sumColor = new int[3] ; 

            for (int i = 0 ; i < n ; ++i ) {
                color[i] = in.nextInt() ;
                sumColor[color[i]] ++ ; 
            } 
            for (int i = 0 ; i < n ; ++i ) {
                adj[i] = new ArrayList<Integer>() ; 
            }
            for (int i = 1 ; i < n ; ++i ) {
                int u = in.nextInt() - 1 ; 
                int v = in.nextInt() - 1 ; 
                adj[u].add(v) ; 
                adj[v].add(u) ; 
            }
            dfs(1 , 1);
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
 
    }
} 