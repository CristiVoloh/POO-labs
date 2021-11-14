package com.company.Hospital;

import com.company.Person.Staff;

import java.util.ArrayList;
import java.util.List;

public class Department {
    private List<Staff> staffList = new ArrayList<>();

    public Department(){

    }
    public Department(List<Staff> staffList) {
        this.staffList = staffList;
    }

    public List<Staff> getStaffList() {
        return staffList;
    }

    public void setStaffList(List<Staff> staffList) {
        this.staffList = staffList;
    }
}
