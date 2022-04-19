#pragma once
#include "Relation.h"
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm> 
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;
using namespace std;
using namespace System;

//najkraæi kljuè
int minKeyLength(vector<string> candidates) {
    int n = 20;
    for (int i = 0;i < candidates.size();i++) {
        if (candidates.at(i).size() < n) {
            n = candidates.at(i).size();
        }
    }
    return n;
}

//razbijanje ograde atributa koja ima kandidata za kljuc na manje ograde
vector<string> disassemblingClosure(string closure) {
    vector<string> combinations;
    if (closure.size() > 1) {
        for (int i = 0;i < closure.size();i++) {
             string tempClosure = "";
             for (int j = 0;j < closure.size() - 1;j++) {
                 if (i != j) {
                     tempClosure.push_back(closure.at(i));
                 }
             }
             combinations.push_back(tempClosure);
         }
    }
    else {
        combinations.push_back("end_of_combinations");
    }
    return combinations;
}

//raspisivanje ograde atributa
string assemblingClosure(vector<string> cannonicDependencies, string relationClosure) {
    string candidatesClosure = relationClosure;
    string tempLeft, tempRight;
    for (int i = 0;i < cannonicDependencies.size();i++) {
        bool flagFound = false;
        tempLeft = cannonicDependencies.at(i).substr(0, cannonicDependencies.at(i).find("->"));
        tempRight = cannonicDependencies.at(i).substr(cannonicDependencies.at(i).find("->") + 2, cannonicDependencies.at(i).size() - 1);
        for (int i = 0;i < tempLeft.size();i++) {
             if (candidatesClosure.find(tempLeft.at(i)) != string::npos) flagFound = true;
        }
        if (!flagFound && relationClosure.find(tempRight) == string::npos) {
            candidatesClosure.append(tempRight);
        }
    }
    sort(candidatesClosure.begin(), candidatesClosure.end());
    return candidatesClosure;
}

//traženje kljuèeva uz pomoæne funkcije
vector<string> getKeyCandidates(string valueSchema, vector<string> cannonicDependencies, string relationClosure) {
    vector<string> keys, potentialKeys, disassembledClosures;
    bool searching = true;
    bool choose = true;

    //schema odgovara ogradi (najduži kljuè, default)
    string candidateClosure = assemblingClosure(cannonicDependencies, relationClosure);
    if (candidateClosure == valueSchema) {
        potentialKeys.push_back(relationClosure);
    }

    //traženje onih atributa koji nisu u ovisnostima
    if (potentialKeys.size() == 0) {
        for (int i = 0;i < valueSchema.size();i++) {  //traženje onih atributa koji nisu u ovisnostima
            if (candidateClosure.find(valueSchema.at(i)) == string::npos) {
                relationClosure.push_back(i);
            }
        }
        sort(relationClosure.begin(), relationClosure.end());
        potentialKeys.push_back(relationClosure);
    }

    int i = 0;
    int j = 0;
    while (searching) {
        //provjera je li potencijalni kljuè u razbijenim ogradama
        bool flag = false;
        for (int k = 0;k < disassembledClosures.size();k++) {
            if (potentialKeys.at(i) == disassembledClosures.at(k)) {
                flag = true;
            }
        }
        //ako nije, kreæemo s razbijanjem potencijalnog kljuèa
        if (!flag) {
            vector<string> disassembled = disassemblingClosure(potentialKeys.at(i));
            if (disassembled.at(0) != "end_of_combinations") {
                for (int l = 0;l < disassembled.size();l++) {
                    candidateClosure = assemblingClosure(cannonicDependencies, disassembled.at(l));
                    bool flagFound = false;
                    //provjera je li neka od varijacija veæ u potencijalnim kljuèevima
                    for (int m = 0;m < potentialKeys.size();m++) {
                        if (potentialKeys.at(m) == disassembled.at(l)) {
                            flagFound = true;
                        }
                    }
                    //ako je nova varijacija koja raspisuje cijelu shemu, dodaj u potencijalne
                    if (candidateClosure == valueSchema && flagFound != true) {
                        potentialKeys.push_back(disassembled.at(l));
                           j++;
                    }
                }
            }
            //koje smo potencijalne kljuèeve raspisali
            disassembledClosures.push_back(potentialKeys.at(i));
        }
        if (i < j) {
            i++;
        }
        else {
            searching = false;
        }
    }
    //koji je/su od potencijalnih kljuèeva najkraæi
    int n = minKeyLength(potentialKeys);
    for (int i = 0;i < n;i++) {
        if (potentialKeys.at(i).size() == n) {
            keys.push_back(potentialKeys.at(i));
        }
    }
    sort(keys.begin(), keys.end());
    return keys;
}

cli::array<String^>^ CalculateKeys(String^ schema, String^ dependencies) {
    //pretvaranje string objekta u regularni string
    string valueSchema = msclr::interop::marshal_as< std::string >(schema);
    string valueDependencies = msclr::interop::marshal_as< std::string >(dependencies);

    //razdvajanje funkcijskih ovisnosti u kanonske forme
    vector<string> cannonicDependencies;
    string tempDependencies, tempLeft, tempRight;
    size_t splitTo, splitFrom = 0;
    while (true) {
        splitTo = valueDependencies.find(",", splitFrom, 1);
        tempDependencies = valueDependencies.substr(splitFrom, splitTo - splitFrom);
        splitFrom = splitTo + 1;
        tempLeft = tempDependencies.substr(0, tempDependencies.find("->"));
        tempRight = tempDependencies.substr(tempDependencies.find("->") + 2, tempDependencies.size() - 1);
        if (tempRight.size() > 1) {
            for (int i = 0;i < tempRight.size();i++) {
                cannonicDependencies.push_back(tempLeft + "->" + tempRight[i]);
            }
        }
        else {
            cannonicDependencies.push_back(tempLeft + "->" + tempRight);
        }
        if (splitTo == string::npos) {
            break;
        }
    }

    //skup cijele relacije (provjera trivijalnih) 
    string relation = "";
    for (int i = 0;i < cannonicDependencies.size();i++) {
        bool flagFound = false;
        tempLeft = cannonicDependencies.at(i).substr(0, cannonicDependencies.at(i).find("->"));
        tempRight = cannonicDependencies.at(i).substr(cannonicDependencies.at(i).find("->") + 2, cannonicDependencies.at(i).size() - 1);
        for (int i = 0;i < tempLeft.size();i++) {
            if (relation.find(tempLeft.at(i)) != string::npos) flagFound = true;
        }
        if (relation.find(tempRight) == string::npos && tempLeft.find(tempRight) == string::npos) {
            relation.append(tempRight);
            if (!flagFound) {
                relation.append(tempLeft);
            }
        }
    }

    //izbacivanje viška + sortiranje
    for (int i = 0; i < relation.size(); i++) {
        int x = 0;
        for (int j = 0; j < relation.size(); j++) {
            if (relation[i] == relation[j]) { x++; }
        }
        if (x > 1) {
            relation.erase(relation[i]);
            i--;
        }
    }
    sort(relation.begin(), relation.end());

    //traženje kljuèeva
    vector<string> keys = getKeyCandidates(valueSchema, cannonicDependencies, relation);

    //pretvaranje u objekt string
    cli::array<String^>^ keysObject = gcnew cli::array<String^> (20);
    for (int i = 0;i < keys.size();i++) {
        keysObject[i] = marshal_as<String^>(keys.at(i));
    }
    return keysObject;
}


