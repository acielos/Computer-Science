package View;

import Model.Member;
import java.util.ArrayList;

/**
 * This class handles displaying member information in a user-friendly way.
 * 
 */
public class MemberView {
    
    /**
     * Display a list of members with their numbers and names.
     * @param memberList The list of members to display.
     */
    public void displayMembersWithNumberAndName(ArrayList<Member> memberList) {
        System.out.println("#Member" + "\t" + "Name" + "\t");
        for (Member member : memberList) {
            System.out.println(member.getMNum()     + "\t" + member.getMName());
        }
    }
    
}
