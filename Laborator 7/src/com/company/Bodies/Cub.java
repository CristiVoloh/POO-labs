package com.company.Bodies;

import com.company.AbstractClasses.GeometricBody;

public class Cub implements GeometricBody {
    private double surface;
    private double volume;

    public Cub() {
    }

    public Cub(double surface, double volume) {
        this.surface = surface;
        this.volume = volume;
    }

    public void setSurface(double surface) {
        this.surface = surface;
    }

    public void setVolume(double volume) {
        this.volume = volume;
    }

    @Override
    public double getSurface() {
        return surface;
    }

    @Override
    public double getVolume() {
        return volume;
    }
}
