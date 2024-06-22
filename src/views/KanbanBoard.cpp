#include "KanbanBoard.h"
#include "TaskCard.h"
#include <wx/dc.h> // for drawing
#include <wx/font.h> // for fonts
#define COLUMNS_SIZE_COUNT 3

template <typename T>
void addToSizer(wxSizer* sizer, T* item, int proportion = 0, int flag = wxEXPAND, int border = 0) {
				wxWindow* windowItem = dynamic_cast<wxWindow*>(item);
				if (windowItem) {
								sizer->Add(windowItem, proportion, flag, border);
				}
				else {
								// Handle the error (e.g., log an error message)
				}
}


KanbanBoard::KanbanBoard(wxWindow* parent, wxWindowID id, TaskList& taskList) : wxPanel(parent, id), m_taskList(taskList) {
				parent->SetSize(800, 500);
				parent->CenterOnParent();
				wxPanel::SetBackgroundColour(*wxWHITE); // background colour

				// Create column panels
				for (int i = 0; i < 3; i++) {
								wxPanel* column = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(3, -1));
								column->SetBackgroundColour(*wxLIGHT_GREY);
								m_columns.push_back(column);
				}

				KanbanBoard::createColumns();
}

KanbanBoard::~KanbanBoard() {
				// clean up UI elements using delete
}

void KanbanBoard::update() {
				// clear other task cards
				for (auto column : m_columns) {
								column->DestroyChildren(); // remove all children from the column
				}

				// create and add task cards
				for (const auto& task : m_taskList.getTasks()) {
								TaskCard* card = new TaskCard(m_columns[(int)task->getStatus()], wxID_ANY, task);
								wxBoxSizer* columnSizer = static_cast<wxBoxSizer*>(m_columns[(int)task->getStatus()]->GetSizer());
								if (columnSizer) {
												addToSizer(columnSizer, card, 0, wxEXPAND | wxALL, 5);	// expand to fill the width, 5 pixel margin on all sides
								}
				}

				// recaluclae layout and refresh the display
				Layout();
}

void KanbanBoard::OnPaint(wxPaintEvent& event) {

}

void KanbanBoard::createColumns() {
				wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

				for (int i = 0; i < 3; i++) {
								wxPanel* column = m_columns[i];

								// Create a vertical sizer for each column
								wxBoxSizer* columnSizer = new wxBoxSizer(wxVERTICAL);

								// (Optionally) Add a label for the column title
								wxStaticText* title = new wxStaticText(column, wxID_ANY, TaskCard::TaskStatusToString((TaskStatus)i));  // Convert enum to string
								columnSizer->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

								column->SetSizer(columnSizer);
								mainSizer->Add(column, 1, wxEXPAND | wxALL, 3);
				}

				SetSizerAndFit(mainSizer); // Set the main sizer and resize the KanbanBoard accordingly
}

// add other methods and destructor