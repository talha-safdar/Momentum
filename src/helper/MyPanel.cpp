#include "MyPanel.h"

MyPanel::MyPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos,
				const wxSize& size, long style, const wxString& name)
				: wxPanel(parent, id, pos, size, style, name), holdTimer(this)
{
				SetBackgroundColour(*wxLIGHT_GREY);

				Bind(wxEVT_LEFT_DOWN, &MyPanel::OnLeftMouseDown, this);
				Bind(wxEVT_LEFT_UP, &MyPanel::OnLeftMouseUp, this);
				holdTimer.Bind(wxEVT_TIMER, &MyPanel::OnHoldTimer, this);
}


void MyPanel::OnLeftMouseDown(wxMouseEvent& event)
{
				isMouseDown = true;
				holdTimer.Start(500);
}

void MyPanel::OnLeftMouseUp(wxMouseEvent& event)
{
				isMouseDown = false;
				holdTimer.Stop();

				if (holdTimer.IsRunning())
				{
								std::cout << "Panel clicked!" << std::endl;
				}
				else
				{
								std::cout << "Panel held!" << std::endl;
				}
}

void MyPanel::OnHoldTimer(wxTimerEvent& event)
{
				if (isMouseDown) {
								holdTimer.Stop();
								std::cout << "Panel held!" << std::endl;
				}
}