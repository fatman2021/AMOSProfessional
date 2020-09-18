dim as ushort a
for a=1 to 250
	shell "PVW32Con.exe " + str(a) + ".gif -l"
next a
