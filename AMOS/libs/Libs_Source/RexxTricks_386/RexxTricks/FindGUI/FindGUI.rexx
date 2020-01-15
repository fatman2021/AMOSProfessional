/*
   $VER: FindGUI.rexx V1.0 (3.4.96) © by Nils Görs

  This is a graphical User Interface for "Find" © by Ralph Seichter.
*/

/* where can i find the main program ;-) */
Find.exe    = "Find"

/* path for the directory requester */
Directory   = "Dh0:"

/* path for the (file) command requester */
CommandPath = "C:"

/* path for the savelist requester */
SaveListDir = "SYS:"

/* WhatIs() Filetyp and Commandlist */
WhatisExe   = "whatis.findGUI"

/************************************************
 * Please don't change anything under this line *
 ************************************************/
OPTIONS RESULTS

PARSE ARG PubScreen SearchArea.1 .

IF PubScreen == "?" THEN DO
 OPTIONS PROMPT "PUBSCREEN/K,SEARCHAREA/K: "
 PARSE PULL PubScreen SearchArea.1 .
END


/*
** Beschreibung der Applikation
*/
appname     = 'FindGUI'
applongname = 'FindGUI - ©1996 by Nils Görs'
appinfo     = "Graphical-User-Interface for 'Find' from Ralph Seichter <zodiac@darkness.gun.de>"
appversion  = '1.0'
apprelease  = '1'
appdate     = '3.4.96'

/*
** Alles öffnen und Variablen initialisieren
*/
CALL _InitAll

UnSort.0    = 2
UnSort.1    = localestring(MSG_GAD_CYCLE_UnSort1)
UnSort.2    = localestring(MSG_GAD_CYCLE_UnSort2)


_maintags:
windowtags = WindowID(1),
             PubScreenName(PubScreen),
             WindowBackfillFB,
             WindowTitle(appname appversion),
             QuickHelpOn(HelpBool),
              BeginMenu(localestring(MSG_MAIN_MENU_PROJECT)),
               BeginSub(localestring(MSG_MAIN_MENUITEM_SAVEFILELIST)),
                SubItemD(localestring(MSG_SUB_MENUITEM_FULLPATH),106),
                SubItemD(localestring(MSG_SUB_MENUITEM_FILENAME),107) ItemBarlabel,
               MenuItem(localestring(MSG_MAIN_MENUITEM_ABOUT),100) ItemBarlabel,
               MenuItemC(localestring(MSG_MAIN_MENUITEM_HELP),103),
               MenuItem(localestring(MSG_MAIN_MENUITEM_CHANGE),102),
               MenuItem(localestring(MSG_MAIN_MENUITEM_ICONIFY),104) ItemBarlabel,
               MenuItem(localestring(MSG_MAIN_MENUITEM_QUIT),101),
              BeginMenu(localestring(MSG_MAIN_MENU_DATABASE)),
               MenuItem(localestring(MSG_MAIN_MENUITEM_SELECTSEARCHAREA),2),
               MenuItem(localestring(MSG_MAIN_MENUITEM_SELECTCOMMAND),31),
               MenuItem(localestring(MSG_MAIN_MENUITEM_SELECTLFORMAT),8) ItemBarlabel,
               MenuItem(localestring(MSG_MAIN_MENUITEM_DATABASE),105),
   'HorizGroupA',
      'Space',
      'VertGroupA',
         'Space',
         'HorizGroupA',
            'Space',
            'VertGroupA',
               'Space',
,
               'LineArray',
                   'BeginLine',
                      Text3(localestring(MSG_MAIN_TEXT_SEARCHAREA)) 'TRAT_ID 1',
                      StringGadget(SearchArea.1,1),
                      GetDrawerButton(2),
                      QuickHelp(localestring(MSG_MAIN_HELP_SEARCHAREA)),
                   'EndLine',
                  'Space',
                   'BeginLine',
                      Text3(localestring(MSG_MAIN_TEXT_SEARCHFOR)) 'TRAT_ID 3',
                      StringGadget('',3),
                   'EndLine',
                  'Space',
                   'BeginLine',
                     Text3(localestring(MSG_MAIN_TEXT_SEARCHDEPTH)) 'TRAT_ID 4',
                     SliderGadget(0,256,0,4),
                     'Space',
                     Text3(localestring(MSG_OFF)) 'TRAT_MinWidth 3 TRAT_ID 44',
                   'EndLine',
                  'Space',
               'EndArray',
             'HorizGroupS',
                    'BeginLine',
                     Text3(localestring(MSG_MAIN_TEXT_OUTPUT)) 'TRAT_ID 55',
                     CycleGadget(unsort,0,55),
                     'Space',
                     Button(localestring(MSG_MAIN_TEXT_EXTENDET),12) 'TRAT_Disabled 1',
                     QuickHelp(localestring(MSG_MAIN_HELP_EXTENDET)),
                     Button(localestring(MSG_MAIN_EXECUTE),13) 'TRAT_Disabled 1',
                     QuickHelp(localestring(MSG_MAIN_EXECUTEHELP)),
                    'EndLine',
             'EndGroup',
                  'Space',
