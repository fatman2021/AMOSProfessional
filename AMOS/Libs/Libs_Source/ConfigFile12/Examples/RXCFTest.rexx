/* RexxConfigFile.library test script */

CFLibName = 'rexxconfigfile.library'

Signal ON Syntax
Signal ON Break_C

If ~Show(L,CFLibName) Then Do
  If ~AddLib(CFLibName,0,-30) Then Do
    Say "Couldn't open" CFLibName "!"
  End
End

Header = cf_Open("test.cfg",OMODE_NEWFILE,OFLG_READ_TOO)
If Header ~= 0 Then Do

  GrpNode = cf_NewGroup(Header,"ExampleGroup")
  ArgNode = cf_NewArgument(GrpNode,"ExampleArgument")
  ItemNode = cf_NewItem(ArgNode,"Hallo")
  cf_NewItem(ArgNode,1,ITYP_BOOL)
  CloneArgNode = cf_CloneArgument(ArgNode)
  cf_AddArgument(GrpNode,CloneArgNode)
  cf_NewArgItem(GrpNode,"Hallo",45488,ITYP_NUMBER,STYP_NUM_DEC)
  CloneGrpNode = cf_CloneGroup(GrpNode)
  cf_AddGroup(Header,CloneGrpNode)

  cf_Write(Header)
  cf_Close(Header)
End
Else Do
  Select
    When RC = OERR_OPEN_FILE    Then EStr = "Couldn't open file!"
    When RC = OERR_READ_FILE    Then EStr = "Couldn't read file!"
    When RC = OERR_NO_FORMAT    Then EStr = "File isn't in CF format!"
    When RC = OERR_NO_SIZE      Then EStr = "File hasn't a size!"
    When RC = OERR_HEADER_MEM   Then EStr = "No memory for Header!"

    When RC = RERR_FORMAT       Then EStr = "Error in the format!"
    When RC = RERR_UNKOWN_ITYPE Then EStr = "Unkown item type!"
    Otherwise EStr = "Unkown failure!"
  End
  Say "cf_Open:" EStr
End

Exit

Syntax:
  Say '+++ Error' RC 'in line' SIGL||':' Errortext(RC)
  Say ':' Sourceline(SIGL)

Break_C:
  If Header ~= 0 Then cf_Close(Header)
  Exit

  