package com.company.PersonData;

import java.util.List;

public class History {
    private List<String> sicknesses;

    public History(){

    }

    public History(List<String> sicknesses) {
        this.sicknesses = sicknesses;
    }

    public List<String> getSicknesses() {
        return sicknesses;
    }

    public void setSicknesses(List<String> sicknesses) {
        this.sicknesses = sicknesses;
    }

    public void addSickness(String sickness){
        sicknesses.add(sickness);
    }

    public boolean removeSickness(String sickness){
        return sicknesses.remove(sickness);
    }

}
