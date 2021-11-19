// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "Snake.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

enum
{
    ID_Hello = 1
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    //wxFont myFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    //frame->SetFont(myFont);
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Snake Game")
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);


    //Game Title
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxSizer* welcomeScreenSizer = new wxBoxSizer(wxVERTICAL);

    gameTitle = new wxStaticText(panel, wxID_ANY, wxT("Snake Game"), wxPoint(10,10), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    gameTitle->Wrap(-1);
    gameTitle->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans Serif")));

    start = new wxButton(panel, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
    leaderBoard = new wxButton(panel, wxID_ANY, wxT("Leader Board"), wxDefaultPosition, wxDefaultSize, 0);
    quit = new wxButton(panel, wxID_ANY, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0);
    welcomeScreenSizer->AddSpacer(200);
    welcomeScreenSizer->Add(gameTitle, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(start, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(leaderBoard, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(quit, 0, wxALIGN_CENTER, 0);

    panel->SetSizer(welcomeScreenSizer);

}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxNO | wxYES | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}