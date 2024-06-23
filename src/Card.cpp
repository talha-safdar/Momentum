#include "Card.h"

Card::Card(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
				: wxPanel(parent, id, pos, size, style, name)
{
				SetBackgroundColour(*wxWHITE);  // Set background color of card (or any other color)
}