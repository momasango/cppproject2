//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unitMain.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	/* This part of the form merely adds the arbitrary information, such as the
	   labels for the application objects, and connects the database to the ap-
	   plicable objects for display and modification. I also disabled the Edit
	   button containing the student ID number because there is a method that
	   calculates it below and it reduces unnecessary teacher-error. */

	Form1->Caption = "School X Information Management System";

	cmbEdtYear->Items->Add("8");
	cmbEdtYear->Items->Add("9");
	cmbEdtYear->Items->Add("10");
	cmbEdtYear->Items->Add("11");
	cmbEdtYear->Items->Add("12");

//	AnsiString sqlGrades = "SELECT s.studentID, s.studentForenames, s.studentSurname,";
//	sqlGrades += " g.subject1, g.subject1YearMark as 'Subject 1 Year Mark', ";
//	sqlGrades += "g.subject1ExamMark as 'Subject 1 Exam Mark',";
//	sqlGrades += " g.subject2, g.subject2YearMark as 'Subject 2 Year Mark', ";
//	sqlGrades += "g.subject2ExamMark as 'Subject 2 Exam Mark',";
//	sqlGrades += " g.subject3, g.subject1YearMark as 'Subject 3 Year Mark', ";
//	sqlGrades += "g.subject3ExamMark as 'Subject 3 Exam Mark',";
//	sqlGrades += " g.subject4, g.subject1YearMark as 'Subject 4 Year Mark', ";
//	sqlGrades += "g.subject4ExamMark as 'Subject 4 Exam Mark',";
//	sqlGrades += " g.subject5, g.subject1YearMark as 'Subject 5 Year Mark', ";
//	sqlGrades += "g.subject5ExamMark as 'Subject 5 Exam Mark',";
//	sqlGrades += " g.subject6, g.subject1YearMark as 'Subject 6 Year Mark', ";
//	sqlGrades += "g.subject6ExamMark as 'Subject 6 Exam Mark',";
//	sqlGrades += " g.subject7, g.subject1YearMark as 'Subject 7 Year Mark', ";
//	sqlGrades += "g.subject7ExamMark as 'Subject 7 Exam Mark'";
//	sqlGrades += "FROM student s, grade g WHERE s.studentID = g.studentID";

	DataSetGrades->Connection = conSchool;
	DataSetGrades->CommandText = "SELECT * FROM grade";
	dsGrades->DataSet = DataSetGrades;
	DataSetGrades->Open();
	DBGrid2->DataSource = dsGrades;

	DataSetStudent->Connection = conSchool;
	DataSetStudent->CommandText = "SELECT * FROM student";
	dsStudent->DataSet = DataSetStudent;
	DataSetStudent->Open();
	DBGrid1->DataSource = dsStudent;
	studentIDcheck->Enabled = false;

	edtName->Clear();
	edtSurname->Clear();
	edtPhone->Clear();
	edtGroup->Clear();
	cmbEdtYear->ItemIndex = 0;

	studentIDcheck->Text = DataSetStudent->FieldByName("studentID")->Value;
	edtName->Text = DataSetStudent->FieldByName("studentForenames")->Value;
	edtSurname->Text = DataSetStudent->FieldByName("studentLastName")->Value;
	edtPhone->Text = DataSetStudent->FieldByName("studentPhone")->Value;
	cmbEdtYear->Text = DataSetStudent->FieldByName("studentYear")->Value;
	edtGroup->Text = DataSetStudent->FieldByName("studentClass")->Value;

	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("-------------------");
	Memo1->Lines->Add("STUDENT IN");
	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("STUDENT INFORMATION");
	Memo1->Lines->Add("STUDENT INFORMATION");

}

