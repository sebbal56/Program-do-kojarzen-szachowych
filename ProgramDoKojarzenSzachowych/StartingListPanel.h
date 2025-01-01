#ifndef STARTING_LIST_PANEL_H
#define STARTING_LIST_PANEL_H

#include <wx/wx.h>
#include <wx/listbox.h>

class StartingListPanel : public wxPanel {
public:
    // Konstruktor
    StartingListPanel(wxWindow* parent);

private:
    // Komponenty interfejsu u¿ytkownika
    wxStaticText* titleLabel;
    wxListBox* listBox;

    // Metoda pomocnicza, aby utworzyæ komponenty panelu
    void CreateUI();
};

#endif // STARTING_LIST_PANEL_H
