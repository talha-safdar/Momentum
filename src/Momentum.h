#pragma once

#include <wx/wx.h>
#include <wx/wxprec.h>
#include "Card.h"

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
				//wxButton* CreateAddCardButton(wxWindow* parent);
				void CreateNewCard(wxWindow* parent);
				wxPoint dragStartPos;
				wxVector<Card*> cards;
				wxButton* addCardButton; // Declare the button pointer

				wxPanel* toDoPanel;


				// Panels for which you want to enable dragging
				wxPanel* topBar; // Assuming this is your top bar panel
};

