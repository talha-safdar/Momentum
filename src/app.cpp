#include <wx/wx.h>
#include "views/KanbanBoard.h"

class App : public wxApp {
public:
    bool OnInit() {
        wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Momentum");

        // create kanban and pass the frame as parent
        KanbanBoard* board = new KanbanBoard(frame, wxID_ANY);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(App);