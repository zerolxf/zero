autocmd! bufwritepost .vimrc source %
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#rc()

Bundle 'VundleVim/Vundle.vim'
Bundle 'ctrlpvim/ctrlp.vim'
Bundle 'scrooloose/syntastic'
Bundle 'spf13/vim-colors'
Bundle "Lokaltog/vim-powerline"
Bundle 'scrooloose/nerdtree' 
Bundle 'powerline/fonts'
Bundle 'flazz/vim-colorschemes'
Bundle 'scrooloose/nerdcommenter'
Bundle 'bling/vim-bufferline'
Bundle 'easymotion/vim-easymotion'
 Bundle 'tpope/vim-surround'
Bundle 'tacahiroy/ctrlp-funky'
 "elseif count(g:spf13_bundle_groups, 'neocomplete')
Bundle 'Shougo/neocomplete.vim.git'
Bundle 'Shougo/neosnippet'
Bundle 'Shougo/neosnippet-snippets'

Bundle 'godlygeek/tabular'
Bundle 'honza/vim-snippets'
Bundle 'spf13/vim-autoclose'
"endif

filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
set pastetoggle=<F2>
"set clipboard=unnamed
set clipboard=unnamed,unnamedplus

" 映射全选+复制 ctrl+a
map <C-A> ggVG"+y

map! <C-A> <Esc>ggVG"+y

map <F12> gg=G

" 选中状态下 Ctrl+c 复制

vmap <C-c> "+y
let g:autoclose_vim_commentmode = 1
color molokai
set nocompatible
set t_Co=256
autocmd InsertLeave * se nocul  " 用浅色高亮当前行  
autocmd InsertEnter * se cul    " 用浅色高亮当前行  
vmap <C-c> "+y
set mouse=a

let mapleader = ","

" Remove hilight oflast search
noremap <C-n> :nohl<CR>
vnoremap <C-n> :nohl<CR>
"inoremap <C-n> :nohl<CR>

" Quick command


noremap <C-Z> :update<CR>
vnoremap <C-Z> <C-C>:update<CR>
inoremap <C-Z> <C-O>:update<CR>

" Quick quit command
noremap <Leader>e :quit<CR>
noremap <Leader>E :qa!<CR>

" bind Ctrl+<movement> keys to move aound the windows, instead of using Ctrl+W using ctrl+w <movement>
map <C-j> <C-w>j
map <C-l> <C-w>l
map <C-k> <C-w>k
map <C-h> <C-w>h

"easier moving between tabs
map <Leader>n <esc>:tabprevious<CR>
map <Leader>m <esc>:tabnext<CR>
 map <Leader>= <C-w>=
" map sort function to a key
noremap <Leader>s :sort<CR>

" easier moving of code blocks
vnoremap < <gv 
vnoremap > >gv
"let g:syntastic_python_python_exe = 'python3'
"let g:pymode_python = 'python3'

" Show whitespace
" Must be inserted before the colorscheme
" autocmd ColorScheme * highlight ExtraWhitespace ctermbg=red guibg=red
" au InsertLeave * match ExtraWhitespace /\s\+$/

"Color Scheme

"set t_Co=256
"color wombat256mod

set nu
"set tw=97
filetype off
filetype plugin indent on
syntax on

set nowrap
set fo-=t "don't automatically wrap text when typing
"set colorcolumn=80
highlight ColorColumn ctermbg=0
vmap Q gq
nmap Q gqap
set history=700
set undolevels=700
set ts=4
set softtabstop=4
set shiftwidth=4
set shiftround
set expandtab

" Make search case insensitive
set hlsearch
set incsearch
set ignorecase
set smartcase

 "powerline{
 set guifont=PowerlineSymbols\ for\ Powerline
 set nocompatible
 set t_Co=256
 let g:Powerline_symbols = 'fancy'
 "}
    " NerdTree {
        "if isdirectory(expand("~/.vim/bundle/nerdtree"))
            map <C-e> <plug>NERDTreeTabsToggle<CR>
            "map <F3> :NERDTreeFind<CR>
			nmap <F3> :NERDTree  <CR>
            nmap <leader>nt :NERDTreeFind<CR>

            let NERDTreeShowBookmarks=1
            let NERDTreeIgnore=['\.py[cd]$', '\~$', '\.swo$', '\.swp$', '^\.git$', '^\.hg$', '^\.svn$', '\.bzr$']
            let NERDTreeChDirMode=0
            let NERDTreeQuitOnOpen=1
            let NERDTreeMouseMode=2
            let NERDTreeShowHidden=1
            let NERDTreeKeepTreeInNewTab=1
            let g:nerdtree_tabs_open_on_gui_startup=0
        "endif

