package com.company;

import com.company.AbstractClasses.GeometricBody;
import com.company.Bodies.Cub;
import com.company.Bodies.Parallelepiped;
import com.company.Bodies.Sphere;
import com.company.Controllers.GeometricBodyController;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Cub cub = new Cub(10.1, 17.3);
        Parallelepiped parallelepiped = new Parallelepiped(12.2, 11.1);
        Sphere sphere = new Sphere(14.2, 17.2);

        List<GeometricBody> geoList = new ArrayList<>();
        geoList.add(cub);
        geoList.add(parallelepiped);
        geoList.add(sphere);

        System.out.println(GeometricBodyController.getBiggestVolume(geoList).getVolume());
        System.out.println(GeometricBodyController.getBiggestSurface(geoList).getSurface());
    }
}
