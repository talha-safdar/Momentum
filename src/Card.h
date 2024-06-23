#pragma once

#include <wx/wx.h>

class Card : public wxPanel
{
public:
				Card(wxWindow* parent, wxWindowID id = wxID_ANY,
								const wxPoint& pos = wxDefaultPosition,
								const wxSize& size = wxDefaultSize,
								long style = wxTAB_TRAVERSAL | wxBORDER_NONE,
								const wxString& name = wxPanelNameStr);
};