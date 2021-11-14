package com.company;

import com.company.Hospital.Hospital;
import com.company.Person.Person;


public class Organization {
    private Hospital hospital;
    private Person people;

    public Organization(Hospital hospital, Person people) {
        this.hospital = hospital;
        this.people = people;
    }

    public Hospital getHospital() {
        return hospital;
    }

    public void setHospital(Hospital hospital) {
        this.hospital = hospital;
    }

    public Person getPeople() {
        return people;
    }

    public void setPeople(Person people) {
        this.people = people;
    }
}
