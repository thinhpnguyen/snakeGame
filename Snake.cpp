// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <vector>
#include <wx/simplebook.h>
#include <wx/dcbuffer.h>
#include "constants.h"
#include "Snake.h"
#include "Backend.h"

using namespace std;
using namespace SnakeGame;


class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

enum
{
    ID_Hello,
    ID_Start_Button
};

wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)

EVT_BUTTON(ID_Start_Button, GameFrame::OnStart)

wxEND_EVENT_TABLE()

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

    start = new wxButton(panel, ID_Start_Button, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
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



void GameFrame::OnStart(wxCommandEvent& event) {
    book->ShowNewPage(gameScreen);
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


GamePanel::GamePanel(wxWindow* parent, int ID) : wxPanel(parent, ID), game(Game(*this)){
    wxSize size(640, 480);
    SetMinSize(size);
    SetMaxSize(size);


}
void GamePanel::onPaint(wxPaintEvent&) {
    wxBufferedPaintDC dc(this);

    // clear the background
    dc.SetBackground(*wxGREY_BRUSH);
    dc.Clear();

    if (game.isPlaying()) {
        // draw the snake
        drawSnake(dc);
    }
}

void GamePanel::newGame() {
    // start a 'novice' difficulty level game
    game.start();

    // refresh the screen
    Refresh();
}

void GamePanel::drawSnake(wxDC& dc) {
    int BLOCK_SIZE = 16;
    const std::vector<wxPoint>& body = game.getSnake().getBody();
    const wxPoint& head = game.getSnake().getHead();
    dc.SetPen(*wxGREEN_PEN);
    dc.SetBrush(*wxBLUE_BRUSH);
    // draw the head
    dc.DrawRectangle(head.x, head.y, BLOCK_SIZE, BLOCK_SIZE);

    //draw the body
    dc.SetPen(*wxGREY_PEN);
    dc.SetBrush(*wxGREEN_BRUSH);

    for (unsigned int i = 0; i < body.size(); i++) {
        dc.DrawRectangle(body[i].x, body[i].y, BLOCK_SIZE, BLOCK_SIZE);
    }
}

void GamePanel::onKeyDown(wxKeyEvent& event) {
    switch (event.m_keyCode) {
    case WXK_PAUSE:
        // (un)pause the game
        game.togglePause();
        break;
    case WXK_UP:
        // up arrow = north
        if (game.getSnake().getDirection() != DOWN) {
            game.changeDirection(UP);
        }

        break;
    case WXK_RIGHT:
        // right arrow = west
        if (game.getSnake().getDirection() != LEFT) {
            game.changeDirection(RIGHT);
        }

        break;
    case WXK_DOWN:
        // down arrow = south
        if (game.getSnake().getDirection() != UP) {
            game.changeDirection(DOWN);
        }

        break;
    case WXK_LEFT:
        // left arrow = west
        if (game.getSnake().getDirection() != RIGHT) {
            game.changeDirection(LEFT);
        }

        break;
    default:
        // allow other handlers to process KEY_DOWN events
        event.Skip();
        break;
    }
}