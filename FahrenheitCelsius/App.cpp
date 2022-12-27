#include "App.h"
#include "MainFrame.h"
// include WxWidgets library
#include <wx/wx.h>

// start GUI app
wxIMPLEMENT_APP(MainApp);

// override OnInit function of MainApp class
bool MainApp::OnInit()
{
    // initialize frame object
    MainFrame* frame = new MainFrame("Temperature Exchange");
    // set size of frame
    frame->SetClientSize(250, 200);
    // place frame on center of screen
    frame->Center();
    // make frame visible
    frame->Show();
    // keep program running
    return true;
}