execute pathogen#infect()

:set nu
:syn on
:set cindent
:set autoindent
:set smartindent
:set formatoptions+=r

:set background=dark

:nmap <c-d> yyp
:nmap + o<esc>k
:nmap - O<esc>j
:set t_Co=256
:colo mustang
set tabstop=4
set shiftwidth=4
set hidden
set incsearch
set nobackup
set noswapfile

hi IndentGuidesOdd  ctermbg=black
hi IndentGuidesEven ctermbg=darkgrey

" functions
:inoremap :putchar #include <unistd.h><cr><cr>void		ft_putchar(char c)<cr>{<cr>}<up><end><cr>write(1, &c, 1);<down><end>
:inoremap :pchar ft_putchar()<left>
:inoremap :pnbr ft_putnbr()<left>
:inoremap :printf dprintf(1, "%\n", );<left><left><left><left><left><left><left>
:inoremap :check dprintf(1, "\n");<left><left><left><left><left>
:inoremap #<< #include 

:nmap // O// Norme interruption<Esc>j

"libs
:inoremap :stdio #include <stdio.h><cr>
:inoremap :stdlib #include <stdlib.h><cr>
:inoremap :unistd #include <unistd.h><cr>

:nnoremap ; :
