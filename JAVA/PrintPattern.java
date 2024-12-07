public class PrintPattern {
  public static void main(String[] args) {
      String result = ""; // To store the pattern
      for (int i = 1; i <= 7; i++) {
          result += i;  // Append the current number
          System.out.print(result + " * "); // Print the current pattern followed by "*"
      }
  }
}

//1 * 12 * 123 * 1234 * 12345 * 123456 * 1234567 *
