#pragma once

#include <wx/wx.h>
#include <wx/vector.h>
#include <wx/sharedptr.h>
#include "Task.h"

class TaskList {
public:
				void addTask(const wxString& title, const wxString& description);
				const wxVector<wxSharedPtr<Task>>& getTasks() const { return tasks; }
				void moveTask(const wxSharedPtr<Task>& task, TaskStatus newStatus);

private:
				wxVector<wxSharedPtr<Task>> tasks;
};