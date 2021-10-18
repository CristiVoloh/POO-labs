package com.company.Entities;

public class Monitor implements Comparable<Monitor>{
    private String color;
    private Resolution resolution;
    private String dimension;

    public Monitor(){

    }

    public Monitor(String color, Resolution resolution, String dimension) {
        this.color = color;
        this.resolution = resolution;
        this.dimension = dimension;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Resolution getResolution() {
        return resolution;
    }

    public void setResolution(Resolution resolution) {
        this.resolution = resolution;
    }

    public String getDimension() {
        return dimension;
    }

    public void setDimension(String dimension) {
        this.dimension = dimension;
    }


    @Override
    public int compareTo(Monitor monitor) {
        if(this.resolution.compareResolution(monitor.resolution))
            return 1;
        else
            return 0;
    }
}
