#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BallisticGame::GameForm form;
	Application::Run(% form);
}

System::Void BallisticGame::GameForm::GamePictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ graphics = e->Graphics;
	graphics->Clear(Color::White);
	leftBallista->draw(graphics);
	rightBallista->draw(graphics);
}

System::Void BallisticGame::GameForm::AngleTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar ^ current = (TrackBar^) sender;
	leftBallista->setAngle((int) current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::SpeedTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ current = (TrackBar^)sender;
	leftBallista->setSpeed((int)current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::MassTrackBarLeftPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ current = (TrackBar^)sender;
	leftBallista->setMass((int)current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::AngleTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ current = (TrackBar^)sender;
	rightBallista->setAngle((int)current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::SpeedTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ current = (TrackBar^)sender;
	rightBallista->setSpeed((int)current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::MassTrackBarRightPlayer_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TrackBar^ current = (TrackBar^)sender;
	rightBallista->setMass((int)current->Value);
	this->GamePictureBox->Invalidate();
}

System::Void BallisticGame::GameForm::ShootButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (leftTurn)
	{
		this->LeftPlayerLabel->Hide();
		this->RightPlayerLabel->Show();

		this->MassTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::MassTrackBarLeftPlayer_Scroll);
		this->SpeedTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::SpeedTrackBarLeftPlayer_Scroll);
		this->AngleTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::AngleTrackBarLeftPlayer_Scroll);

		this->MassTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::MassTrackBarRightPlayer_Scroll);
		this->SpeedTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::SpeedTrackBarRightPlayer_Scroll);
		this->AngleTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::AngleTrackBarRightPlayer_Scroll);

		this->MassTrackBar->Value = rightBallista->getMass();
		this->SpeedTrackBar->Value = rightBallista->getSpeed();
		this->AngleTrackBar->Value = rightBallista->getAngle();
	}
	else
	{
		this->LeftPlayerLabel->Show();
		this->RightPlayerLabel->Hide();
		
		this->MassTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::MassTrackBarRightPlayer_Scroll);
		this->SpeedTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::SpeedTrackBarRightPlayer_Scroll);
		this->AngleTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::AngleTrackBarRightPlayer_Scroll);

		this->MassTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::MassTrackBarLeftPlayer_Scroll);
		this->SpeedTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::SpeedTrackBarLeftPlayer_Scroll);
		this->AngleTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::AngleTrackBarLeftPlayer_Scroll);
		
		this->MassTrackBar->Value = leftBallista->getMass();
		this->SpeedTrackBar->Value = leftBallista->getSpeed();
		this->AngleTrackBar->Value = leftBallista->getAngle();
	}
	this->Shoot();
}

System::Void BallisticGame::GameForm::Shoot()
{
	if (leftTurn)
	{
		if (leftBallista->shoot(this->GamePictureBox->CreateGraphics(), rightBallista->getX(), rightBallista->getY()))
		{
			MessageBox::Show("The Left Player is hit! You win!", "Shoot Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->StartNewGame();
			return;
		}
		else
		{
			MessageBox::Show("The Left Player has missed!", "Shoot Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		leftTurn = false;
	}
	else
	{
		if (rightBallista->shoot(this->GamePictureBox->CreateGraphics(), leftBallista->getX(), leftBallista->getY()))
		{
			MessageBox::Show("The Right Player is hit! You win!", "Shoot Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->StartNewGame();
			return;
		}
		else
		{
			MessageBox::Show("The Right Player has missed!", "Shoot Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		leftTurn = true;
	}
}

System::Void BallisticGame::GameForm::StartNewGame()
{
	delete leftBallista;
	delete rightBallista;

	leftBallista = gcnew Ballista(0, 0, Color::Blue, true);
	rightBallista = gcnew Ballista(780, 0, Color::Red, false);

	leftTurn = true;
	this->MassTrackBar->Value = leftBallista->getMass();
	this->SpeedTrackBar->Value = leftBallista->getSpeed();
	this->AngleTrackBar->Value = leftBallista->getAngle();

	this->MassTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::MassTrackBarRightPlayer_Scroll);
	this->SpeedTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::SpeedTrackBarRightPlayer_Scroll);
	this->AngleTrackBar->Scroll -= gcnew System::EventHandler(this, &GameForm::AngleTrackBarRightPlayer_Scroll);

	this->MassTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::MassTrackBarLeftPlayer_Scroll);
	this->SpeedTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::SpeedTrackBarLeftPlayer_Scroll);
	this->AngleTrackBar->Scroll += gcnew System::EventHandler(this, &GameForm::AngleTrackBarLeftPlayer_Scroll);

	this->GamePictureBox->Invalidate();
}
