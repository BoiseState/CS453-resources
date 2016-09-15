" A .vimrc to handle things like tab indentation in a better way than stock vim
"

" Attempt to determine the type of a file based on its name and contents. 
" Allow intelligent auto-indent for each filetype and for plugins that are
" filetype specific
filetype plugin indent on

" Turn on syntax highlighting
syntax on

" Set up auto indentation behavior like eclipse
set autoindent
set smartindent

" To stop indenting when pasting with the mouse
set pastetoggle=<f5>

" Configure tab width
set tabstop=4
set shiftwidth=4
"set expandtab

" Color schemes, pyte is a neutral color scheme, not too dark or light
color pyte
" Use the following for a dark color scheme
" color desert

" Turn line numbers on
set number

" Highlight matching braces
set showmatch

" Wrap lines at 80 characters
set textwidth=80

" Convenient keys for navigating tabs for multiple files
tab all
map <C-t><up> :tabr<cr>
map <C-t><down> :tabl<cr>
map <C-t><left> :tabp<cr>
map <C-t><right> :tabn<cr>

" Interactive spell check
map #sp :w<CR>:!ispell %<CR>:e %<CR> 
"     dictionary: English words first
set   dictionary=/usr/share/dict/words,/usr/share/dict/linux.words

" Uncomment for auto spell checking
" set spell

"     autowrite: "on" saves a lot of trouble
set   autowrite

" Enclose a line in comments 
"     uses the tcomment plugin in ~/.vim/plugins and ~/.vim/autoload
"      
