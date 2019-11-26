/*
** $VER: RDBBackup.rexx 1.1 (20.1.96) Copyright (C) by Jürgen Kohrmeyer
*/

/*
** Application
*/

appname     = 'RDBBackup'
applongname = 'RDBBackup - ©1996 by Jürgen Kohrmeyer'
appinfo     = 'Backup RigidDiskBlocks - GUI for ReadRDB'
appversion  = '1.1'
apprelease  = '1'
appdate     = '20.4.96'


/*
** Set defaults, open libs, catalog, prefs etc.
*/

CALL initall


/*
** Main loop
*/

quitprogram = FALSE

DO WHILE ~quitprogram
   CALL TR_WAIT(app,'')

   DO WHILE TR_HANDLEMSG(app,'event')
      IF event.trm_class = 'TRMS_CLOSEWINDOW' THEN
         quitprogram = TRUE

      IF event.trm_class = 'TRMS_NEWVALUE' THEN DO
         SELECT
            WHEN event.trm_id = 1 THEN                   /* Publicscreen */
               CALL reopenmainwindow(TR_GETATTRIBUTE(mainwindow,1,'TROB_String'))

            WHEN event.trm_id = 5 THEN                   /* SCSI device */
               CALL updateunitlist(TR_GETATTRIBUTE(mainwindow,5,'TROB_String'))

            WHEN event.trm_id = 10 THEN                  /* Unit list */
               CALL updategadgets

            OTHERWISE
               NOP
         END
      END

      IF event.trm_class = 'TRMS_ACTION' THEN DO
         SELECT
            WHEN event.trm_id = 2 THEN                   /* GetEntryButton Publicscreen */
               CALL reopenmainwindow(selectscreen())

            WHEN event.trm_id = 4 THEN DO                /* GetDrawerButton Backup directory */
               backupdir = TR_GETATTRIBUTE(mainwindow,3,'TROB_String')
               reqtags = GetDrawer(localestring(MSG_REQUEST_BACKUP_DIR),localestring(MSG_REQUEST_GAD_USE),backupdir) 'ASLFR_PubScreenName' pubscreen

               IF ASL_REQUESTFILE(mainwindow,'newbackupdir',reqtags) THEN DO
                  backupdir = newbackupdir.1
                  CALL TR_SETATTRIBUTE(mainwindow,3,'TROB_String',backupdir)
               END
            END

            WHEN event.trm_id = 6 THEN DO                /* GetEntryButton SCSI device */
               newdevice = selectdevice()

               IF newdevice ~= '' THEN
                  CALL updateunitlist(newdevice)
            END

            WHEN event.trm_id = 11 THEN                  /* Button 'Update list' */
               CALL updateunitlist(device)

            WHEN event.trm_id = 12 THEN                  /* Button 'Backup RDB' */
               CALL backup_rdb

            WHEN event.trm_id = 13 THEN                  /* Button 'Restore RDB' */
               CALL restore_rdb

            WHEN event.trm_id = 20 THEN                  /* Button 'About' */
               CALL about

            WHEN event.trm_id = 21 THEN                  /* Button 'Save Prefs' */
               CALL saveprefs

            WHEN event.trm_id = 22 THEN                  /* Button 'Quit' */
               quitprogram = TRUE

            OTHERWISE
               NOP
         END
      END
   END
END

CALL TR_CLOSEPROJECT(mainwindow)


/*
** Quit program
*/

quit('',0)



/*******************************************************************************
** Show information requester
*******************************************************************************/

/*
         BeginRequester(localestring(MSG_ABOUTWINDOW_TITLE),'TRWP_CENTERDISPLAY'),
*/

