//
//  Member.h
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#ifndef Member_h
#define Member_h

#include "customer.hpp"

class member: public customer
{
public:
    member(): customer(){};
    member(std::string f, std::string l, int id) : customer(f,l, id){};
    ~member();
    bool login(customer &user, const std::string *, const std::string *);
    bool signUp(customer &user, std::string *, std::string *, std::string *, std::string *, std::string *);
    bool isExists(std::string *);
    bool logout();
    void editProfile(customer &, std::string &, std::string &, std::string &);
    void viewProfile(customer &);
    std::vector<car>* getRentedCars();
    void getRentedCars(std::vector<car> &, int);
    void chooseCarRent(car c);
    void printBill();
    std::string toString();
};

#endif /* Member_h */
