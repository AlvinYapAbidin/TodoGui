#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	// Methods
	void CreateControls();
	void BindEventHandlers();
	void AddSavedTasks();

	// Event handlers
	void OnAddButtonClicked(wxCommandEvent& evt);
	void OnInputEnter(wxCommandEvent& evt);
	void OnListKeyDown(wxKeyEvent& evt);
	void OnClearButtonClicked(wxCommandEvent& evt);
	void OnWindowClosed(wxCloseEvent& evt);


	// Helper methods
	void AddTaskFromInput();
	void DeleteSelectedTask();
	void MoveSelectedTask(int offset);
	void SwapTasks(int i, int j);

	wxPanel* panel;
	wxStaticText* headlineText; // Headline
	wxTextCtrl* inputField; // User input task
	wxButton* addButton; // Button to add task
	wxCheckListBox* checkListBox; // Checkboxes for each task
	wxButton* clearButton; // Button to clear all tasks
	
};

