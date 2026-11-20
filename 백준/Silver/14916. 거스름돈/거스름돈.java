import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int cnt = 0;
        boolean flag = true;

        while(n > 0 && flag){
            if(n >= 5){
                n -= 5;
                cnt++;
            } else {
                if(n % 2 == 0){
                    cnt += n / 2;
                    break;
                } else {
                    flag = false;
                }
            }
        }

        if(!flag){
            while(true){
                n += 5;
                cnt--;

                if(cnt < 0){
                    cnt = -1;
                    break;
                }

                if(n % 2 == 0){
                    cnt += n / 2;
                    break;
                }
            }
        }

        System.out.println(cnt);
    }
}