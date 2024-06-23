#include <wx/wx.h>
#include "Momentum.h"

class App : public wxApp {
public:
				bool OnInit() {
								Momentum* frame = new Momentum();
								frame->SetBackgroundColour(*wxBLACK);
								frame->Center();
								frame->Show(true);

								return true;
				}
};

wxIMPLEMENT_APP(App);