,
              'HorizGroupSAC',
                     Text3(localestring(MSG_MAIN_TEXT_FILETYP)) 'TRAT_ID 56',
                     CheckBox(56),
                     QuickHelp(localestring(MSG_MAIN_HELP_FILETYP)),
                      'SpaceB',
                     Text3(localestring(MSG_MAIN_TEXT_PATH)) 'TRAT_ID 5',
                     CheckBox(5),
                     QuickHelp(localestring(MSG_MAIN_HELP_PATH)),
                      'SpaceB',
                         Text3(localestring(MSG_MAIN_TEXT_FULL)) 'TRAT_ID 6',
                          CheckBox(6),
                          QuickHelp(localestring(MSG_MAIN_HELP_FULL)),
                      'SpaceB',
                         Text3(localestring(MSG_MAIN_TEXT_EXEC)) 'TRAT_ID 11',
                          CheckBox(11),
                          QuickHelp(localestring(MSG_MAIN_HELP_EXEC)),
              'EndGroup',
,
           'Space',
               'LineArray',
                   'BeginLine',
                     Text3(localestring(MSG_MAIN_TEXT_LFORMAT)) 'TRAT_ID 7',
                     StringGadget('',7),
                     GetEntryButton(8),
                     QuickHelp(localestring(MSG_MAIN_HELP_LFORMAT)),
                   'EndLine',
                  'Space',
                   'BeginLine',
                     Text3(localestring(MSG_MAIN_TEXT_EXECCOM)) 'TRAT_ID 9',
                     StringGadget('',9),
                      GetFileButton(31),
                      QuickHelp(localestring(MSG_MAIN_HELP_EXECCOM)),
                   'EndLine',
                  'Space',
               'EndArray',
             'VertGroupA',
                     Button(localestring(MSG_MAIN_BUT_START),10),
                     QuickHelp(localestring(MSG_MAIN_HELP_START)),
                    'Space',
                  ListSS(Files,99,0,0),
                  ClippedTextBox("",98),
             'EndGroup',
,
            'EndGroup',
            'Space',
         'EndGroup',
        'Space',
,
,
      'EndGroup',
      'Space',
   'EndGroup EndProject'

/*
** Unterbrechungssignale
*/

SIGNAL ON break_c
/*SIGNAL ON failure*/
SIGNAL ON halt
SIGNAL ON ioerr
SIGNAL ON syntax

app = TR_CREATEAPP('TRCA_Name'     '"'appname'"',
                   'TRCA_LongName' '"'applongname'"',
                   'TRCA_Info'     '"'appinfo'"',
                   'TRCA_Version'  '"'appversion'"',
                   'TRCA_Release'  '"'apprelease'"',
                   'TRCA_Date'     '"'appdate'"',
                   'TAG_END')


IF app ~= '00000000'x THEN DO
   window = TR_OPENPROJECT(app,windowtags)
   WindowProject=C2D(window) /* zum Locken des Fensters bei Über */
IF fromNewPub == 1 THEN CALL _AttributeZurueck

   CALL TR_SETATTRIBUTE(window,98,'TRAT_TEXT',localestring(MSG_TEXT_WHATAREYOU))

   IF window ~= '00000000'x THEN DO
      ende = 0
     IF HelpBool = 1 THEN CALL TR_SetAttribute(window,103,TRMN_Flags,TRMF_CHECKED)

No = 1
IF SearchArea.1 ~= "" THEN No = 3

IF fromNewPub ~= 1 THEN CALL TR_SendMessage(Window,No,'TROM_ACTIVATE',0)
fromNewPub=0

       DO WHILE ende ~= 1
         CALL TR_WAIT(app,'')

         DO WHILE TR_HANDLEMSG(app,'event')

/******************
*** CLOSEGADGET ***
*******************/
            IF event.trm_class = 'TRMS_CLOSEWINDOW' THEN DO
             setuni = 0
              IF event.trm_project = dummywindow THEN DO
               CALL _uniconify
               setuni = 1
              END

             IF setuni ~= 1 THEN DO
              IF event.trm_project = window THEN DO
               nummer = TR_GETATTRIBUTE(window,10,'TRAT_Value')+1
               ende = 1
              END
             END
            END

/**************
 *** Slider ***
 **************/
            IF event.trm_class = 'TRMS_NEWVALUE' THEN DO
              IF BITAND(D2X(event.trm_qualifier),'0200'x) = '0200'x THEN CALL _ShowInformation
             SELECT
              WHEN event.trm_id = 4 THEN DO
                event.trm_data = event.trm_data-1
                IF event.trm_data = -1 THEN  CALL TR_SETATTRIBUTE(window,44,'TRAT_Text',(localestring(MSG_OFF)))
                 ELSE CALL TR_SETATTRIBUTE(window,44,'TRAT_Text',event.trm_data)
              END
              WHEN event.trm_id = 5 THEN DO
               Path=event.trm_data
               IF TR_GETATTRIBUTE(window,6,'TRAT_Value') == 1 THEN
               CALL TR_SETATTRIBUTE(window,5,'TRAT_Value',1)
              END
              WHEN event.trm_id = 6 THEN DO
               Full=event.trm_data
               CALL TR_SETATTRIBUTE(window,5,'TRAT_Value',event.trm_data)
              END
              WHEN event.trm_id =11 THEN Exec=event.trm_data
              WHEN event.trm_id =55 THEN DO
               Sort=event.trm_data
               IF Sort == 1 THEN normal= filesSorted
                            ELSE normal= files

               CALL TR_SETATTRIBUTE(window,99,'TROB_ListView',normal)
              END
              WHEN event.trm_id =56 THEN FileTyp=event.trm_data

              WHEN event.trm_id = 103 THEN DO
               HelpBool = TR_GETATTRIBUTE(window,103,'TRAT_VALUE')
               CALL TR_SETATTRIBUTE(window,0,'TRWI_QuickHelp',HelpBool)
               END

             OTHERWISE
             nop
             END
            END
