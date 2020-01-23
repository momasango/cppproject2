object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 326
  ClientWidth = 313
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 24
    Top = 96
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 24
    Top = 160
    Width = 31
    Height = 13
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 168
    Top = 32
    Width = 31
    Height = 13
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 168
    Top = 96
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object Label6: TLabel
    Left = 168
    Top = 160
    Width = 31
    Height = 13
    Caption = 'Label6'
  end
  object Edit1: TEdit
    Left = 24
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 24
    Top = 115
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 24
    Top = 179
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 168
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit4'
  end
  object Edit6: TEdit
    Left = 168
    Top = 179
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit6'
  end
  object btnAddStudent: TButton
    Left = 214
    Top = 275
    Width = 75
    Height = 25
    Caption = 'Add Student'
    TabOrder = 5
    OnClick = btnAddStudentClick
  end
  object cmbYear: TComboBox
    Left = 168
    Top = 115
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'cmbYear'
  end
  object btnClear: TButton
    Left = 124
    Top = 275
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 7
    OnClick = btnClearClick
  end
  object conSchool1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Regina.Re' +
      'gina-PC\Desktop\Projects for the CV\School Management System\sch' +
      'oolxman.accdb;Persist Security Info=False'
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 24
    Top = 264
  end
  object DataSetStudent1: TADODataSet
    Parameters = <>
    Left = 80
    Top = 240
  end
  object dsStudent1: TDataSource
    Left = 120
    Top = 240
  end
  object ADOCommand1: TADOCommand
    Parameters = <>
    Left = 160
    Top = 240
  end
end
