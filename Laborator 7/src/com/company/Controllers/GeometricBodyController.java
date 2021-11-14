package com.company.Controllers;

import com.company.AbstractClasses.GeometricBody;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class GeometricBodyController {

    public static GeometricBody getBiggestVolume(List<GeometricBody> bodies) {
        return Collections.max(bodies, new Comparator<GeometricBody>() {
            @Override
            public int compare(GeometricBody a, GeometricBody b) {

                if(a.getVolume() < b.getVolume())
                    return -1;
                else if(a.getVolume() == b.getVolume())
                    return 0;
                else
                    return 1;
            }
        });
    }

    public static GeometricBody getBiggestSurface(List<GeometricBody> bodies) {
        return Collections.max(bodies, new Comparator<GeometricBody>() {
            @Override
            public int compare(GeometricBody a, GeometricBody b){
                if(a.getSurface() < b.getSurface())
                    return -1;
                else if(a.getSurface() == b.getSurface())
                    return 0;
                else
                    return 1;
            }
        });
    }
}
