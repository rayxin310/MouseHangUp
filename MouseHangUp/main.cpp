#include "TopForm.h";
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MouseHangUp::TopForm frm;
	Application::Run(% frm);
}