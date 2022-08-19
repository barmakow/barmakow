//CovidDB.h
//Barbara Makowski
#ifndef COVIDDB_H
#define COVIDDB_H
#include <vector>
#include <iostream>
#include "DataEntry.h"

class CovidDB{
    private:
        int tableSize;
        vector<vector<DataEntry> > table;
        int hash(string country);

    public:
        CovidDB(int m){
            table = vector<vector<DataEntry> > (m);
            this->tableSize = m;
        }
        
        bool add(DataEntry entry);
        DataEntry* get(string country);
        void remove(string country);
        void displayTable();
        void remove(int key);
};
#endif
