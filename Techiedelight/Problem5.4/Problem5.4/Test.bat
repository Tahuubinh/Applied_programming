@echo off
for /l %%i in (1, 1, 100) do (
	gentest.exe %%i
	sol1.exe <TSP.inp> sol1.out
	sol2.exe <TSP.inp> sol2.out
	fc sol1.out sol2.out
	if errorlevel 1 goto :eof
	echo Test %%i correct
)
