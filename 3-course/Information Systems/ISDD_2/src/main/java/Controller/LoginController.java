package Controller;

import Model.ConnectionDB;
import View.ConsoleMessagesView;
import java.sql.SQLException;

/**
 * The LoginController class manages user authentication and database connection.
 */
public class LoginController {

    private ConnectionDB connection = null;
    private ConsoleMessagesView messageView = null;
    private MainController controller = null;
   
    /**
     * Constructor for LoginController class.
     * Initializes ConsoleMessagesView, DBInfoView, and establishes a database connection.
     */
    public LoginController() {
        messageView = new ConsoleMessagesView();
        connection = connect();
        MainController controller = new MainController(connection);
    }
    
    /**
     * Establishes a connection to the database.
     *
     * @return The established ConnectionDB object.
     */
    private ConnectionDB connect() {
        try {
            // String server = "oracle";
            // String ip = "172.17.20.39";
            // String bd = "etsi";
            String server = "mariadb";
            String ip = "172.18.1.241";
            String bd = "ISDD_008";
            String u = "ISDD_008";
            String p = "antonio12";
            //connection = new ConnectionDB(server, ip, bd, u, p);
            connection = new ConnectionDB(); // to connect with the server
            messageView.displayMessage("Connection Successful"); 

        } catch (SQLException sqle) {
            messageView.displayMessage("Error in connection. Please check the provided parameters: " + sqle.getMessage());
        } catch (ClassNotFoundException ex) {
            messageView.displayMessage("Unknown Error: " + ex.getMessage());
        }
        return connection;
    }   

    /**
     * Disconnects from the database.
     *
     * @return True if disconnection is successful, otherwise false.
     */
    public boolean disconnect() {
        boolean result = false;
        if (connection != null) {	        
            try {	
                connection.disconnect();
                messageView.displayMessage("Successful Disconnection");
                result = true;
            }
            catch (SQLException sqle)  {
                messageView.displayErrorMessage("Error", sqle.getMessage());    
            }      
        }
        return result;
    }
}