/*************
*** GADGET ***
**************/
            IF event.trm_class = 'TRMS_ACTION' THEN DO
             SELECT
              WHEN event.trm_id = 2 THEN CALL _DrawerRequest
              WHEN event.trm_id = 31 THEN CALL _FileRequest
              WHEN event.trm_id = 8 THEN CALL _LFormatList
              WHEN event.trm_id = 10 THEN CALL _StartSearching
              WHEN event.trm_id = 12 THEN CALL _ShowInformation
              WHEN event.trm_id = 13 THEN DO
  CALL _GETNAMEFORINFO
  CALL _UseWhatIs
  END
              WHEN event.trm_id = 101 THEN
               DO
                 Erg=rtezrequest(localestring(MSG_REQ_REALLYQUIT),localestring(MSG_YESNO),,"rt_pubscrname="PubScreen)
                 IF Erg == 1 THEN ende = 1
              END

              WHEN event.trm_id = 100 THEN CALL About
              WHEN event.trm_id = 102 THEN CALL _NewPubScreen
              WHEN event.trm_id = 104 THEN CALL _Iconify
              WHEN event.trm_id = 105 THEN WhatIsListbool = RXTR_READFILE(Progdir2||WhatIsExe,WhatIsList)
              WHEN event.trm_id = 106 THEN CALL _SaveFileListFull
              WHEN event.trm_id = 107 THEN CALL _SaveFileListNames
             OTHERWISE
              NOP
             END
            END

/****************
 *** Tastatur ***
 ****************/
            IF event.trm_class = 'TRMS_KEYPRESSED' THEN DO
             IF event.trm_data == 13 THEN DO
               sel1 = TR_GETATTRIBUTE(window,1,'TROB_String')
               sel2 = TR_GETATTRIBUTE(window,3,'TROB_String')
              SELECT
              WHEN sel1 = "" THEN CALL TR_SendMessage(Window,1,'TROM_ACTIVATE',0)
              WHEN sel2 = "" THEN CALL TR_SendMessage(Window,3,'TROM_ACTIVATE',0)
              OTHERWISE
              NOP
              END
             END
            END

/* große Schleife! */
         END
      END
      CALL TR_CLOSEPROJECT(window)
   END
   CALL TR_DELETEAPP(app)
   IF catalog ~= 0 THEN CALL CLOSECATALOG(catalog)
END
EXIT(0)


_DrawerRequest:			/* hole Suchpfad!*/
searchArea.1 = TR_GETATTRIBUTE(window,1,'TROB_String')
searchArea.1 = WORD(searchArea.1,1)
If searchArea.1 ~= "" THEN Directory = searchArea.1

bool = ASL_RequestFile(window,searchArea,,
                       "ASLFR_PubScreenName" PubScreen,
                       "ASLFR_InitialDrawer" Directory,
                       "ASLFR_DrawersOnly" 1,
                       "ASLFR_TitleText" localestring(MSG_REQ_SELECTSEARCHAREA))
IF bool ~= 0 THEN DO
 CALL TR_SETATTRIBUTE(window,1,'TROB_String',searchArea.1)
 CALL TR_GETATTRIBUTE(window,3,'TROB_String')
IF result == "" THEN CALL TR_SendMessage(Window,3,'TROM_ACTIVATE',0)
END

ELSE DO
 CALL TR_GETATTRIBUTE(window,1,'TROB_String')
IF result == "" THEN CALL TR_SendMessage(Window,1,'TROM_ACTIVATE',0)
 ELSE DO
  CALL TR_GETATTRIBUTE(window,3,'TROB_String')
  IF result == "" THEN CALL TR_SendMessage(Window,3,'TROM_ACTIVATE',0)
 END
END
RETURN

_FileRequest:
                  bool = ASL_RequestFile(window,filename,,
                               "ASLFR_PubScreenName" PubScreen,
                               "ASLFR_InitialDrawer" CommandPath,
                               "ASLFR_TitleText" localestring(MSG_REQ_SELECTSCOMMAND))
IF bool ~= 0 THEN CALL TR_SETATTRIBUTE(window,9,'TROB_String',filename.1)
RETURN


_StartSearching:
searchArea.1 = TR_GETATTRIBUTE(window,1,'TROB_String')
  searchFile = TR_GETATTRIBUTE(window,3,'TROB_String')
     LFormat = TR_GETATTRIBUTE(window,7,'TROB_String')
 ExecCommand = TR_GETATTRIBUTE(window,9,'TROB_String')
SELECT
 WHEN searchArea.1 == "" THEN 
 DO
   CALL TR_SETATTRIBUTE(window,98,'TRAT_TEXT',localestring(MSG_MAIN_TEXT_PATHMISSING))
   CALL TR_SendMessage(Window,1,'TROM_ACTIVATE',0)
  RETURN
 END
 WHEN searchFile == "" THEN DO
   CALL TR_SETATTRIBUTE(window,98,'TRAT_TEXT',localestring(MSG_MAIN_TEXT_FILEMISSING))
   CALL TR_SendMessage(Window,3,'TROM_ACTIVATE',0)
  RETURN
 END
