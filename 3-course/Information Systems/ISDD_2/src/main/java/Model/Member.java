package Model;
/**
 * The Member class represents a member in the gym.
 */
public class Member {
    private String mNum;
    private String mName;
    private String mId;
    private String mBirthdate;
    private String mPhone;
    private String mEmailMember;
    private String mStartingDateMember;
    private String mCategoryMember;
    
    public Member() {
        this.mNum = null;
        this.mName = null;
        this.mId = null;
        this.mBirthdate = null;
        this.mPhone = null;
        this.mEmailMember = null;
        this.mStartingDateMember = null;
        this.mCategoryMember = null;
    }
    
    // Constructor
    public Member(String mNum, String mName, String mId, String mBirthdate, String mPhone,
                  String mEmailMember, String mStartingDateMember, String mCategoryMember) {
        this.mNum = mNum;
        this.mName = mName;
        this.mId = mId;
        this.mBirthdate = mBirthdate;
        this.mPhone = mPhone;
        this.mEmailMember = mEmailMember;
        this.mStartingDateMember = mStartingDateMember;
        this.mCategoryMember = mCategoryMember;
    }
    
    public Member(String mNum, String mName, String mId, String mStartingDateMember, String mCategoryMember) {
        this.mNum = mNum;
        this.mName = mName;
        this.mId = mId;
        this.mStartingDateMember = mStartingDateMember;
        this.mCategoryMember = mCategoryMember;
    }

    // Getters and Setters
    public String getMNum() {
        return mNum;
    }

    public void setMNum(String mNum) {
        this.mNum = mNum;
    }

    public String getMName() {
        return mName;
    }

    public void setMName(String mName) {
        this.mName = mName;
    }

    public String getMId() {
        return mId;
    }

    public void setMId(String mId) {
        this.mId = mId;
    }

    public String getMBirthdate() {
        return mBirthdate;
    }

    public void setMBirthdate(String mBirthdate) {
        this.mBirthdate = mBirthdate;
    }

    public String getMPhone() {
        return mPhone;
    }

    public void setMPhone(String mPhone) {
        this.mPhone = mPhone;
    }

    public String getMEmailMember() {
        return mEmailMember;
    }

    public void setMEmailMember(String mEmailMember) {
        this.mEmailMember = mEmailMember;
    }

    public String getMStartingDateMember() {
        return mStartingDateMember;
    }

    public void setMStartingDateMember(String mStartingDateMember) {
        this.mStartingDateMember = mStartingDateMember;
    }

    public String getMCategoryMember() {
        return mCategoryMember;
    }

    public void setMCategoryMember(String mCategoryMember) {
        this.mCategoryMember = mCategoryMember;
    }
}

