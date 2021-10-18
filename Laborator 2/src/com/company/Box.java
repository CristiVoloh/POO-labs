package com.company;

public class Box {
    private float height;
    private float width;
    private float depth;

    {
        height = 1f;
        width = 1f;
        depth = 1f;
    }

    public Box(int value){
        this.height = value;
        this.width = value;
        this.depth = value;
    }

    public Box(int height, int width, int deph) {
        this.height = height;
        this.width = width;
        this.depth = deph;
    }

    public float getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public float getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public float getDeph() {
        return depth;
    }

    public void setDeph(int deph) {
        this.depth = deph;
    }

    public double getArea(){
        return 2*(width*height) + 2*(width*depth) + 2*(height*depth);
    }

    public double getVolume(){
        return height*width*depth;
    }
}
