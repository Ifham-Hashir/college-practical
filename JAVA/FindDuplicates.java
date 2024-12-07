import java.util.HashSet;
import java.util.Scanner;

public class FindDuplicates {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input for array size
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        // Take input for array elements
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Find duplicates
        HashSet<Integer> seen = new HashSet<>();
        System.out.println("Duplicate elements:");

        boolean hasDuplicates = false;
        for (int num : arr) {
            if (!seen.add(num)) {
                System.out.println(num);
                hasDuplicates = true;
            }
        }

        if (!hasDuplicates) {
            System.out.println("No duplicates found.");
        }

        sc.close();
    }
}

// Enter the number of elements: 5
// Enter the elements:
// 1 4 3 4 1
// Duplicate elements:
// 4
// 1
