package com.company.PersonData;

public class FullName {
    private String givenName;
    private  String middleName;
    private String familyName;

    public FullName() {
    }

    public FullName(String givenName, String middleName, String familyName) {
        this.givenName = givenName;
        this.middleName = middleName;
        this.familyName = familyName;
    }

    public String getGivenName() {
        return givenName;
    }

    public void setGivenName(String givenName) {
        this.givenName = givenName;
    }

    public String getMiddleName() {
        return middleName;
    }

    public void setMiddleName(String middleName) {
        this.middleName = middleName;
    }

    public String getFamilyName() {
        return familyName;
    }

    public void setFamilyName(String familyName) {
        this.familyName = familyName;
    }

    public String getName(){
        return givenName+middleName+familyName;
    }
}
