import java.util.*;
import java.io.*;

public class Main {
  
  public static int n;
  
  public static HashMap memo = new HashMap();
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    n = Integer.parseInt(in.readLine());
    
    int[][] values = new int[n][n * 2 -1];
    
    for (int i = 0; i < n; i ++)
      Arrays.fill(values[i],0);
    
    int half = n -1;
    
    int x = half;
    int count;
    
    String[] tokens;
    
    for (int i = 0; i < n; i ++) {
      tokens = in.readLine().split(" ");
      count = 0;
      for (int y = x; y < 2*n - 1; y += 2) {
        if (count >= tokens.length)
          break;
        values[i][y] = Integer.parseInt(tokens[count]);
        count ++;
      }
      x --;
    }
    
    System.out.println(dp(values,0,half));
  }
  
  public static int dp(int[][] val, int i, int j) {
    String key = Integer.toString(i) + "BB" + Integer.toString(j);
    int maxi, temp1 = 0, temp2 = 0;
    
    if (i == n) {
      return 0;
    }
    
    if (memo.containsKey(key)) {
      return (int)memo.get(key);
    }

    temp1 = dp(val, i+1, j +1) + val[i][j];
    temp2 = dp(val, i + 1, j - 1) + val[i][j];
    
    maxi = Math.max(temp1, temp2);
    memo.put(key,maxi);
    return maxi;
   }
}