//---------------------------------------------------------------------------
void TForm1::showCurrentRecord(TObject *Sender)
{
	/* This form class method, in conjunction with the below-mentioned
	   buttons, takes the current record of the student database and
	   places it in the edit boxes. studentIDcheck, an object on the
	   second tab, is disabled here too. The last five lines of code
	   ensure that if there isn't a record for a student's date of
	   birth, that the space is given a default value. */

	studentIDcheck->Enabled = false;

	studentIDcheck->Text = DataSetStudent->FieldByName("studentID")->Value;
	edtName->Text = DataSetStudent->FieldByName("studentForenames")->Value;
	edtSurname->Text = DataSetStudent->FieldByName("studentLastName")->Value;
	edtPhone->Text = DataSetStudent->FieldByName("studentPhone")->Value;
	cmbEdtYear->Text = DataSetStudent->FieldByName("studentYear")->Value;
	edtGroup->Text = DataSetStudent->FieldByName("studentClass")->Value;


	if (DataSetStudent->FieldByName("studentDOB")->Value.IsNull())
	{
		DateTimePicker1->Date = Date() - 30*365.25;
	}
	else
		DateTimePicker1->Date = DataSetStudent->FieldByName("studentDOB")->Value;
}

/*The next four methods are merely buttons that move through the database and
  display whatever record they move to based on the relative position of the
  cursor. */

void __fastcall TForm1::btnFirstClick(TObject *Sender)
{
	DataSetStudent->First();
	showCurrentRecord(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnPreviousClick(TObject *Sender)
{
	DataSetStudent->Prior();
	showCurrentRecord(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnNextClick(TObject *Sender)
{
	DataSetStudent->Next();
	showCurrentRecord(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnLastClick(TObject *Sender)
{
	DataSetStudent->Last();
	showCurrentRecord(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnUpdateClick(TObject *Sender)
{
	/* This button also edits the student database, but in this instance, lets
	   the user modify a single record's information. Query statements are
	   followed by editing using parameters, refreshing the database and then
	   informing the user. */

	ADOCommand2->Connection = conSchool;

	AnsiString sql = "UPDATE student SET ";
	sql += " studentForenames = :sname,";
	sql += " studentLastName = :slastname, ";
	sql += " studentPhone = :sphone, ";
	sql += " studentDOB = :sdob, ";
	sql += " studentYear = :syear, ";
	sql += " studentClass = :sgroup ";
	sql += " WHERE studentID = :id ";

	ADOCommand2->CommandText = sql;

	ADOCommand2->Parameters->ParamByName("sname")->Value =
		edtName->Text;
	ADOCommand2->Parameters->ParamByName("slastname")->Value =
		edtSurname->Text;
	ADOCommand2->Parameters->ParamByName("sphone")->Value =
		edtPhone->Text;
	ADOCommand2->Parameters->ParamByName("sdob")->Value =
		DateTimePicker1->Date;
	ADOCommand2->Parameters->ParamByName("syear")->Value =
		cmbEdtYear->Text;
	ADOCommand2->Parameters->ParamByName("sgroup")->Value =
		edtGroup->Text;
	ADOCommand2->Parameters->ParamByName("id")->Value =
		studentIDcheck->Text;

	ADOCommand2->Execute();        //1
	ShowMessage ("You've changed " + edtName->Text + " " + edtSurname->Text + "'s information.");   //0.5

	DataSetStudent->Close();
	DataSetStudent->Open();
}//---------------------------------------------------------------------------

void __fastcall TForm1::btnDeleteClick(TObject *Sender)
{
	/* This button will delete the record the cursor is situated on. */

	ADOCommand3->Connection = conSchool;

	AnsiString sql = "DELETE FROM student";
	sql += " WHERE studentID = :id";
	ADOCommand3->CommandText = sql;

	AnsiString selStudent = DataSetStudent->FieldByName("studentID")->Value;

	ADOCommand3->Parameters->ParamByName("id")->Value = studentIDcheck->Text;

	String warningMessage = "Are you sure you want to delete this student's information?";

	if (MessageDlg(warningMessage, mtConfirmation, mbYesNo, 0) == mrYes)
	{
		ADOCommand3->Execute();
		ShowMessage("This student record has been deleted.");
		DataSetStudent->Close();
		DataSetStudent->Open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//	Form2 = new TForm(this);
//	Form2->ShowModal();
//    delete Form2;

	Form2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnRefreshClick(TObject *Sender)
{
	DataSetStudent->Close();
	DataSetStudent->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnEditMarksClick(TObject *Sender)
{
   // Form4->Visible = true;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

