import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int max = 0, answer = 0;
        long low = 1;
        long high, mid;
        int k = input.nextInt();
        int n = input.nextInt();
        int[] line = new int[k];

        for(int i = 0; i<k; i++){
            line[i] = input.nextInt();
            max = Math.max(line[i], max);
        }
        high = max;

        while(low <= high){
            int cnt = 0;
            mid = (low + high)/2;
            
            for(int i = 0; i<k; i++){
                cnt += line[i] /mid;
            }

            if(cnt >= n){
                low = mid + 1;
                if(answer < mid){
                    answer = (int) mid;
                }
            }else{
                high = mid - 1;
            }
        }

        System.out.println(answer);
        input.close();
    }
}