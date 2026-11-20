import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int M = input.nextInt();
        int K = input.nextInt();

        if (M % K == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        input.close();
    }
}