OTHERWISE
CALL TR_LOCKPROJECT(window)

 Depth = TR_GETATTRIBUTE(window,4,'TRAT_Value')-1
 Arg = ""
 IF Depth >=0 THEN Arg = "DEPTH="Depth
 IF Path == 1 THEN Arg = Arg||" PATH"
 IF Full == 1 THEN Arg = Arg||" FULL"

  IF Exec == 1 THEN DO
      IF LFormat     = "" THEN BREAK
      IF ExecCommand = "" THEN BREAK
     Arg=Arg||" LFORMAT="'"'ExecCommand LFormat'"' "EXEC"
  END
  ELSE IF LFormat ~= "" THEN Arg = Arg||" LFORMAT="'"'LFormat'"'

  CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',localestring(MSG_SEARCHING))
  IF Arg == "" THEN ADDRESS COMMAND Find.exe ">t:find.list" "PATTERN="searchFile "DIRECTORY="searchArea.1
  ELSE ADDRESS COMMAND Find.exe ">t:find.list" "PATTERN="searchFile "DIRECTORY="searchArea.1 Arg

IF (RC) ~= 0 THEN DO
  CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',"'"find.exe"'" localestring(MSG_MAIN_TEXT_FINDNOTFOUND))
  CALL TR_UNLOCKPROJECT(window)
  RETURN
END

  CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',localestring(MSG_MAIN_TEXT_SORTING))
  CALL RXTR_READFILE("t:find.list",Files)

ADDRESS COMMAND "delete t:find.list QUIET"

IF files.1 ~= "No matching files" THEN DO
IF LFormat == "" THEN DO
 IF FileTyp == 1 THEN DO
   DO i = 1 to files.0
    files.i = files.i||"  ("||RXTR_WHATIS(files.i)||")"
   END
 END
END

CALL RXTR_QSORT(files,FilesSorted)

IF Sort == 1 THEN normal = filesSorted
             ELSE normal = files

   CALL TR_SETATTRIBUTE(window,106,'TRAT_Disabled',0)
   CALL TR_SETATTRIBUTE(window,107,'TRAT_Disabled',0)

   CALL TR_SETATTRIBUTE(window,99,'TROB_ListView',normal)
   CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',,
          localestring(MSG_FOUNDFILES) files.0 localestring(MSG_FOUNDFILES2))
   IF LFormat == "" THEN DO
                           CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',0)
                           CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',0)
                    END
                    ELSE DO
                           CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',1)
                           CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',1)
                    END
END
 ELSE DO
  Files.0       = 0
  FilesSorted.0 = 0
  CALL TR_SETATTRIBUTE(window,99,'TROB_ListView',filesSorted)
   CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',Files.1)
  CALL TR_SETATTRIBUTE(window,99,'TROB_ListView',files)
   CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',Files.1)
   CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',1)
   CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',1)
   CALL TR_SETATTRIBUTE(window,106,'TRAT_Disabled',1)
   CALL TR_SETATTRIBUTE(window,107,'TRAT_Disabled',1)

 END

IF Exec == 1 THEN DO
  IF ExecCommand = "" THEN BREAK
  IF files.1 == "No matching files" THEN DO
   CALL TR_SETATTRIBUTE(window,98,'TRAT_TEXT',Files.1)
   CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',1)
   CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',1)
  END
  ELSE DO
   CALL TR_SETATTRIBUTE(window,98,'TRAT_Text',,
     localestring(MSG_OUTPUTCONSISTS) files.0 localestring(MSG_OUTPUTCONSISTS2))
   CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',1)
   CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',1)
  END
END
CALL TR_UNLOCKPROJECT(window)
RETURN


_SaveFileListFull:
Savetitle='"'||localestring(MSG_REQ_SELECTSAVEFILE)||'"'
CALL _SaveFileRequest					/* Filerequest öffnen */
IF bool == 0 THEN RETURN				/* Cancel */

IF EXISTS(ListFileName.1) THEN DO
  CALL rtezrequest(localestring(MSG_REQ_DESTFILEEXISTS),localestring(MSG_REQ_OVERRIDE)"|"localestring(MSG_REQ_APPEND)"|"localestring(MSG_REQ_ABORT),,
  ListfileName.1,"rt_pubscrname="PubScreen)
    SELECT
      WHEN result == 0 THEN RETURN
      WHEN result == 1 THEN CALL OPEN(FileOutPut,Listfilename.1,"Write")
      WHEN result == 2 THEN CALL OPEN(FileOutPut,Listfilename.1,"Append")
      OTHERWISE
      NOP
    END
END
ELSE CALL OPEN(FileOutPut,Listfilename.1,"Write")

IF normal == files THEN
 DO
  DO i = 1 to files.0
   CALL WRITELN(fileoutPut,files.i)
  END
 END

ELSE DO
  DO i = 1 to filessorted.0
   CALL WRITELN(fileoutPut,filessorted.i)
  END
END

CALL CLOSE(FileOutPut)
RETURN

_SaveFileListNames:
Savetitle='"'||localestring(MSG_REQ_SELECTSAVEFILE2)||'"'
CALL _SaveFileRequest					/* Filerequest öffnen */
IF bool == 0 THEN RETURN				/* Cancel */

IF EXISTS(ListFileName.1) THEN DO
  CALL rtezrequest(localestring(MSG_REQ_DESTFILEEXISTS),localestring(MSG_REQ_OVERRIDE)"|"localestring(MSG_REQ_APPEND)"|"localestring(MSG_REQ_ABORT),,
  ListfileName.1,"rt_pubscrname="PubScreen)
    SELECT
      WHEN result == 0 THEN RETURN
      WHEN result == 1 THEN CALL OPEN(FileOutPut,Listfilename.1,"Write")
      WHEN result == 2 THEN CALL OPEN(FileOutPut,Listfilename.1,"Append")
      OTHERWISE
      NOP
    END
