import java.util.*;
import java.io.*;
import java.lang.*;
public class Solution {
	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream) ;
		PrintWriter out = new PrintWriter(outputStream) ;
		int n = in.nextInt(), q = in.nextInt();
		Edge[] edges = new Edge[n] ;
		for (int i = 0; i < n - 1; ++i){
			int u = in.nextInt() , v = in.nextInt(), w = in.nextInt();
			edges[i] = new Edge(u - 1, v - 1, w);
		}
		edges[n - 1] = new Edge(0 , 0, 1000000000);
		Arrays.sort(edges);
		long[] ans = new long[q] ;
		Pair[] query = new Pair[q] ;
		for (int i = 0; i < q ; ++i) {
			int u = in.nextInt();
			query[i] = new Pair(u , i);
		}
		Arrays.sort(query);
		DisjointSet DisjointSet = new DisjointSet(n) ;
		int index = 0 ;
		for (Pair pos: query) {
			while(edges[index].weight <= pos.first){
				DisjointSet.union(edges[index].src, edges[index].dest);
				index++;
			}
			ans[pos.second] = DisjointSet.res;
		}
		for (int i = 0; i < q; ++i){
			System.out.print(ans[i] + " ");
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

class Pair implements Comparable<Pair> {
	public int first, second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public int compareTo(Pair p) {
		return first - p.first;
	}
}

class Edge implements Comparable<Edge> {
	public int src, dest, weight;

	public Edge(int src, int dest, int weight) {
		this.src = src;
		this.dest = dest;
		this.weight = weight;
	}

	public int compareTo(Edge other) {
		return this.weight - other.weight;
	}

	public String toString() {
		return src + " " + dest + " " + weight;
	}
}

class Subset {
	public int parent;
	public long size;

	public Subset(int parent, int size) {
		this.parent = parent;
		this.size = size;
	}
}

class DisjointSet {
	private int V, E;
	public long res= 0;
	public Subset[] subset;

	public DisjointSet(int V) {
		this.V = V;

		subset = new Subset[V];
		for (int i = 0; i < V; i++)
			subset[i] = new Subset(i, 1);
	}

	public int findSet(int v) {
		if (subset[v].parent == v) return v;
		return subset[v].parent = findSet(subset[v].parent);
	}

	public void union(int v, int u) {
		int parentV = findSet(v);
		int parentU = findSet(u);
		if (parentV == parentU)
			return;

		res = res - subset[parentV].size * (subset[parentV].size - 1) / 2;
		res = res - subset[parentU].size * (subset[parentU].size - 1) / 2;
		long s = subset[parentU].size + subset[parentV].size;
		res= res + s * (s - 1) / 2;

		if (subset[parentV].size < subset[parentU].size) {
			subset[parentV].parent = parentU;
			subset[parentU].size += subset[parentV].size;
		} else {
			subset[parentU].parent = parentV;
			subset[parentV].size += subset[parentU].size;
		}
	}
}
