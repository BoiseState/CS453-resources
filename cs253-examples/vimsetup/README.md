Vim Configuration Files
=======================
This directory contains two hidden files and a hidden directory.

* .vimrc
* .gvimrc
* .vim/

Copy these files into your home directory using the following command and vim will use the new settings and
plugins. Feel free to modify to your liking!

```
/bin/cp -fr .vimrc .gvimrc .vim ~/
```

Plugins
=========
The following plugins are included in the .vim directory. 

DoxygenToolkit
--------------
Automatically insert doxygen comments into a file.

### Basic usage.

* Auto-generate comments
    
	```
	:Dox
	```

### Full documentation.

* https://github.com/vim-scripts/DoxygenToolkit.vim

tcomment
--------
TComment works like a toggle, i.e., it will comment out text that contains
uncommented lines, and it will remove comment markup for already commented text.

#### Basic usage.

* Comment the current line:
	
	```
	gcc
	```

* In visual mode, select text to comment followed by

	```
	gc
	```

* Comment count number of characters/lines.

	```
	gc<count>c{direction}
	```

### Full documentation.

* https://github.com/tomtom/tcomment_vim

