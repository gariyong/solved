import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        String s = input.next();

        if(s.charAt(0) == 'N' || s.charAt(0) == 'n'){
            System.out.println("Naver D2");
        }else{
            System.out.println("Naver Whale");
        }

        input.close();
    }
}