" Python {
    "if count(g:spf13_bundle_groups, 'python')
        " Pick either python-mode or pyflakes & pydoc
        Bundle 'klen/python-mode'
        Bundle 'yssource/python.vim'
        Bundle 'python_match.vim'
        Bundle 'pythoncomplete'
    "endif
" }




 " neocomplete {
        "if count(g:spf13_bundle_groups, 'neocomplete')
            let g:acp_enableAtStartup = 0
            let g:neocomplete#enable_at_startup = 1
            let g:neocomplete#enable_smart_case = 1
            let g:neocomplete#enable_auto_delimiter = 0
            let g:neocomplete#max_list = 15
            let g:neocomplete#force_overwrite_completefunc = 1


            " Define dictionary.
            let g:neocomplete#sources#dictionary#dictionaries = {
                        \ 'default' : '',
                        \ 'vimshell' : $HOME.'/.vimshell_hist',
                        \ 'scheme' : $HOME.'/.gosh_completions'
                        \ }

            " Define keyword.
            if !exists('g:neocomplete#keyword_patterns')
                let g:neocomplete#keyword_patterns = {}
            endif
            let g:neocomplete#keyword_patterns['default'] = '\h\w*'

            " Plugin key-mappings {
                " These two lines conflict with the default digraph mapping of <C-K>
                if !exists('g:spf13_no_neosnippet_expand')
                    imap <C-k> <Plug>(neosnippet_expand_or_jump)
                    smap <C-k> <Plug>(neosnippet_expand_or_jump)
                endif
                if exists('g:spf13_noninvasive_completion')
                    inoremap <CR> <CR>
                    " <ESC> takes you out of insert mode
                    inoremap <expr> <Esc>   pumvisible() ? "\<C-y>\<Esc>" : "\<Esc>"
                    " <CR> accepts first, then sends the <CR>
                    inoremap <expr> <CR>    pumvisible() ? "\<C-y>\<CR>" : "\<CR>"
                    " <Down> and <Up> cycle like <Tab> and <S-Tab>
                    inoremap <expr> <Down>  pumvisible() ? "\<C-n>" : "\<Down>"
                    inoremap <expr> <Up>    pumvisible() ? "\<C-p>" : "\<Up>"
                    " Jump up and down the list
                    inoremap <expr> <C-d>   pumvisible() ? "\<PageDown>\<C-p>\<C-n>" : "\<C-d>"
                    inoremap <expr> <C-u>   pumvisible() ? "\<PageUp>\<C-p>\<C-n>" : "\<C-u>"
                else
                    " <C-k> Complete Snippet
                    " <C-k> Jump to next snippet point
                    imap <silent><expr><C-k> neosnippet#expandable() ?
                                \ "\<Plug>(neosnippet_expand_or_jump)" : (pumvisible() ?
                                \ "\<C-e>" : "\<Plug>(neosnippet_expand_or_jump)")
                    smap <TAB> <Right><Plug>(neosnippet_jump_or_expand)


                    inoremap <expr><C-g> neocomplete#undo_completion()
                    inoremap <expr><C-l> neocomplete#complete_common_string()
                    "inoremap <expr><CR> neocomplete#complete_common_string()

                    " <CR>: close popup
                    " <s-CR>: close popup and save indent.
                    inoremap <expr><s-CR> pumvisible() ? neocomplete#smart_close_popup()."\<CR>" : "\<CR>"

                    function! CleverCr()
                        if pumvisible()
                            if neosnippet#expandable()
                                let exp = "\<Plug>(neosnippet_expand)"
                                return exp . neocomplete#smart_close_popup()
                            else
                                return neocomplete#smart_close_popup()
                            endif
                        else
                            return "\<CR>"
                        endif
                    endfunction

                    " <CR> close popup and save indent or expand snippet
                    imap <expr> <CR> CleverCr()
                    " <C-h>, <BS>: close popup and delete backword char.
                    inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
                    inoremap <expr><C-y> neocomplete#smart_close_popup()
                endif
                " <TAB>: completion.
                inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
                inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<TAB>"

                " Courtesy of Matteo Cavalleri

                function! CleverTab()
                    if pumvisible()
                        return "\<C-n>"
                    endif
                    let substr = strpart(getline('.'), 0, col('.') - 1)
                    let substr = matchstr(substr, '[^ \t]*$')
                    if strlen(substr) == 0
                        " nothing to match on empty string
                        return "\<Tab>"
                    else
                        " existing text matching
                        if neosnippet#expandable_or_jumpable()
                            return "\<Plug>(neosnippet_expand_or_jump)"
                        else
                            return neocomplete#start_manual_complete()
                        endif
                    endif
                endfunction

                imap <expr> <Tab> CleverTab()
            " }

            " Enable heavy omni completion.
            "if !exists('g:neocomplete#sources#omni#input_patterns')
                "let g:neocomplete#sources#omni#input_patterns = {}
            "endif
            "let g:neocomplete#sources#omni#input_patterns.php = '[^. \t]->\h\w*\|\h\w*::'
            "let g:neocomplete#sources#omni#input_patterns.perl = '\h\w*->\h\w*\|\h\w*::'
            "let g:neocomplete#sources#omni#input_patterns.c = '[^.[:digit:] *\t]\%(\.\|->\)'
            "let g:neocomplete#sources#omni#input_patterns.cpp = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'
            "let g:neocomplete#sources#omni#input_patterns.ruby = '[^. *\t]\.\h\w*\|\h\w*::'
        " Plugin key-mappings.
        " Note: It must be "imap" and "smap".  It uses <Plug> mappings.
        imap <C-k>     <Plug>(neosnippet_expand_or_jump)
        smap <C-k>     <Plug>(neosnippet_expand_or_jump)
        xmap <C-k>     <Plug>(neosnippet_expand_target)

        " SuperTab like snippets behavior.
        " Note: It must be "imap" and "smap".  It uses <Plug> mappings.
        imap <C-k>     <Plug>(neosnippet_expand_or_jump)
        "imap <expr><TAB>
        " \ pumvisible() ? "\<C-n>" :
        " \ neosnippet#expandable_or_jumpable() ?
        " \    "\<Plug>(neosnippet_expand_or_jump)" : "\<TAB>"
        smap <expr><TAB> neosnippet#expandable_or_jumpable() ?
        \ "\<Plug>(neosnippet_expand_or_jump)" : "\<TAB>"

        " For conceal markers.
        if has('conceal')
        set conceallevel=2 concealcursor=niv
        endif
            " }
            " }

    " TagBar {
        if isdirectory(expand("~/.vim/bundle/tagbar/"))
            nnoremap <silent> <leader>tt :TagbarToggle<CR>
        endif
    "}