END
ELSE CALL OPEN(FileOutPut,Listfilename.1,"Write")

IF normal == files THEN
 DO
  DO i = 1 to files.0
   filenamepure=RXTR_FILEPART(files.i)
   CALL WRITELN(fileoutPut,filenamepure)
  END
 END

ELSE DO
  DO i = 1 to filessorted.0
   filenamepure=RXTR_FILEPART(filessorted.i)
   CALL WRITELN(fileoutPut,filenamepure)
  END
END
CALL CLOSE(FileOutPut)
RETURN

_SaveFileRequest:
                  bool = ASL_RequestFile(window,Listfilename,,
                               "ASLFR_PubScreenName" PubScreen,
                               "ASLFR_InitialDrawer" SaveListDir,
                               "ASLFR_TitleText" SaveTitle)
SaveListDir=RXTR_PATHPART(ListFileName.1)
RETURN


/**************************************
 *** Routinen zum (un)iconifizieren ***
 **************************************/
_Iconify:
CALL _AttributeBehalten
iwinsize.trd_left=10
iwinsize.trd_top=10
iwinsize.trd_width=20
iwinsize.trd_height=10
iwinsize.trd_left2=10
iwinsize.trd_top2=10
iwinsize.trd_width2=10
iwinsize.trd_height2=20
iwinsize.trd_zoomed=30

SleepWin = WindowID(1000),
           PubScreenName(PubScreen),
           WindowBackfillFB,
           WindowTitle(appname appversion),
           WindowDimensions(iwinsize),
                        BeginMenu(localestring(MSG_MAIN_MENU_PROJECT)),
                        MenuItem(localestring(MSG_MAIN_MENUITEM_QUIT),101),
           'EndProject'

  ok=tr_closeproject(window)
  window = '00000000'x
dummywindow = TR_OPENPROJECT(app,SleepWin)
return

_uniconify:
  ok=tr_closeproject(dummywindow)
  dummywindow = '00000000'x

  prefs.iwinx=iwinsize.trd_left
  prefs.iwiny=iwinsize.trd_top
  prefs.iwinw=iwinsize.trd_width
  prefs.iwinh=iwinsize.trd_height
  prefs.iwinx2=iwinsize.trd_left2
  prefs.iwiny2=iwinsize.trd_top2
  prefs.iwinw2=iwinsize.trd_width2
  prefs.iwinh2=iwinsize.trd_height2
  prefs.iwinz=iwinsize.trd_zoomed

   window = TR_OPENPROJECT(app,windowtags)
   WindowProject=C2D(window) /* zum Locken des Fensters bei About */

IF HelpBool = 1 THEN DO
 CALL TR_SetAttribute(window,103,TRMN_Flags,TRMF_CHECKED)
 CALL TR_SetAttribute(window,0,TRWI_QuickHelp,1)
END
CALL _AttributeZurueck
RETURN

_AttributeZurueck:
/*******************************************************
*** Zustand vor der Ikonifizierung wieder herstellen ***
********************************************************/
CALL TR_SETATTRIBUTE(window,1,'TROB_STRING',iconifyString1)
CALL TR_SETATTRIBUTE(window,3,'TROB_STRING',iconifyString2)
CALL TR_SETATTRIBUTE(window,7,'TROB_STRING',iconifyString3)
CALL TR_SETATTRIBUTE(window,9,'TROB_STRING',iconifyString4)
CALL TR_SETATTRIBUTE(window,4,'TRAT_Value',Depth+1)
IF  Depth = -1 THEN CALL TR_SETATTRIBUTE(window,44,'TRAT_Text',(localestring(MSG_OFF)))
               ELSE CALL TR_SETATTRIBUTE(window,44,'TRAT_Text',Depth)
CALL TR_SETATTRIBUTE(window,55,'TRAT_Value',iconifyString5)
CALL TR_SETATTRIBUTE(window,56,'TRAT_Value',iconifyString6)
CALL TR_SETATTRIBUTE(window,5,'TRAT_Value',iconifyString7)
CALL TR_SETATTRIBUTE(window,6,'TRAT_Value',iconifyString8)
CALL TR_SETATTRIBUTE(window,11,'TRAT_Value',iconifyString9)
               IF Sort == 1 THEN normal= filesSorted
                            ELSE normal= files
               CALL TR_SETATTRIBUTE(window,99,'TROB_ListView',normal)
               CALL TR_SETATTRIBUTE(window,98,'TRAT_TEXT',localestring(MSG_MAIN_TEXT_SLEEP))

               sel1 = TR_GETATTRIBUTE(window,1,'TROB_String')
               sel2 = TR_GETATTRIBUTE(window,3,'TROB_String')
              SELECT
              WHEN sel1 = "" THEN CALL TR_SendMessage(Window,1,'TROM_ACTIVATE',0)
              WHEN sel2 = "" THEN CALL TR_SendMessage(Window,3,'TROM_ACTIVATE',0)
              OTHERWISE
              NOP
              END

If files.0 ~= 0 THEN DO
   CALL TR_SETATTRIBUTE(window,12,'TRAT_Disabled',0)
   CALL TR_SETATTRIBUTE(window,13,'TRAT_Disabled',0)
END
RETURN

