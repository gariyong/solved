import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] solution = new int[n];

        for(int i = 0; i < n; i++){
            solution[i] = input.nextInt();
        }

        int low = 0;
        int high = n - 1;
        int minAbs = Integer.MAX_VALUE;
        int sol_val1 = 0;
        int sol_val2 = 0;

        while(low < high){
            int value = solution[low] + solution[high];
            int absVal = Math.abs(value);

            if(absVal < minAbs){
                minAbs = absVal;
                sol_val1 = solution[low];
                sol_val2 = solution[high];
            }

            if(value < 0){
                low++;
            } else {
                high--;
            }
        }

        System.out.printf("%d %d\n", sol_val1, sol_val2);
        input.close();
    }
}