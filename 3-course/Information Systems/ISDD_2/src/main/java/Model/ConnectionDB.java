package Model;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * The ConnectionDB class manages database connections and transactions.
 */
public class ConnectionDB {

    private Connection connection = null; // It is necessary to initialize the variable with null to indicate 
                                  // that at that moment, no connection to the database has been established. 

    /**
     * Default constructor that establishes a connection to the ETSI Oracle database.
     *
     * @throws ClassNotFoundException If the database driver class is not found.
     * @throws SQLException           If a database access error occurs.
     */
    public ConnectionDB() throws ClassNotFoundException, SQLException {
        String url = "jdbc:oracle:thin:@172.17.20.39:1521:etsi";
        String user = "ISDD_008";
        String password = "antonio12";
        connection = DriverManager.getConnection(url, user, password);
    }

    /**
     * Default constructor that allows connecting to different databases.
     *
     * @param dbms     The type of DBMS (e.g., "mariadb" or "oracle").
     * @param ip       The IP address of the database server.
     * @param db       The database name.
     * @param user     The username for authentication.
     * @param password The password for authentication.
     * @throws ClassNotFoundException If the database driver class is not found.
     * @throws SQLException           If a database access error occurs.
     */
    public ConnectionDB(String dbms, String ip, String db, String user, String password) throws ClassNotFoundException, SQLException {
        String aux = null;
        if (dbms.equals("mariadb"))
            aux = "jdbc:mariadb://" + ip + "/" + db;
        else if (dbms.equals("oracle"))
            aux = "jdbc:oracle:thin:@" + ip + ":1521:etsi";
        System.out.println(aux);
        connection = DriverManager.getConnection(aux, user, password);
    }

    /**
     * Retrieves the established database connection.
     *
     * @return The database connection.
     */
    public Connection getConnection() {
        return connection;
    }

    

    /**
     * Disconnects from the database.
     *
     * @return True if disconnection is successful, otherwise false.
     * @throws SQLException If a database access error occurs.
     */
    public boolean disconnect() throws SQLException {
        if (connection != null) {
            connection.close();
            return true;
        } else return false;
    }

    
}




