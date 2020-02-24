#ifndef CUSTOMERINFOTYPE_H
#define CUSTOMERINFOTYPE_H

#include "utilities.h"

enum interestLevel
{
    NO_INTEREST,
    LOW_INTEREST,
    MODERATE_INTEREST,
    HIGH_INTEREST,
    EXTREMELY_HIGH_INTEREST
};

class customerInfoType
{
private:
    string customerName;            //The name of the customer
    string phoneNumber;             //The phone number of the customer
    string email;                   //The email of the customer
    string business;                //The business the customer belongs to
    interestLevel customerInterest; //A scale of how interested the customer is ranging from NO_INTEREST to EXTREMELY_HIGH_INTEREST
public:
    customerInfoType();
    customerInfoType(string name, string number, string mail, string work, interestLevel interest);

    void setName(string name);
    void setPhoneNumber(string number);
    void setEmail(string mail);
    void setBusiness(string work);
    void setInterestLevel(interestLevel interest);

    string getName();
    string getPhoneNumber();
    string getEmail();
    string getBusiness();
    string getInterestLevel();

    void print();
};

#endif // CUSTOMERINFOTYPE_H
