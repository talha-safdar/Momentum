#pragma once

class TaskCard;

#include <wx/wx.h>
#include <wx/vector.h>
#include <wx/sharedptr.h>
#include "../models/TaskList.h"
#include "TaskCard.h"

class KanbanBoard : wxPanel {
public:
				KanbanBoard(wxWindow* parent, wxWindowID id, TaskList& taskList);
				virtual ~KanbanBoard();

				void update(); // to update the board's display

private:
				TaskList& m_taskList;
				wxVector<wxPanel*> m_columns;

				void OnPaint(wxPaintEvent& event);
				void createColumns();
				// add events for drag-and-drop
};