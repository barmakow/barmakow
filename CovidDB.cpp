//CovidDB.cpp
//Barbara Makowski
#include "DataEntry.h"
#include "CovidDB.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int CovidDB::hash(string country){ 
    int sum = 0; 
    for (int i = 0; i < country.size(); i++){ 
        int c = int(country[i]); //c is ASCII 
        sum += (i + 1) * c;// m is the hash table size, c is the ASCII code for char.
    } 
    return sum % tableSize; 
}

vector<int> splitDate(string str, char del){
    vector<int> result;
    // declaring temp string to store the curr "word" upto del
    int temp = 0;
    for(int i = 0; i < (int)str.size(); i++){
        // If current char is not ',', then append it to the "word", otherwise you have completed the word, and start the next word
        if(str[i] != del){
            temp += str[i];
        }else{
            result.push_back(temp);
            temp = 0;
        }
    }
    // push the last substring after the last ',' to the result
    result.push_back(temp);
    return result;
}

bool compareDates(string ogDate, string newDate){
    char delim = '/';
    int newMonth, newDay, newYear;
    int ogMonth, ogDay, ogYear;

    vector<int> resultOne = splitDate(ogDate, delim);
    vector <int> resultTwo = splitDate(newDate, delim);

    if(newYear > ogYear){
        return true;
    }

    if(newMonth > ogMonth){
        return true;
    }

    if(newDay > ogDay){
        return true;
    }
    
    return false;
}

bool CovidDB::add(DataEntry entry){
    int i = hash(entry.getCountry());
    bool key = false;
    for(int j = 0; j < table[i].size(); j++){
        if(table[i][j].getCountry() == entry.getCountry()){
            key = true;
            if(compareDates(table[i][j].getDate(), entry.getDate())){
                table[i][j].setDate(entry.getDate());
                table[i][j].setCases(table[i][j].getCases() + entry.getCases());
                table[i][j].setDeaths(table[i][j].getDeaths() + entry.getDeaths());
            }
        }
    }
    if(!key)
        table[i].push_back(entry);

    return key;
}

DataEntry* CovidDB::get(string country){
    DataEntry* place;
    cout << "Data for: " << country << endl;
    int searching = hash(country);
    for(int i = 0; i < table[searching].size(); i++){
        if(table[searching][i].getCountry() == country){
            place = &table[searching][i];
            return place;
        }
    }
    return nullptr; 
}

void CovidDB::displayTable(){
    for(int i = 0; i < int(table.size()); i++)
    {
        cout << setw(2) << i;
        for(int j = 0; j < int(table[i].size()); j++)
            cout << " -> " << table[i][j].getCountry();
        cout << endl;
    }
    cout << endl;
}


void CovidDB::remove(string country){
    // get index first
    int i = hash(country);
    // traverse ith list(vector) to search 
    for(int j = 0; j < table[i].size(); j++){
        // if found, delete
        if(table[i][j].getCountry() == country){
            table[i].erase(table[i].begin() + j);
            cout << country << " key: " << country << " is deleted!" << endl << endl;
            return;
        }
    }
    cout << "No key: " << country << " in hash table!" << endl << endl;
}