//
//  Customer.h
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <string>
#include <iostream>
#include "car.hpp"
#include "payment.hpp"

const std::string FNAME = "_default";
const std::string LNAME = "_default";
const std::string DOF = "_default";
const int ID    = 10000;

class customer
{
private:
    std::string firstName;
    std::string lastName;
    int customer_id;
    std::string dof;
    std::vector<car> crs;
    payment bill;
public:
    customer(): bill(), firstName(FNAME), lastName(LNAME), customer_id(ID){};
    customer(std::string f, std::string l, int id): bill(), firstName(f), lastName(l), customer_id(id){};
    virtual ~customer();
    
    virtual bool login(customer &user, const std::string *username, const std::string *password)
    {
        return false;
    }
    virtual bool signUp(customer &user, std::string *username, std::string *password, std::string *fname, std::string *lname, std::string *dof){return false;}
    virtual bool isExists(std::string *username){return false;}
    virtual bool logout(){return false;}
    virtual void editProfile(customer &cstm, std::string &fn, std::string &ln, std::string &dob){}
    virtual void viewProfile(customer &){}
    
    virtual std::vector<car>* getRentedCars();
    virtual void getRentedCars(std::vector<car> &, int);
    virtual void chooseCarRent(car c);
    virtual void printBill();
    virtual std::string toString()=0;
    
    /* getters **/
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getDof() const;
    
    /* setters **/
    void setFirstName(std::string);
    void setLastName(std::string);
    void setDof(std::string);
};

#endif /* Customer_h */
