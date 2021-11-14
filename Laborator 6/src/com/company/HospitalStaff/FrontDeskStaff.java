package com.company.HospitalStaff;

import com.company.Hospital.AdministrativeStaff;
import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class FrontDeskStaff extends AdministrativeStaff {
    public FrontDeskStaff() {
    }

    public FrontDeskStaff(String title, String givenName, String middleName, String familyName, Date birthDate, Gender gender, Address address, Phone phone, Date joined, String[] education, String[] certification, String[] languages) {
        super(title, givenName, middleName, familyName, birthDate, gender, address, phone, joined, education, certification, languages);
    }

    public FrontDeskStaff(Date joined, String[] education, String[] certification, String[] languages) {
        super(joined, education, certification, languages);
    }
}
