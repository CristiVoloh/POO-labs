package com.company.Entities;

public class Students {
    public static int studentID;
    private String name;
    private int age;
    private int markMath;
    private int markProgramming;

    public Students() {
    }

    public Students(String name, int age, int markMath, int markProgramming) {
        this.name = name;
        this.age = age;
        this.markMath = markMath;
        this.markProgramming = markProgramming;
    }

    public static int getStudentID() {
        return studentID;
    }

    public static void setStudentID(int studentID) {
        Students.studentID = studentID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getMarkMath() {
        return markMath;
    }

    public void setMarkMath(int markMath) {
        this.markMath = markMath;
    }

    public int getMarkProgramming() {
        return markProgramming;
    }

    public void setMarkProgramming(int markProgramming) {
        this.markProgramming = markProgramming;
    }

    public float averageMedia(){
        Float media = (float)(this.markMath + this.markProgramming) / 2;
        return media;
    }
}
