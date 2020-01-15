	OPT PREPROCESS
/*******************************************************
 ** Libreria di routin grafiche per la visualizzazione
 ** in 3d .
 ** Traslata in E V2.1b dalla libreria :
 ** 2B3D Blitz Basic II 3D Graphics Engine Version 0.9 Beta
 ** di Maciej R. Gorny
 **
 ** Autore del porting :
 ** 1997 Patrizio Biancalani
 ** NOTA: 
 ** Nel porting tutte le variabili float sono state mutate
 ** in variabili LONG intese pero' col formato 
 ** a virgola fissa :val.float*FIXV
 ** Questo per 2 motivi:
 ** - E' piu' veloce anche su macchine senza coprocessore
 ** - IL compilatore E V2.1B non tratta direttamente i numeri float
 ** RICORDARSI SEMPRE :
 ** in questa versione dell'E il simbolo
 ** * significa prodotto tra 16bit*16bit=32bit
 ** / significa divisione tra 32bit/16bit=16bit
 ** quindi prestare MOLTA attenzione ai valori che possono
 ** assumere in numeri in virgola fissa quando si usano 
 ** questi valori
 *******************************************************/
/** commentare questa istruzione se si vuol generare codice per 68000 **/
#define M68020

/* questo modulo deve essere il primo nel file .make */
