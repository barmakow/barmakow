//DataEntry.cpp
//Barbara Makowski

#include "DataEntry.h"
#include <iostream>

void DataEntry::setDate(string newDate)
{
    date = newDate;
}

void DataEntry::setCountry(string newCountry)
{
    country = newCountry;
}

void DataEntry::setCases(int newCases)
{
    c_cases = newCases;
}

void DataEntry::setDeaths(int newDeaths)
{
    c_deaths = newDeaths;
}

string DataEntry::getDate() const
{
    return date;
}

string DataEntry::getCountry() const
{
    return country;
}


int DataEntry::getCases() const
{
    return c_cases;
}

int DataEntry::getDeaths() const
{
    return c_deaths;
}
