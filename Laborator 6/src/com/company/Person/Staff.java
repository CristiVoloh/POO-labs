package com.company.Person;

import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class Staff extends Person{
    public Date joined;
    public String[] education;
    public String[] certification;
    public String[] languages;

    public Staff(){

    }

    public Staff(String title, String givenName, String middleName, String familyName, Date birthDate, Gender gender, Address address, Phone phone, Date joined, String[] education, String[] certification, String[] languages) {
        super(title, givenName, middleName, familyName, birthDate, gender, address, phone);
        this.joined = joined;
        this.education = education;
        this.certification = certification;
        this.languages = languages;
    }

    public Staff(Date joined, String[] education, String[] certification, String[] languages) {
        this.joined = joined;
        this.education = education;
        this.certification = certification;
        this.languages = languages;
    }

    public Date getJoined() {
        return joined;
    }

    public void setJoined(Date joined) {
        this.joined = joined;
    }

    public String[] getEducation() {
        return education;
    }

    public void setEducation(String[] education) {
        this.education = education;
    }

    public String[] getCertification() {
        return certification;
    }

    public void setCertification(String[] certification) {
        this.certification = certification;
    }

    public String[] getLanguages() {
        return languages;
    }

    public void setLanguages(String[] languages) {
        this.languages = languages;
    }
}
