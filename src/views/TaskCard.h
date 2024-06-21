#pragma once

#include <wx/panel.h>
#include <wx/stattext.h>
#include "../models/Task.h"

class TaskCard : wxPanel, wxStaticText{
public:
    void update() {
        // update the display based on the task data
    }

    // equality operator
    bool operator==(const TaskCard& other) const {
        return (*task == *other.task); // Compare Task objects (assuming you've overloaded == for Task)
    }

    // add event handlers for mouse events (click, hover etc.)

private:
    Task* task;
};

