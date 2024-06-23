#pragma once

#include <wx/wx.h>
#include <wx/wxprec.h>

class Momentum : public wxFrame
{
public:
				Momentum();
				virtual ~Momentum();

private:
				long originalStyle;
				void OnTopClicked(wxCommandEvent& evt);

				void OnPanelLeftMouseDown(wxMouseEvent& event);
				void OnPanelLeftMouseUp(wxMouseEvent& event);
				void OnPanelMouseMove(wxMouseEvent& event);
				wxPoint dragStartPos;

				// Panels for which you want to enable dragging
				wxPanel* topBar; // Assuming this is your top bar panel
};

