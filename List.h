    //
// Created by ubuntu on 31/01/22.
//

#ifndef TODOLIST_LIST_H
#define TODOLIST_LIST_H

#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
#include <ctime>
#include "Task.h"

using namespace std;

class List {
    private:
        string nameList;
        list<Task> lista;

    public:

        List(const string &nameList);
        List() = default;

        const std::list<Task>& getElements() const;

        void addElement(const Task& element);
        void removeElement(const Task& element);

        void setNameList(string nameList);
        const string& getNameList() const;

        list<Task>::iterator find(string name);
        void loadFile(string namefile);
        void writeFile();

        void toggleElement(const Task& element);

        int countTaskToDo();

        int countTaskToDoDay(const tm& date);

};


#endif //TODOLIST_LIST_H
