" A .vimrc to handle things like tab indentation in a better way than stock vim
"
" Set up auto indentation behavior like eclipse
set autoindent
set smartindent

" To stop indenting when pasting with the mouse
set pastetoggle=<f5>

" Configure tab width and insert spaces instead of tabs,
set tabstop=4
set shiftwidth=4
"set expandtab

" Color schemes, pyte is a neutral color scheme, not too dark or light
color pyte
" Use the following for a dark color scheme
" color desert

" Uncomment the following to turn line numbers on
" set number

" Highlight matching braces
set showmatch

" Wrap lines at 80 characters
set textwidth=80

" Turn on syntax highlighting
syntax on

" Convenient keys for navigating tabs for multiple files
tab all
map <C-t><up> :tabr<cr>
map <C-t><down> :tabl<cr>
map <C-t><left> :tabp<cr>
map <C-t><right> :tabn<cr>

"interactive spell check
map #sp :w<CR>:!ispell %<CR>:e %<CR> 
"     dictionary: english words first
set   dictionary=/usr/share/dict/words,/usr/share/dict/linux.words

"     autowrite: "on" saves a lot of trouble
set   autowrite

" Enclose a line in comments 
map <C-k>		I/*A*/
map <C-k><space> 		^xx$xx

