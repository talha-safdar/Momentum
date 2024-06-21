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
        int indexToRemove = findTaskIndex(&task); // Find the index of the task (if it exists)
        if (indexToRemove != -1) { // Check if the task was found
            tasks.erase(tasks.begin() + indexToRemove); // Remove the task at the specified index
            // std::cout << "Task removed successfully!" << std::endl;
        }
        else {
            // std::cout << "Task not found." << std::endl; // Handle the case where task is not found
        }
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

