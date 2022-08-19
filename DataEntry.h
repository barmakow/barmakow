//DateEntry.h
//Barbara Makowski
#ifndef DATAENTRY_H
#define DATAENTRY_H
#include <iostream>
#include <string>
using namespace std;

class DataEntry{
    private:
        string date;
        string country;
        int c_cases;
        int c_deaths;

    public:
        void setDate(string);
        void setCountry(string);
        void setCases(int);
        void setDeaths(int);

        string getDate() const;
        string getCountry() const;
        int getCases() const;
        int getDeaths() const;
};
#endif