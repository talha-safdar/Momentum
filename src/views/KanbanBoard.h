#pragma once

#include <wx/scrolwin.h>
#include <vector>
#include <memory>
#include "Columns.h"
#include "TaskCard.h"
#include "../models/Task.h"
#include "../controllers/KanbanController.h"

class KanbanBoard : wxScrolledWindow {
public:
				// initialise columns
				void createColumns(std::vector<std::unique_ptr<Columns>> columns) {
								// this->columns = columns;
				}

				void addTaskCard(TaskCard* taskCard) {
								taskCards.push_back(std::unique_ptr<TaskCard>(taskCard));
				}

				void removeTaskCard(TaskCard* taskCard) {
								int indexToRemove = findTaskIndex(taskCard); // Find the index of the task (if it exists)
								if (indexToRemove != -1) { // Check if the task was found
												this->taskCards.erase(this->taskCards.begin() + indexToRemove); // Remove the task at the specified index
												// std::cout << "Task removed successfully!" << std::endl;
								}
								else {
												// std::cout << "Task not found." << std::endl; // Handle the case where task is not found
								}
				}

				void moveTaskCard(TaskCard* taskCard, int newStatus) {
								auto it = std::find_if(this->taskCards.begin(), this->taskCards.end(), [taskCard](const std::unique_ptr<TaskCard>& t) {
												return t.get() == taskCard; // compare pointers
												});

								if (it != this->taskCards.end()) { // task found
												// update the status
											// (**it).setStatus(newStatus); // Dereference twice to access the task object and call its method
								}
								else {
												// error handling
								}
				}

				void update() {
								// called by controller
				}

				void onDragStart(wxMouseEvent& mouseEvt) {
								// apply logic
				}

				void onDragMove(wxMouseEvent& mouseEvt) {
								// apply logic
				}

				void onDragEnd(wxMouseEvent& mouseEvt) {
								// apply logic
				}

private:
				// std::vector<std::unique_ptr<Columns>> columns; // a list of Columns pointers
				std::vector<std::unique_ptr<TaskCard>> taskCards;
				// KanbanController* kanbankController;

				// repeated code
				int findTaskIndex(const TaskCard* taskCard) const {
								for (size_t i = 0; i < this->taskCards.size(); i++) {
												if (this->taskCards[i].get() == taskCard) {
																return i;
												}
								}
								return -1; // Task not found
				}
};