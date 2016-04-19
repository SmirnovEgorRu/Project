#include "game.h"
#include <stdio.h>
#include <stdlib.h>

#pragma once


namespace Курсовая 
{
	game* Game=NULL;	//указатель на объект класса

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		/*объявление компонентов формы*/
		private:
		System::Windows::Forms::Label^  GameStatus;
		System::Windows::Forms::Button^  Round1;
		System::Windows::Forms::Button^  Round2;
		System::Windows::Forms::Label^  Turn;
		System::Windows::Forms::Button^  TurnToComputer;
		System::Windows::Forms::Label^  Error;
		System::Windows::Forms::Button^  Exit;
		System::Windows::Forms::Button^  Menu1;
		System::Windows::Forms::Button^  Menu2;
		System::Windows::Forms::RadioButton^  radioButton1;
		System::Windows::Forms::RadioButton^  radioButton2;
		System::Windows::Forms::RadioButton^  radioButton3;
		System::Windows::Forms::Button^  Rules;
		System::Windows::Forms::Label^  Dif;
		System::Windows::Forms::Label^  Icon;
		System::Windows::Forms::Button^  ButtonReturn;
		System::Windows::Forms::Label^  LabelRules1;
		System::Windows::Forms::Label^  LabelRules2;
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::PictureBox^  SUp1;
		System::Windows::Forms::PictureBox^  SUp2;
		System::Windows::Forms::PictureBox^  SDown1;
		System::Windows::Forms::PictureBox^  SDown2;
		System::Windows::Forms::PictureBox^  SLeft1;
		System::Windows::Forms::PictureBox^  SLeft2;
		System::Windows::Forms::PictureBox^  SRight1;
		System::Windows::Forms::PictureBox^  SRight2;
		System::Windows::Forms::Label^  WhoWin;
		System::Windows::Forms::Button^  ExitToMenu;
		System::ComponentModel::Container ^components;		// Требуется переменная конструктора.

		/*2 массива кнопок под поля игроков*/
		array<Button^>^ Field1;
		array<Button^>^ Field2;
	
		public: MyForm(void)	//конструктор формы
		{
			InitializeComponent();
		}

		protected: ~MyForm()	//деструктор формы
		{
			if (components) delete components;
		}

		
		private:

