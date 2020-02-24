#include "customerinfotype.h"

customerInfoType::customerInfoType()
{
    customerName     = "not given";
    phoneNumber      = "not given";
    email            = "not given";
    business         = "not given";
    customerInterest = NO_INTEREST;
}

customerInfoType::customerInfoType(string name, string number, string mail, string work, interestLevel interest)
{
    customerName     = name;
    phoneNumber      = number;
    email            = mail;
    business         = work;
    customerInterest = interest;
}

void customerInfoType::setName(string name)
{
    customerName = name;
}

void customerInfoType::setPhoneNumber(string number)
{
    phoneNumber = number;
}

void customerInfoType::setEmail(string mail)
{
    email = mail;
}

void customerInfoType::setBusiness(string work)
{
    business = work;
}
void customerInfoType::setInterestLevel(interestLevel interest)
{
    customerInterest = interest;
}


string customerInfoType::getName()
{
    return customerName;
}

string customerInfoType::getPhoneNumber()
{
    return phoneNumber;
}

string customerInfoType::getEmail()
{
    return email;
}

string customerInfoType::getBusiness()
{
    return business;
}

string customerInfoType::getInterestLevel()
{
    string interest; //The interest level of the customer
    switch (customerInterest)
    {
    case NO_INTEREST             : interest = "No Interest";
                                   break;
    case LOW_INTEREST            : interest = "Low Interest";
                                    break;
    case MODERATE_INTEREST       : interest = "Moderate Interest";
                                    break;
    case HIGH_INTEREST           : interest = "High Interest";
                                    break;
    case EXTREMELY_HIGH_INTEREST : interest = "Extremely High Interest";
                                    break;
    }

    return interest;
}

void customerInfoType::print()
{

}

