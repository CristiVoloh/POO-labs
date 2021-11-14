package com.company.HospitalStaff.SubStaff;

import com.company.HospitalStaff.Technologist;
import com.company.PersonData.Address;
import com.company.PersonData.Gender;
import com.company.PersonData.Phone;

import java.util.Date;

public class SurgicalTechnologist extends Technologist {
    public SurgicalTechnologist() {
    }

    public SurgicalTechnologist(String title, String givenName, String middleName, String familyName, Date birthDate, Gender gender, Address address, Phone phone, Date joined, String[] education, String[] certification, String[] languages) {
        super(title, givenName, middleName, familyName, birthDate, gender, address, phone, joined, education, certification, languages);
    }

    public SurgicalTechnologist(Date joined, String[] education, String[] certification, String[] languages) {
        super(joined, education, certification, languages);
    }
}
