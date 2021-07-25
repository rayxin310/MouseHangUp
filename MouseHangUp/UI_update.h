#pragma once
namespace UpdateUI
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Text box control
	delegate void InvokeDelegate_TB_Control_Text(TextBox^ text_box, String^ control_data);
	void TB_text_update(TextBox^ text_box, String^ text_data);
	//void TB_color_update(TextBox^ text_box, String^ color_data);
	//Label control
	delegate void InvokeDelegate_LB_Control_Text(Label^ text_box, String^ control_data);
	void LB_text_update(Label^ label, String^ text_data);
	//void LB_color_update(Label^ text_box, String^ text_data);
}