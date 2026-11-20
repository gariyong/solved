import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        
        if(n / 10 == n % 10){
            System.out.println(1);
        }else{
            System.out.println(0);
        }

        input.close();
    }
}