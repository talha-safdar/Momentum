#pragma once

#include <wx/wx.h>
#include <wx/sharedptr.h>
#include "../models/Task.h"

class TaskCard : public wxPanel, wxStaticText{
public:
				TaskCard(wxWindow* parent, wxWindowID id, wxSharedPtr<Task> task);

				wxString getTitle() const;
				wxString getDescription() const;
				static wxString TaskStatusToString(TaskStatus status);

private:
				wxSharedPtr<Task> m_task;
				wxStaticText title;
				wxStaticText description;
				// add more UI later
};

