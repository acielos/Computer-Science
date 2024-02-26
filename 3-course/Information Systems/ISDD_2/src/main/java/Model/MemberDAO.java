package Model;

import View.ConsoleMessagesView;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import Model.*;
import Controller.*;
import View.*;
import Application.*;
import java.util.Scanner;

/**
 * The MemberDAO class handles the data access operations for members.
 */
public class MemberDAO {

    ConnectionDB connection = null;
    PreparedStatement ps = null;
    
    /**
     * Constructor that takes a ConnectionDB object to establish database connection.
     * @param c The ConnectionDB object for database connection.
     */
    public MemberDAO(ConnectionDB c) {
        this.connection = c;
    }

    /**
     * Checks if a member with a specific number exists in the database.
     * @param memberNumber The number of the member to check.
     * @return True if the member exists, false otherwise.
     * @throws SQLException If a database access error occurs.
     */
    public boolean existsMember(String memberNumber) throws SQLException {
        ps = connection.getConnection().prepareStatement("SELECT * from MEMBER where M_NUM= '" + memberNumber + "'");
        ps.setString(1, memberNumber);
        ResultSet rs = ps.executeQuery();
        boolean result = rs.next();
        ps.close();

        return result;
    }

    /**
     * Retrieves a list of all members from the database.
     * @return An ArrayList of Member objects representing the members.
     * @throws SQLException If a database access error occurs.
     */
    public ArrayList<Member> listMembers() throws SQLException {
        ArrayList<Member> membersList = new ArrayList<>();

        String query = "SELECT * FROM MEMBER";
        ps = connection.getConnection().prepareStatement(query);
        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            Member member = new Member(
                    rs.getString(1), rs.getString(2),
                    rs.getString(3), rs.getString(4),
                    rs.getString(5), rs.getString(6),
                    rs.getString(7), rs.getString(8)
            );
            membersList.add(member);
        }

        return membersList;
    }

    

    /**
     * Inserts a new member into the database.
     * @param member The Member object representing the new member.
     * @throws SQLException If a database access error occurs.
     */
    public void insertMember(Member member) throws SQLException {
        ps = connection.getConnection().prepareStatement("INSERT INTO MEMBER VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        ps.setString(1, member.getMNum());
        ps.setString(2, member.getMName());
        ps.setString(3, member.getMId());
        ps.setString(4, member.getMBirthdate());
        ps.setString(5, member.getMPhone());
        ps.setString(6, member.getMEmailMember());
        ps.setString(7, member.getMStartingDateMember());
        ps.setString(8, member.getMCategoryMember());

        ps.executeUpdate();
        ps.close();
    }

    /**
     * Updates the information of an existing member in the database.
     * @param memberNumber The Member object representing the updated member information.
     * @throws SQLException If a database access error occurs.
     */
    public void updateMember(String memberNumber, int op) throws SQLException {
        // TODO
        String change;
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.printf("Introduce new change: ");
        change = scanner.nextLine();
        
       if(op == 1){
           //name
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_NAME= " + "'" + change + "'" + " WHERE M_NUM = " + "'" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op == 2){
           //id
          
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_ID= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op == 3){
           //birthdate
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_BIRTHDATE= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op == 4){
           //phone
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_PHONE= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op == 5){
           //email
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_EMAILMEMBER= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op == 6){
           //statting date
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_STARTINGDATEMEMBER= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
           
       }else if(op ==7){
           //category
           
           ps = connection.getConnection().prepareStatement("UPDATE MEMBER SET M_CATEGORYMEMBER= '" + change + "' WHERE M_NUM= '" + memberNumber + "'");
           ps.executeUpdate();
       }
           
       
    }
   

    /**
     * Deletes a member from the data1base.
     * @param memberNumber The number of the member to be deleted.
     * @throws SQLException If a database access error occurs.
     */
    public void deleteMember(String memberNumber) throws SQLException {
        // TODO
        ps =connection.getConnection().prepareStatement("DELETE from MEMBER WHERE M_NUM= " + "'" + memberNumber+"'");
        ps.executeUpdate();
        
        
    }
    
}
