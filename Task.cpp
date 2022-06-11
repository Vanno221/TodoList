//
// Created by ubuntu on 31/01/22.
//

#include "Task.h"

Task::Task(const string &name, const tm &data) : name(name), checked(false), data(data)  {}



const string &Task::getName() const {
    return name;
}

void Task::setName(const string &name) {
    Task::name = name;
}

bool Task::isChecked () const {
    return this->checked;
}

void Task::setChecked(bool checked) {
    this->checked = checked;
}

const string Task::toString() const {
    return this->name + ": " + (checked?"|TRUE|" : "|FALSE|") + " Data : " + to_string(this->data.tm_mday) + "/" +
            to_string(this->data.tm_mon) + "/" + to_string(this->data.tm_year);
}

bool Task::operator==(const Task &rhs) const {
    return name == rhs.name;
}

bool Task::operator!=(const Task &rhs) const {
    return !(rhs == *this);
}

void Task::toggle() {
    setChecked(!this->checked);
}

const tm &Task::getDateTime() const {
    return this->data;
}

void Task::setDateTime(const tm &dateTime) {
    Task::data = dateTime;
}


