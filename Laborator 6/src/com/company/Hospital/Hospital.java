package com.company.Hospital;

import com.company.Person.Patient;
import com.company.Person.Person;
import com.company.PersonData.Address;
import com.company.PersonData.Phone;

import java.util.List;

public class Hospital {
    private String name;
    private Address address;
    private Phone phone;
    private List<Department> departments;
    private List<Person> people;

    public Hospital(){

    }

    public Hospital(String name, Address address, Phone phone, List<Department> departments, List<Person> people) {
        this.name = name;
        this.address = address;
        this.phone = phone;
        this.departments = departments;
        this.people = people;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public Phone getPhone() {
        return phone;
    }

    public void setPhone(Phone phone) {
        this.phone = phone;
    }

    public List<Department> getDepartments() {
        return departments;
    }

    public void setDepartments(List<Department> departments) {
        this.departments = departments;
    }

    public List<Person> getPeople() {
        return people;
    }

    public void setPeople(List<Person> people) {
        this.people = people;
    }
}
