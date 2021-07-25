#include "TopForm.h"
namespace MouseHangUp 
{
	System::Void TopForm::btn_start_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Start_Process_backgroundWorker();
	}

	System::Void TopForm::Mouse_Fuzzy_Control_function(int process_time)
	{
		
		int x_set, y_set;
		int x_get, y_get;
		int x_delta, y_delta;
		int x_temp, y_temp;
		int percentage;
		int now_time;
		int time_left;
		bool turn_back = true;
		Random^ rnd_x = gcnew Random();
		System::Threading::Thread::Sleep(50);//�ݶ��j15ms�H�W random seed �~�|���P
		Random^ rnd_y = gcnew Random();
		System::Diagnostics::Stopwatch^ loop_timer = gcnew System::Diagnostics::Stopwatch;
		loop_timer->Reset();
		loop_timer->Start();
		while (!this->Process_backgroundWorker->CancellationPending && loop_timer->Elapsed.TotalMilliseconds <= process_time)
		{
			POINT position;
			IOControl::GetMousePosition(&position);
			//mouse_event(MOUSEEVENTF_LEFTDOWN, position.x, position.y, 0, 0);
			System::Threading::Thread::Sleep(10);
			x_delta = rnd_x->Next(-10, 11);
			y_delta = rnd_y->Next(-10, 11);
			x_get = position.x;
			y_get = position.y;
			if ((x_get != x_set && y_get != y_set) || turn_back)
			{
				x_set = x_get + x_delta;
				y_set = y_get + y_delta;
				x_temp = x_delta;
				y_temp = y_delta;
				turn_back = false;
			}
			else
			{
				x_set -= x_temp;
				y_set -= y_temp;
				x_temp = 0;
				y_temp = 0;
				turn_back = true;
			}
			IOControl::SetMousePosition(x_set, y_set);

			//this->lb_status->Invoke(this->UI_Update_LB_Text_Control, this->lb_status, "Set:(" + x_set + "," + y_set + ")");
			now_time = loop_timer->Elapsed.TotalMilliseconds;
			time_left = (process_time - now_time) / 1000;//sec
			this->lb_status->Invoke(this->UI_Update_LB_Text_Control, this->lb_status, "Ongoing:(" + (time_left / 3600).ToString("00") +":" + ((time_left % 3600) / 60).ToString("00") + ":" + ((time_left % 3600) % 60).ToString("00") + ")");
			
			percentage = (now_time * 100) / process_time;
			
			this->Process_backgroundWorker->ReportProgress(percentage, "Set:(" + x_set + "," + y_set + ")");
			System::Threading::Thread::Sleep(200);
			//mouse_event(MOUSEEVENTF_LEFTDOWN, x_set, y_set, 0, 0);
		}
		loop_timer->Stop();
		if (loop_timer->Elapsed.TotalMilliseconds > process_time)
		{
			this->Process_backgroundWorker->ReportProgress(100,"Done");
		}
		
	}
	System::Void TopForm::Start_Process_backgroundWorker() 
	{
		this->btn_start->Enabled = false;
		this->btn_start->BackColor = System::Drawing::Color::Orange;
		this->gb_time_set->Enabled = false;
		this->Setting_time_transfer();
		this->UI_Update_LB_Text_Control = gcnew InvokeDelegate_LB_Control_Text(&LB_text_update);
		if (this->Process_backgroundWorker->IsBusy != true) {
			this->Process_backgroundWorker->RunWorkerAsync();
		}
	}
	System::Void TopForm::Interrupt_Process_backgroundWorker()
	{
		if (this->Process_backgroundWorker->IsBusy)
		{
			this->Process_backgroundWorker->CancelAsync();
			this->btn_start->Enabled = true;
			this->btn_start->BackColor = System::Drawing::Color::LimeGreen;
			this->gb_time_set->Enabled = true;
			this->lb_status->Text = "Interrupt";
			MessageBox::Show("Interrupt !!");
			this->lb_status->Text = "Ready";
			this->TopToolStripProgressBar->Value = 0;
		}
	}
	
	//background worker
	System::Void TopForm::Process_backgroundWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
	{
		Mouse_Fuzzy_Control_function(this->Program_process_time);
	}
	System::Void TopForm::Process_backgroundWorker_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e)
	{

		this->TopToolStripProgressBar->Value = e->ProgressPercentage;
		this->lb_BackgroundWorker_status->Text = e->UserState->ToString();
	}
	System::Void TopForm::Process_backgroundWorker_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) 
	{

		if (this->TopToolStripProgressBar->Value == 100)
		{
			MessageBox::Show("End !!");
			this->TopToolStripProgressBar->Value = 0;
			this->btn_start->Enabled = true;
			this->btn_start->BackColor = System::Drawing::Color::LimeGreen;
			this->gb_time_set->Enabled = true;
			this->lb_status->Text = "Ready";
		}
		
	}
	//Key event
	void TopForm::KeyDown_Event(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode)
		{
		case Keys::Escape:
		{
			Interrupt_Process_backgroundWorker();
			break;
		}
		case Keys::F1:
		{
			Start_Process_backgroundWorker();
			break;
		}
		default:
			break;
		}
	}
	//setting data control
	System::Void TopForm::Setting_time_transfer()
	{
		this->Program_process_time = (Convert::ToInt32(this->tb_set_hr->Text)*3600 + Convert::ToInt32(this->tb_set_min->Text) * 60 + Convert::ToInt32(this->tb_set_sec->Text)) * 1000;//ms
	}
	System::Void TopForm::btn_increase_sec_low_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->tb_set_sec->Text = Convert::ToString(Convert::ToInt32(this->tb_set_sec->Text) + 1);
	}
	System::Void TopForm::btn_reduce_sec_low_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->tb_set_sec->Text = Convert::ToString(Convert::ToInt32(this->tb_set_sec->Text) - 1);
	}
	System::Void TopForm::tb_set_sec_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->tb_set_sec->Text == "")
			this->tb_set_sec->Text = "0";
		else if(Convert::ToInt32(this->tb_set_sec->Text) < 0)
			this->tb_set_sec->Text = "0";
		else if (Convert::ToInt32(this->tb_set_sec->Text) > 60)
			this->tb_set_sec->Text = "60";

	}
	System::Void TopForm::btn_increase_min_low_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_set_min->Text = Convert::ToString(Convert::ToInt32(this->tb_set_min->Text) + 1);
	}
	System::Void TopForm::btn_reduce_min_low_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_set_min->Text = Convert::ToString(Convert::ToInt32(this->tb_set_min->Text) - 1);
	}
	System::Void TopForm::tb_set_min_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->tb_set_min->Text == "")
			this->tb_set_min->Text = "0";
		else if (Convert::ToInt32(this->tb_set_min->Text) > 60)
			this->tb_set_min->Text = "60";
		else if (Convert::ToInt32(this->tb_set_min->Text) < 0)
			this->tb_set_min->Text = "0";
	}

	System::Void TopForm::btn_increase_hr_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_set_hr->Text = Convert::ToString(Convert::ToInt32(this->tb_set_hr->Text) + 1);
	}
	System::Void TopForm::btn_reduce_hr_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_set_hr->Text = Convert::ToString(Convert::ToInt32(this->tb_set_hr->Text) - 1);
	}
	System::Void TopForm::tb_set_hr_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->tb_set_hr->Text == "")
			this->tb_set_hr->Text = "0";
		else if (Convert::ToInt32(this->tb_set_hr->Text) > 24)
			this->tb_set_hr->Text = "24";
		else if (Convert::ToInt32(this->tb_set_hr->Text) < 0)
			this->tb_set_hr->Text = "0";
	}

}
