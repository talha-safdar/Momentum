#pragma once

#include <vector>
#include <memory> // for unique_ptr
#include "Task.h"

class TaskList {
public:
				void addTask(Task* task) {
								tasks.push_back(std::unique_ptr<Task>(task)); // trasnfer ownership for pointer style
				}

				void removeTask(Task* task) {
        int indexToRemove = findTaskIndex(task); // Find the index of the task (if it exists)
        if (indexToRemove != -1) { // Check if the task was found
            tasks.erase(tasks.begin() + indexToRemove); // Remove the task at the specified index
            // std::cout << "Task removed successfully!" << std::endl;
        }
        else {
            // std::cout << "Task not found." << std::endl; // Handle the case where task is not found
        }
				}

    void moveTask(Task* task, int newStatus) {
        // find the task
        auto it = std::find_if(tasks.begin(), tasks.end(), [task](const std::unique_ptr<Task>& t) {
            return t.get() == task; // compare pointers
        });

        if (it != tasks.end()) { // task found
            // update the status
           // (**it).setStatus(newStatus); // Dereference twice to access the task object and call its method
        }
        else {
            // error handling
        }
    }

    std::vector<std::unique_ptr<Task>>& getTasks() {
        return tasks;
    }

    // Observer pattern
    void notifyObserver() {

    }

private:
				std::vector<std::unique_ptr<Task>> tasks; // a list of Task pointers

    int findTaskIndex(const Task* task) const {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].get() == task) {
                return i;
            }
        }
        return -1; // Task not found
    }
};

