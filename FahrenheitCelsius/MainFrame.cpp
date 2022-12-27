#include <wx/wx.h>
#include <wx/valnum.h>
#include "MainFrame.h"
#include "functions.h"


MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, "Temperature Exchange")
{
    wxFloatingPointValidator<float>
        val(4, &m_value, wxNUM_VAL_ZERO_AS_BLANK);
    panel = new wxPanel(this, wxID_ANY);
    wxStaticText* f_text = new wxStaticText(panel, wxID_ANY, "F°", wxPoint(25, 0), wxSize(200, 30), wxTEXT_ALIGNMENT_CENTER);
    f_inp = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(25, 20), wxSize(200, 30), 0, val);
    wxStaticText* c_text = new wxStaticText(panel, wxID_ANY, "C°", wxPoint(25, 55), wxSize(200, 30), wxTEXT_ALIGNMENT_CENTER);
    c_inp = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(25, 75), wxSize(200, 30), 0, val);
    ConvertF = new wxButton(panel, wxID_ANY, _T("F° to C°"), wxPoint(25, 110), wxSize(200, 40), 0);
    ConvertC = new wxButton(panel, wxID_ANY, _T("C° to F°"), wxPoint(25, 155), wxSize(200, 40), 0);

    ConvertF->Bind(wxEVT_BUTTON, &MainFrame::OnConvertF, this);
    ConvertC->Bind(wxEVT_BUTTON, &MainFrame::OnConvertC, this);

    wxMenu* menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Temperature conversion.");

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a temperature conversion app.",
        "About Converter", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnConvertF(wxCommandEvent& event)
{
    SetStatusText("converting...");
    double val_f;
    this->f_inp->GetValue().ToDouble(&val_f);

    this->c_inp->ChangeValue(std::to_string(fahrenheit2celsius(val_f)));
    SetStatusText("");
}

void MainFrame::OnConvertC(wxCommandEvent& event)
{
    SetStatusText("converting...");
    double val_c;
    this->c_inp->GetValue().ToDouble(&val_c);

    this->f_inp->ChangeValue(std::to_string(celsius2fahrenheit(val_c)));
    SetStatusText("");
}