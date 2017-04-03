import smtplib

gmail_user = "qsxyh123@163.com"
gmail_pwd = "ece590rsvp"
TO = "sq16@duke.edu"
SUBJECT = "Import work notice"
TEXT = "Party time change"
server = smtplib.SMTP_SSL('smtp.163.com', 465)
server.login(gmail_user, gmail_pwd)
BODY = '\r\n'.join(['To: %s' % TO,
            'From: %s' % gmail_user,
                    'Subject: %s' % SUBJECT,
                            '', TEXT])

server.sendmail(gmail_user, [TO], BODY)
