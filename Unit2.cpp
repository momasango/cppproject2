//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Form2->Caption = "Add Student";

	Label1->Caption = "Student ID";
	Label2->Caption = "Student Forenames";
	Label3->Caption = "Student Surname";
	Label4->Caption = "Student Phone";
	Label5->Caption = "Student Year";
	Label6->Caption = "Student Class";

	cmbYear->Items->Add("8");
	cmbYear->Items->Add("9");
	cmbYear->Items->Add("10");
	cmbYear->Items->Add("11");
	cmbYear->Items->Add("12");

	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Edit6->Clear();

	DataSetStudent1->Connection = conSchool1;
	DataSetStudent1->CommandText = "SELECT * FROM student";
	dsStudent1->DataSet = DataSetStudent1;
	DataSetStudent1->Open();
	Edit1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnAddStudentClick(TObject *Sender)
{
	 /* This button adds a record of information inputted by the user to the
	   database. In the first few lines, we calculate the student ID numbers
	   by chronological order, and then adding one to the highest to make the
	   next student ID number, and then inputting it into the disabled Edit box.
	   Next, the query statements used to add the student records, and the code
	   to refresh the database, execute the query statements and update the
	   user on their changes are put in a try clause to catch out potential
	   errors. */

	int highestStudentID = 0;
	// Make student ID value based on last highest student ID number
	for (DataSetStudent1->First(); !DataSetStudent1->Eof; DataSetStudent1->Next())
	{
		if (DataSetStudent1->Fields->FieldByName("studentID")->AsInteger >= highestStudentID)
		{
			   highestStudentID = DataSetStudent1->Fields->FieldByName("studentID")->AsInteger + 1;
		}
	}

	Edit1->Text = IntToStr(highestStudentID);

	try
	{

		if (MessageDlg("Are you sure you want to add this information?", mtConfirmation, mbYesNo, 0) == mrYes)
		{
			ADOCommand1->Connection = conSchool1;
			AnsiString insSql = "INSERT INTO student (studentID, studentForenames,";
			insSql += " studentLastName, studentPhone, studentYear, studentClass)";
			insSql += " VALUES (:id,:names, :surname, :phone, :year, :class)";
			ADOCommand1->CommandText = insSql;
			ADOCommand1->Parameters->ParamByName("id")->Value = Edit1->Text;
			ADOCommand1->Parameters->ParamByName("names")->Value = Edit2->Text;
			ADOCommand1->Parameters->ParamByName("surname")->Value = Edit3->Text;
			ADOCommand1->Parameters->ParamByName("phone")->Value = Edit4->Text;
			ADOCommand1->Parameters->ParamByName("year")->Value = cmbYear->Text;
			ADOCommand1->Parameters->ParamByName("class")->Value = Edit6->Text;

			ADOCommand1->Execute();
			DataSetStudent1->Refresh();
			ShowMessage (Edit2->Text + " " + Edit3->Text + "'s details have been captured.");
			DataSetStudent1->Close();  // Refresh database grid
			DataSetStudent1->Open();
		}

	}
	catch (EConvertError &ex)
	{
		ShowMessage ("Enter an integer for the student ID.");
	}
	catch (Exception &ex)
	{
		ShowMessage ("We couldn't save your changes. Here's why.\n" + ex.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnClearClick(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Edit6->Clear();
}
//---------------------------------------------------------------------------