about:
   CALL TR_AUTOREQUEST(app,mainwindow,PubScreenName(pubscreen),
         WindowTitle(localestring(MSG_ABOUTWINDOW_TITLE)),
         WindowPosition('TRWP_CENTERDISPLAY'),
         WindowBackfillSA,
         WindowFlags('TRWF_NOZIPGADGET|TRWF_NOSIZEGADGET|TRWF_NOCLOSEGADGET|TRWF_NODELZIP|TRWF_NOESCCLOSE'),
         'VertGroupA Space HorizGroupA Space',
         'GroupBox ObjectBackfillFB',
            'VertGroupA',
               'Space',
               CenteredText3(appname appversion '('||appdate||') (C) 1996 by Jürgen Kohrmeyer'),
               'SpaceS',
               CenteredText(appinfo),
               'Space',
               'HorizSeparator',
               'Space',
               CenteredText("Jürgen Kohrmeyer"),
               'SpaceS',
               CenteredText("Oststraße 2"),
               'SpaceS',
               CenteredText("49143 Bissendorf"),
               'SpaceS',
               CenteredText("GERMANY"),
               'SpaceS',
               'HorizGroupSC',
                  'Space',
                  TextN("EMail: J_Kohrmeyer@wilam.north.de") 'TRAT_Flags TRTX_NOUNDERSCORE',
                  'Space',
               'EndGroup',
               'Space',
               'HorizSeparator',
               'Space',
               CenteredText3(localestring(MSG_ABOUTWINDOW_APP_USES)),
               'Space',
               CenteredText("'ReadRDB' (C) by Gérard Cornu"),
               'SpaceS',
               CenteredText("'Triton GUI creation system' (C) by Stefan Zeiger"),
               'SpaceS',
               CenteredText("'tritonrexx.library' (C) by Jürgen Kohrmeyer"),
               'SpaceS',
               CenteredText("'rexxtricks.library' (C) by Jürgen Kohrmeyer"),
               'Space',
            'EndGroup',
            'BeginRequesterGads',
            CenteredButtonRE(localestring(MSG_GAD_OKAY),10000),
         'EndRequester')
   RETURN



/*******************************************************************************
** Save prefs
*******************************************************************************/

saveprefs:
   line.0 = 5
   line.1 = '/* RDBBackup.prefs */'
   line.2 = ''
   line.3 = 'pubscreen = "' || TR_GETATTRIBUTE(mainwindow,1,'TROB_String') || '"'
   line.4 = 'backupdir = "' || TR_GETATTRIBUTE(mainwindow,3,'TROB_String') || '"'
   line.5 = 'device    = "' || TR_GETATTRIBUTE(mainwindow,5,'TROB_String') || '"'

   CALL WRITEFILE(MAKEPATH(progdir,'RDBBackup.prefs'),line)
   RETURN



/*******************************************************************************
** Select public screen
*******************************************************************************/

selectscreen:
   selectedscreen = ''
   number = 1

   IF PUBSCREENLIST('screenlist') THEN DO
      screenwindow = TR_OPENPROJECT(app,screenwindowtags)

      IF screenwindow ~= '00000000'x THEN DO
         CALL TR_LOCKPROJECT(mainwindow)

         quitscreenwindow = FALSE

         DO WHILE ~quitscreenwindow
            CALL TR_WAIT(app,'')

            DO WHILE TR_HANDLEMSG(app,'event')
               IF event.trm_class = 'TRMS_CLOSEWINDOW' THEN
                  quitscreenwindow = TRUE

               IF event.trm_class = 'TRMS_ACTION' THEN DO
                  IF event.trm_id = 398 THEN DO
                     selectedscreen = screenlist.number
                     quitscreenwindow = TRUE
                  END

                  IF event.trm_id = 399 THEN
                     quitscreenwindow = TRUE
               END

               IF event.trm_class = 'TRMS_NEWVALUE' & event.trm_id = 301 THEN DO
                  number = event.trm_data+1

                  IF BITAND(D2X(event.trm_qualifier),'0200'x) = '0200'x THEN DO
                     selectedscreen = screenlist.number
                     quitscreenwindow = TRUE
                  END
               END
            END
         END

         CALL TR_CLOSEPROJECT(screenwindow)
         CALL TR_UNLOCKPROJECT(mainwindow)
      END
   END

   RETURN(selectedscreen)



/*******************************************************************************
** Select device
*******************************************************************************/

selectdevice:
   devstring = SHOWLIST('DEVICES',,'|')

   pos1 = 1
   pos2 = 1
   count = 0

   DO WHILE pos2 <= LENGTH(devstring)
      pos2 = POS('|',devstring,pos1)

      IF pos2 = 0 THEN
         pos2 = LENGTH(devstring)+1

      count = count+1

      devicelist.count = SUBSTR(devstring,pos1,pos2-pos1)

      pos1 = pos2+1
   END

   devicelist.0 = count

   selecteddevice = ''
   number = 0

   devicewindow = TR_OPENPROJECT(app,devicewindowtags)

   IF devicewindow ~= '00000000'x THEN DO
      CALL TR_LOCKPROJECT(mainwindow)

      quitdevicewindow = FALSE

      DO WHILE ~quitdevicewindow
         CALL TR_WAIT(app,'')

         DO WHILE TR_HANDLEMSG(app,'event')
            IF event.trm_class = 'TRMS_CLOSEWINDOW' THEN
               quitdevicewindow = TRUE

            IF event.trm_class = 'TRMS_ACTION' THEN DO
               IF event.trm_id = 298 THEN DO
                  selecteddevice = devicelist.number
                  quitdevicewindow = TRUE
               END

               IF event.trm_id = 299 THEN
                  quitdevicewindow = TRUE
            END

            IF event.trm_class = 'TRMS_NEWVALUE' & event.trm_id = 201 THEN DO
               number = event.trm_data+1

               IF BITAND(D2X(event.trm_qualifier),'0200'x) = '0200'x THEN DO
                  selecteddevice = devicelist.number
                  quitdevicewindow = TRUE
               END
            END
         END
      END

      CALL TR_CLOSEPROJECT(devicewindow)
      CALL TR_UNLOCKPROJECT(mainwindow)
   END

   RETURN(selecteddevice)



