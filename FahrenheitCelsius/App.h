// make sure loads only once
#pragma once
// include WxWidgets library
#include <wx/wx.h>

// class for GUI app
class MainApp : public wxApp
{
public:
    // initialization function from wxApp class
    virtual bool OnInit();
};