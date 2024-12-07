public class ReverseArray {
  public static void main(String[] args) {
      // Create an integer array
      int[] a = {9, 3, 6, 8, 4, 7};
      
      // Print the array elements in reverse order
      System.out.print("Array in reverse: ");
      for (int i = a.length - 1; i >= 0; i--) {
          System.out.print(a[i] + " ");
      }
  }
}

// Array in reverse: 7 4 8 6 3 9