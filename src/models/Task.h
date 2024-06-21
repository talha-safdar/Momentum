#pragma once

#include <string>

class Task {
public:
				Task() {};

				std::string getTitle() {
								return this->title;
				}

				void setTitle(std::string title) {
								this->title = title;
				}

				std::string getDescription() {
								return this->title;
				}

				void setDescription(std::string description) {
								this->description = description;
				}
				
				std::string getPriority() {
								return std::to_string(this->priority);
				}

				void setPriority(int priority) {
								this->priority = priority;
				}

private:
				std::string title;
				std::string description;
				enum status { ToDo, InProgress, DOne };
				// dueDate could be useful
				int priority;
};

