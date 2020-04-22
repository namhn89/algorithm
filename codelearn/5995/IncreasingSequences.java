import java.util.HashSet;
import java.util.Arrays;
import java.util.Set;
 
public class IncreasingSequences {
    static final long MODULO = 998244353;
 
    public static int countLISHard(int[] L, int[] R) {
        Set<Integer> interestingSet = new HashSet<>();
        for (int x : L) interestingSet.add(x);
        for (int x : R) interestingSet.add(x + 1);
        int[] interesting = new int[interestingSet.size()];
        int ptr = 0;
        for (int x : interestingSet) interesting[ptr++] = x;
        if (ptr != interesting.length) throw new RuntimeException();
        Arrays.sort(interesting);
 
        long[] invs = new long[R.length + 1];
        if (1 < invs.length)
            invs[1] = 1;
        for (int i = 2; i < invs.length; ++i) {
            invs[i] = (MODULO - invs[((int) (MODULO % i))] * (MODULO / i) % MODULO) % MODULO;
            if (invs[i] * i % MODULO != 1) throw new RuntimeException();
        }
 
        long[] ways = new long[R.length + 1];
        ways[0] = 1;
 
        for (int block = 0; block + 1 < interesting.length; ++block) {
            long blockSize = interesting[block + 1] - interesting[block];
            long[] comb = new long[R.length + 1];
            comb[0] = 1;
            for (int i = 1; i < comb.length; ++i) {
                comb[i] = comb[i - 1] * (blockSize - i + 1) % MODULO * invs[i] % MODULO;
            }
            long[] nways = new long[R.length + 1];
            for (int last = 0; last <= R.length; ++last) {
                long s = 0;
                for (int count = 0; count <= last; ++count) {
                    if (count > 0) {
                        int cur = last - count;
                        if (L[cur] >= interesting[block + 1] || R[cur] + 1 <= interesting[block]) break;
                        if (L[cur] > interesting[block] || R[cur] + 1 < interesting[block + 1])
                            throw new RuntimeException();
                    }
                    s = (s + comb[count] * ways[last - count]) % MODULO;
                }
                nways[last] = s % MODULO;
            }
            ways = nways;
        }
        return (int) ways[R.length];
    }
    public static void main(String[] args) {
        int[] L = new int[] {10, 30}; 
        int[] R = new int[] {20, 40};
        System.out.println(countLISHard(L, R)); 
    }
 
}