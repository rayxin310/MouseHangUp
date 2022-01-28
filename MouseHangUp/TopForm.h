#pragma once
#include"UserIOControl.h"
#include"UI_update.h"
namespace MouseHangUp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace IOControl;
	using namespace UpdateUI;
	/// <summary>
	/// TopForm 的摘要
	/// </summary>
	public ref class TopForm : public System::Windows::Forms::Form
	{
	public:
		TopForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			InitializeCustomItem();
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~TopForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::BackgroundWorker^ Process_backgroundWorker;


	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::Label^ lb_status;
	private: System::Delegate^ UI_Update_LB_Text_Control;
	private: System::Windows::Forms::Button^ btn_reduce_sec_low;

	private: System::Windows::Forms::Button^ btn_increase_sec_low;

	private: System::Windows::Forms::TextBox^ tb_set_sec;
	private: System::Windows::Forms::GroupBox^ gb_time_set;
	public: int Program_process_time;
	public: int mouse_random_value;
	public: int mouse_process_speed;

	private: System::Windows::Forms::TextBox^ tb_set_min;
	private: System::Windows::Forms::Button^ btn_increase_min_low;
	private: System::Windows::Forms::Button^ btn_reduce_min_low;






	private: System::Windows::Forms::GroupBox^ gb_min;
	private: System::Windows::Forms::GroupBox^ gb_sec;
	private: System::Windows::Forms::GroupBox^ gb_hour;
	private: System::Windows::Forms::Button^ btn_reduce_hr;
	private: System::Windows::Forms::TextBox^ tb_set_hr;
	private: System::Windows::Forms::Button^ btn_incrase_hr;
	private: System::Windows::Forms::ToolStrip^ TopToolStrip;
	private: System::Windows::Forms::ToolStripProgressBar^ TopToolStripProgressBar;

	private: System::Windows::Forms::ToolStripLabel^ lb_BackgroundWorker_status;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::TrackBar^ RandomTrackBar;
	private: System::Windows::Forms::TrackBar^ SpeedTrackBar;
	private: System::Windows::Forms::GroupBox^ gb_mouse_range;
	private: System::Windows::Forms::GroupBox^ gb_mouse_speed;
	private: System::Windows::Forms::GroupBox^ gb_function;
	private: System::Windows::Forms::RadioButton^ rb_fuzzy;
	private: System::Windows::Forms::RadioButton^ rb_record;
	private: System::Windows::Forms::RadioButton^ rb_play;
	private: System::Windows::Forms::RadioButton^ rb_auto;


	private: System::Windows::Forms::Label^ lb_remark;

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		void InitializeCustomItem()
		{
			this->KeyDown += gcnew KeyEventHandler(this, &TopForm::KeyDown_Event);
		}
		/// </summary>
		System::ComponentModel::Container ^components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TopForm::typeid));
			this->Process_backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->lb_status = (gcnew System::Windows::Forms::Label());
			this->btn_reduce_sec_low = (gcnew System::Windows::Forms::Button());
			this->btn_increase_sec_low = (gcnew System::Windows::Forms::Button());
			this->tb_set_sec = (gcnew System::Windows::Forms::TextBox());
			this->gb_time_set = (gcnew System::Windows::Forms::GroupBox());
			this->gb_sec = (gcnew System::Windows::Forms::GroupBox());
			this->gb_hour = (gcnew System::Windows::Forms::GroupBox());
			this->btn_reduce_hr = (gcnew System::Windows::Forms::Button());
			this->tb_set_hr = (gcnew System::Windows::Forms::TextBox());
			this->btn_incrase_hr = (gcnew System::Windows::Forms::Button());
			this->gb_min = (gcnew System::Windows::Forms::GroupBox());
			this->btn_reduce_min_low = (gcnew System::Windows::Forms::Button());
			this->tb_set_min = (gcnew System::Windows::Forms::TextBox());
			this->btn_increase_min_low = (gcnew System::Windows::Forms::Button());
			this->lb_remark = (gcnew System::Windows::Forms::Label());
			this->TopToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->TopToolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->lb_BackgroundWorker_status = (gcnew System::Windows::Forms::ToolStripLabel());
			this->RandomTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->SpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->gb_mouse_range = (gcnew System::Windows::Forms::GroupBox());
			this->gb_mouse_speed = (gcnew System::Windows::Forms::GroupBox());
			this->gb_function = (gcnew System::Windows::Forms::GroupBox());
			this->rb_play = (gcnew System::Windows::Forms::RadioButton());
			this->rb_record = (gcnew System::Windows::Forms::RadioButton());
			this->rb_fuzzy = (gcnew System::Windows::Forms::RadioButton());
			this->rb_auto = (gcnew System::Windows::Forms::RadioButton());
			this->gb_time_set->SuspendLayout();
			this->gb_sec->SuspendLayout();
			this->gb_hour->SuspendLayout();
			this->gb_min->SuspendLayout();
			this->TopToolStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RandomTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedTrackBar))->BeginInit();
			this->gb_mouse_range->SuspendLayout();
			this->gb_mouse_speed->SuspendLayout();
			this->gb_function->SuspendLayout();
			this->SuspendLayout();
			// 
			// Process_backgroundWorker
			// 
			this->Process_backgroundWorker->WorkerReportsProgress = true;
			this->Process_backgroundWorker->WorkerSupportsCancellation = true;
			this->Process_backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &TopForm::Process_backgroundWorker_DoWork);
			this->Process_backgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &TopForm::Process_backgroundWorker_ProgressChanged);
			this->Process_backgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &TopForm::Process_backgroundWorker_RunWorkerCompleted);
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::Color::LimeGreen;
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_start->Location = System::Drawing::Point(12, 13);
			this->btn_start->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(66, 34);
			this->btn_start->TabIndex = 1;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &TopForm::btn_start_Click);
			// 
			// lb_status
			// 
			this->lb_status->AutoSize = true;
			this->lb_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lb_status->Location = System::Drawing::Point(84, 17);
			this->lb_status->Name = L"lb_status";
			this->lb_status->Size = System::Drawing::Size(74, 25);
			this->lb_status->TabIndex = 2;
			this->lb_status->Text = L"Ready";
			// 
			// btn_reduce_sec_low
			// 
			this->btn_reduce_sec_low->Location = System::Drawing::Point(6, 22);
			this->btn_reduce_sec_low->Name = L"btn_reduce_sec_low";
			this->btn_reduce_sec_low->Size = System::Drawing::Size(18, 23);
			this->btn_reduce_sec_low->TabIndex = 3;
			this->btn_reduce_sec_low->Text = L"-";
			this->btn_reduce_sec_low->UseVisualStyleBackColor = true;
			this->btn_reduce_sec_low->Click += gcnew System::EventHandler(this, &TopForm::btn_reduce_sec_low_Click);
			// 
			// btn_increase_sec_low
			// 
			this->btn_increase_sec_low->Location = System::Drawing::Point(49, 22);
			this->btn_increase_sec_low->Name = L"btn_increase_sec_low";
			this->btn_increase_sec_low->Size = System::Drawing::Size(18, 23);
			this->btn_increase_sec_low->TabIndex = 3;
			this->btn_increase_sec_low->Text = L"+";
			this->btn_increase_sec_low->UseVisualStyleBackColor = true;
			this->btn_increase_sec_low->Click += gcnew System::EventHandler(this, &TopForm::btn_increase_sec_low_Click);
			// 
			// tb_set_sec
			// 
			this->tb_set_sec->Location = System::Drawing::Point(24, 22);
			this->tb_set_sec->Name = L"tb_set_sec";
			this->tb_set_sec->Size = System::Drawing::Size(25, 21);
			this->tb_set_sec->TabIndex = 4;
			this->tb_set_sec->Text = L"10";
			this->tb_set_sec->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_set_sec->TextChanged += gcnew System::EventHandler(this, &TopForm::tb_set_sec_TextChanged);
			// 
			// gb_time_set
			// 
			this->gb_time_set->Controls->Add(this->gb_sec);
			this->gb_time_set->Controls->Add(this->gb_hour);
			this->gb_time_set->Controls->Add(this->gb_min);
			this->gb_time_set->Location = System::Drawing::Point(12, 54);
			this->gb_time_set->Name = L"gb_time_set";
			this->gb_time_set->Size = System::Drawing::Size(273, 80);
			this->gb_time_set->TabIndex = 5;
			this->gb_time_set->TabStop = false;
			this->gb_time_set->Text = L"Time Setting";
			// 
			// gb_sec
			// 
			this->gb_sec->Controls->Add(this->btn_reduce_sec_low);
			this->gb_sec->Controls->Add(this->btn_increase_sec_low);
			this->gb_sec->Controls->Add(this->tb_set_sec);
			this->gb_sec->Location = System::Drawing::Point(176, 20);
			this->gb_sec->Name = L"gb_sec";
			this->gb_sec->Size = System::Drawing::Size(72, 54);
			this->gb_sec->TabIndex = 7;
			this->gb_sec->TabStop = false;
			this->gb_sec->Text = L"Second";
			// 
			// gb_hour
			// 
			this->gb_hour->Controls->Add(this->btn_reduce_hr);
			this->gb_hour->Controls->Add(this->tb_set_hr);
			this->gb_hour->Controls->Add(this->btn_incrase_hr);
			this->gb_hour->Location = System::Drawing::Point(20, 20);
			this->gb_hour->Name = L"gb_hour";
			this->gb_hour->Size = System::Drawing::Size(72, 54);
			this->gb_hour->TabIndex = 6;
			this->gb_hour->TabStop = false;
			this->gb_hour->Text = L"Hour";
			// 
			// btn_reduce_hr
			// 
			this->btn_reduce_hr->Location = System::Drawing::Point(6, 22);
			this->btn_reduce_hr->Name = L"btn_reduce_hr";
			this->btn_reduce_hr->Size = System::Drawing::Size(18, 23);
			this->btn_reduce_hr->TabIndex = 3;
			this->btn_reduce_hr->Text = L"-";
			this->btn_reduce_hr->UseVisualStyleBackColor = true;
			this->btn_reduce_hr->Click += gcnew System::EventHandler(this, &TopForm::btn_reduce_hr_Click);
			// 
			// tb_set_hr
			// 
			this->tb_set_hr->Location = System::Drawing::Point(24, 22);
			this->tb_set_hr->Name = L"tb_set_hr";
			this->tb_set_hr->Size = System::Drawing::Size(25, 21);
			this->tb_set_hr->TabIndex = 4;
			this->tb_set_hr->Text = L"0";
			this->tb_set_hr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_set_hr->TextChanged += gcnew System::EventHandler(this, &TopForm::tb_set_hr_TextChanged);
			// 
			// btn_incrase_hr
			// 
			this->btn_incrase_hr->Location = System::Drawing::Point(49, 22);
			this->btn_incrase_hr->Name = L"btn_incrase_hr";
			this->btn_incrase_hr->Size = System::Drawing::Size(18, 23);
			this->btn_incrase_hr->TabIndex = 3;
			this->btn_incrase_hr->Text = L"+";
			this->btn_incrase_hr->UseVisualStyleBackColor = true;
			this->btn_incrase_hr->Click += gcnew System::EventHandler(this, &TopForm::btn_increase_hr_Click);
			// 
			// gb_min
			// 
			this->gb_min->Controls->Add(this->btn_reduce_min_low);
			this->gb_min->Controls->Add(this->tb_set_min);
			this->gb_min->Controls->Add(this->btn_increase_min_low);
			this->gb_min->Location = System::Drawing::Point(98, 20);
			this->gb_min->Name = L"gb_min";
			this->gb_min->Size = System::Drawing::Size(72, 54);
			this->gb_min->TabIndex = 6;
			this->gb_min->TabStop = false;
			this->gb_min->Text = L"Minute";
			// 
			// btn_reduce_min_low
			// 
			this->btn_reduce_min_low->Location = System::Drawing::Point(6, 22);
			this->btn_reduce_min_low->Name = L"btn_reduce_min_low";
			this->btn_reduce_min_low->Size = System::Drawing::Size(18, 23);
			this->btn_reduce_min_low->TabIndex = 3;
			this->btn_reduce_min_low->Text = L"-";
			this->btn_reduce_min_low->UseVisualStyleBackColor = true;
			this->btn_reduce_min_low->Click += gcnew System::EventHandler(this, &TopForm::btn_reduce_min_low_Click);
			// 
			// tb_set_min
			// 
			this->tb_set_min->Location = System::Drawing::Point(24, 22);
			this->tb_set_min->Name = L"tb_set_min";
			this->tb_set_min->Size = System::Drawing::Size(25, 21);
			this->tb_set_min->TabIndex = 4;
			this->tb_set_min->Text = L"0";
			this->tb_set_min->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_set_min->TextChanged += gcnew System::EventHandler(this, &TopForm::tb_set_min_TextChanged);
			// 
			// btn_increase_min_low
			// 
			this->btn_increase_min_low->Location = System::Drawing::Point(49, 22);
			this->btn_increase_min_low->Name = L"btn_increase_min_low";
			this->btn_increase_min_low->Size = System::Drawing::Size(18, 23);
			this->btn_increase_min_low->TabIndex = 3;
			this->btn_increase_min_low->Text = L"+";
			this->btn_increase_min_low->UseVisualStyleBackColor = true;
			this->btn_increase_min_low->Click += gcnew System::EventHandler(this, &TopForm::btn_increase_min_low_Click);
			// 
			// lb_remark
			// 
			this->lb_remark->AutoSize = true;
			this->lb_remark->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lb_remark->ForeColor = System::Drawing::Color::Red;
			this->lb_remark->Location = System::Drawing::Point(98, 247);
			this->lb_remark->Name = L"lb_remark";
			this->lb_remark->Size = System::Drawing::Size(173, 13);
			this->lb_remark->TabIndex = 6;
			this->lb_remark->Text = L"※Press F1 to Start, ESC to Interrupt";
			// 
			// TopToolStrip
			// 
			this->TopToolStrip->AutoSize = false;
			this->TopToolStrip->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->TopToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->TopToolStripProgressBar,
					this->toolStripSeparator1, this->lb_BackgroundWorker_status
			});
			this->TopToolStrip->Location = System::Drawing::Point(0, 262);
			this->TopToolStrip->Name = L"TopToolStrip";
			this->TopToolStrip->Padding = System::Windows::Forms::Padding(0);
			this->TopToolStrip->Size = System::Drawing::Size(297, 25);
			this->TopToolStrip->TabIndex = 7;
			this->TopToolStrip->Text = L"toolStrip1";
			// 
			// TopToolStripProgressBar
			// 
			this->TopToolStripProgressBar->Name = L"TopToolStripProgressBar";
			this->TopToolStripProgressBar->Padding = System::Windows::Forms::Padding(0, 5, 0, 5);
			this->TopToolStripProgressBar->Size = System::Drawing::Size(190, 22);
			this->TopToolStripProgressBar->Step = 1;
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// lb_BackgroundWorker_status
			// 
			this->lb_BackgroundWorker_status->Name = L"lb_BackgroundWorker_status";
			this->lb_BackgroundWorker_status->Size = System::Drawing::Size(41, 22);
			this->lb_BackgroundWorker_status->Text = L"Status";
			// 
			// RandomTrackBar
			// 
			this->RandomTrackBar->AutoSize = false;
			this->RandomTrackBar->Location = System::Drawing::Point(6, 18);
			this->RandomTrackBar->Minimum = 1;
			this->RandomTrackBar->Name = L"RandomTrackBar";
			this->RandomTrackBar->Size = System::Drawing::Size(121, 22);
			this->RandomTrackBar->TabIndex = 9;
			this->RandomTrackBar->Value = 6;
			this->RandomTrackBar->Scroll += gcnew System::EventHandler(this, &TopForm::RandomTrackBar_Scroll);
			// 
			// SpeedTrackBar
			// 
			this->SpeedTrackBar->AutoSize = false;
			this->SpeedTrackBar->LargeChange = 1;
			this->SpeedTrackBar->Location = System::Drawing::Point(6, 18);
			this->SpeedTrackBar->Name = L"SpeedTrackBar";
			this->SpeedTrackBar->RightToLeftLayout = true;
			this->SpeedTrackBar->Size = System::Drawing::Size(121, 22);
			this->SpeedTrackBar->TabIndex = 10;
			this->SpeedTrackBar->Value = 5;
			this->SpeedTrackBar->Scroll += gcnew System::EventHandler(this, &TopForm::SpeedTrackBar_Scroll);
			// 
			// gb_mouse_range
			// 
			this->gb_mouse_range->Controls->Add(this->RandomTrackBar);
			this->gb_mouse_range->Location = System::Drawing::Point(12, 134);
			this->gb_mouse_range->Name = L"gb_mouse_range";
			this->gb_mouse_range->Size = System::Drawing::Size(133, 46);
			this->gb_mouse_range->TabIndex = 11;
			this->gb_mouse_range->TabStop = false;
			this->gb_mouse_range->Text = L"Range";
			// 
			// gb_mouse_speed
			// 
			this->gb_mouse_speed->Controls->Add(this->SpeedTrackBar);
			this->gb_mouse_speed->Location = System::Drawing::Point(152, 134);
			this->gb_mouse_speed->Name = L"gb_mouse_speed";
			this->gb_mouse_speed->Size = System::Drawing::Size(133, 46);
			this->gb_mouse_speed->TabIndex = 12;
			this->gb_mouse_speed->TabStop = false;
			this->gb_mouse_speed->Text = L"Speed";
			// 
			// gb_function
			// 
			this->gb_function->Controls->Add(this->rb_auto);
			this->gb_function->Controls->Add(this->rb_play);
			this->gb_function->Controls->Add(this->rb_record);
			this->gb_function->Controls->Add(this->rb_fuzzy);
			this->gb_function->Location = System::Drawing::Point(12, 186);
			this->gb_function->Name = L"gb_function";
			this->gb_function->Size = System::Drawing::Size(272, 58);
			this->gb_function->TabIndex = 13;
			this->gb_function->TabStop = false;
			this->gb_function->Text = L"Function select";
			// 
			// rb_play
			// 
			this->rb_play->AutoSize = true;
			this->rb_play->Location = System::Drawing::Point(205, 20);
			this->rb_play->Name = L"rb_play";
			this->rb_play->Size = System::Drawing::Size(48, 19);
			this->rb_play->TabIndex = 0;
			this->rb_play->Text = L"Play";
			this->rb_play->UseVisualStyleBackColor = true;
			// 
			// rb_record
			// 
			this->rb_record->AutoSize = true;
			this->rb_record->Location = System::Drawing::Point(134, 20);
			this->rb_record->Name = L"rb_record";
			this->rb_record->Size = System::Drawing::Size(65, 19);
			this->rb_record->TabIndex = 0;
			this->rb_record->Text = L"Record";
			this->rb_record->UseVisualStyleBackColor = true;
			// 
			// rb_fuzzy
			// 
			this->rb_fuzzy->AutoSize = true;
			this->rb_fuzzy->Location = System::Drawing::Point(72, 20);
			this->rb_fuzzy->Name = L"rb_fuzzy";
			this->rb_fuzzy->Size = System::Drawing::Size(56, 19);
			this->rb_fuzzy->TabIndex = 0;
			this->rb_fuzzy->Text = L"Fuzzy";
			this->rb_fuzzy->UseVisualStyleBackColor = true;
			// 
			// rb_auto
			// 
			this->rb_auto->AutoSize = true;
			this->rb_auto->Checked = true;
			this->rb_auto->Location = System::Drawing::Point(17, 20);
			this->rb_auto->Name = L"rb_auto";
			this->rb_auto->Size = System::Drawing::Size(49, 19);
			this->rb_auto->TabIndex = 1;
			this->rb_auto->TabStop = true;
			this->rb_auto->Text = L"Auto";
			this->rb_auto->UseVisualStyleBackColor = true;
			// 
			// TopForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 287);
			this->Controls->Add(this->gb_function);
			this->Controls->Add(this->gb_mouse_speed);
			this->Controls->Add(this->gb_mouse_range);
			this->Controls->Add(this->TopToolStrip);
			this->Controls->Add(this->lb_remark);
			this->Controls->Add(this->lb_status);
			this->Controls->Add(this->btn_start);
			this->Controls->Add(this->gb_time_set);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"TopForm";
			this->Text = L"Mouse Hang Up";
			this->gb_time_set->ResumeLayout(false);
			this->gb_sec->ResumeLayout(false);
			this->gb_sec->PerformLayout();
			this->gb_hour->ResumeLayout(false);
			this->gb_hour->PerformLayout();
			this->gb_min->ResumeLayout(false);
			this->gb_min->PerformLayout();
			this->TopToolStrip->ResumeLayout(false);
			this->TopToolStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RandomTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedTrackBar))->EndInit();
			this->gb_mouse_range->ResumeLayout(false);
			this->gb_mouse_speed->ResumeLayout(false);
			this->gb_function->ResumeLayout(false);
			this->gb_function->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//this->KeyDown += gcnew KeyEventHandler(this, &TopForm::KeyDown_Event);
	public: void KeyDown_Event(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void Process_backgroundWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
	private: System::Void Process_backgroundWorker_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);
	private: System::Void Process_backgroundWorker_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e);
	public: System::Void Start_Process_backgroundWorker();
	public: System::Void Interrupt_Process_backgroundWorker();
	private: System::Void Mouse_Fuzzy_Control_function();
	private: System::Void Mouse_AutoHangUp_Function();
	private: System::Boolean Record_Mouse_Action(int time);
	private: System::Boolean HangUP(POINT Initial_Pos, int Random_Val);
	private: System::Void Mouse_Record_function(std::vector<int>& x_axis, std::vector<int>& y_axis);
	private: System::Void Mouse_Play_function(std::vector<int>& x_axis, std::vector<int>& y_axis);
	private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Setting_time_transfer();
	private: System::Void btn_increase_sec_low_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_reduce_sec_low_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_increase_min_low_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_reduce_min_low_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_increase_hr_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_reduce_hr_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tb_set_sec_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tb_set_min_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tb_set_hr_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RandomTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SpeedTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e);
};
}
