package com.company.PersonData;

public class Address {
    private String street;
    private Integer houseNumber;
    private Integer flatNumber;
    private String address;

    public Address(){
        this.street = "not set";
        this.houseNumber = 0;
        this.flatNumber = 0;
    }

    public Address(String street, Integer houseNumber, Integer flatNumber) {
        this.street = street;
        this.houseNumber = houseNumber;
        this.flatNumber = flatNumber;
        this.address = street + Integer.toString(houseNumber) + Integer.toString(flatNumber);
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public Integer getHouseNumber() {
        return houseNumber;
    }

    public void setHouseNumber(Integer houseNumber) {
        this.houseNumber = houseNumber;
    }

    public Integer getFlatNumber() {
        return flatNumber;
    }

    public void setFlatNumber(Integer flatNumber) {
        this.flatNumber = flatNumber;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getAddress(){
        return address;
    }
}
