package com.company;

import org.w3c.dom.ls.LSOutput;

import java.util.ArrayList;
import java.util.List;

public class queue {
    int capacity;
    List<Box> limitedQ = new ArrayList<>(capacity);
    List<Box> unlimitedQ = new ArrayList<>();

    boolean limited = false;
    boolean unlimited = false;


    queue(int capacity){
        this.capacity = capacity;
        limited = true;
    }

    queue(){
        unlimited = true;
    }

    public boolean push(Box element){

        if(limited){
            try{
                limitedQ.add(element);
            }
            catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("The queue is full");
                return false;
            }
        }
        else if(unlimited)
            unlimitedQ.add(element);

        return true;
    }

    public Box pop() {
        Box element = null;

        if(unlimited){
            if(unlimitedQ.isEmpty()){
                System.out.println("Empty queue");
                return null;
            }
            element = unlimitedQ.get(0);
            unlimitedQ.remove(0);
        }
        else if(limited){
            if(limitedQ.isEmpty()){
                System.out.println("Empty queue");
                return null;
            }
            element = limitedQ.get(0);
            unlimitedQ.remove(0);
        }

        return element;
    }

    public boolean isEmpty(){
        if(limited)
            return limitedQ.isEmpty();
        else
            return unlimitedQ.isEmpty();
    }

}
