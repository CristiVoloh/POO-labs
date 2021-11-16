package com.company;

import org.w3c.dom.ls.LSOutput;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static boolean checkExpression(String exp){
        Stack s = new Stack();
        boolean isValid;

        for(char c: exp.toCharArray()){
            if(c == '('){
                s.push("(");
            }
            else if(c == ')' && !s.contains("(")){
                isValid = false;
                return isValid;
            }
            else if(c == ')' && s.contains("(")){
                s.pop();
            }
        }

        if(!s.isEmpty()){
            isValid = false;
        }
        else {
            isValid = true;
        }

        return isValid;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("one_expression.txt");
        Scanner scanner = new Scanner(file);
        String str = scanner.nextLine();
        System.out.println("Expression: " + str);
        System.out.println("Valid expression: " + checkExpression(str));
    }
}
