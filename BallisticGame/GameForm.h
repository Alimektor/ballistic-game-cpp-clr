#pragma once
#include "Ballista.h"

namespace BallisticGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		bool leftPlayerTurn = true;
		Ballista ^ leftBallista = gcnew Ballista(0, 0, Color::Blue, true);
		Ballista ^ rightBallista = gcnew Ballista(780, 0, Color::Red, false);
		bool leftTurn = true;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^ MassTrackBar;
	private: System::Windows::Forms::TrackBar^ SpeedTrackBar;
	private: System::Windows::Forms::TrackBar^ AngleTrackBar;
	protected:

	protected:


	private: System::Windows::Forms::Button^ ShootButton;
	private: System::Windows::Forms::PictureBox^ GamePictureBox;

	private: System::Windows::Forms::Label^ MassLabel;
	private: System::Windows::Forms::Label^ SpeedLabel;
	private: System::Windows::Forms::Label^ AngleLabel;
	private: System::Windows::Forms::Label^ LeftPlayerLabel;
	private: System::Windows::Forms::Label^ RightPlayerLabel;




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MassTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->SpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->AngleTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->ShootButton = (gcnew System::Windows::Forms::Button());
			this->GamePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->MassLabel = (gcnew System::Windows::Forms::Label());
			this->SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->AngleLabel = (gcnew System::Windows::Forms::Label());
			this->LeftPlayerLabel = (gcnew System::Windows::Forms::Label());
			this->RightPlayerLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MassTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AngleTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GamePictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// MassTrackBar
			// 
			this->MassTrackBar->Location = System::Drawing::Point(50, 30);
			this->MassTrackBar->Maximum = 100;
			this->MassTrackBar->Minimum = 1;
			this->MassTrackBar->Name = L"MassTrackBar";
			this->MassTrackBar->Size = System::Drawing::Size(200, 45);
			this->MassTrackBar->TabIndex = 0;
			this->MassTrackBar->Value = 50;
			this->MassTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::MassTrackBarLeftPlayer_Scroll);
			// 
			// SpeedTrackBar
			// 
			this->SpeedTrackBar->Location = System::Drawing::Point(300, 30);
			this->SpeedTrackBar->Maximum = 150;
			this->SpeedTrackBar->Minimum = 1;
			this->SpeedTrackBar->Name = L"SpeedTrackBar";
			this->SpeedTrackBar->Size = System::Drawing::Size(200, 45);
			this->SpeedTrackBar->TabIndex = 1;
			this->SpeedTrackBar->Value = 75;
			this->SpeedTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::SpeedTrackBarLeftPlayer_Scroll);
			// 
			// AngleTrackBar
			// 
			this->AngleTrackBar->Location = System::Drawing::Point(550, 30);
			this->AngleTrackBar->Maximum = 89;
			this->AngleTrackBar->Minimum = 1;
			this->AngleTrackBar->Name = L"AngleTrackBar";
			this->AngleTrackBar->Size = System::Drawing::Size(200, 45);
			this->AngleTrackBar->SmallChange = 5;
			this->AngleTrackBar->TabIndex = 2;
			this->AngleTrackBar->Value = 45;
			this->AngleTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::AngleTrackBarLeftPlayer_Scroll);
			// 
			// ShootButton
			// 
			this->ShootButton->Location = System::Drawing::Point(348, 86);
			this->ShootButton->Name = L"ShootButton";
			this->ShootButton->Size = System::Drawing::Size(75, 23);
			this->ShootButton->TabIndex = 3;
			this->ShootButton->Text = L"Shoot";
			this->ShootButton->UseVisualStyleBackColor = true;
			this->ShootButton->Click += gcnew System::EventHandler(this, &GameForm::ShootButton_Click);
			// 
			// GamePictureBox
			// 
			this->GamePictureBox->Location = System::Drawing::Point(0, 110);
			this->GamePictureBox->Name = L"GamePictureBox";
			this->GamePictureBox->Size = System::Drawing::Size(780, 300);
			this->GamePictureBox->TabIndex = 4;
			this->GamePictureBox->TabStop = false;
			this->GamePictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameForm::GamePictureBox_Paint);
			// 
			// MassLabel
			// 
			this->MassLabel->AutoSize = true;
			this->MassLabel->Location = System::Drawing::Point(11, 30);
			this->MassLabel->Name = L"MassLabel";
			this->MassLabel->Size = System::Drawing::Size(33, 13);
			this->MassLabel->TabIndex = 5;
			this->MassLabel->Text = L"Mass";
			// 
			// SpeedLabel
			// 
			this->SpeedLabel->AutoSize = true;
			this->SpeedLabel->Location = System::Drawing::Point(261, 30);
			this->SpeedLabel->Name = L"SpeedLabel";
			this->SpeedLabel->Size = System::Drawing::Size(39, 13);
			this->SpeedLabel->TabIndex = 6;
			this->SpeedLabel->Text = L"Speed";
			// 
			// AngleLabel
			// 
			this->AngleLabel->AllowDrop = true;
			this->AngleLabel->AutoSize = true;
			this->AngleLabel->Location = System::Drawing::Point(505, 30);
			this->AngleLabel->Name = L"AngleLabel";
			this->AngleLabel->Size = System::Drawing::Size(36, 13);
			this->AngleLabel->TabIndex = 7;
			this->AngleLabel->Text = L"Angle";
			// 
			// LeftPlayerLabel
			// 
			this->LeftPlayerLabel->AutoSize = true;
			this->LeftPlayerLabel->Location = System::Drawing::Point(246, 86);
			this->LeftPlayerLabel->Name = L"LeftPlayerLabel";
			this->LeftPlayerLabel->Size = System::Drawing::Size(96, 13);
			this->LeftPlayerLabel->TabIndex = 8;
			this->LeftPlayerLabel->Text = L"Left Player Shoot!";
			// 
			// RightPlayerLabel
			// 
			this->RightPlayerLabel->AutoSize = true;
			this->RightPlayerLabel->Location = System::Drawing::Point(429, 86);
			this->RightPlayerLabel->Name = L"RightPlayerLabel";
			this->RightPlayerLabel->Size = System::Drawing::Size(104, 13);
			this->RightPlayerLabel->TabIndex = 9;
			this->RightPlayerLabel->Text = L"Right Player Shoot!";
			this->RightPlayerLabel->Visible = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 411);
			this->Controls->Add(this->RightPlayerLabel);
			this->Controls->Add(this->LeftPlayerLabel);
			this->Controls->Add(this->AngleLabel);
			this->Controls->Add(this->SpeedLabel);
			this->Controls->Add(this->MassLabel);
			this->Controls->Add(this->GamePictureBox);
			this->Controls->Add(this->ShootButton);
			this->Controls->Add(this->AngleTrackBar);
			this->Controls->Add(this->SpeedTrackBar);
			this->Controls->Add(this->MassTrackBar);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GameForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MassTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AngleTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GamePictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GamePictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void AngleTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SpeedTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MassTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AngleTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SpeedTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MassTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShootButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Shoot();
	private: System::Void StartNewGame();
};
}
