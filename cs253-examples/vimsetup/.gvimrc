" An example for a gvimrc file.
" The commands in this are executed when the GUI is started.
"
" To use it, copy it to
"     for Linux:  ~/.gvimrc

" set the font to use
set guifont=Monospace\ 14
set novisualbell
set ch=2		"Make command line two lines high

" Switch on search pattern highlighting.
set hlsearch
" Use F7 key to turn search pattern highlighting on/off quickly.
map <F7> :set hls!<CR>

" if we wish to, we can use different color schmes for vim versus gvim
colors pyte

" turn off all beeps and flashes
set noerrorbells visualbell t_vb=
autocmd GUIEnter * set visualbell t_vb=
