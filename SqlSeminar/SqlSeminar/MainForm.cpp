#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SqlSeminar::MainForm mainForm;

	mainForm.ShowDialog(); //end of session data
	Relation^ relation = mainForm.relation;

	if (relation != nullptr) {
	}
	else {
		MessageBox::Show("Neuspjelo pokretanje");
	}
}