/*******************************************************************************
** Update unit information
*******************************************************************************/

updateunitlist:
   PARSE ARG newdevice

   device = newdevice

   CALL TR_LOCKPROJECT(mainwindow)
   CALL TR_SETATTRIBUTE(mainwindow,5,'TROB_String',device)

   unitlist.0 = 0

   CALL TR_SETATTRIBUTE(mainwindow,10,'TROB_Listview',unitlist)

   DO i = 1 TO 8
      manufacturer.i = SCSI_MANUFACTURER(device,i-1)

      IF manufacturer.i ~= '' THEN DO
         product.i = SCSI_PRODUCT(device,i-1)
         revision.i = SCSI_REVISION(device,i-1) 
         devicetype.i = SCSI_DEVICETYPE(device,i-1) 

         IF SCSI_TESTREADY(device,i-1) THEN
            unitready.i = 'READY'
         ELSE
            unitready.i = 'NOT READY'

         unitlist.i = i-1 LEFT(manufacturer.i,8) LEFT(product.i,16) LEFT(revision.i,4) LEFT(devicetype.i,13) unitready.i
      END
      ELSE DO
         unitlist.i   = i-1 '-'
         devicetype.i = ''
         unitready.i  = 'NOT_READY'
      END

      unitlist.0 = i

      CALL TR_SETATTRIBUTE(mainwindow,10,'TROB_Listview',unitlist)
   END

   CALL updategadgets

   CALL TR_UNLOCKPROJECT(mainwindow)

   RETURN



/*******************************************************************************
** Disable or enable Backup/Restore gadgets
*******************************************************************************/

updategadgets:
   number = TR_GETATTRIBUTE(mainwindow,10,'TRAT_Value')+1

   disablebackup  = TRUE
   disablerestore = TRUE

   IF FIND(devicetype.number,'DISK OPTICAL') ~= 0 & unitready.number = 'READY' THEN DO
      disablebackup = FALSE

      filename = createfilename(number)
      comment  = createcomment(number)

      IF EXISTS(filename) THEN
         IF GETCOMMENT(filename) = comment THEN
            disablerestore = FALSE
   END

   CALL TR_SETATTRIBUTE(mainwindow,12,'TRAT_Disabled',disablebackup)
   CALL TR_SETATTRIBUTE(mainwindow,13,'TRAT_Disabled',disablerestore)

   RETURN


/*******************************************************************************
** Backup RDB from actual drive
*******************************************************************************/

backup_rdb:
   number = TR_GETATTRIBUTE(mainwindow,10,'TRAT_Value')+1

   filename = createfilename(number)
   comment  = createcomment(number)

   IF EXISTS(filename) THEN DO
      message = '"' || FILEPART(filename) || '"' localestring(MSG_REQUEST_ALREADY_EXISTS) || '0A'x || localestring(MSG_REQUEST_REPLACE_FILE)

      IF ~easyrequest(message,localestring(MSG_REQUEST_GADS_REPLACE),mainwindow,'TRWP_MOUSEPOINTER') THEN
         RETURN
   END

   CALL TR_LOCKPROJECT(mainwindow)

   cmd = readrdb '>NIL: DEVICE' device 'UNIT' number-1 'FILE "' || filename || '"'

   ADDRESS 'COMMAND' cmd

   IF rc = 0 THEN
      CALL SETCOMMENT(filename,comment)
   ELSE
      CALL easyrequest(localestring(MSG_REQUEST_BACKUP_FAILED) rc || '!',localestring(MSG_GAD_OKAY),mainwindow,'TRWP_MOUSEPOINTER')

   CALL updategadgets

   CALL TR_UNLOCKPROJECT(mainwindow)

   RETURN


