import java.io.IOException;

public class OpenNotepad {
    @SuppressWarnings("deprecation")
    public static void main(String[] args) {
        try {
            // Open Notepad
            Runtime.getRuntime().exec("notepad.exe");
            System.out.println("Notepad opened successfully!");
        } catch (IOException e) {
            System.out.println("Error opening Notepad: " + e.getMessage());
        }
    }
}

//Notepad opened successfully!