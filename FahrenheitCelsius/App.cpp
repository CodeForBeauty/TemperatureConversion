#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
    MainFrame* frame = new MainFrame("Temperature Exchange");
    frame->SetClientSize(250, 200);
    frame->Center();
    frame->Show();
    return true;
}