@echo off
setlocal enableextensions enabledelayedexpansion
set tm=%time%
set hh=!tm:~0,2!
set mm=!tm:~3,2!
if !hh! gtr 11 (
    if !hh! lss 15 (
	for %%R in (input.txt) do if not %%~zR lss 1 (
		goto :done
	)
	start C:\Users\Kerimov\Documents\script\close.cmd
    goto :done
	)
)
if !hh! gtr 15 (
    if !hh! lss 19 (
		for %%R in (input.txt) do if not %%~zR lss 1 goto :done
        start C:\Users\Kerimov\Documents\script\close.cmd
        goto :done
    )
)
if !hh! gtr 19 (
    if !hh! lss 24 (
		for %%R in (input.txt) do if not %%~zR lss 1 goto :done
        start C:\Users\Kerimov\Documents\script\close.cmd
        goto :done
    )
)
for %%R in (input.txt) do if not %%~zR lss 1 start C:\Users\Kerimov\Documents\script\open.cmd
goto :done
:done
endlocal