//#pragma once
//
//#include "../models/TaskList.h"
//#include "../views/KanbanBoard.h"
//
//class KanbanController {
//public:
//				// KanbanController() {}
//
//				void addTask(const std::string& title, const std::string& description) {
//								task = new Task();
//								task->setTitle(title);
//								task->setDescription(description);
//								taskList->addTask(task);
//								// kanboard->update(); // to be implemented
//				}
//
//				void editTask(wxSharedPtr<Task> task, wxSharedPtr<Task> updatedTask) {
//								// find the current task
//								// update it
//				}
//
//				void removeTask(wxSharedPtr<Task> task) {
//								taskList->removeTask(task);
//				}
//
//				void moveTask(wxSharedPtr<Task> task, int newStatus) {
//								taskList->moveTask(task, newStatus);
//				}
//				
//				// more functions to handle user actions
//
//private:
//				TaskList* taskList; // pointer to models
//				wxSharedPtr<Task> task; // pointer to models
//				// KanbanBoard* kanboard; // pointer to views
//};