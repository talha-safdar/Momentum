#pragma once
#include <wx/wx.h>

class KanbanBoard : wxPanel {
public:
				KanbanBoard(wxWindow* parent, wxWindowID id);
private:
				void OnPaint(wxPaintEvent& event);
};