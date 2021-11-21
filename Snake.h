#pragma once
#include <wx/wxprec.h>
#include <wx/simplebook.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class GamePanel : public wxPanel
{
public:
    GamePanel(wxWindow* parent, int ID);

};
class GameFrame : public wxFrame
{
public:
    GameFrame();
protected:
    wxSimplebook* book;
    wxStaticText* gameTitle;
    wxButton* start;
    wxButton* leaderBoard;
    wxButton* quit;
    GamePanel* gameScreen;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

