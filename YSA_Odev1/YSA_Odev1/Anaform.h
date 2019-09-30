#pragma once

namespace YSAOdev1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Anaform
	/// </summary>
	public ref class Anaform : public System::Windows::Forms::Form
	{
	public:
		Anaform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Anaform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btngrup4;
	private: System::Windows::Forms::Button^  btngrup3;
	private: System::Windows::Forms::Button^  btngrup2;
	private: System::Windows::Forms::Button^  btngrup1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DomainUpDown^  domainUpDown1;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Label^  lblKonum;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblKonum = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->btngrup4 = (gcnew System::Windows::Forms::Button());
			this->btngrup3 = (gcnew System::Windows::Forms::Button());
			this->btngrup2 = (gcnew System::Windows::Forms::Button());
			this->btngrup1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->lblKonum);
			this->panel1->Controls->Add(this->btnExit);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->domainUpDown1);
			this->panel1->Controls->Add(this->btngrup4);
			this->panel1->Controls->Add(this->btngrup3);
			this->panel1->Controls->Add(this->btngrup2);
			this->panel1->Controls->Add(this->btngrup1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(650, 40);
			this->panel1->TabIndex = 0;
			// 
			// lblKonum
			// 
			this->lblKonum->AutoSize = true;
			this->lblKonum->Location = System::Drawing::Point(363, 10);
			this->lblKonum->Name = L"lblKonum";
			this->lblKonum->Size = System::Drawing::Size(0, 13);
			this->lblKonum->TabIndex = 8;
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(619, 7);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(25, 23);
			this->btnExit->TabIndex = 7;
			this->btnExit->Text = L"X";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Anaform::btnExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(492, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Artýnýn Boyutu:";
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->BackColor = System::Drawing::SystemColors::Control;
			this->domainUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->domainUpDown1->InterceptArrowKeys = false;
			this->domainUpDown1->Items->Add(L"2");
			this->domainUpDown1->Items->Add(L"3");
			this->domainUpDown1->Items->Add(L"4");
			this->domainUpDown1->Items->Add(L"5");
			this->domainUpDown1->Items->Add(L"6");
			this->domainUpDown1->Items->Add(L"7");
			this->domainUpDown1->Items->Add(L"8");
			this->domainUpDown1->Items->Add(L"9");
			this->domainUpDown1->Items->Add(L"10");
			this->domainUpDown1->Location = System::Drawing::Point(573, 10);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->ReadOnly = true;
			this->domainUpDown1->Size = System::Drawing::Size(32, 20);
			this->domainUpDown1->TabIndex = 5;
			this->domainUpDown1->Text = L"2";
			this->domainUpDown1->SelectedItemChanged += gcnew System::EventHandler(this, &Anaform::domainUpDown1_SelectedItemChanged);
			// 
			// btngrup4
			// 
			this->btngrup4->Location = System::Drawing::Point(111, 3);
			this->btngrup4->Name = L"btngrup4";
			this->btngrup4->Size = System::Drawing::Size(30, 30);
			this->btngrup4->TabIndex = 4;
			this->btngrup4->Text = L"4";
			this->btngrup4->UseVisualStyleBackColor = true;
			this->btngrup4->Click += gcnew System::EventHandler(this, &Anaform::btngrup4_Click);
			// 
			// btngrup3
			// 
			this->btngrup3->Location = System::Drawing::Point(75, 3);
			this->btngrup3->Name = L"btngrup3";
			this->btngrup3->Size = System::Drawing::Size(30, 30);
			this->btngrup3->TabIndex = 3;
			this->btngrup3->Text = L"3";
			this->btngrup3->UseVisualStyleBackColor = true;
			this->btngrup3->Click += gcnew System::EventHandler(this, &Anaform::btngrup3_Click);
			// 
			// btngrup2
			// 
			this->btngrup2->Location = System::Drawing::Point(39, 3);
			this->btngrup2->Name = L"btngrup2";
			this->btngrup2->Size = System::Drawing::Size(30, 30);
			this->btngrup2->TabIndex = 2;
			this->btngrup2->Text = L"2";
			this->btngrup2->UseVisualStyleBackColor = true;
			this->btngrup2->Click += gcnew System::EventHandler(this, &Anaform::btngrup2_Click);
			// 
			// btngrup1
			// 
			this->btngrup1->Location = System::Drawing::Point(3, 3);
			this->btngrup1->Name = L"btngrup1";
			this->btngrup1->Size = System::Drawing::Size(30, 30);
			this->btngrup1->TabIndex = 0;
			this->btngrup1->Text = L"1";
			this->btngrup1->UseVisualStyleBackColor = true;
			this->btngrup1->Click += gcnew System::EventHandler(this, &Anaform::btngrup1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(650, 560);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Anaform::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Anaform::pictureBox1_MouseMove);
			// 
			// Anaform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 600);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Anaform";
			this->Text = L"Anaform";
			this->Load += gcnew System::EventHandler(this, &Anaform::Anaform_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: void ArtiCiz(int NoktaX, int NoktaY, Color renk);
			 Void CizgiCiz(int a, int b);
			 int XiBul(int y, int a, int b);
			 Point NormalKordinattanÝstenilenKordinataCevirme(int x, int y);
			 Point IstenilenKordinattanNormaleCevirme(int x, int y);
			 Bitmap^ asd;
			 Graphics^ grfx;
			 int islem_number = 1;
			 int arti_boyutu = 5;


	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: System::Void btngrup1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		islem_number = 1;
	}
	private: System::Void btngrup2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		islem_number = 2;

	}
	private: System::Void btngrup3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		islem_number = 3;
	}
	private: System::Void btngrup4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		islem_number = 4;
	}
	private: System::Void domainUpDown1_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e)
	{
		arti_boyutu = domainUpDown1->SelectedIndex + 2;
	}












	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	

	private: System::Void Anaform_Load(System::Object^  sender, System::EventArgs^  e);


			 
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
};
}