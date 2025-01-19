#ifndef TOURNAMENTWINDOW_H
#define TOURNAMENTWINDOW_H

#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/log.h>
#include "MainFrame.h"
#include "Tournament.h"
#include "StartingListPanel.h"
#include "InfoPanel.h"
#include "ResultsPanel.h"
#include "RoundPanel.h"


class TournamentWindow : public wxPanel {
public:
    TournamentWindow(wxWindow* parent, Tournament* t);
    void OnSaveTournament(wxCommandEvent& event);
    void RefreshRoundButtons();
private:
    void OnShowStartingList(wxCommandEvent& event);
    void OnShowInfoPanel(wxCommandEvent& event);
    void OnShowResults(wxCommandEvent& event);
    void OnShowRound(wxCommandEvent& event, int roundNumber);
    wxPanel* contentPanel;
    wxPanel* buttonPanel;
    Tournament* tournament;
    wxStaticText* mainLabel;
    wxStaticText* tournamentLabel;
    wxStaticText* arbiterLabel;
    wxStaticText* arbiterLabel2;
    wxStaticText* placeLabel;
    wxStaticText* placeLabel2;
    wxStaticText* dateLabel;
    wxStaticText* dateLabel2;
    wxStaticText* aboutLabel;
    wxStaticText* aboutLabel2;
    wxButton* startingListButton;
    wxButton* resultsButton;
    wxButton* mainButton;
};

#endif // TOURNAMENTWINDOW_H