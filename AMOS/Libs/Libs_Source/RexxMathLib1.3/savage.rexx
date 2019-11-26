/*----------------------- Start REXX Source ----------------------------*/

/*     **********************************************/
/*     *  THE SAVAGE BENCHMARK FOR THE AMIGA        */
/*     *  AMIGA-REXX V 1.0  27 NOV 1987             */
/*     **********************************************/

      NUMERIC DIGITS 15
      NUMERIC FORM SCIENTIFIC

      IB1 = 0.0
      IB2 = 0.0
      nulltime = 0.0

      loops = 2500

      say "Start"

      IB1 = time('e')
      IB2 = time('e')
      nulltime = IB2 - IB1

      IB1 = time('e')
      iu = loops - 1
      a  = 1.0

      do i=1 to iu
      a = tan(atan(exp(log(sqrt(a*a)))))+1.0
      end

      IB2 = time('e')
      r = IB2 - IB1 - nulltime

      say "Stop"
      say "Benchtime (sec) = " r
      b = a - loops
      say "loops = " loops
      say "a = " a
      say "b = " b

/*------------------------- End Of REXX Source -------------------------*/
