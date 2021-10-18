package com.company.Entities;

public class Resolution {
    private int height;
    private int width;

    public Resolution() {
    }

    public Resolution(int height, int width) {
        this.height = height;
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public boolean compareResolution(Resolution object){
        if((this.height * this.width) > (object.height * object.width))
            return true;
        else
            return false;
    }
}
