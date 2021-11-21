// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "Snake.h"
#include <wx/simplebook.h>

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
    GameFrame* frame = new GameFrame();
    frame->SetClientSize(640, 880);
    frame->Centre();
    frame->Show(true);
    return true;
}
GameFrame::GameFrame()
    : wxFrame(NULL, wxID_ANY, "Snake Game", wxDefaultPosition,
        wxDefaultSize, wxCAPTION | wxSYSTEM_MENU |
        wxMINIMIZE_BOX | wxCLOSE_BOX)
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
    SetStatusText("Welcome!");
    Bind(wxEVT_MENU, &GameFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &GameFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &GameFrame::OnExit, this, wxID_EXIT);


    //Welcome page
    book = new wxSimplebook(this, wxID_ANY);
    wxPanel* panel = new wxPanel(book, wxID_ANY);
    wxSizer* welcomeScreenSizer = new wxBoxSizer(wxVERTICAL);
    gameScreen = new GamePanel(book, wxID_ANY);

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

    book->ShowNewPage(panel);

}
void GameFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void GameFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxNO | wxYES | wxICON_INFORMATION);
}
void GameFrame::OnHello(wxCommandEvent& event)
{
    book->ShowNewPage(gameScreen);
}


GamePanel::GamePanel(wxWindow* parent, int ID) : wxPanel(parent, ID) {
    wxSizer* welcomeScreenSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* gameTitle = new wxStaticText(this, wxID_ANY, wxT("Game Screen"), wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    gameTitle->Wrap(-1);
    gameTitle->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans Serif")));

    wxButton* start = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
    wxButton* leaderBoard = new wxButton(this, wxID_ANY, wxT("Leader Board"), wxDefaultPosition, wxDefaultSize, 0);
    wxButton* quit = new wxButton(this, wxID_ANY, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0);
    welcomeScreenSizer->AddSpacer(200);
    welcomeScreenSizer->Add(gameTitle, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(start, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(leaderBoard, 0, wxALIGN_CENTER, 0);
    welcomeScreenSizer->AddSpacer(20);
    welcomeScreenSizer->Add(quit, 0, wxALIGN_CENTER, 0);

    this->SetSizer(welcomeScreenSizer);
}
