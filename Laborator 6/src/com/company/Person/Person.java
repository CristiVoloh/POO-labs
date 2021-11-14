package com.company.Person;

import com.company.PersonData.Address;
import com.company.PersonData.FullName;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class Person {
    private String title;
    private String givenName;
    private String middleName;
    private String familyName;
    private FullName fullName;
    private Date birthDate;
    private Gender gender;
    private Address address;
    private Phone phone;

    public Person(){

    }

    public Person(String title, String givenName,
                  String middleName, String familyName, Date birthDate,
                  Gender gender, Address address, Phone phone) {

        this.title = title;
        this.givenName = givenName;
        this.middleName = middleName;
        this.familyName = familyName;
        this.fullName = new FullName(givenName, middleName, familyName);
        this.birthDate = birthDate;
        this.gender = gender;
        this.address = address;
        this.phone = phone;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
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

    public String getFullName() {
        return fullName.getName();
    }

    public void setFullName(FullName fullName) {
        this.fullName = fullName;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }

    public String getGender() {
        return gender.getGender();
    }

    public void setGender(Gender gender) {
        this.gender = gender;
    }

    public String getAddress() {
        return address.getAddress();
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String getPhone() {
        return phone.getPhone();
    }

    public void setPhone(Phone phone) {
        this.phone = phone;
    }

}
