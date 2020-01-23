object DMod: TDMod
  OldCreateOrder = False
  Height = 370
  Width = 350
  object conSchool: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Regina.Re' +
      'gina-PC\Desktop\Projects for the CV\School Management System\sch' +
      'oolxman.accdb;Mode=ReadWrite;Persist Security Info=False'
    Mode = cmReadWrite
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 32
    Top = 88
  end
  object DataSetStudent: TADODataSet
    Connection = conSchool
    CommandText = 'select * from student'
    Parameters = <>
    Left = 160
    Top = 168
  end
  object dsStudent: TDataSource
    DataSet = DataSetStudent
    Left = 64
    Top = 248
  end
  object ADOCommand1: TADOCommand
    Parameters = <>
    Left = 168
    Top = 296
  end
  object ADOCommand2: TADOCommand
    Parameters = <>
    Left = 248
    Top = 208
  end
  object ADOCommand3: TADOCommand
    Connection = conSchool
    Parameters = <>
    Left = 136
    Top = 112
  end
  object dsStudent1: TDataSource
    Left = 120
    Top = 248
  end
end
