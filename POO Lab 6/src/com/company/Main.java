package com.company;

import com.company.Hospital.Department;
import com.company.Hospital.Hospital;
import com.company.HospitalStaff.Doctor;
import com.company.HospitalStaff.SubStaff.Surgeon;
import com.company.Person.Patient;
import com.company.Person.Person;
import com.company.Person.Staff;
import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Hospital hospital = new Hospital();
        List<Department> departments = new ArrayList<>();
        List<Person> people = new ArrayList<>();

        // Emergency department //
        Department emergency = new Department();
        List<Staff> emergencyStaff = new ArrayList<>();

        emergencyStaff.add(
                new Staff("Emergency1", "Emergency1 - Givenname", "Emergency1 - MiddleName", "Emergency1 - FamilyName",
                    new Date(01, 02, 2001),
                    new Gender("M"),
                    new Address("Botanica", 2, 39),
                    new Phone("+37360102807"),
                    new Date(10, 07, 2010),
                    new String[]{"Math, Sport"},
                    new String[]{"Massage"},
                    new String[]{"Romanian", "English"})
        );

        emergencyStaff.add(
                new Surgeon("Emergency2", "Emergency1 - Givenname", "Emergency1 - MiddleName", "Emergency1 - FamilyName",
                        new Date(01, 02, 2001),
                        new Gender("M"),
                        new Address("Botanica", 2, 39),
                        new Phone("+37360102807"),
                        new Date(10, 07, 2010),
                        new String[]{"Math, Sport"},
                        new String[]{"Massage"},
                        new String[]{"Romanian", "English"},
                        new String[]{"Oculist"},
                        new String[]{"Hospital"})
        );

        emergency.setStaffList(emergencyStaff); // Set staff list to Department
        departments.add(emergency); // Add emergency Department to Hospital

        people.addAll(emergencyStaff); // Add staff list to People
        ///////////////////////////////////

        hospital.setAddress(new Address("Burebista", 90, 0));
        hospital.setName("Hospital1");
        hospital.setPhone(new Phone("+373111111"));
        hospital.setDepartments(departments);
        hospital.setPeople(people);

    }
}
