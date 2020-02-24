#ifndef DATABASE_H
#define DATABASE_H

customerInfoType *  readFile(customerInfoType *database, int &databaseSize);
void writeFile(customerInfoType *database, int databaseSize);
customerInfoType * addCustomer(customerInfoType *database, int databaseSize, customerInfoType newCustomer);

#endif // DATABASE_H
