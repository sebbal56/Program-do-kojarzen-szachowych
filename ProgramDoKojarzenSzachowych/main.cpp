#include <wx/wx.h>
#include "MainFrame.h"


class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MainFrame* frame = new MainFrame("Program do kojarzeñ szachowych");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
