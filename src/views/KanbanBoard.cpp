#include "KanbanBoard.h"
#include <wx/dc.h> // for drawing
#include <wx/font.h> // for fonts
#define COLUMNS_SIZE_COUNT 3

KanbanBoard::KanbanBoard(wxWindow* parent, wxWindowID id) : wxPanel(parent, id) {
				parent->SetSize(800, 500);
				parent->CenterOnParent();
				wxPanel::SetBackgroundColour(*wxBLACK); // background colour
}

void KanbanBoard::OnPaint(wxPaintEvent& event) {
				wxPaintDC dc(this); // device context for drawing on the panel

				// dimensions for columns and cards
				int columnWidth = 200;
				int cardHeight = 80;
				int margin = 20;

				// column titles
				wxString columnTitles[] = { "To Do", "In Progress", "Done" };

				// drawing columns
				for (int i = 0; i < COLUMNS_SIZE_COUNT; i++) {
								wxRect columnRect(i * (columnWidth + margin), 0, columnWidth, GetClientSize().y);
								dc.SetBrush(*wxLIGHT_GREY_BRUSH);
								dc.DrawRectangle(columnRect);

								// draw column title (font and colour)
								dc.SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
								dc.DrawText(columnTitles[i], columnRect.x + 10, columnRect.y + 10);

								// draw placeholder cards (to be replaced with real cards later)
								for (int j = 0; j < 2; j++) {
												wxRect cardRect(columnRect.x + 10, columnRect.y + 40 + j * (cardHeight + margin), columnWidth - 20, cardHeight);
												dc.SetBrush(*wxWHITE_BRUSH);
												dc.DrawRectangle(cardRect);
								}
				}
}