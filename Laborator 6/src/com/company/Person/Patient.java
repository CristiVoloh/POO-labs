package com.company.Person;

import com.company.PersonData.*;

import java.util.Date;

public class Patient extends Person{
    private String id;
    private Integer age;
    private Date accepted;
    private History sickness;
    private String[] prescriptions;
    private String[] allergies;
    private String[] specialReqs;


    public Patient(){

    }

    public Patient(String id, Integer age,
                   Date accepted, History sickness,
                   String[] prescriptions, String[] allergies,
                   String[] specialReqs) {

        this.id = id;
        this.age = age;
        this.accepted = accepted;
        this.sickness = sickness;
        this.prescriptions = prescriptions;
        this.allergies = allergies;
        this.specialReqs = specialReqs;
    }

    public Patient(String title, String givenName,
                   String middleName, String familyName,
                   Date birthDate, Gender gender, Address address,
                   Phone phone, String id, Integer age,
                   Date accepted, History sickness,
                   String[] prescriptions, String[] allergies, String[] specialReqs) {

        super(title, givenName, middleName, familyName, birthDate, gender, address, phone);
        this.id = id;
        this.age = age;
        this.accepted = accepted;
        this.sickness = sickness;
        this.prescriptions = prescriptions;
        this.allergies = allergies;
        this.specialReqs = specialReqs;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }


    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public Date getAccepted() {
        return accepted;
    }

    public void setAccepted(Date accepted) {
        this.accepted = accepted;
    }

    public History getSickness() {
        return sickness;
    }

    public void setSickness(History sickness) {
        this.sickness = sickness;
    }

    public String[] getPrescriptions() {
        return prescriptions;
    }

    public void setPrescriptions(String[] prescriptions) {
        this.prescriptions = prescriptions;
    }

    public String[] getAllergies() {
        return allergies;
    }

    public void setAllergies(String[] allergies) {
        this.allergies = allergies;
    }

    public String[] getSpecialReqs() {
        return specialReqs;
    }

    public void setSpecialReqs(String[] specialReqs) {
        this.specialReqs = specialReqs;
    }
}
