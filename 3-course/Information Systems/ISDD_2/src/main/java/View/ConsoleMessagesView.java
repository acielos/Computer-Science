package View;

/**
 * This class handles console messages for better user interaction.
 * @author Vicky
 */
public class ConsoleMessagesView {

    /**
     * Display a user message in the console.
     * @param message The message to display.
     */
    public void displayMessage(String message) {
        System.out.println("****************************************");
        System.out.println(message);
        System.out.println("****************************************");
    }

    /**
     * Display an error message along with a user message in the console.
     * @param message The user message.
     * @param error The error message.
     */
    public void displayErrorMessage(String message, String error) {
        System.out.println("****************************************");
        System.out.println(message);
        System.out.println(error);
        System.out.println("****************************************");
    }

}