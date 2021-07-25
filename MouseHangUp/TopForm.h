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

	public:

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
			this->lb_BackgroundWorker_status = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->gb_time_set->SuspendLayout();
			this->gb_sec->SuspendLayout();
			this->gb_hour->SuspendLayout();
			this->gb_min->SuspendLayout();
			this->TopToolStrip->SuspendLayout();
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
			this->btn_start->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->lb_status->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lb_status->Location = System::Drawing::Point(84, 17);
			this->lb_status->Name = L"lb_status";
			this->lb_status->Size = System::Drawing::Size(73, 27);
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
			this->tb_set_sec->Size = System::Drawing::Size(25, 23);
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
			this->tb_set_hr->Size = System::Drawing::Size(25, 23);
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
			this->tb_set_min->Size = System::Drawing::Size(25, 23);
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
			this->lb_remark->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lb_remark->ForeColor = System::Drawing::Color::Red;
			this->lb_remark->Location = System::Drawing::Point(12, 137);
			this->lb_remark->Name = L"lb_remark";
			this->lb_remark->Size = System::Drawing::Size(187, 15);
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
			this->TopToolStrip->Location = System::Drawing::Point(0, 153);
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
			// lb_BackgroundWorker_status
			// 
			this->lb_BackgroundWorker_status->Name = L"lb_BackgroundWorker_status";
			this->lb_BackgroundWorker_status->Size = System::Drawing::Size(41, 22);
			this->lb_BackgroundWorker_status->Text = L"Status";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// TopForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 178);
			this->Controls->Add(this->TopToolStrip);
			this->Controls->Add(this->lb_remark);
			this->Controls->Add(this->lb_status);
			this->Controls->Add(this->btn_start);
			this->Controls->Add(this->gb_time_set);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
	private: System::Void Mouse_Fuzzy_Control_function(int process_time);
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
};
}