		/*инициализация компонентов формы*/
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Menu1 = (gcnew System::Windows::Forms::Button());
			this->Menu2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->Rules = (gcnew System::Windows::Forms::Button());
			this->Dif = (gcnew System::Windows::Forms::Label());
			this->Icon = (gcnew System::Windows::Forms::Label());
			this->ButtonReturn = (gcnew System::Windows::Forms::Button());
			this->GameStatus = (gcnew System::Windows::Forms::Label());
			this->Round1 = (gcnew System::Windows::Forms::Button());
			this->Round2 = (gcnew System::Windows::Forms::Button());
			this->Turn = (gcnew System::Windows::Forms::Label());
			this->TurnToComputer = (gcnew System::Windows::Forms::Button());
			this->Error = (gcnew System::Windows::Forms::Label());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LabelRules1 = (gcnew System::Windows::Forms::Label());
			this->LabelRules2 = (gcnew System::Windows::Forms::Label());
			this->SUp1 = (gcnew System::Windows::Forms::PictureBox());
			this->SUp2 = (gcnew System::Windows::Forms::PictureBox());
			this->SDown1 = (gcnew System::Windows::Forms::PictureBox());
			this->SDown2 = (gcnew System::Windows::Forms::PictureBox());
			this->SLeft1 = (gcnew System::Windows::Forms::PictureBox());
			this->SLeft2 = (gcnew System::Windows::Forms::PictureBox());
			this->SRight1 = (gcnew System::Windows::Forms::PictureBox());
			this->SRight2 = (gcnew System::Windows::Forms::PictureBox());
			this->WhoWin = (gcnew System::Windows::Forms::Label());
			this->ExitToMenu = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SUp1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SUp2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLeft1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLeft2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SRight1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SRight2))->BeginInit();
			this->SuspendLayout();
			// 
			// Menu1
			// 
			this->Menu1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Menu1->Location = System::Drawing::Point(191, 161);
			this->Menu1->Name = L"Menu1";
			this->Menu1->Size = System::Drawing::Size(240, 69);
			this->Menu1->TabIndex = 1;
			this->Menu1->Text = L"Против компьютера";
			this->Menu1->UseVisualStyleBackColor = true;
			this->Menu1->Click += gcnew System::EventHandler(this, &MyForm::Menu1_Click);
			// 
			// Menu2
			// 
			this->Menu2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Menu2->Location = System::Drawing::Point(191, 236);
			this->Menu2->Name = L"Menu2";
			this->Menu2->Size = System::Drawing::Size(240, 69);
			this->Menu2->TabIndex = 2;
			this->Menu2->Text = L"Игрок против игрока";
			this->Menu2->UseVisualStyleBackColor = true;
			this->Menu2->Click += gcnew System::EventHandler(this, &MyForm::Menu2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(477, 211);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(88, 29);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->Text = L"Легко";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(477, 246);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(143, 29);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Нормально";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(477, 281);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(108, 29);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->Text = L"Сложно";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// Rules
			// 
			this->Rules->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Rules->Location = System::Drawing::Point(191, 311);
			this->Rules->Name = L"Rules";
			this->Rules->Size = System::Drawing::Size(240, 69);
			this->Rules->TabIndex = 3;
			this->Rules->Text = L"Правила";
			this->Rules->UseVisualStyleBackColor = true;
			this->Rules->Click += gcnew System::EventHandler(this, &MyForm::Rules_Click);
			// 
			// Dif
			// 
			this->Dif->AutoSize = true;
			this->Dif->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Dif->Location = System::Drawing::Point(471, 183);
			this->Dif->Name = L"Dif";
			this->Dif->Size = System::Drawing::Size(257, 25);
			this->Dif->TabIndex = 6;
			this->Dif->Text = L"Сложность компьютера:";
			// 
			// Icon
			// 
			this->Icon->AutoSize = true;
			this->Icon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon->Location = System::Drawing::Point(231, 31);
			this->Icon->Name = L"Icon";
			this->Icon->Size = System::Drawing::Size(313, 91);
			this->Icon->TabIndex = 7;
			this->Icon->Text = L"Чисоло";
			// 
			// ButtonReturn
			// 
			this->ButtonReturn->Location = System::Drawing::Point(650, 185);
			this->ButtonReturn->Name = L"ButtonReturn";
			this->ButtonReturn->Size = System::Drawing::Size(94, 68);
			this->ButtonReturn->TabIndex = 8;
			this->ButtonReturn->Text = L"Вернуть прошлый ход";
			this->ButtonReturn->UseVisualStyleBackColor = true;
			this->ButtonReturn->Visible = false;
			this->ButtonReturn->Click += gcnew System::EventHandler(this, &MyForm::ButtonReturn_Click);
			// 
			// GameStatus
			// 
			this->GameStatus->AutoSize = true;
			this->GameStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GameStatus->Location = System::Drawing::Point(25, 248);
			this->GameStatus->Name = L"GameStatus";
			this->GameStatus->Size = System::Drawing::Size(160, 20);
			this->GameStatus->TabIndex = 9;
			this->GameStatus->Text = L"Ход первого игрока";
			this->GameStatus->Visible = false;
			// 
			// Round1
			// 
			this->Round1->Location = System::Drawing::Point(324, 237);
			this->Round1->Name = L"Round1";
			this->Round1->Size = System::Drawing::Size(70, 45);
			this->Round1->TabIndex = 10;
			this->Round1->Text = L"По часовой";
			this->Round1->UseVisualStyleBackColor = true;
			this->Round1->Visible = false;
			this->Round1->Click += gcnew System::EventHandler(this, &MyForm::Round1_Click);
			// 
			// Round2
			// 
			this->Round2->Location = System::Drawing::Point(400, 237);
			this->Round2->Name = L"Round2";
			this->Round2->Size = System::Drawing::Size(70, 45);
			this->Round2->TabIndex = 11;
			this->Round2->Text = L"Против часовой";
			this->Round2->UseVisualStyleBackColor = true;
			this->Round2->Visible = false;
			this->Round2->Click += gcnew System::EventHandler(this, &MyForm::Round2_Click);
			// 
			// Turn
			// 
			this->Turn->AutoSize = true;
			this->Turn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Turn->Location = System::Drawing::Point(645, 57);
			this->Turn->Name = L"Turn";
			this->Turn->Size = System::Drawing::Size(79, 29);
			this->Turn->TabIndex = 12;
			this->Turn->Text = L"label1";
			this->Turn->Visible = false;
			// 
			// TurnToComputer
			// 
			this->TurnToComputer->Location = System::Drawing::Point(650, 260);
			this->TurnToComputer->Name = L"TurnToComputer";
			this->TurnToComputer->Size = System::Drawing::Size(94, 65);
			this->TurnToComputer->TabIndex = 15;
			this->TurnToComputer->Text = L"Передать ход компьютеру";
			this->TurnToComputer->UseVisualStyleBackColor = true;
			this->TurnToComputer->Visible = false;
			this->TurnToComputer->Click += gcnew System::EventHandler(this, &MyForm::TurnToComputer_Click);
			// 
			// Error
			// 
			this->Error->AutoSize = true;
			this->Error->Location = System::Drawing::Point(582, 123);
			this->Error->Name = L"Error";
			this->Error->Size = System::Drawing::Size(146, 26);
			this->Error->TabIndex = 16;
			this->Error->Text = L"Произошло зацикливание, \r\nвыберите другую клетку";
			this->Error->Visible = false;
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->ImageKey = L"(отсутствует)";
			this->Exit->Location = System::Drawing::Point(191, 386);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(240, 69);
			this->Exit->TabIndex = 4;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(26, 214);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(382, 289);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// LabelRules1
			// 
			this->LabelRules1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelRules1->Location = System::Drawing::Point(25, 5);
			this->LabelRules1->Name = L"LabelRules1";
			this->LabelRules1->Size = System::Drawing::Size(750, 214);
			this->LabelRules1->TabIndex = 20;
			this->LabelRules1->Text = resources->GetString(L"LabelRules1.Text");
			this->LabelRules1->Visible = false;
			// 
			// LabelRules2
			// 
			this->LabelRules2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelRules2->Location = System::Drawing::Point(411, 220);
			this->LabelRules2->Name = L"LabelRules2";
			this->LabelRules2->Size = System::Drawing::Size(361, 216);
			this->LabelRules2->TabIndex = 21;
			this->LabelRules2->Text = resources->GetString(L"LabelRules2.Text");
			this->LabelRules2->Visible = false;
			// 
			// SUp1
			// 
			this->SUp1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SUp1.Image")));
			this->SUp1->Location = System::Drawing::Point(235, 5);
			this->SUp1->Name = L"SUp1";
			this->SUp1->Size = System::Drawing::Size(167, 26);
			this->SUp1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SUp1->TabIndex = 22;
			this->SUp1->TabStop = false;
			this->SUp1->Visible = false;
			// 
			// SUp2
			// 
			this->SUp2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SUp2.Image")));
			this->SUp2->Location = System::Drawing::Point(235, 205);
			this->SUp2->Name = L"SUp2";
			this->SUp2->Size = System::Drawing::Size(167, 26);
			this->SUp2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SUp2->TabIndex = 23;
			this->SUp2->TabStop = false;
			this->SUp2->Visible = false;
			// 
			// SDown1
			// 
			this->SDown1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SDown1.Image")));
			this->SDown1->Location = System::Drawing::Point(235, 285);
			this->SDown1->Name = L"SDown1";
			this->SDown1->Size = System::Drawing::Size(167, 26);
			this->SDown1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SDown1->TabIndex = 24;
			this->SDown1->TabStop = false;
			this->SDown1->Visible = false;
			// 
			// SDown2
			// 
			this->SDown2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SDown2.Image")));
			this->SDown2->Location = System::Drawing::Point(235, 487);
			this->SDown2->Name = L"SDown2";
			this->SDown2->Size = System::Drawing::Size(167, 26);
			this->SDown2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SDown2->TabIndex = 25;
			this->SDown2->TabStop = false;
			this->SDown2->Visible = false;
			// 
			// SLeft1
			// 
			this->SLeft1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SLeft1.Image")));
			this->SLeft1->Location = System::Drawing::Point(2, 60);
			this->SLeft1->Name = L"SLeft1";
			this->SLeft1->Size = System::Drawing::Size(30, 105);
			this->SLeft1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SLeft1->TabIndex = 26;
			this->SLeft1->TabStop = false;
			this->SLeft1->Visible = false;
			// 
			// SLeft2
			// 
			this->SLeft2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SLeft2.Image")));
			this->SLeft2->Location = System::Drawing::Point(2, 340);
			this->SLeft2->Name = L"SLeft2";
			this->SLeft2->Size = System::Drawing::Size(30, 105);
			this->SLeft2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SLeft2->TabIndex = 27;
			this->SLeft2->TabStop = false;
			this->SLeft2->Visible = false;
			// 
			// SRight1
			// 
			this->SRight1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SRight1.Image")));
			this->SRight1->Location = System::Drawing::Point(609, 60);
			this->SRight1->Name = L"SRight1";
			this->SRight1->Size = System::Drawing::Size(30, 105);
			this->SRight1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SRight1->TabIndex = 28;
			this->SRight1->TabStop = false;
			this->SRight1->Visible = false;
			// 
			// SRight2
			// 
			this->SRight2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SRight2.Image")));
			this->SRight2->Location = System::Drawing::Point(609, 340);
			this->SRight2->Name = L"SRight2";
			this->SRight2->Size = System::Drawing::Size(30, 105);
			this->SRight2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SRight2->TabIndex = 29;
			this->SRight2->TabStop = false;
			this->SRight2->Visible = false;
			// 
			// WhoWin
			// 
			this->WhoWin->AutoSize = true;
			this->WhoWin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->WhoWin->Location = System::Drawing::Point(-1, 214);
			this->WhoWin->Name = L"WhoWin";
			this->WhoWin->Size = System::Drawing::Size(645, 91);
			this->WhoWin->TabIndex = 30;
			this->WhoWin->Text = L"1 игрок победил";
			this->WhoWin->Visible = false;
			// 
			// ExitToMenu
			// 
			this->ExitToMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ExitToMenu->Location = System::Drawing::Point(650, 438);
			this->ExitToMenu->Name = L"ExitToMenu";
			this->ExitToMenu->Size = System::Drawing::Size(94, 65);
			this->ExitToMenu->TabIndex = 31;
			this->ExitToMenu->Text = L"Выход в главное меню";
			this->ExitToMenu->UseVisualStyleBackColor = true;
			this->ExitToMenu->Visible = false;
			this->ExitToMenu->Click += gcnew System::EventHandler(this, &MyForm::ExitToMenu_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(784, 515);
			this->Controls->Add(this->ExitToMenu);
			this->Controls->Add(this->WhoWin);
			this->Controls->Add(this->SRight2);
			this->Controls->Add(this->SRight1);
			this->Controls->Add(this->SLeft2);
			this->Controls->Add(this->SLeft1);
			this->Controls->Add(this->SDown2);
			this->Controls->Add(this->SDown1);
			this->Controls->Add(this->SUp2);
			this->Controls->Add(this->SUp1);
			this->Controls->Add(this->LabelRules2);
			this->Controls->Add(this->LabelRules1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->Error);
			this->Controls->Add(this->TurnToComputer);
			this->Controls->Add(this->Turn);
			this->Controls->Add(this->Round2);
			this->Controls->Add(this->Round1);
			this->Controls->Add(this->GameStatus);
			this->Controls->Add(this->ButtonReturn);
			this->Controls->Add(this->Icon);
			this->Controls->Add(this->Dif);
			this->Controls->Add(this->Rules);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->Menu2);
			this->Controls->Add(this->Menu1);
			this->MaximumSize = System::Drawing::Size(800, 553);
			this->MinimumSize = System::Drawing::Size(800, 553);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Чисоло";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SUp1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SUp2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLeft1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLeft2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SRight1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SRight2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}



		//
		//обработка кликов по форме
		//

		/*игрок против компьютера*/
		System::Void Menu1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			/*создаем объекта игры и устанавливаем игровой мод на игру против компьютера*/
			Game = new game;
			Game->SetGameMode(1);
			

			/*устанавливаем сложность игры*/
			if (this->radioButton1->Checked == true) Game->SetGameDifficulty(1);
			else if (this->radioButton2->Checked == true) Game->SetGameDifficulty(2);
			else if (this->radioButton3->Checked == true) Game->SetGameDifficulty(3);
			
			/*очистка главного меню*/
			ClearMenu();			

			/*прорисовка игрового поля*/
			this->TurnToComputer->Visible = true;
			PrintDesktop();
			
			PrintTurn();
		}
			 
		/*игрок против игрока*/
		System::Void Menu2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			/*создаем объект игры и устанавливаем игровой мод на игру 2 игроков*/
			Game = new game;
			Game->SetGameMode(2);
			
			/*очистка главного меню*/
			ClearMenu();			
			
			/*прорисовка игрового поля*/
			PrintDesktop();

			PrintTurn();
		}

		/*клик по 1 игровому полю*/
		System::Void Field1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int index;		//индекс нажатой кнопки
			int Error;		//индикатор ошибки

			/*преобразуем название кнопки (равно названию индексу соответсвующей клетки)
			в индекс массива ячеек, по которой произошел клик*/
			index = System::Convert::ToInt64(((Button^)sender)->Name);

			this->Error->Visible = false;
			
			/*сохраняем направление предыдущего обхода*/
			if (Game->GetNumberOfTurn()>2) Game->SetPrevRound(Game->GetRound());

			/*если ожидается клик по 2 полю*/
			if (Game->GetGameStatus() == 2 || Game->GetGameStatus() == 3 ) return;		
			/*если не выбрано направление обхода*/
			else if (this->Round1->Visible == true && Game->GetGameMode() == 2) return;	
			/*если нужна перестановка камешков*/
			else if (Game->GetGameStatus() == 1)
			{
				/*если есть камни в заданной ячейке,осуществляем ход*/
				 if (Game->GetField_1(index))
				 {
					 Error = Game->PlayerTurn(index, 1);
					 this->ButtonReturn->Enabled = true;	//даем возможность отменить ход
				 }
				
				/*если требуется 2 игроку выбрать обход*/
				if (Game->GetGameStatus() == 2 && Game->GetNumberOfTurn()==2)			
				{
					this->Round1->Visible = true;
					this->Round2->Visible = true;
				}
			}
			/*забираем камушки из заданной ячейки*/
			else if (Game->GetGameStatus() == 4 && Game->GetField_1(index)) Game->AddToIndexForAdd(index);

			if (Error == -1) this->Error->Visible = true;	//проверка на ошибку (зацикливание)

			PrintTurn();									//отрисовка игрового поля
			if (Game->WhoWin()) NewGame();					//проверка на победу одного из игрока
		}

		/*клик по 2 игровому полю*/
		System::Void Field2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int index;			//индекс нажатой кнопки
			int Error;			//индикатор ошибки
		
			/*преобразуем название кнопки (равно названию индексу соответсвующей клетки)
			в индекс массива ячеек*/
			index = System::Convert::ToInt64(((Button^)sender)->Name);

			/*сохраняем направление предыдущего обхода*/
			if (Game->GetNumberOfTurn()>2) Game->SetPrevRound(Game->GetRound());

			this->Error->Visible = false;

			/*если ожидается клик по 1 полю*/
			if (Game->GetGameStatus() == 1 || Game->GetGameStatus() == 4 ) return;
		
			/*если не выбрано направление обхода*/
			else if (this->Round1->Visible == true && Game->GetGameMode() == 2) return;
		
			/*если нужна перестановка камешков*/
			else if (Game->GetGameStatus() == 2 && Game->GetField_2(index)) Error = Game->PlayerTurn(index, 2);
		
			/*забираем камушки из заданной ячейки*/
			else if (Game->GetGameStatus() == 3 && Game->GetField_2(index))
			{
				Game->AddToIndexForAdd(index);
			
				/*если требуется 2 игроку выбрать обход*/
				if (Game->GetNumberOfTurn() == 2 && Game->GetGameMode() == 2)
				{
					this->Round1->Visible = true;
					this->Round2->Visible = true;
				}
			}

			if (Error == -1) this->Error->Visible = true;	//проверка на ошибку (зацикливание)

			PrintTurn();									//отрисовка игрового поля
			if (Game->WhoWin()) NewGame();					//проверка на победу одного из игроков
		}

		/*клик по кнопке правил*/
		System::Void Rules_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ClearMenu();
			this->LabelRules1->Visible = true;
			this->LabelRules2->Visible = true;
			this->pictureBox1->Visible = true;
			this->ExitToMenu->Visible = true;
		}

		/*клик по кнопке возрата хода*/
		System::Void ButtonReturn_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (Game->GetPrevNumberOfTurn() == 2)
			{
				this->Round1->Visible = true;
				this->Round2->Visible = true;
			}
			else
			{
				this->Round1->Visible = false;
				this->Round2->Visible = false;
			}


			Game->ReturnTurn();

			for (int i = 0; i < 14; i++)
			{
				Field1[i]->Text = Game->GetField_1(i).ToString();
				Field2[i]->Text = Game->GetField_2(i).ToString();
			}

			PrintTurn();
		}
		
		/*клик по кнопке передачи хода компьютеру*/
		System::Void TurnToComputer_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Game->GetGameStatus() == 0) Game->ComputerTurn();
			PrintTurn();
			if (Game->WhoWin()) NewGame();
		}

		/*клик по кнопке установления обхода по часовой стрелке*/
		System::Void Round1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Round1->Visible = false;
			this->Round2->Visible = false;
			Game->SetPrevRound(-1);
			Game->SetRound(0);				//установление обхода по часовой стрелки
			PrintTurn();
		}
		
		/*клик по кнопке установления обхода против часовой стрелки*/
		System::Void Round2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Round1->Visible = false;
			this->Round2->Visible = false;
			Game->SetPrevRound(-1);
			Game->SetRound(1);				//установление обхода против часовой стрелки
			PrintTurn();
		}
		
		/*клик по кнопке перехода в главное меню после победы*/
		System::Void Win_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			/*очистка рабочего поля*/
			ClearDesktop();
		}

		/*выход из программы*/
		System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			exit(0);
		}

		/*выход в главное меню*/
		System::Void ExitToMenu_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Game) ClearDesktop();
			else
			{
				PrintMenu();
				this->pictureBox1->Visible = false;
				this->LabelRules1->Visible = false;
				this->LabelRules2->Visible = false;
				this->ExitToMenu->Visible = false;
			}
		}


		//
		//вспомогательные функции
		//

		/*прорисовка игрового поля*/
		void PrintTurn()
		{
			for (int i = 0; i < 14; i++)
			{
				Field1[i]->Text = Game->GetField_1(i).ToString();
				Field2[i]->Text = Game->GetField_2(i).ToString();
			}

			this->Turn->Text = ("Ход: " + Game->GetNumberOfTurn().ToString());
				
			switch (Game->GetGameStatus())
			{
				case 0: this->GameStatus->Text = "Ход компьютера"; break;
				case 1: this->GameStatus->Text = "Ход первого игрока"; break;
				case 2: this->GameStatus->Text = "Ход второго игрока"; break;
				case 3: this->GameStatus->Text = "Первый игрок выбирает, из какой ячейки забрать все вражеские камни"; break;
				case 4: this->GameStatus->Text = "Второй игрок выбирает, из какой ячейки забрать все вражеские камни"; break;
			}

			if (Game->GetRound() == -1 || Game->GetRound() == 0)
			{
				this->SUp1->Location = System::Drawing::Point(235, 5);
				this->SUp2->Location = System::Drawing::Point(235, 205);
			
				this->SDown1->Location = System::Drawing::Point(235, 285);
				this->SDown2->Location = System::Drawing::Point(235, 487);
			
				this->SLeft1->Location = System::Drawing::Point(2, 60);
				this->SRight1->Location = System::Drawing::Point(609, 60);

				this->SLeft2->Location = System::Drawing::Point(2, 340);
				this->SRight2->Location = System::Drawing::Point(609, 340);
			}
			else
			{
				this->SUp1->Location = System::Drawing::Point(235, 205);
				this->SUp2->Location = System::Drawing::Point(235, 5);

				this->SDown1->Location = System::Drawing::Point(235, 487);
				this->SDown2->Location = System::Drawing::Point(235, 285);

				this->SLeft1->Location = System::Drawing::Point(609, 60);
				this->SRight1->Location = System::Drawing::Point(2, 60);

				this->SLeft2->Location = System::Drawing::Point(609, 340);
				this->SRight2->Location = System::Drawing::Point(2, 340);
			}


		}

		/*прорисовка главного меню*/
		void PrintMenu()
		{
			this->Rules->Visible = true;
			this->Menu1->Visible = true;
			this->Menu2->Visible = true;
			this->Icon->Visible = true;
			this->Dif->Visible = true;
			this->Dif->Visible = true;
			this->radioButton1->Visible = true;
			this->radioButton2->Visible = true;
			this->radioButton3->Visible = true;
			this->Exit->Visible = true;
		}

		/*очистка главного меню*/
		void ClearMenu()
			 {
				 this->Rules->Visible = false;
				 this->Menu1->Visible = false;
				 this->Menu2->Visible = false;
				 this->Icon->Visible = false;
				 this->Dif->Visible = false;
				 this->Dif->Visible = false;
				 this->radioButton1->Visible = false;
				 this->radioButton2->Visible = false;
				 this->radioButton3->Visible = false;
				 this->Exit->Visible = false;
			 }

		/*очистка игрового поля*/
		void ClearDesktop()
		{
			/*очистка рабочего поля*/
			this->ButtonReturn->Visible = false;
			this->GameStatus->Visible = false;
			this->Turn->Visible = false;
			this->Round1->Visible = false;
			this->Round2->Visible = false;
			this->WhoWin->Visible = false;
			this->TurnToComputer->Visible = false;
			this->Error->Visible = false;
			this->ButtonReturn->Visible = false;
			this->ExitToMenu->Visible = false;

			this->SUp1->Visible = false;
			this->SUp2->Visible = false;
			this->SDown1->Visible = false;
			this->SDown2->Visible = false;
			this->SLeft1->Visible = false;
			this->SLeft2->Visible = false;
			this->SRight1->Visible = false;
			this->SRight2->Visible = false;

			for (int i = 0; i < 14; ++i)
			{
				Field1[i]->Visible = false;
				Field2[i]->Visible = false;
			}

			/*отрисовка главного меню*/
			PrintMenu();

			/*удаление массива кнопок*/
			delete[]Field1;
			delete[]Field2;

			/*удаление класса*/
			delete Game;
			Game = NULL;
		}

		/*создание поля 1 игрока*/
		void CreateField_1()
		{
			/*координаты расположения кнопок*/
			int x;
			int y;

			/*создание массива кнопок - ячеек поля*/
			Field1 = gcnew array<Button^>(14);

			for (int i = 0; i < Field1->Length; i++)
			{
				if (i < 7)
				{
					x = 40 + 80 * i;
					y = 40;
				}
				
				else
				{
					x = 40 + 80 * (6 - (i - 7));
					y = 120;
				}
				
				/*создание кнопки и устанавление ее свойств*/
				Field1[i] = gcnew Button();
				Field1[i]->Size = Drawing::Size(75, 75);
				Field1[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				Field1[i]->Text = Game->GetField_1(i).ToString();
				Field1[i]->Name = i.ToString();
				Field1[i]->Location = System::Drawing::Point(x, y);
				Field1[i]->Click += gcnew System::EventHandler(this, &MyForm::Field1_Click);
				Field1[i]->UseVisualStyleBackColor = true;
				Controls->Add(Field1[i]);
			}
		}
		
		/*создание поля 2 игрока*/
		void CreateField_2()
		{
			/*координаты расположения кнопок*/
			int x;
			int y;

			/*создание массива кнопок - ячеек поля*/
			Field2 = gcnew array<Button^>(14);
				
			for (int i = 0; i < Field2->Length; i++)
			{
				if (i < 7)
				{
					x = 520 - 80 * i;
					y = 400;
				}
				else
				{
					x = 40 + 80 * (i - 7);
					y = 320;
				}

				/*создание кнопки и устанавление ее свойств*/
				Field2[i] = gcnew Button();
				Field2[i]->Size = Drawing::Size(75, 75);
				Field2[i]->Text = Game->GetField_2(i).ToString();
				Field2[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				Field2[i]->Name = i.ToString();
				Field2[i]->Location = System::Drawing::Point(x, y);
				Field2[i]->Click += gcnew System::EventHandler(this, &MyForm::Field2_Click);
				Field2[i]->UseVisualStyleBackColor = true;
				Controls->Add(Field2[i]);
			}
		}

		/*когда кто-то из игроков победил*/
		void NewGame()
		{
			for (int i = 0; i < 14; ++i)
			{
					 Field1[i]->Enabled = false;
					 Field2[i]->Enabled = false;
			}

			this->Turn->Enabled = false;
			this->GameStatus->Visible= false;
			this->TurnToComputer->Enabled = false;
			this->ButtonReturn->Enabled = false;
			this->SUp1->Visible = false;
			this->SUp2->Visible = false;
			this->SDown1->Visible = false;
			this->SDown2->Visible = false;
			this->SLeft1->Visible = false;
			this->SLeft2->Visible = false;
			this->SRight1->Visible = false;
			this->SRight2->Visible = false;

			this->WhoWin->Visible = true;
			this->WhoWin->Enabled = true;
			this->WhoWin->Text = (Game->WhoWin().ToString() + " игрок победил");
		}

		void PrintDesktop()
		{
			CreateField_1();		//создание поля 1 игрока
			CreateField_2();		//создание поля 2 игрока

			this->ButtonReturn->Visible = true;
			this->ButtonReturn->Enabled = false;

			this->GameStatus->Enabled = true;
			this->GameStatus->Visible = true;

			this->Turn->Enabled = true;
			this->Turn->Visible = true;
			this->Turn->Text = "Ход: 1";

			this->Exit->Visible = false;
			this->ExitToMenu->Visible = true;

			this->SUp1->Visible = true;
			this->SUp2->Visible = true;
			this->SDown1->Visible = true;
			this->SDown2->Visible = true;
			this->SLeft1->Visible = true;
			this->SLeft2->Visible = true;
			this->SRight1->Visible = true;
			this->SRight2->Visible = true;
		}


};
}