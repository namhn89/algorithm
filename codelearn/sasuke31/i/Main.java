package codelearn.sasuke31.i;

import java.util.BitSet;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

public class Main {
    final static int MOD = 1_000_000_007;
    public static int fillBoard(String[] grid) {
        final int[][][] shapes = {
            {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
            {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
            {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}
            ,
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
            {{0, 0}, {1, 0}, {1, 1}, {1, 2}}
            ,
            {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
        };
        int m = grid.length; 
        int n = grid[0].length();
        // System.out.println(m + " " + n);
        BitSet base = new BitSet(n * m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i].charAt(j) == '#') {
                    base.set(j + i * n);
                }
            }
        }

        HashMap<BitSet, Integer> hashMap = new HashMap<BitSet, Integer>(); 
        PriorityQueue<BitSet> priorityQueue = new PriorityQueue<BitSet>(n * m, new Comparator<BitSet>() {
            @Override
            public int compare(BitSet o1, BitSet o2) {
                int i1 = o1.nextClearBit(0);
                int i2 = o2.nextClearBit(0);
                return i1 - i2;
            }
        });
        // System.out.println(base); 
        hashMap.put(base, 1); 
        priorityQueue.add(base); 

        while(!priorityQueue.isEmpty()) {
            BitSet u = priorityQueue.poll(); 
            int val = hashMap.get(u); 
            // System.out.println(u); 
            int state = u.nextClearBit(0); 
            if (state == n * m) {
                return val; 
            }
            int x = state % n, y = state / n;
            // System.out.println(x + " " + y); 
            loop: for (int[][] ps : shapes) {
                BitSet nextState = (BitSet) u.clone();
                for (int[] p : ps) {
                    int xx = x + p[0];
                    int yy = y + p[1];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m || u.get(xx + yy * n)) {
                        continue loop;
                    }
                    nextState.set(xx + yy * n);
                }
                // System.out.println(state); 
                // System.out.println("--->");
                // System.out.println(nextState); 
                if (!hashMap.containsKey(nextState)) {
                    hashMap.put(nextState, 0);
                    priorityQueue.add(nextState);
                }
                hashMap.put(nextState, (hashMap.get(nextState) + val) % MOD);
            }
        }
        return 0; 
    }
    public static void main(String[] args) {
        String[] strings = new String[]{"#.#", "..."}; 
        System.out.println(fillBoard(strings));
    }
}