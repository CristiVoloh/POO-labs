package com.company.HospitalStaff.SubStaff;

import com.company.HospitalStaff.Doctor;
import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class Surgeon extends Doctor {
    public Surgeon(String[] specialty, String[] locations) {
        super(specialty, locations);
    }

    public Surgeon(String title, String givenName, String middleName, String familyName, Date birthDate, Gender gender, Address address, Phone phone, Date joined, String[] education, String[] certification, String[] languages, String[] specialty, String[] locations) {
        super(title, givenName, middleName, familyName, birthDate, gender, address, phone, joined, education, certification, languages, specialty, locations);
    }

    public Surgeon(Date joined, String[] education, String[] certification, String[] languages, String[] specialty, String[] locations) {
        super(joined, education, certification, languages, specialty, locations);
    }
}
