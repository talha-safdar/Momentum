#include "TaskCard.h"

TaskCard::TaskCard(wxWindow* parent, wxWindowID id, wxSharedPtr<Task> task)
				: wxPanel(parent, id), m_task(task) {
				// set the size for layout
				wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

				// create UI elemnts for task details
				wxStaticText* titleText = new wxStaticText(static_cast<wxPanel*>(this), wxID_ANY, task->getTitle());
				wxStaticText* descText = new wxStaticText(static_cast<wxPanel*>(this), wxID_ANY, task->getDescription());

				// customise appareance (fonts, colours, etc.)
				sizer->Add(titleText, 0, wxALL | wxEXPAND, 5);
				sizer->Add(descText, 1, wxALL | wxEXPAND, 5);

				wxPanel::SetSizer(sizer);
}

wxString TaskCard::getTitle() const {
				return m_task->getTitle();
}

wxString TaskCard::getDescription() const {
				return m_task->getDescription();
}

wxString TaskCard::TaskStatusToString(TaskStatus status)
{
				switch (status) {
				case TaskStatus::ToDo:
								return "To Do";
				case TaskStatus::InProgress:
								return "In Progress";
				case TaskStatus::Done:
								return "Done";
								// Add cases for other TaskStatus values
				default:
								return "Unknown";
				}
}
