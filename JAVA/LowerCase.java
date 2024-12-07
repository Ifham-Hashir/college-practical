import java.util.Scanner;

public class LowerCase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input from the user
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        // Convert to lowercase
        String lowerCaseStr = input.toLowerCase();

        // Output result
        System.out.println("Lowercase String: " + lowerCaseStr);
        
        sc.close();
    }
}

// Enter a string: Ifham
// Lowercase String: ifham