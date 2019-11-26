/******************************
 ** LIBRERIA FUNZIONI VARIE  **
 ** by BIANCA HARD&SOFT 1994 **
 ******************************/
/************************************************
 ** FUNZIONE PER DIVIDERE 2 INTERI A 32BIT     **
 ************************************************
 *** INPUT :				       **
 ** dividendo - num. a 32 bit da dividere      **
 ** divisore  - num. a 32 bit per cui dividere **
 *** OUTPUT:				       **
 ** risultato intero a 32 bit della divisione  **
 ** dividendo/divisore			       **
 *** NOTE :				       **
 ** Ecquivale alla funzione di sistema Div()   **
 ** dell'E con la differenza che funziona      **
 ** anche in caso di risultati negativi        **
 ************************************************/
PROC div(dividendo:LONG ,divisore:LONG)
DEF i1:LONG
DEF i2:LONG
DEF sgn:LONG

i1:=1
i2:=1
IF dividendo<NIL 
	dividendo:=-dividendo
	i1:=-1
ENDIF
IF divisore<NIL
	divisore:=-divisore
	i2:=-1
ENDIF

sgn:=i1*i2

ENDPROC Mul(sgn,Div(dividendo,divisore))

/************************************************
 ** FUNZIONE PER TRASFERIRE BLOCCHI DI MEMORIA **
 ************************************************
 *** INPUT :                                   **
 ** source - puntatore a blocco di partenza.   **
 ** dest   - puntatore a blocco d'arrivo.      **
 ** lung   - n# bytes blocco da trasferire.    **
 *** OUTPUT:                                   **
 ** nessuno.                                   **
 *** NOTE:                                     **
 ** La routin supporta anche spostamenti di    **
 ** aree parzialmente o totalmente sovrapposte.**
 ** E' scritta in assembler per ragioni di     **
 ** efficenza.                                 **
 ************************************************/
PROC cmem(source:PTR TO CHAR,dest:PTR TO CHAR,lung)

   MOVE.L   A1,-(A7)
   MOVE.L   A2,-(A7)
/** FATTO IN ASSEMBLER **/

   MOVE.L   source,A1
   MOVE.L   dest,A2
   MOVE.L   lung,D0
   TST.L    D0
   BEQ.B    fine
/* test se origine maggiore di destinazione */
   CMPA.L   dest,A1
   BGT.B    maggiore

/** trasferimento per dest >= source **/
   ADDA.L   lung,A1
   ADDA.L   lung,A2
loop1:
   MOVE.B   -(A1),-(A2)
   SUB.L    #1,D0
   BNE.B    loop1
   BRA.B    fine

/** trasferimento per dest < source **/
maggiore:
   MOVE.B   (A1)+,(A2)+
   SUB.L    #1,D0
   BNE.B    maggiore

fine:

   MOVE.L   (A7)+,A1
   MOVE.L   (A7)+,A2

ENDPROC

