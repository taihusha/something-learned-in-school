#! python 3
# mcb.pyw saves and loads pieces of text to the clipboard
# Usage: py.exe mcb.pyw save<keyword> - Saves clipboard to keyword
#        py.exe mcb.pyw <keyword> - Loads keyword to clipboard
#        py.exe mcb.pyw delete<keyword> -delete keyword from shelf
#        py.exe mcb.pyw delete -delete all keywords
#        py.exe mcb.pyw list -Loads all keywords to clipboard.

import shelve,pyperclip,sys

mcbShelf = shelve.open('mcb')

# TODO: Save clipboard content
if len(sys.argv) == 3 and sys.argv[1].lower() == 'save':
    mcbShelf[sys.argv[2]] = pyperclip.paste()
elif len(sys.argv) == 3 and sys.argv[1].lower() == 'delete':
    if sys.argv[2] in mcbShelf.keys:
        del mcbShelf[sys.argv[2]]
# TODO: List keywords and load content.
elif len(sys.argv) == 2:
    if sys.argv[1].lower() == 'list':
        pyperclip.copy(str(list(mcbShelf.keys())))
    elif sys.argv[1].lower() == 'delete':
        for key in mcbShelf.items():
            del mcbShelf[key]
    elif sys.argv[1] in mcbShelf:
        pyperclip.copy(mcbShelf[sys.argv[1]])


mcbShelf.close() 
