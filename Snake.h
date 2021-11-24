#pragma once
#ifndef _SNAKE_HH_
#define _SNAKE_HH_

#include <wx/wxprec.h>
#include <wx/simplebook.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "game.h"


class GamePanel : public wxPanel
{
public:
    GamePanel(wxWindow* parent, int ID);
private:
    Game& game;
    void drawSnake(wxDC& dc);
    void onPaint(wxPaintEvent& event);
    void onEraseBackground(wxEraseEvent& event);
    void onKeyDown(wxKeyEvent& event);

};
class GameFrame : public wxFrame
{
public:
    GameFrame();
    //~GameFrame();
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
    void OnStart(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();

};

#endif