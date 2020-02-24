#include "utilities.h"
#include "customerinfotype.h"
#include <fstream>
#include <QDebug>

customerInfoType * readFile(customerInfoType *database, int &databaseSize)
{
    std::ifstream fin; //A variable for reading the file

    string tempName;                 //The name of the customer
    string tempPhoneNumber;          //The phone number of the customer
    string tempEmail;                //The email of the customer
    string tempBusiness;             //The business the customer belongs to
    int    tempInterestInt;          //The interest level as an int
    interestLevel tempInterestLevel; //A scale of how interested the customer is ranging from NO_INTEREST to EXTREMELY_HIGH_INTEREST

    int index = 0; //The index of the current customer being read in

    databaseSize = 0;

    fin.open("/home/tony/lawson_stuff/project1/Project-1/database.txt");

    qDebug() << "testing seekg";
    fin.seekg(0, std::ios::end);
    qDebug() << "testing tellg()";
    int size = fin.tellg();
    qDebug() << "after testing";

    qDebug() << "readFile test";
    if (size != 0)
    {
        //going back to the beginning
        fin.close();
        fin.open("/home/tony/lawson_stuff/project1/Project-1/database.txt");

        qDebug() << "In if(fin)";
        fin >> databaseSize;
        fin.ignore(1000, '\n');

        database = new customerInfoType[databaseSize];

        if (databaseSize != 0)
        {
            while (fin)
            {
                std::getline(fin, tempName);

                qDebug() << "First name " << QString::fromStdString(tempName);

                std::getline(fin, tempPhoneNumber);

                std::getline(fin, tempEmail);

                std::getline(fin, tempBusiness);

                fin >> tempInterestInt;
                fin.ignore(1000, '\n');

    //            switch (tempInterestInt)
    //            {
    //            case 0 : tempInterestLevel = NO_INTEREST;
    //                     break;
    //            case 1 : tempInterestLevel = LOW_INTEREST;
    //                     break;
    //            case 2 : tempInterestLevel = MODERATE_INTEREST;
    //                     break;
    //            case 3 : tempInterestLevel = HIGH_INTEREST;
    //                     break;
    //            case 4 : tempInterestLevel = EXTREMELY_HIGH_INTEREST;
    //                     break;
    //            }

                tempInterestLevel = NO_INTEREST;

                qDebug() << "index: " << index;
                database[index] = customerInfoType(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempInterestLevel);
                qDebug() << "Name: " << QString::fromStdString(database[index].getName());
                index++;
            }//end while (fin)
        }//end if (databaseSize != 0)
    }//end if (fin)
    else
    {
        databaseSize = 0;
    }

    fin.close();

    return database;
}// end readFile

void writeFile(customerInfoType *database, int databaseSize)
{
    std::ofstream fout; //The variable for writing to file
    int index = 0; //A looping variable

    fout.open("/home/tony/lawson_stuff/project1/Project-1/database.txt");

    qDebug() << databaseSize;
    fout << databaseSize << endl;

    qDebug() << "entering loop";
    for (index = 0; index < databaseSize; index++)
    {
        qDebug() << QString::fromStdString(database[index].getName()) << " test";
        fout << database[index].getName() << '\n';
        qDebug() << "testing one line";
        fout << database[index].getPhoneNumber() << endl;
        fout << database[index].getEmail() << endl;
        fout << database[index].getBusiness() << endl;
        fout << database[index].getInterestLevel() << endl;
        qDebug() << "end of loop";
    }
    qDebug() << "exit loop";

    fout.close();
}

customerInfoType* addCustomer(customerInfoType *database, int databaseSize, customerInfoType newCustomer)
{
    customerInfoType *tempPtr; //A temp pointer to create the new array

    qDebug() << "creating new array";
    tempPtr = new customerInfoType[databaseSize + 1];

    qDebug() << "database size " << databaseSize;
//    qDebug() << "entering loop " << QString::fromStdString(database[0].getName());
    for (int index = 0; index < databaseSize; index++)
    {
        tempPtr[index] = database[index];
    }

    qDebug() << "adding new customer";
    tempPtr[databaseSize] = newCustomer;
    databaseSize++;

    qDebug() << "deleting old array";
    delete [] database;

    database = tempPtr;

    qDebug() << QString::fromStdString(database[0].getName());
    return database;
}