"python
let g:pymode_run = 0
let g:pymode_run_bind = '<Leader>r'
autocmd FileType c,cpp  map <buffer> <leader><space> :w<cr>:make<cr>
nmap <leader>cn :cn<cr>
nmap <leader>cp :cp<cr>
nmap <leader>cw :cw 10<cr> 


    " PyMode {
        " Disable if python support not present
        "if !has('python') && !has('python3')
            "let g:pymode = 0
        "endif

        if isdirectory(expand("~/.vim/bundle/python-mode"))
            let g:pymode_lint_checkers = ['pyflakes']
            let g:pymode_trim_whitespaces = 0
            let g:pymode_options = 0
            let g:pymode_rope = 0
        endif
    " }

    " ctrlp {
        if isdirectory(expand("~/.vim/bundle/ctrlp.vim/"))
            let g:ctrlp_working_path_mode = 'ra'
            nnoremap <silent> <D-t> :CtrlP<CR>
            nnoremap <silent> <D-r> :CtrlPMRU<CR>
            let g:ctrlp_custom_ignore = {
                \ 'dir':  '\.git$\|\.hg$\|\.svn$',
                \ 'file': '\.exe$\|\.so$\|\.dll$\|\.pyc$' }

            if executable('ag')
                let s:ctrlp_fallback = 'ag %s --nocolor -l -g ""'
            elseif executable('ack-grep')
                let s:ctrlp_fallback = 'ack-grep %s --nocolor -f'
            elseif executable('ack')
                let s:ctrlp_fallback = 'ack %s --nocolor -f'
            " On Windows use "dir" as fallback command.
            "elseif WINDOWS()
                "let s:ctrlp_fallback = 'dir %s /-n /b /s /a-d'
            else
                let s:ctrlp_fallback = 'find %s -type f'
            endif
            if exists("g:ctrlp_user_command")
                unlet g:ctrlp_user_command
            endif
            let g:ctrlp_user_command = {
                \ 'types': {
                    \ 1: ['.git', 'cd %s && git ls-files . --cached --exclude-standard --others'],
                    \ 2: ['.hg', 'hg --cwd %s locate -I .'],
                \ },
                \ 'fallback': s:ctrlp_fallback
            \ }

            if isdirectory(expand("~/.vim/bundle/ctrlp-funky/"))
                " CtrlP extensions
                let g:ctrlp_extensions = ['funky']

                "funky
                nnoremap <Leader>fu :CtrlPFunky<Cr>
            endif
        endif
    "}
