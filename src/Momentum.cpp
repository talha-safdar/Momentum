#include "Momentum.h"
#include "Momentum.h"
#include <wx/wx.h>
#include <iostream>

Momentum::Momentum()
				: wxFrame(nullptr, wxID_ANY, "Momentum", wxDefaultPosition, wxSize(970, 610))
{
				// Store original style
				originalStyle = GetWindowStyle();

				// Remove border and disallow interaction
				SetWindowStyle(originalStyle & ~wxCAPTION & ~wxSYSTEM_MENU & ~wxCLOSE_BOX & ~wxRESIZE_BORDER);

				// TOP BAR
				topBar = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(970, 30));
				topBar->SetBackgroundColour(*wxRED);

				// Close Button
				wxButton* closeButton = new wxButton(topBar, wxID_EXIT, "X", wxPoint(940, 2), wxSize(25, 25));
				closeButton->SetBackgroundColour(*wxBLACK);

				// LEFT PANEL
				wxPanel* iconLeftPanel = new wxPanel(this, wxID_ANY, wxPoint(10, 50), wxSize(80, 550));
				iconLeftPanel->SetBackgroundColour(wxColor(64, 64, 64));

				wxPanel* box;
				for (int i = 0; i < 4; i++) {
								if (i == 0) {
												box = new wxPanel(iconLeftPanel, wxID_ANY, wxPoint(10, 12 + i * 90), wxSize(60, 60));
								}
								else {
												box = new wxPanel(iconLeftPanel, wxID_ANY, wxPoint(10, 10 + i * 90), wxSize(60, 60));
								}
								box->SetBackgroundColour(*wxWHITE);
				}

				// COLUMNS
				toDoPanel = new wxPanel(this, wxID_ANY, wxPoint(100, 50), wxSize(280, 550));
				toDoPanel->SetBackgroundColour(wxColor(153, 153, 153));
				wxPanel* inProgressPanel = new wxPanel(this, wxID_ANY, wxPoint(390, 50), wxSize(280, 550));
				inProgressPanel->SetBackgroundColour(wxColor(128, 128, 128));
				wxPanel* donePanel = new wxPanel(this, wxID_ANY, wxPoint(680, 50), wxSize(280, 550));
				donePanel->SetBackgroundColour(wxColor(102, 102, 102));

				// Event Bindings (after creating all elements)
				topBar->Bind(wxEVT_LEFT_DOWN, &Momentum::OnPanelLeftMouseDown, this);
				topBar->Bind(wxEVT_LEFT_UP, &Momentum::OnPanelLeftMouseUp, this);
				topBar->Bind(wxEVT_MOTION, &Momentum::OnPanelMouseMove, this);
				closeButton->Bind(wxEVT_BUTTON, &Momentum::OnTopClicked, this);

				//toDoPanel = new wxPanel(this, wxID_ANY, wxPoint(100, 50), wxSize(280, 550));
				//toDoPanel->SetBackgroundColour(wxColor(153, 153, 153));

				// Add Card Button
				// Store original addCardButton color
				// wxColor* originalButtonColor = addCardButton->GetBackgroundColour();
				//addCardButton = CreateAddCardButton(toDoPanel);
				addCardButton = new wxButton(toDoPanel, wxID_ANY, "+ Add Card", wxPoint(10, 10), wxSize(100, 30));
				addCardButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
								CreateNewCard(this); // Call CreateNewCard with the parent panel
								});
				addCardButton->Raise();

				Layout();
}

Momentum::~Momentum()
{
				// Restore original style (important for cleanup)
				SetWindowStyle(originalStyle);
}



//wxButton* Momentum::CreateAddCardButton(wxWindow* parent)
//{
//				//wxButton* button = new wxButton(parent, wxID_ANY, "+ Add Card", wxPoint(10, 10), wxSize(100, 30));
//
//				// Ensure the correct function is bound with the correct parameter 
//				//button->Bind(wxEVT_BUTTON, [this, parent](wxCommandEvent&) { CreateNewCard(parent); });
//
//				return;
//}

// CreateNewCard method
void Momentum::CreateNewCard(wxWindow* parent)
{
				if (cards.size() >= 3) { // Limit to 3 cards
								return;
				}

				int newCardY = 10; // Start at the top
				if (!cards.empty()) {
								newCardY = cards.back()->GetPosition().y + cards.back()->GetSize().GetHeight() + 10; // Position below the last card
				}

				Card* newCard = new Card(toDoPanel, wxID_ANY, wxPoint(10, newCardY), wxSize(260, 100));
				newCard->Raise();
				cards.push_back(newCard);

				// Move "Add Card" button below the new card
				addCardButton->Move(10, newCardY + newCard->GetSize().GetHeight() + 10);
}



// EVENT HANDLING
void Momentum::OnTopClicked(wxCommandEvent& evt)
{
				Close(true);
}

// Event Handlers for Dragging
void Momentum::OnPanelLeftMouseDown(wxMouseEvent& event)
{
				dragStartPos = event.GetPosition();
				topBar->CaptureMouse();
}

void Momentum::OnPanelLeftMouseUp(wxMouseEvent& event)
{
				if (topBar->HasCapture()) {
								topBar->ReleaseMouse();
				}
}

void Momentum::OnPanelMouseMove(wxMouseEvent& event)
{
				if (topBar->HasCapture())
				{
								wxPoint currentPos = ClientToScreen(event.GetPosition());

								int newX = currentPos.x - dragStartPos.x;
								int newY = currentPos.y - dragStartPos.y;

								Move(newX, newY); // Directly set the new position
				}
}