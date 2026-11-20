import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int[] T = new int[n];
        int[] P = new int[n];
        int[] dp = new int[n + 1];

        for(int i = 0; i < n; i++){
            T[i] = input.nextInt();
            P[i] = input.nextInt();            
        }

        for(int i = 0; i < n; i++){
            dp[i + 1] = Math.max(dp[i + 1], dp[i]);

            if(i + T[i] <= n){
                dp[i + T[i]] = Math.max(dp[i + T[i]], dp[i] + P[i]);
            }
        }

        System.out.println(dp[n]);
        input.close();
    }
}