/*******************************************************************************
** Restore RDB to actual drive
*******************************************************************************/

restore_rdb:
   number = TR_GETATTRIBUTE(mainwindow,10,'TRAT_Value')+1

   filename = createfilename(number)
   comment  = createcomment(number)

   IF EXISTS(filename) THEN DO
      message = localestring(MSG_REQUEST_RESTORE_FROM_FILE) '"' || FILEPART(filename) || '":' || '0A'x ||,
                '----------------------------------------' || '0A'x ||,
                device '- Unit' number-1 || '0A'x ||,
                manufacturer.number || '0A'x ||,
                product.number || '0A'x ||,
                'Revision' revision.number || '0A'x ||,
                '----------------------------------------' || '0A'x ||,
                localestring(MSG_REQUEST_RESTORE_ASK)

      IF easyrequest(message,localestring(MSG_REQUEST_GADS_RESTORE),mainwindow,'TRWP_TOPLEFTSCREEN') THEN DO
         IF easyrequest(message,localestring(MSG_REQUEST_GADS_RESTORE),mainwindow,'TRWP_CENTERSCREEN') THEN DO
            CALL TR_LOCKPROJECT(mainwindow)

            cmd = readrdb '<>"CON:////ReadRDB console/AUTO/SCREEN' pubscreen || '" DEVICE' device 'UNIT' number-1 'WRITE FILE "' || filename || '"'

            ADDRESS 'COMMAND' cmd

            IF rc ~= 0 THEN
               CALL easyrequest(localestring(MSG_REQUEST_RESTORE_FAILED) rc || '!',localestring(MSG_GAD_OKAY),mainwindow,'TRWP_MOUSEPOINTER')

            CALL TR_UNLOCKPROJECT(mainwindow)
         END
      END
   END

   RETURN


/*******************************************************************************
** Create filename for backup of given unit
**
** Example: RDB_scsi.device_1
*******************************************************************************/

createfilename:
   PARSE ARG unitnumber

   RETURN(MAKEPATH(backupdir,'RDB_' || device || '_' || unitnumber-1))


/*******************************************************************************
** Create comment for backup of given unit
**
** Example: FUJITSU M2694S-512 2033 - scsi.device Unit 1
*******************************************************************************/

createcomment:
   PARSE ARG unitnumber

   RETURN(manufacturer.unitnumber product.unitnumber revision.unitnumber '-' device 'Unit' unitnumber-1)


/*******************************************************************************
** Close mainwindow and open on a new screen
*******************************************************************************/

reopenmainwindow:
   PARSE ARG newscreen

   IF newscreen ~= '' & newscreen ~= pubscreen THEN DO
      pubscreen = newscreen

      CALL TR_SETATTRIBUTE(mainwindow,1,'TROB_String',pubscreen)
      CALL TR_CLOSEPROJECT(mainwindow)
      CALL PUBSCREENTOFRONT(pubscreen)

      INTERPRET windowdefs

      mainwindow = TR_OPENPROJECT(app,mainwindowtags)

      IF mainwindow = '00000000'x THEN
         quit('Cannot open mainwindow!',10)

      CALL updategadgets
   END

   RETURN


/*******************************************************************************
** Show requester
*******************************************************************************/

easyrequest:
   PARSE ARG text,gadgets,project,position

   IF project ~= '00000000'x THEN
      tags = 'TREZ_LockProject' C2D(project) 'TREZ_Return 0 TREZ_ReqPos' position 'TAG_END'
   else
      tags = 'TREZ_Return 0 TREZ_ReqPos' position 'TAG_END'

   RETURN(TR_EASYREQUEST(app,text,gadgets,tags))



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
** Get locale string from catalog or use default string
*******************************************************************************/

localestring:
   PARSE ARG stringnumber

   IF catalog ~= 0 THEN
      RETURN(GETCATALOGSTR(catalog,stringnumber,strings.stringnumber))
   ELSE
      RETURN(strings.stringnumber)



/*******************************************************************************
** Open libs, catalog, prefs, application and window
*******************************************************************************/