_AttributeBehalten:
iconifyString1 = TR_GETATTRIBUTE(window,1,'TROB_STRING')
iconifyString2 = TR_GETATTRIBUTE(window,3,'TROB_STRING')
iconifyString3 = TR_GETATTRIBUTE(window,7,'TROB_STRING')
iconifyString4 = TR_GETATTRIBUTE(window,9,'TROB_STRING')
Depth          = TR_GETATTRIBUTE(window,4,'TRAT_Value')-1
iconifyString5 = TR_GETATTRIBUTE(window,55,'TRAT_VALUE')
iconifyString6 = TR_GETATTRIBUTE(window,56,'TRAT_VALUE')
iconifyString7 = TR_GETATTRIBUTE(window,5,'TRAT_VALUE')
iconifyString8 = TR_GETATTRIBUTE(window,6,'TRAT_VALUE')
iconifyString9 = TR_GETATTRIBUTE(window,11,'TRAT_VALUE')
RETURN

/*******
 *** ***
 *******/
_LFORMATList:
IF PUBSCREENLIST('ScreenList') == 0 THEN RETURN

/*
                  WindowFlags('TRWF_NODRAGBAR|TRWF_NOCLOSEGADGET|TRWF_NOESCCLOSE'),
*/
LFormatListTags = WindowID(3),
                  WindowPosition('TRWP_MOUSEPOINTER'),
                  WindowBackfillFB,
                  WindowTitle('LFORMAT'),
                  WindowFlags('TRWF_NOCLOSEGADGET|TRWF_NOESCCLOSE'),
                  PubScreenName(Pubscreen),
                 'VertGroupA',
                 'Space',
                  'HorizGroupA',
                   'Space',
                    ListSel('LForm',301,0),
                    'Space',
                  'EndGroup',
                 'Space',
                 'HorizSeparator',
                 'Space',
                  'HorizGroupA',
                   'Space',
                   ButtonRE(localestring(MSG_GAD_OKAY),302),
                   'Space',
                 'EndGroup Space EndGroup EndGroup EndProject'

LFormatProject = TR_OPENPROJECT(app,LFormatlisttags)
  IF LFormatProject ~= '00000000'x THEN DO
    CALL TR_LOCKPROJECT(window)

      DO WHILE ende ~= 1
         DO WHILE TR_HANDLEMSG(app,'event3')
            IF event3.trm_class = 'TRMS_ACTION' THEN ende = 1 /* Cancel Gadget */
             IF event3.trm_class = 'TRMS_NEWVALUE' THEN DO
                nummer = TR_GETATTRIBUTE(LformatProject,301,'TRAT_Value')+1
                IF nummer <8 THEN lformattemplate=WORD(Lform.nummer,1)
                             ELSE lformattemplate = Lform.nummer
                oldTemplate=TR_GETATTRIBUTE(window,7,'TROB_STRING')
                lformattemplate = oldTemplate||lformattemplate
                CALL TR_SETATTRIBUTE(window,7,'TROB_STRING',lformattemplate)
             END
         END
      END
  END

   ende = 0
    CALL TR_UNLOCKPROJECT(window)
    CALL TR_CLOSEPROJECT(LFormatProject)
RETURN

/*******************************************************************
 ***  Routine, die das GUI auf einem neuen PubScreen öffnen läßt ***
 *******************************************************************/
_NewPubScreen:
IF PUBSCREENLIST('ScreenList') == 0 THEN RETURN

delstart=LSEARCH(PubScreen,Screenlist)
IF delstart ~= -1 THEN RXTR_STEMREMOVE(ScreenList,delstart)

ScreenListTags = WindowID(2),
   WindowBackfillFB,
   WindowPosition('TRWP_MOUSEPOINTER'),
   WindowTitle(localestring(MSG_TITLE_CHANGEPUBSCREEN)),
   WindowFlags('TRWF_NOCLOSEGADGET|TRWF_NOESCCLOSE'),
   PubScreenName(Pubscreen),
   'VertGroupA',
      'Space',
      'HorizGroupA',
         'Space',
         ListSel('screenlist',301,0),
         'Space',
      'EndGroup',
      'Space',
      'HorizSeparator',
      'Space',
      'HorizGroupA',
      'Space',
      ButtonRE(localestring(MSG_GAD_CANCEL),302),
      'Space',
   'EndGroup Space EndGroup EndGroup EndProject'

    PubScreenProject = TR_OPENPROJECT(app,Screenlisttags)

  IF PubScreenProject ~= '00000000'x THEN DO
    CALL TR_LOCKPROJECT(window)

      DO WHILE ende ~= 1
         DO WHILE TR_HANDLEMSG(app,'event2')
            IF event2.trm_class = 'TRMS_ACTION' THEN ende = 1 /* Cancel Gadget */

            IF event2.trm_class = 'TRMS_NEWVALUE' THEN DO
            nummer = TR_GETATTRIBUTE(PubScreenProject,301,'TRAT_Value')+1
              PubScreen = ScreenList.nummer
              CALL _AttributeBehalten
              CALL TR_UNLOCKPROJECT(window)
              CALL TR_CLOSEPROJECT(PubScreenProject)
              CALL TR_CLOSEPROJECT(window)
              CALL TR_DELETEAPP(app)
              CALL RXTR_PUBSCREENTOFRONT(PubScreen)
              fromNewPub=1
              CALL _maintags
            END
         END
      END

   ende = 0
    CALL TR_UNLOCKPROJECT(window)
    CALL TR_CLOSEPROJECT(PubScreenProject)
END
RETURN

