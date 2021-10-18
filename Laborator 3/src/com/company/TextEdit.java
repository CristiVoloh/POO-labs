package com.company;

import java.util.*;

public class TextEdit {

    String text;

    public TextEdit(String text) {
        this.text = text;
    }

    public TextEdit() {
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public static int sentenceCount (String text){
        if (text == null || text.isEmpty()) {
            return 0;
        }

        return text.split("[!?.:]+").length;
    }

    public static int wordCount (String text) {
        if (text == null || text.isEmpty())
            return 0;

        return text.split("\\s+").length;
    }

    public static int consonantCount (String text){
        int consonasCount = 0;

        if (text == null || text.isEmpty())
            return 0;

        for(int i = 0; i < text.length(); i++){
            if(text.charAt(i) >= 'a' && text.charAt(i)<='z') {
                consonasCount++;
            }
        }

        return consonasCount;
    }

    public static int vowelsCount (String text){
        int vowelsCount = 0;

        if (text == null || text.isEmpty())
            return 0;

        for(int i = 0; i < text.length(); i++){
            if(text.charAt(i) == 'a' || text.charAt(i) == 'e' || text.charAt(i) == 'i' || text.charAt(i) == 'o' || text.charAt(i) == 'u') {
                vowelsCount++;
            }
        }

        return vowelsCount;
    }

    public static void topWords (String text){
        Map<String, Integer> topWords = new HashMap<>();
        String[] proccessedText = text.split("\\s+");

        for(String word: proccessedText){
            if(topWords.containsKey(word)){
                Integer value = topWords.get(word);
                topWords.put(word, ++value);
            }
            else{
                topWords.put(word, 1);
            }
        }


        System.out.println("Top 3 words: ");

        Integer temp = text.length();
        List<String> top3list = new ArrayList();

        while(temp != 0){
            for(Map.Entry<String, Integer> entry: topWords.entrySet()) {
                if (temp.equals(entry.getValue()) && !top3list.contains(entry.getKey())) {
                    top3list.add(entry.getKey());
                }
            }
            temp--;
        }
        for(int i = 0; i < 3; i++){
            System.out.println(top3list.get(i));
        }

    }

}
