package com.company.Entities;

import java.util.ArrayList;
import java.util.List;

public class University {
    private String name;
    private int foundationYear;
    private List<Students> students;

    public University() {

    }

    public University(String name, int foundationYear, List<Students> students) {
        this.name = name;
        this.foundationYear = foundationYear;
        this.students = students;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFoundationYear() {
        return foundationYear;
    }

    public void setFoundationYear(int foundationYear) {
        this.foundationYear = foundationYear;
    }

    public List<Students> getStudents() {
        return students;
    }

    public void setStudents(List<Students> students) {
        this.students = students;
    }

    public Float generalUniversityMedia(){
        Float generalMedia = 0.0F;
        for (Students student : this.students) {
            generalMedia += student.averageMedia();
        }
        return (generalMedia/ students.size());
    }

    public static Float generalMedia(List<University> universities){
        Float generalMedia = 0F;

        for (University university : universities){
            generalMedia += university.generalUniversityMedia();
        }

        return (generalMedia / universities.size());
    }
}