/*******************************************************************************
** Info über das Programm anzeigen
*******************************************************************************/
about:
   CALL TR_AUTOREQUEST(app,window,PubScreenName(PubScreen),
         BeginRequester('About','TRWP_CENTERDISPLAY'),
            'VertGroupA',
               'Space',
               CenteredText3(appname appversion '('||appdate||') (C) 1996 by Nils Görs <N.Goers@Art-Line.de>'),
               'SpaceS',
               CenteredText(appinfo),
               'Space',
               'HorizSeparator',
               'Space',
               CenteredText3('This program is using the 'Triton GUI creation system''),
               'SpaceS',
               CenteredText("'Triton' is (C) by Stefan Zeiger <s.zeiger@laren.rhein-main.de>"),
               'Space',
               'HorizSeparator',
               'Space',
               CenteredText3("This program also use 'tritonrexx.library'"),
               'SpaceS',
               'HorizGroupSC',
                  'Space',
                  TextN("'tritonrexx.library' is (C) by Jürgen Kohrmeyer <j_kohrmeyer@wilam.north.de>") 'TRAT_Flags TRTX_NOUNDERSCORE',
                  'Space',
               'EndGroup',
               'Space',
            'EndGroup',
            'BeginRequesterGads',
            CenteredButtonRE(localestring(MSG_THANKS),10000),
         'EndRequester')
   RETURN

_ShowInformation:
CALL _GETNAMEFORINFO
IF WhatIsListBool = 1 THEN DO
                CALL rtezrequest(localestring(MSG_CREATIONDATE)  fileinfo.3,
                               NL||localestring(MSG_CREATIONDATE2) fileinfo.4,
                               NL||localestring(MSG_SIZE) fileinfo.1 "Bytes",
                               NL||localestring(MSG_BLOCKS) fileinfo.2,
                            NL NL||localestring(MSG_ATTRIBUTES) fileinfo.5,
                               NL||localestring(MSG_FILETYP) WhatIsTyp,
                            NL NL||localestring(MSG_COMMENT) fileinfo.6,
                               ,localestring(MSG_THANKSEXECUTE),FileNameInfo,"rt_pubscrname="PubScreen)
 IF result = 1 THEN CALL _UseWhatIs
END
ELSE
                CALL rtezrequest(localestring(MSG_CREATIONDATE)  fileinfo.3,
                               NL||localestring(MSG_CREATIONDATE2) fileinfo.4,
                               NL||localestring(MSG_SIZE) fileinfo.1 "Bytes",
                               NL||localestring(MSG_BLOCKS) fileinfo.2,
                            NL NL||localestring(MSG_ATTRIBUTES) fileinfo.5,
                               NL||localestring(MSG_FILETYP) WhatIsTyp,
                            NL NL||localestring(MSG_COMMENT) fileinfo.6,
                               ,localestring(MSG_THANKS),FileNameInfo,"rt_pubscrname="PubScreen)

CALL TR_UnlockProject(window)
RETURN

_GETNAMEFORINFO:
               nummer = TR_GETATTRIBUTE(window,99,'TRAT_Value')+1
               IF LFormat = "LFORMAT" THEN RETURN
               CALL TR_LockProject(window)
               IF Lformat ~= "" THEN DO
                CALL rtezrequest(localestring(MSG_NOTPOSSIBLE),localestring(MSG_THANKS),,"rt_pubscrname="PubScreen)
                CALL TR_UnlockProject(window)
                RETURN
               END
               IF Sort == 1 THEN normal= filesSorted
                            ELSE normal= files
               FilenameInfo = VALUE(normal||.||nummer)

IF filenameinfo == "FILES.1" THEN DO/* damit der Inforequester nicht auf- */
CALL TR_UnlockProject(window)       /* poppt, falls man RETURN drückt und */
RETURN                              /* noch keine Liste vorhanden ist.    */
END
                ADDRESS COMMAND 'list' FileNameInfo 'LFORMAT = "%L*N%B*N%-9D*N%T*N%A*N%c*N" >t:FileInfo'
                CALL RXTR_READFILE("T:FileInfo",FileInfo)
                ADDRESS COMMAND 'delete t:fileinfo QUIET'
                  IF fileinfo.6 = "" THEN fileinfo.6 = localestring(MSG_NONE)
                 IF LENGTH(fileinfo.6) > 40 THEN DO
                  Anzahl = WORDS(fileinfo.6)
                  IF DATATYPE(Anzahl/2,"Wh") == 0 THEN Anzahl2 = (Anzahl/2)+0.5
                                                  ELSE Anzahl2 = Anzahl/2
                  fileinfo.6=SUBWORD(fileinfo.6,1,Anzahl2)||NL,
           "              "||SUBWORD(fileinfo.6,Anzahl2+1)
                 END
  IF Filetyp = 1 THEN WhatIsTyp = STRIP(WORD(FilenameInfo,2),"Both","()")
                 ELSE WhatisTyp=RXTR_WHATIS(FileNameInfo)

RETURN

_UseWhatIs:
IF FileTyp == 1 THEN FileNameInfo = WORD(FilenameInfo,1)

WI_Entry =LSEARCH(WhatIsTyp,WhatIsList)
  IF WI_Entry = = -1 THEN DO
   CALL rtezrequest(WhatisTyp localestring(MSG_NOTSUPPORTED),localestring(MSG_THANKS),,"rt_pubscrname="PubScreen)
   CALL TR_UnlockProject(window)
   RETURN
  END
WI_Entry = WI_Entry + 1
CALL _SetFilename
CALL _SetPubScreenName

