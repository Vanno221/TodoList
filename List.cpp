//
// Created by ubuntu on 31/01/22.
//

#include "List.h"


void List::addElement(const Task &element){
    this->lista.push_back(element);

}

void List::removeElement(const Task &element){
    this->lista.remove(element);
}


const string& List::getNameList() const{
    return this->nameList;
}

const string List::toString() const {
    string stampa;
    for (auto &element: this->lista)
        stampa += "\n " + element.toString() + "\n ";
    return stampa;
}


void List::setNameList(string name) {
    this->nameList = name;
}

const list<Task>& List::getElements() const {
    return this->lista;
}


list<Task>::iterator List::find(string name) {
    return std::find(this->lista.begin(), this->lista.end(), Task(name));
}

List::List(const string &nameList) : nameList(nameList) {}

void List::writeFile() {

    if(lista.empty())
        return;
    ofstream outputFile("./" + nameList + ".txt");
    if(outputFile.is_open()){
        for(const auto& el : lista){
            outputFile << el.toString() << endl;
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}

void List::loadFile(string namefile) {

    ifstream inputFile("./" + namefile + ".txt");
    if(inputFile.good()){
        string str;
        Task e;
        vector<char*> pch;
        this->nameList = namefile;
        while(getline(inputFile, str)){
            pch.clear();
            pch.push_back(strtok (const_cast<char*>(str.c_str()),"|"));
            while (auto test = strtok (nullptr, "|"))
            {
                pch.push_back(test);
            }
            e = Task(pch[0]);
            if(pch.size() > 1){
                e.setChecked(true);
                //e.setDateTime(pch[2]);
            }

            addElement(e);
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}

void List::toggleElement(const Task &element) {
    find(element.getName())->toggle();
}

int List::countTaskToDo() const{
    int count {0};
    for (auto elemet : this->lista)
        if (elemet.isChecked() == false)
            count++;
    return count;
}

string List::getTaskToDoDay(const tm &date) const{
    string elements;
    int count {0};
    for (auto elemet : this->lista)
        if (elemet.getDateTime().tm_mon == date.tm_mon && elemet.getDateTime().tm_mday == date.tm_mday && elemet.getDateTime().tm_year == date.tm_year) {
            if (elemet.isChecked() == false) {
                count++;
                elements += "\n " + elemet.toString() + "\n ";
            }
        }
    return elements + "\n Numero elementi: " + to_string(count) + "\n";
}

int List::countTaskToDoDay(const tm &date) const{
    string elements;
    int count {0};
    for (auto elemet : this->lista)
        if (elemet.getDateTime().tm_mon == date.tm_mon && elemet.getDateTime().tm_mday == date.tm_mday && elemet.getDateTime().tm_year == date.tm_year) {
            if (elemet.isChecked() == false) {
                count++;
            }
        }
    return count;
}
