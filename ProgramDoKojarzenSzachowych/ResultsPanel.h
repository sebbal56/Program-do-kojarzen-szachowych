#ifndef RESULTS_PANEL_H
#define RESULTS_PANEL_H

#include <wx/wx.h>
//#include <wx/listbox.h>
#include "Tournament.h"
#include "AddPlayerPanel.h"
#include <wx/listctrl.h>

class ResultsPanel : public wxPanel {
public:
    ResultsPanel(wxWindow* parent, Tournament* t);

private:

   // wxListBox* listBox;
    wxListCtrl* listCtrl;
    Tournament* tournament;

};

#endif // RESULTS_PANEL_H
