package com.company.HospitalStaff;

import com.company.Hospital.OperationsStaff;
import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class Doctor extends OperationsStaff {
    public String[] specialty;
    public String[] locations;

    public Doctor(String[] specialty, String[] locations) {
        this.specialty = specialty;
        this.locations = locations;
    }

    public Doctor(String title, String givenName, String middleName, String familyName, Date birthDate, Gender gender, Address address, Phone phone, Date joined, String[] education, String[] certification, String[] languages, String[] specialty, String[] locations) {
        super(title, givenName, middleName, familyName, birthDate, gender, address, phone, joined, education, certification, languages);
        this.specialty = specialty;
        this.locations = locations;
    }

    public Doctor(Date joined, String[] education, String[] certification, String[] languages, String[] specialty, String[] locations) {
        super(joined, education, certification, languages);
        this.specialty = specialty;
        this.locations = locations;
    }

    public String[] getSpecialty() {
        return specialty;
    }

    public void setSpecialty(String[] specialty) {
        this.specialty = specialty;
    }

    public String[] getLocations() {
        return locations;
    }

    public void setLocations(String[] locations) {
        this.locations = locations;
    }
}
