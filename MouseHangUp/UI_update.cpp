#include"UI_update.h"
namespace UpdateUI 
{
	void TB_text_update(TextBox^ text_box, String^ text_data) 
	{
		text_box->Text = text_data;
	}
	void LB_text_update(Label^ label, String^ text_data)
	{
		label->Text = text_data;
	}
	
}