IF Yep ~= 0 THEN ADDRESS COMMAND StartCommand ">NIL:"
CALL TR_UnlockProject(window)
RETURN

_SetFileName:
   Yep = INDEX(WhatIslist.WI_entry,"%s")-1
    IF Yep == 0 THEN RETURN
   Len= LENGTH(WhatIsList.WI_entry)
   NewCommand = LEFT(WhatIsList.WI_entry,Yep)
   NewCommand2= RIGHT(WhatIsList.WI_entry,Len-yep-2)
  StartCommand=NewCommand||FilenameInfo||NewCommand2
RETURN

_SetPubScreenName:
  Yep2 = INDEX(StartCommand,"%p")-1
   IF Yep2 == -1 THEN RETURN
   Len= LENGTH(NewCommand||FilenameInfo||NewCommand2)
   NewCommand3 = LEFT(StartCommand,Yep2)
   NewCommand4= RIGHT(NewCommand||FilenameInfo||NewCommand2,Len-yep2-2)
  StartCommand = newcommand3||PubScreen||newcommand4
RETURN
/*******************************************************************************
** Load and interpret arexx script
*******************************************************************************/

loadrexx:
   PARSE ARG dir,file,store

   IF dir ~= '' THEN DO
      IF RIGHT(dir,1) = ':' THEN
         file = dir||file
      ELSE
         file = dir||'/'||file
   END

   IF ~OPEN('rexxfile',file,'R') THEN
      RETURN(FALSE)

   rexxtext = READCH('rexxfile',64000)
   INTERPRET rexxtext

   CALL CLOSE('rexxfile')

   IF store ~= '' THEN
      INTERPRET store '= rexxtext'

   DROP rexxtext

   RETURN(TRUE)

/*******************************************************************************
** Text aus dem Catalog-File auslesen, falls vorhanden
*******************************************************************************/

localestring:
   PARSE ARG stringnumber

   IF catalog ~= 0 THEN
      RETURN(GETCATALOGSTR(catalog,stringnumber,strings.stringnumber))
   ELSE
      RETURN(strings.stringnumber)

_InitAll:
NL = '0a'x
TRUE  = 1
FALSE = 0

HelpBool      = 0
Files.0       = 0
FilesSorted.0 = 0
Path          = 0
Full          = 0
Exec          = 0

LForm.0     = 8
LForm.1     = "%e   Name suffix"
LForm.2     = "%f   Full path and name"
LForm.3     = "%m   Name without suffix"
LForm.4     = "%N   Full name"
LForm.5     = "%n   Full name (lowercase)"
LForm.6     = "%p   Fully qualified path"
LForm.7     = "%%   Percent sign"
LForm.8     = "%-30p%-20N"

   catalog      = 0


   /*
   ** Open libs
   */

   IF ~SHOW('LIBRARIES','tritonrexx.library') THEN
      IF ~ADDLIB('tritonrexx.library',10,-30,0) THEN
         quit('Cannot open tritonrexx.library!',10)

   IF ~SHOW(LIBRARIES,'rexxtricks.library') THEN
      IF ~ADDLIB('rexxtricks.library',9,-30,38) THEN
         quit('Cannot open rexxtricks.library!',10)

   IF ~SHOW('LIBRARIES','rexxreqtools.library') THEN
      IF ~ADDLIB('rexxreqtools.library',9,-30,0) THEN
         quit('Cannot open rexxreqtools.library!',10)

   IF ~SHOW('LIBRARIES','rexxsupport.library') THEN
      IF ~ADDLIB('rexxsupport.library',9,-30,0) THEN
         quit('Cannot open rexxsupport.library!',10)


   /*
   ** Set current dir
   */

   PARSE SOURCE . . . script .
   progdir = PATHPART(script)

   booll = LENGTH(progdir)
   booli= LASTPOS(":",progdir)
   boolh= LASTPOS("/",progdir)

  IF booli <= booll THEN progdir2=progdir||"/"
  IF boolh == 0 THEN progdir2=progdir||"/"

   CALL PRAGMA('D',progdir)

   /*
   ** Read default strings, open locale.library and catalog
   */

   IF ~loadrexx(progdir,'FindGUI.strings','') THEN
      quit('Error reading file "FindGUI.strings"!'),10)

   IF ~SHOW('LIBRARIES','locale.library') THEN
      CALL ADDLIB('locale.library',0,-30,0)

   IF SHOW('LIBRARIES','locale.library') THEN DO
      language = GETENV('language')
      IF language ~= '' THEN
         catalog = OPENCATALOG(MAKEPATH(progdir,'catalogs/' || language || '/FindGUI.catalog'),'english',0)

      IF catalog = 0 THEN
         catalog = OPENCATALOG('FindGUI.catalog','english',0)

   END

IF PubScreen == "" THEN
   PubScreen = RXTR_GETDEFAULTPUBSCREEN()

WhatIsListbool = RXTR_READFILE(Progdir2||WhatIsExe,WhatIsList)
RETURN
/*******************************************************************************
** Routine, die bei einer Unterbrechung des Scripts aufgerufen wird
*******************************************************************************/
break_c:
failure:
halt:
ioerr:
syntax:
   SAY '+++ Fehler' rc 'in Zeile' sigl '-' ERRORTEXT(rc)
   SAY SOURCELINE(sigl)

   IF app ~= '00000000'x THEN
      CALL TR_DELETEAPP(app)

   EXIT(10)
/*EOS*/
