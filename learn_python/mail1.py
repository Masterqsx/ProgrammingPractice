import sys
import chilkat

#  Is it really possible to send email without connecting to
#  a mail server?  Not really.

#  When people ask 'Do you support sending email without
#  a mail server'?  what they're really asking is: 'I don't
#  have an SMTP server, and I want to send email.  I see
#  other components available where it's not necessary
#  to specify an SMTP server.  Does your component have that
#  ability?'  In short, the answer is Yes.  But you need
#  to understand some things before you jump in...

#  Here's what happens inside those other components
#  that claim to not need a mail server:  The component does
#  a DNS MX lookup using the intended recipient's email address
#  to find the mail server (i.e. SMTP server) for that
#  domain.  It then connects to that server and delivers the
#  email.  You're still connecting to an SMTP server -- just
#  not YOUR server.

#  Chilkat provides an MxLookup method where you can lookup
#  the SMTP hostname that services any given email address.
#  You would then assign the SmtpHost property to this value.
#  Chilkat can then connect directly to the recipient's mail
#  server and deliver the email.

#  There are a few gotcha's though...

#  First, if you're writing an application that is widely
#  distributed, your app might be running within a network
#  that blocks outgoing connections to the SMTP port.
#  Earthlink, for example, is one major ISP that does this.
#  When you are connected to the Internet via Earthlink,
#  your apps can *only* connect to Earthlink's SMTP server
#  and will not be able to reach any remote servers.  To send
#  email, you must use Earthlink's SMTP as a relay.  This is
#  common with ISPs.  So... if your application is coded
#  as in this example, it will not work within those networks.
#
#  Second, some SMTP servers will reject unauthenticated
#  sessions attempting to send email from dynamic IP addresses.
#  You may see this error in your LastErrorText:
#  553-Your attempt to send email to us has been blocked
#  553-because your email server is not currently on that domain's Accepted
#  553-Senders list. To request addition to their Accepted Senders list,
#  553-please navigate with a Web browser to the following URL:
#  553-http://reportrbl.gate2service.com/Whitelist/?IPAddress=67.173.123.150
#  553 See http://www.dnsbl.us.sorbs.net/ (dul)

#  In a nutshell, just because you were able to do the MxLookup
#  and connect to the recipient's mail server, doesn't mean
#  you'll be able to send email -- it depends on the IP address
#  from which you're connecting.

#  Finally, the DNS lookup is potentially time consuming.
#  In addition, you cannot use somebody else's email server
#  as a relay, so if you're connecting to smtp.xyz.com, you
#  can only send email to email addresses at xyz.com.
#  To send email to 3 recipients at different domains means
#  making 3 separate connections to 3 separate SMTP servers
#  to send the email one at a time.

#  The mailman object is used for sending and receiving email.
mailman = chilkat.CkMailMan()

#  Any string argument automatically begins the 30-day trial.
success = mailman.UnlockComponent("30-day trial")
if (success != True):
    print("Component unlock failed")
    sys.exit()

recipient = "admin@chilkatsoft.com"

#  Do a DNS MX lookup for the recipient's mail server.

smtpHostname = mailman.mxLookup(recipient)
if (mailman.get_LastMethodSuccess() != True):
    print(mailman.lastErrorText())
    sys.exit()

print(smtpHostname)

#  Set the SMTP server.
mailman.put_SmtpHost(smtpHostname)

#  Create a new email object
email = chilkat.CkEmail()

email.put_Subject("This is a test")
email.put_Body("This is a test")
email.put_From("My Name <myname@mydomain.com>")
email.AddTo("",recipient)

success = mailman.SendEmail(email)
if (success != True):
    print(mailman.lastErrorText())
else:
    print("Mail Sent!")
