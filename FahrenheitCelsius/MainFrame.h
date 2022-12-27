#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    wxPanel* panel;
    wxButton* ConvertF;
    wxButton* ConvertC;
    wxTextCtrl* f_inp;
    wxTextCtrl* c_inp;

    float m_value;

private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnConvertF(wxCommandEvent& event);
    void OnConvertC(wxCommandEvent& event);
};