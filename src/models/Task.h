#pragma once

#include <wx/string.h>

enum class TaskStatus {
				ToDo,
				InProgress,
				Done
				// add more if needed
};

class Task {
public:
				Task(const wxString& title, const wxString& description = "", TaskStatus status = TaskStatus::ToDo);

				wxString getTitle() const { return title; }
				void setTitle(const wxString& title) { this->title = title; }

				wxString getDescription() const { return description; }
				void setDescription(const wxString& description) { this->description = description; }

				TaskStatus getStatus() const { return status;  }
				void setStatus(TaskStatus status) { this->status = status; }

				// add more methods for other properties like due date, priority, etc.

				// overloaded operator== for comparison (std::find_if, etc.)
				bool operator==(const Task& other) const {
								return (title == other.title && description == other.description && status == other.status);
				}

private:
				wxString title;
				wxString description;
				TaskStatus status;
				// add more like due date, priority etc.
};

