#pragma once

#include <wx/wx.h>
#include <wx/sharedptr.h>
#include "../models/TaskList.h"
#include "../views/KanbanBoard.h"

class KanbanController {
public:
				KanbanController(TaskList& model, KanbanBoard& view);

				void addTask(const wxString& title, const wxString& description);
				void moveTask(wxSharedPtr<Task>& task, TaskStatus newStatus);

private:
				TaskList& m_model;
				KanbanBoard& m_view;
};