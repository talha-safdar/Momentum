#pragma once

#include <wx/wx.h>
#include <iostream>

class MyPanel : public wxPanel
{
public:
				MyPanel(wxWindow* parent, wxWindowID id = wxID_ANY,
								const wxPoint& pos = wxDefaultPosition,
								const wxSize& size = wxDefaultSize,
								long style = wxTAB_TRAVERSAL | wxBORDER_NONE,
								const wxString& name = wxPanelNameStr);

private:
				void OnLeftMouseDown(wxMouseEvent& event);
				void OnLeftMouseUp(wxMouseEvent& event);
				void OnHoldTimer(wxTimerEvent& event);

				wxTimer holdTimer;
				bool isMouseDown = false;
};

