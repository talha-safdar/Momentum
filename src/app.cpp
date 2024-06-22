#include <wx/wx.h>
#include "views/KanbanBoard.h"
#include "controllers/KanbanController.h"

class App : public wxApp {
public:
    bool OnInit() override {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Momentum");

        // create kanban and pass the frame as parent
								TaskList taskList;
        KanbanBoard* board = new KanbanBoard(frame, wxID_ANY, taskList);

        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(App);