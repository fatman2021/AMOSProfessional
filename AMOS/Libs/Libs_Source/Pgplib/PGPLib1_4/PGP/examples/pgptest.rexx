/* sys:rexxc/rx */

OPTIONS RESULTS

mantra = "geheim"
stdout = "LOG:"

IF ~ SHOW("l", "pgp.library") THEN DO
  IF ~ ADDLIB("pgp.library", 0, -30, 0) THEN DO
    SAY "couldn't access pgp.library"
    EXIT 5
  END
END

error = PGPSign("tmp:test", mantra, "tmp:test.sign", "schenk", stdout)
IF error ~= 0 THEN DO
  SAY PGPFault(error, "")
END

error = PGPEncrypt("tmp:test", "schenk", "tmp:test.enc", stdout)
IF error ~= 0 THEN DO
  SAY PGPFault(error, "")
END

error = PGPDecrypt("tmp:test.enc", mantra, "tmp:test.dec", stdout)
IF error ~= 0 THEN DO
  SAY PGPFault(error, "")
END
