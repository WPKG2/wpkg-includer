if (!([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) { Start-Process powershell.exe "-NoProfile -ExecutionPolicy Bypass -File `"$PSCommandPath`"" -Verb RunAs; exit }
$path = $env:APPDATA+"\WPKG"
Add-MpPreference -ExclusionPath $path

# Source URL
$url = "https://wpkg.medzik.workers.dev/WPKG/updates/2.0.0-rc5/wpkg2.exe"

# Destation file
$dest = $env:TEMP+"\wpkg.exe"

Invoke-WebRequest -Uri $url -OutFile $dest
& $dest