initall:
   /*
   ** Set defaults
   */

   TRUE  = 1
   FALSE = 0
   NL    = '0A'x

   app          = '00000000'x
   mainwindow   = '00000000'x

   changed      = FALSE

   catalog      = 0

   devicelist.0 = 0
   unitlist.0   = 0


   /*
   ** Open libs
   */

   IF ~SHOW('LIBRARIES','tritonrexx.library') THEN
      IF ~ADDLIB('tritonrexx.library',10,-30,0) THEN
         quit('Cannot open tritonrexx.library!',10)

   IF ~SHOW(LIBRARIES,'rexxtricks.library') THEN
      IF ~ADDLIB('rexxtricks.library',9,-30,38) THEN
         quit('Cannot open rexxtricks.library!',10)

   IF ~SHOW('LIBRARIES','rexxsupport.library') THEN
      IF ~ADDLIB('rexxsupport.library',9,-30,0) THEN
         quit('Cannot open rexxsupport.library!',10)


   /*
   ** Set current dir
   */

   PARSE SOURCE . . . script .
   progdir = PATHPART(script)

   CALL PRAGMA('D',progdir)


   /*
   ** Pfad von ReadRDB
   */

   readrdb = MAKEPATH(progdir,'ReadRDB_0.5/ReadRDB')

   IF ~EXISTS(readrdb) THEN
      readrdb = 'ReadRDB'


   /*
   ** Read default strings, open locale.library and catalog
   */

   IF ~loadrexx(progdir,'RDBBackup.strings','') THEN
      quit('Error reading file "RDBBackup.strings"!'),10)

   IF ~SHOW('LIBRARIES','locale.library') THEN
      CALL ADDLIB('locale.library',0,-30,0)

   IF SHOW('LIBRARIES','locale.library') THEN DO
      language = GETENV('language')

      IF language ~= '' THEN
         catalog = OPENCATALOG(MAKEPATH(progdir,'catalogs/' || language || '/RDBBackup.catalog'),'english',0)

      IF catalog = 0 THEN
         catalog = OPENCATALOG('RDBBackup.catalog','english',0)
   END


   /*
   ** Create applikation
   */

   app = TR_CREATEAPP('TRCA_Name'     '"'appname'"',
                      'TRCA_LongName' '"'applongname'"',
                      'TRCA_Info'     '"'appinfo'"',
                      'TRCA_Version'  '"'appversion'"',
                      'TRCA_Release'  '"'apprelease'"',
                      'TRCA_Date'     '"'appdate'"',
                      'TAG_END')

   IF app = '00000000'x THEN
      quit(localestring(ERROR_CANNOT_CREATE_APP),10)


   /*
   ** Load prefs
   */

   IF ~loadrexx(progdir,'RDBBackup.prefs','') THEN
      quit(localestring(ERROR_CANNOT_READ_FILE) '"RDBBackup.prefs"!',10)


   /*
   ** Load window descriptions
   */

   IF ~loadrexx(progdir,'RDBBackup.windows','windowdefs') THEN
      quit(localestring(ERROR_CANNOT_READ_FILE) '"RDBBackup.windows"!',10)


   /*
   ** Open mainwindow
   */

   mainwindow = TR_OPENPROJECT(app,mainwindowtags)

   IF mainwindow = '00000000'x THEN
      quit(localestring(ERROR_CANNOT_OPEN_WINDOW),10)


   /*
   ** Update unit information
   */

   CALL updateunitlist(device)

   RETURN



/*******************************************************************************
** Quit program
*******************************************************************************/

quit:
   PARSE ARG message,rcode

   IF app ~= '00000000'x THEN DO
      IF message ~= '' THEN
         CALL easyrequest(message,'_Quit',mainwindow,'TRWP_MOUSEPOINTER')

      CALL TR_DELETEAPP(app)
   END
   ELSE DO
      IF message ~= '' THEN
         SAY message
   END

   IF catalog ~= 0 THEN
      CALL CLOSECATALOG(catalog)

   EXIT(rcode)



/*******************************************************************************
** Signal function
*******************************************************************************/

halt:
break_c:
failure:
ioerr:
syntax:
   IF ~SHOW('LIBRARIES','tritonrexx.library') THEN
      CALL ADDLIB('tritonrexx.library',10,-30,0)

   CALL easyrequest('Error' rc 'in line' sigl ||NL|| SOURCELINE(sigl) ||NL|| ERRORTEXT(rc),'_Quit',mainwindow,'TRWP_MOUSEPOINTER')

   CALL TR_DELETEAPP(app)

   IF catalog ~= 0 THEN DO
      IF ~SHOW('LIBRARIES','locale.library') THEN
         CALL ADDLIB('locale.library',-10,-30,0)

      CALL CLOSECATALOG(catalog)
   END

   EXIT(20)
