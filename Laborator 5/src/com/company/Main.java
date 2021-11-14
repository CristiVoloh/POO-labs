package com.company;

public class Main {

    public static void main(String[] args) {
        Letters.J j = new Letters.J("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", new Letters.X("x"));
        System.out.println(j.print());
    }
}
