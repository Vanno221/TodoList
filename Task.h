//
// Created by ubuntu on 31/01/22.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>
#include <ctime>
using namespace std;

class Task {
    private:
        string name;
        bool checked;
        tm data;

    public:
        Task() = default;
        explicit Task (const string &name, const tm &data = {});


        const string &getName() const;
        void setName(const string &name);
        const string toString() const;

        bool isChecked() const;
        void setChecked(bool Checked);

        //Le date a cui si fa riferimento sono quelle di termine del Task
        const tm &getDateTime() const;
        void setDateTime(const tm &dateTime);

        void toggle();

        bool operator==(const Task &rhs) const;
        bool operator!=(const Task &rhs) const;


};


#endif //TODOLIST_TASK_H
