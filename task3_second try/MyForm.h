#pragma once
#include "MyMatrix.h"
#include "Tore.h"
#include "RotateX.h"
#include "RotateY.h"
#include "Cube.h"
#include "Projector.h"
#include "ProectMatrix.h"
#include "RotateZ.h"
#include "ZBuffer.h"

namespace task3_secondtry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bm;
			currentObject = gcnew Tore();
		//	currentObject = gcnew Cube(20);
			currentObject->MoveToGlobal();

			zBuffer = gcnew ZBuffer(bm);
			zBuffer->Draw(currentObject);
		/*	zBuffer->setPicture(pictureBox1);
			zBuffer->Draw(currentObject);*/
//			currentObject->Draw(zBuffer, bm);
//			currentObject->Draw(currentObject->sides, bm, gcnew ProectMatrix());
/*			currentObject = gcnew currentObject(100);
			currentObject->MoveToGlobal();
			currentObject->GetObjectMatrix();

			currentObject->Draw(currentObject->sides, bm, gcnew ProectMatrix());
*/
			pictureBox1->Refresh();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  rotateXAngle;
	private: System::Windows::Forms::NumericUpDown^  rotateYAngle;
	private: System::Windows::Forms::NumericUpDown^  rotateZAngle;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: My3DObject^ currentObject;
	private: ZBuffer^ zBuffer;
	private: Bitmap^ bm;
	private: System::Windows::Forms::NumericUpDown^  xShift;
	private: System::Windows::Forms::NumericUpDown^  yShift;
	private: System::Windows::Forms::NumericUpDown^  zShift;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->rotateXAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->rotateYAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->rotateZAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->xShift = (gcnew System::Windows::Forms::NumericUpDown());
			this->yShift = (gcnew System::Windows::Forms::NumericUpDown());
			this->zShift = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateXAngle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateYAngle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateZAngle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xShift))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yShift))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zShift))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(206, 9);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(968, 614);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// rotateXAngle
			// 
			this->rotateXAngle->Location = System::Drawing::Point(112, 14);
			this->rotateXAngle->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rotateXAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->rotateXAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->rotateXAngle->Name = L"rotateXAngle";
			this->rotateXAngle->Size = System::Drawing::Size(90, 20);
			this->rotateXAngle->TabIndex = 1;
			this->rotateXAngle->ValueChanged += gcnew System::EventHandler(this, &MyForm::rotateXAngle_ValueChanged);
			// 
			// rotateYAngle
			// 
			this->rotateYAngle->Location = System::Drawing::Point(112, 37);
			this->rotateYAngle->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rotateYAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->rotateYAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->rotateYAngle->Name = L"rotateYAngle";
			this->rotateYAngle->Size = System::Drawing::Size(90, 20);
			this->rotateYAngle->TabIndex = 2;
			this->rotateYAngle->ValueChanged += gcnew System::EventHandler(this, &MyForm::rotateYAngle_ValueChanged);
			// 
			// rotateZAngle
			// 
			this->rotateZAngle->Location = System::Drawing::Point(112, 59);
			this->rotateZAngle->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rotateZAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->rotateZAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->rotateZAngle->Name = L"rotateZAngle";
			this->rotateZAngle->Size = System::Drawing::Size(90, 20);
			this->rotateZAngle->TabIndex = 3;
			this->rotateZAngle->ValueChanged += gcnew System::EventHandler(this, &MyForm::rotateZAngle_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 15);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"угол поворта X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 38);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"угол поворта Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 61);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"угол поворта Z";
			// 
			// xShift
			// 
			this->xShift->Location = System::Drawing::Point(112, 141);
			this->xShift->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->xShift->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->xShift->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->xShift->Name = L"xShift";
			this->xShift->Size = System::Drawing::Size(90, 20);
			this->xShift->TabIndex = 7;
			this->xShift->ValueChanged += gcnew System::EventHandler(this, &MyForm::xShift_ValueChanged);
			// 
			// yShift
			// 
			this->yShift->Location = System::Drawing::Point(112, 164);
			this->yShift->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->yShift->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->yShift->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->yShift->Name = L"yShift";
			this->yShift->Size = System::Drawing::Size(90, 20);
			this->yShift->TabIndex = 8;
			this->yShift->ValueChanged += gcnew System::EventHandler(this, &MyForm::yShift_ValueChanged);
			// 
			// zShift
			// 
			this->zShift->Location = System::Drawing::Point(112, 187);
			this->zShift->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->zShift->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->zShift->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, System::Int32::MinValue });
			this->zShift->Name = L"zShift";
			this->zShift->Size = System::Drawing::Size(90, 20);
			this->zShift->TabIndex = 9;
			this->zShift->ValueChanged += gcnew System::EventHandler(this, &MyForm::zShift_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 188);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"сдвиг по Z";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 166);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"сдвиг по Y";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 143);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"сдвиг по X";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 228);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 29);
			this->button1->TabIndex = 14;
			this->button1->Text = L"карусель";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 309);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 29);
			this->button2->TabIndex = 15;
			this->button2->Text = L"О программе";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 634);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->zShift);
			this->Controls->Add(this->yShift);
			this->Controls->Add(this->xShift);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->rotateZAngle);
			this->Controls->Add(this->rotateYAngle);
			this->Controls->Add(this->rotateXAngle);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateXAngle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateYAngle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rotateZAngle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xShift))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yShift))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zShift))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: void redraw() {

		bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		pictureBox1->Image = bm;

		int angleX = (int)rotateXAngle->Value;
		int angleY = (int)rotateYAngle->Value;
		int angleZ = (int)rotateZAngle->Value;

		int shiftX = (int)xShift->Value;
		int shiftY = (int)yShift->Value;
		int shiftZ = (int)zShift->Value;

		
		RotateX^ rotateX = gcnew RotateX(angleX);

		RotateY^ rotateY = gcnew RotateY(angleY);

		RotateZ^ rotateZ = gcnew RotateZ(angleZ);


		currentObject->MoveToGlobal(rotateX, rotateY, rotateZ, shiftX, shiftY, shiftZ);
	//	currentObject->GetObjectMatrix();
		zBuffer->setBitmap(bm);
		zBuffer->Draw(currentObject);
		//currentObject->Draw(currentObject->sides, bm, gcnew ProectMatrix());

		pictureBox1->Refresh();

	}

	private: System::Void rotateXAngle_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}
	private: System::Void rotateYAngle_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}
	private: System::Void rotateZAngle_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}
	private: System::Void xShift_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}
	private: System::Void yShift_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}
	private: System::Void zShift_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		redraw();
	}

	private:
		bool isVolchok = false;

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		isVolchok = true;

		rotateXAngle->Enabled = !isVolchok;
		rotateYAngle->Enabled = !isVolchok;;
		rotateZAngle->Enabled = !isVolchok;;

		xShift->Enabled = !isVolchok;
		yShift->Enabled = !isVolchok;
		zShift->Enabled = !isVolchok;
		this->Refresh();
		xShift->Value = 50;
		xShift->Refresh();
		int j = 0;

		while (j++ < 360) {
			rotateYAngle->UpButton();
				
			rotateYAngle->Refresh();
			xShift->Refresh();

			redraw();

		//	Thread::Sleep(10);
		}
		isVolchok = false;

		rotateXAngle->Enabled = !isVolchok;
		rotateYAngle->Enabled = !isVolchok;;
		rotateZAngle->Enabled = !isVolchok;;

		xShift->Enabled = !isVolchok;
		yShift->Enabled = !isVolchok;
		zShift->Enabled = !isVolchok;
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Выполнил Жадобин Юрий, БПИ133(2). \n Управление:\n\t " +
		"Для поворотов и сдвигов: менять значения в боксах. \n\t" +
		"Для запуска карусели необходимо нажать на кнопку \"Карусель\".\n\t" +
		"Выполнил только базовые преобразования и карусель");
}
};
}
