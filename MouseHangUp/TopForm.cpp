#include "TopForm.h"
namespace MouseHangUp 
{
	std::vector<int> x_axis;
	std::vector<int> y_axis;
	//UI control event
	System::Void TopForm::btn_start_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Start_Process_backgroundWorker();
	}
	System::Void TopForm::RandomTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) 
	{
		this->lb_status->Text = "Range:"+ this->RandomTrackBar->Value;
	}
	System::Void TopForm::SpeedTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		this->lb_status->Text = "Speed:" + this->SpeedTrackBar->Value;
	}
	//Algorithm
	System::Void TopForm::Mouse_Fuzzy_Control_function()
	{
		
		int x_set, y_set;
		int x_get, y_get;
		int x_delta, y_delta;
		int x_temp, y_temp;
		int percentage;
		int now_time;
		int time_left;
		bool turn_back = true;
		int random_val = this->mouse_random_value;
		int speed = this->mouse_process_speed;
		int process_time = this->Program_process_time;
		Random^ rnd_x = gcnew Random();
		System::Threading::Thread::Sleep(50);//需間隔15ms以上 random seed 才會不同
		Random^ rnd_y = gcnew Random();
		System::Diagnostics::Stopwatch^ loop_timer = gcnew System::Diagnostics::Stopwatch;
		loop_timer->Reset();
		loop_timer->Start();
		while (!this->Process_backgroundWorker->CancellationPending && loop_timer->Elapsed.TotalMilliseconds <= process_time)
		{
			POINT position;
			IOControl::GetMousePosition(&position);
			//mouse_event(MOUSEEVENTF_LEFTDOWN, position.x, position.y, 0, 0);
			//System::Threading::Thread::Sleep(10);
			x_delta = rnd_x->Next(-1 * random_val, random_val + 1);
			y_delta = rnd_y->Next(-1 * random_val, random_val + 1);
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
			
			System::Threading::Thread::Sleep(20*(10 - speed));
			//mouse_event(MOUSEEVENTF_LEFTDOWN, x_set, y_set, 0, 0);
		}
		loop_timer->Stop();
		if (loop_timer->Elapsed.TotalMilliseconds > process_time)
		{
			this->Process_backgroundWorker->ReportProgress(100,"Done");
		}
		
	}
	System::Void TopForm::Mouse_Record_function(std::vector<int> &x_axis, std::vector<int> &y_axis)
	{
		int percentage;
		int now_time;
		int time_left;
		int speed = this->mouse_process_speed;
		
		int process_time = this->Program_process_time;
		System::Diagnostics::Stopwatch^ loop_timer = gcnew System::Diagnostics::Stopwatch;
		//Remote
		loop_timer->Reset();
		loop_timer->Start();
		while (!this->Process_backgroundWorker->CancellationPending && loop_timer->Elapsed.TotalMilliseconds <= process_time)
		{
			POINT position;
			IOControl::GetMousePosition(&position);
			x_axis.push_back(position.x);
			y_axis.push_back(position.y);
			now_time = loop_timer->Elapsed.TotalMilliseconds;
			time_left = (process_time - now_time) / 1000;//sec
			this->lb_status->Invoke(this->UI_Update_LB_Text_Control, this->lb_status, "Ongoing:(" + (time_left / 3600).ToString("00") + ":" + ((time_left % 3600) / 60).ToString("00") + ":" + ((time_left % 3600) % 60).ToString("00") + ")");

			percentage = (now_time * 100) / process_time;

			this->Process_backgroundWorker->ReportProgress(percentage, "Get:(" + position.x + "," + position.y + ")");

			System::Threading::Thread::Sleep(20 * (10 - speed));
			//mouse_event(MOUSEEVENTF_LEFTDOWN, x_set, y_set, 0, 0);
		}
		loop_timer->Stop();
		
		if (loop_timer->Elapsed.TotalMilliseconds > process_time)
		{
			this->Process_backgroundWorker->ReportProgress(100, "Record finish");
		}
	}
	System::Void TopForm::Mouse_Play_function(std::vector<int>& x_axis, std::vector<int>& y_axis) 
	{
		int percentage;
		int now_time;
		int time_left;
		int speed = this->mouse_process_speed;
		int set_num = 0;
		int process_time = this->Program_process_time;
		System::Diagnostics::Stopwatch^ loop_timer = gcnew System::Diagnostics::Stopwatch;
		//play
		loop_timer->Reset();
		loop_timer->Start();
		while (!this->Process_backgroundWorker->CancellationPending && loop_timer->Elapsed.TotalMilliseconds <= process_time && set_num < x_axis.size())
		{
			IOControl::SetMousePosition(x_axis[set_num], y_axis[set_num]);
			now_time = loop_timer->Elapsed.TotalMilliseconds;
			time_left = (process_time - now_time) / 1000;//sec
			this->lb_status->Invoke(this->UI_Update_LB_Text_Control, this->lb_status, "Ongoing:(" + (time_left / 3600).ToString("00") + ":" + ((time_left % 3600) / 60).ToString("00") + ":" + ((time_left % 3600) % 60).ToString("00") + ")");

			percentage = (now_time * 100) / process_time;

			this->Process_backgroundWorker->ReportProgress(percentage, "Set:(" + x_axis[set_num] + "," + y_axis[set_num] + ")");

			System::Threading::Thread::Sleep(20 * (10 - speed));
			set_num++;
		}

		loop_timer->Stop();


		if (set_num == x_axis.size())
		{
			this->Process_backgroundWorker->ReportProgress(100, "Play finish");
		}
	}
	//background worker control function
	System::Void TopForm::Start_Process_backgroundWorker() 
	{

		this->btn_start->Enabled = false;
		this->btn_start->BackColor = System::Drawing::Color::Orange;
		this->gb_time_set->Enabled = false;
		this->Setting_time_transfer();
		this->mouse_random_value = this->RandomTrackBar->Value;
		this->mouse_process_speed = this->SpeedTrackBar->Value;
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
		if (this->rb_fuzzy->Checked)
		{
			Mouse_Fuzzy_Control_function();
		}
		else if(this->rb_record->Checked)
		{
			x_axis.clear();
			y_axis.clear();
			Mouse_Record_function(x_axis,y_axis);
		}
		else if (this->rb_play->Checked) 
		{
			Mouse_Play_function(x_axis, y_axis);
		}

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
