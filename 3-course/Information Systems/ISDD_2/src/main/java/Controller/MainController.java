package Controller;

//import Model.ConnectionDB;
//import Model.Member;
import Model.*;
import View.*;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * The MainController class handles the main logic and user interface of the Gym Management System.
 */
public class MainController {

    private ConnectionDB connection = null;
    private MemberDAO memberDAO = null;
    private ConsoleMessagesView messagesView = null;
    private MemberView memberView = null;

    /**
     * Constructs a MainController instance.
     *
     * @param connection The database connection object.
     */
    public MainController(ConnectionDB connection) {
        this.connection = connection;
        
        // Initialize Data Access Objects and Views
       
        memberDAO = new MemberDAO(connection);
        messagesView = new ConsoleMessagesView(); 
        memberView = new MemberView(); // to display member information
       // Start the main menu
        menu();
    }

    /**
     * Displays the main menu and handles user input.
     */
    private void menu() {
        while (true) {
            // Display menu options
            System.out.println("================================");
            System.out.println("           Gym Management       ");
            System.out.println("================================");
            System.out.println("1. List Members");
            System.out.println("2. Insert Member");
            System.out.println("3. Update Member");
            System.out.println("4. Delete Member");
            System.out.println("0. Exit");
            System.out.println("--------------------------------");
            System.out.printf("Select an option: ");
            
            // Handle user input
            Scanner scanner = new Scanner(System.in);
            int option = scanner.nextInt();
            scanner.nextLine(); // consume the newline character
            
            switch (option) {
                case 1:
                    try {
                        ArrayList<Member> membersList = requestMembers();
                        memberView.displayMembersWithNumberAndName(membersList);
                    } catch (SQLException e) {
                        messagesView.displayErrorMessage("Error in request", e.getMessage());
                    }
                    break;

                case 2:
                    try {
                        Member newMember = new Member("M011", "New Member",
                                "11222333X", "20/04/2000", "999000999", "new@Gym.com",
                                "24/09/23", "A");
                        addMember(newMember);
                        messagesView.displayMessage("Insertion Successful");
                    } catch (SQLException e) {
                        messagesView.displayErrorMessage("Error adding Member", e.getMessage());
                    }
                    break;
                case 3:
                    // TODO
                    
                    try{
                        System.out.printf("Introduce Member's Number: ");
                        String op = scanner.nextLine();
                        //if(memberDAO.existsMember(op)){
                            // Display menu options
                            System.out.println("================================");
                            System.out.println("           Update Member       ");
                            System.out.println("================================");
                            System.out.println("1. Member Name");
                            System.out.println("2. Member ID");
                            System.out.println("3. Member Birthdate");
                            System.out.println("4. Member Phone");
                            System.out.println("5. Member Email");
                            System.out.println("6. Member Starting Date");
                            System.out.println("7. Member Category");
                            System.out.println("0. Exit");
                            System.out.println("--------------------------------");
                            System.out.printf("Select an option: ");

                            // Handle user input
                            int xor = scanner.nextInt();
                            
                            //let's do it!
                            switch(xor){
                                case 1:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 2:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 3:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 4:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 5:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 6:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                case 7:
                                    memberDAO.updateMember(op, xor);
                                    break;
                                default:
                                    System.out.println("Invalid option. Please select a valid option.");
                                    break;
                            }
                        //}
                    }catch(SQLException e){
                        messagesView.displayErrorMessage("Error updatin Member", e.getMessage());
                    }
                     break;

                case 4:
                   // TODO
                    try{
                        System.out.println("Introduce Member's Number: ");
                        String op = scanner.nextLine();
                        memberDAO.deleteMember(op);
                    }catch(SQLException e){
                        messagesView.displayErrorMessage("Error deleting Member", e.getMessage());
                    }
                    break;
                case 0:
                    System.out.println("Exiting program. Goodbye!");
                    scanner.close(); // Close the scanner before exiting
                    System.exit(0);

                default:
                    System.out.println("Invalid option. Please select a valid option.");
                    break;
            }
        }
    }

    /**
     * Requests a list of members from the database.
     *
     * @return The list of members.
     * @throws SQLException If a database access error occurs.
     */
    private ArrayList<Member> requestMembers() throws SQLException {
        return memberDAO.listMembers();
    }

    /**
     * Adds a new member to the database.
     *
     * @param newMember The new member object.
     * @throws SQLException If a database access error occurs.
     */
    private void addMember(Member newMember) throws SQLException {
        memberDAO.insertMember(newMember);
    }
    
 
}