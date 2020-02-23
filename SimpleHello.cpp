#include <wx/wxprec.h>
#include <iostream>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
using namespace std;

enum
{
    NEW_FILE_ID = 1
};

class SimpleHello : public wxApp
{
    wxFrame *frame;
    bool OnInit() {
        frame = new wxFrame(NULL, wxID_ANY, "Yo from Toby!");
        wxMenu * menuFile = new wxMenu;
        menuFile->Append(1, "&New", "Create a new file and stuff...");
        //menuFile->Append(wxID_EXIT);
        //menuFile->Append(2, "&My Exit", "Get the eff outta here");
        wxMenuBar *menuBar = new wxMenuBar();
        menuBar->Append(menuFile, "File");
        wxPanel *panel = new wxPanel(frame, wxID_ANY);
        wxTextCtrl *text = new wxTextCtrl(panel, wxID_ANY);
        //wxButton *button = new wxButton(panel, wxID_ANY, "Click Me");
        frame->Bind(wxEVT_MENU, &SimpleHello::OnNewFile, this, 1);
        //frame->Bind(wxEVT_MENU, &SimpleHello::OnExit, this, wxID_EXIT);
        frame->SetMenuBar(menuBar);
        frame->Show(true);
        return true;
    }

    void OnNewFile(wxCommandEvent& event) {
        wxLogMessage("New File");
    }
    /*
    void OnExit(wxCommandEvent& event) {
        frame->Close(true);
    }
    */
};

wxIMPLEMENT_APP(SimpleHello);
