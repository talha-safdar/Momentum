#pragma once

#include <wx/vector.h>
#include <wx/sharedptr.h>
#include "Task.h"

class TaskList {
public:
				void addTask(wxSharedPtr<Task> task) {
        wxSharedPtr<Task> sharedTask(task);
								tasks.push_back(sharedTask); // trasnfer ownership for pointer style
				}

				void removeTask(wxSharedPtr<Task> task) {
        int indexToRemove = findTaskIndex(task); // Find the index of the task (if it exists)
        if (indexToRemove != -1) { // Check if the task was found
            tasks.erase(tasks.begin() + indexToRemove); // Remove the task at the specified index
            // std::cout << "Task removed successfully!" << std::endl;
        }
        else {
            // std::cout << "Task not found." << std::endl; // Handle the case where task is not found
        }
				}

    // chaege pointer from * to wxWidgets
    void moveTask(wxSharedPtr<Task> task, int newStatus) {
        // Find a task in the tasks vector
        wxSharedPtr<Task> taskToFind = /* ... get the task you want to find ... */;
        auto it = std::find_if(tasks.begin(), tasks.end(),
            [taskToFind](const wxSharedPtr<Task>& t) {
                return *t == *taskToFind;
            });

        if (it != tasks.end()) {
            // Task found at iterator position 'it'
            // You can now access the task using *it
        }
        else {
            // Task not found
        }
    }

    wxVector<wxSharedPtr<Task>>& getTasks() {
        return tasks;
    }

    // Observer pattern
    void notifyObserver() {

    }

private:
				wxVector<wxSharedPtr<Task>> tasks; // a list of Task pointers

    int findTaskIndex(const wxSharedPtr<Task> task) const {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (*tasks.at(i) == *task) {
                return i;
            }
        }
        return -1; // Task not found
    }
};

