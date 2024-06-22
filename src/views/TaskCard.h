#pragma once

#include <wx/wx.h>
#include <wx/sharedptr.h>
#include "../models/Task.h"

class TaskCard : wxPanel, wxStaticText{
public:
				TaskCard(wxWindow* parent, wxSharedPtr<Task> task);
				wxString getTitle() const;
				wxString getDescription() const;

private:
				wxSharedPtr<Task> m_task;
				wxStaticText title;
				wxStaticText description;
				// add more UI later
};

