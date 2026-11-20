import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        int sum = 0;
        int n;

        for(int i = 0; i < 5; i++){
            n = input.nextInt();
            sum += n;
        }
        System.out.println(sum);

        input.close();
    }
}