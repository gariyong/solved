import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        int[] dp = new int[12];

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i = 4; i < 12; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        while(t > 0){
            int n = input.nextInt();
            System.out.println(dp[n]);
            t--;
        }
        input.close();
    }
}