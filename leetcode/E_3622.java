import java.util.Scanner;

public class E_3622 {
  public static void main(String[] args) {
    String ans = "false";
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    if (checkDivisibility(n)) {
      ans = "true";
    }
    System.out.println(ans);
    in.close();
  }

  private static boolean checkDivisibility(int n) {
    int m = n;
    long product = 1;
    int sum = 0;
    while (m != 0) {
      int digit = m % 10;
      sum += digit;
      product *= digit;
      m /= 10;
    }
    if (n % (sum + product) == 0) {
      return true;
    }
    return false;
  }
}
