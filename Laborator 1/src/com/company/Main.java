package com.company;

import com.company.Entities.Students;
import com.company.Entities.University;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Students> firstGroup = new ArrayList<>();
        firstGroup.add(new Students("Cristi", 20, 7, 9));
        firstGroup.add(new Students("Mark", 19, 6, 8));
        firstGroup.add(new Students("John", 23, 7, 6));


        List<Students> secondGroup = new ArrayList<>();
        secondGroup.add(new Students("Marcel", 20, 7, 5));
        secondGroup.add(new Students("Surea", 19, 6, 4));
        secondGroup.add(new Students("Danik", 23, 1, 8));

        List<Students> thirdGroup = new ArrayList<>();
        thirdGroup.add(new Students("Lobstr", 20, 7, 5));
        thirdGroup.add(new Students("Scopuly", 19, 6, 5));
        thirdGroup.add(new Students("Whip", 23, 6, 5));

        University firstUni = new University("Oxford", 2001, firstGroup);
        University secondUni = new University("Cambridge", 1957, secondGroup);
        University thirdUni = new University("Endava", 2000, thirdGroup);

        List<University> universities = new ArrayList<>();
        universities.add(firstUni);
        universities.add(secondUni);
        universities.add(thirdUni);

        System.out.println("Media of the first univeristy: " + firstUni.generalUniversityMedia());
        System.out.println("Media of the second university: " + secondUni.generalUniversityMedia());
        System.out.println("Media of the third university: " + thirdUni.generalUniversityMedia());
        System.out.println("General media of the universities: " + University.generalMedia(universities));
    }
}
