// make sure loads only once
#pragma once
// include WxWidgets library
#include <wx/wx.h>

// class for frame of app
class MainFrame : public wxFrame
{
public:
    // constructor
    MainFrame(const wxString& title);
    // UI elements
    wxPanel* panel;
    wxButton* ConvertF;
    wxButton* ConvertC;
    wxTextCtrl* f_inp;
    wxTextCtrl* c_inp;

    // variable for text input validator
    float m_value;

private:
    // events
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnConvertF(wxCommandEvent& event);
    void OnConvertC(wxCommandEvent& event);
};