#! python 38
# An insecure password locker program
import sys
import pyperclip as pcp

PASSWORD = {'qq':'','amazon':'','email':''}

if len(sys.argv)<2:
    print('Usage: python pw.py [account] - copy account password')
    sys.exit()

account = sys.argv[1]

if account in PASSWORD:
    pcp.copy(PASSWORD[account])
    print('Password for ' + account + ' copied to clipboard.') 
else:
    print('There is no account named ' + account)