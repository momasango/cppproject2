object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 504
  ClientWidth = 757
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object tlBar1: TToolBar
    Left = 0
    Top = 0
    Width = 757
    Height = 18
    Caption = 'tlBar1'
    List = True
    TabOrder = 0
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 24
    Width = 739
    Height = 448
    ActivePage = tbshtRecordMarks
    TabOrder = 1
    object tbsheetManStudent: TTabSheet
      Caption = 'Manage Information'
      ImageIndex = 1
      object btnDelete: TButton
        Left = 438
        Top = 371
        Width = 75
        Height = 25
        Caption = 'Delete'
        TabOrder = 0
        OnClick = btnDeleteClick
      end
      object btnUpdate: TButton
        Left = 519
        Top = 371
        Width = 75
        Height = 25
        Caption = 'Update'
        TabOrder = 1
        OnClick = btnUpdateClick
      end
      object edtName: TEdit
        Left = 192
        Top = 288
        Width = 121
        Height = 21
        TabOrder = 2
        Text = 'edtName'
      end
      object edtSurname: TEdit
        Left = 352
        Top = 288
        Width = 121
        Height = 21
        TabOrder = 3
        Text = 'edtSurname'
      end
      object edtPhone: TEdit
        Left = 504
        Top = 288
        Width = 121
        Height = 21
        TabOrder = 4
        Text = 'edtPhone'
      end
      object edtGroup: TEdit
        Left = 344
        Top = 328
        Width = 121
        Height = 21
        TabOrder = 5
        Text = 'edtGroup'
      end
      object cmbEdtYear: TComboBox
        Left = 192
        Top = 328
        Width = 121
        Height = 21
        TabOrder = 6
        Text = 'cmbEdtYear'
      end
      object studentIDcheck: TEdit
        Left = 32
        Top = 288
        Width = 121
        Height = 21
        TabOrder = 7
      end
      object DateTimePicker1: TDateTimePicker
        Left = 32
        Top = 328
        Width = 121
        Height = 21
        Date = 43832.000000000000000000
        Time = 0.907789374999993000
        TabOrder = 8
      end
      object btnFirst: TButton
        Left = 36
        Top = 371
        Width = 29
        Height = 25
        Caption = '<<'
        TabOrder = 9
        OnClick = btnFirstClick
      end
      object btnLast: TButton
        Left = 135
        Top = 371
        Width = 29
        Height = 25
        Caption = '>>'
        TabOrder = 10
        OnClick = btnLastClick
      end
      object btnNext: TButton
        Left = 103
        Top = 371
        Width = 26
        Height = 25
        Caption = '>'
        TabOrder = 11
        OnClick = btnNextClick
      end
      object btnPrevious: TButton
        Left = 71
        Top = 371
        Width = 26
        Height = 25
        Caption = '<'
        TabOrder = 12
        OnClick = btnPreviousClick
      end
      object Button1: TButton
        Left = 600
        Top = 371
        Width = 105
        Height = 25
        Caption = 'Add New Student'
        TabOrder = 13
        OnClick = Button1Click
      end
      object btnRefresh: TButton
        Left = 357
        Top = 371
        Width = 75
        Height = 25
        Caption = 'Refresh'
        TabOrder = 14
        OnClick = btnRefreshClick
      end
      object DBGrid1: TDBGrid
        Left = 55
        Top = 93
        Width = 673
        Height = 236
        TabOrder = 15
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
      end
    end
    object tbshtRecordMarks: TTabSheet
      Caption = 'Inspect Marks'
      ImageIndex = 1
      ExplicitLeft = -22
      ExplicitTop = 0
      object Label3: TLabel
        Left = 352
        Top = 208
        Width = 31
        Height = 13
        Caption = 'Label3'
      end
      object btnEditMarks: TButton
        Left = 622
        Top = 355
        Width = 75
        Height = 25
        Caption = 'Edit Marks'
        TabOrder = 0
        OnClick = btnEditMarksClick
      end
      object DBGrid2: TDBGrid
        Left = 12
        Top = 21
        Width = 389
        Height = 236
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
      end
    end
  end
  object Memo1: TMemo
    Left = 432
    Top = 69
    Width = 277
    Height = 236
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object conSchool: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Regina.Re' +
      'gina-PC\Desktop\Projects for the CV\School Management System\sch' +
      'oolxman.accdb;Persist Security Info=False'
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 336
    Top = 272
  end
  object DataSetStudent: TADODataSet
    Parameters = <>
    Left = 424
    Top = 272
  end
  object dsStudent: TDataSource
    Left = 496
    Top = 272
  end
  object ADOCommand2: TADOCommand
    Parameters = <>
    Left = 256
    Top = 272
  end
  object ADOCommand3: TADOCommand
    Parameters = <>
    Left = 176
    Top = 272
  end
  object dsGrades: TDataSource
    Left = 496
    Top = 328
  end
  object DataSetGrades: TADODataSet
    Parameters = <>
    Left = 416
    Top = 296
  end
end
