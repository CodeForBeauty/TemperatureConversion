// include WxWidgets library
#include <wx/wx.h>
#include <wx/valnum.h>
#include "MainFrame.h"
#include "functions.h"

// override MainFrame's constructor
MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, "Temperature Exchange")
{
    // initialize text input validator with max 4 numbers after point
    wxFloatingPointValidator<float>
        val(4, &m_value, wxNUM_VAL_ZERO_AS_BLANK);
    // initialize panel object
    panel = new wxPanel(this, wxID_ANY);
    // initialize text input elements with static text above
    wxStaticText* f_text = new wxStaticText(panel, wxID_ANY, "F°", wxPoint(25, 0), wxSize(200, 30), wxTEXT_ALIGNMENT_CENTER);
    f_inp = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(25, 20), wxSize(200, 30), 0, val);
    wxStaticText* c_text = new wxStaticText(panel, wxID_ANY, "C°", wxPoint(25, 55), wxSize(200, 30), wxTEXT_ALIGNMENT_CENTER);
    c_inp = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(25, 75), wxSize(200, 30), 0, val);
    // initiallize buttons
    ConvertF = new wxButton(panel, wxID_ANY, _T("F° to C°"), wxPoint(25, 110), wxSize(200, 40), 0);
    ConvertC = new wxButton(panel, wxID_ANY, _T("C° to F°"), wxPoint(25, 155), wxSize(200, 40), 0);

    // add event when button clicked
    ConvertF->Bind(wxEVT_BUTTON, &MainFrame::OnConvertF, this);
    ConvertC->Bind(wxEVT_BUTTON, &MainFrame::OnConvertC, this);

    // initialize file menu
    wxMenu* menuFile = new wxMenu;
    menuFile->AppendSeparator();
    // add exit button
    menuFile->Append(wxID_EXIT);

    // initialize help menu
    wxMenu* menuHelp = new wxMenu;
    // add about button
    menuHelp->Append(wxID_ABOUT);

    // initialize menu bar
    wxMenuBar* menuBar = new wxMenuBar;
    // add file menu and help menu to menu bar
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    // set menu bar of frame
    SetMenuBar(menuBar);

    // initialize status bar and set status text
    CreateStatusBar();
    SetStatusText("Temperature conversion.");

    // add events for exit and about buttons
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

// override OnExit function
void MainFrame::OnExit(wxCommandEvent& event)
{
    // destroy frame
    Close();
}

// override OnAbout function
void MainFrame::OnAbout(wxCommandEvent& event)
{
    // show information about app
    wxMessageBox("This is a temperature conversion app.",
        "About Converter", wxOK | wxICON_INFORMATION);
}

// override OnConvertF function
void MainFrame::OnConvertF(wxCommandEvent& event)
{
    // set status text
    SetStatusText("converting...");
    // initialize fahrenheit variable
    double val_f;
    // get value from text input to variable
    this->f_inp->GetValue().ToDouble(&val_f);

    // set value of celsius text input
    this->c_inp->ChangeValue(std::to_string(fahrenheit2celsius(val_f)));
    // set status text
    SetStatusText("");
}

// override OnConvertC function
void MainFrame::OnConvertC(wxCommandEvent& event)
{
    // set status text
    SetStatusText("converting...");
    // initialize celsius variable
    double val_c;
    // get value from text input to variable
    this->c_inp->GetValue().ToDouble(&val_c);

    // set value of fahrenheit text input
    this->f_inp->ChangeValue(std::to_string(celsius2fahrenheit(val_c)));
    // set status text
    SetStatusText("");
}