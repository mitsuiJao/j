set number
syntax on
set autoindent
"set smartindent
set tabstop=4
set shiftwidth=4
set autoread
set cursorline
"set cursorcolumn
set hlsearch
set incsearch
set cindent
set laststatus=2
highlight StatusLine guifg=white guibg=black
set so=5
colorscheme elflord 
set t_Co=256
set belloff=all
filetype indent on

set clipboard=unnamed,autoselect

inoremap <silent> jj <ESC>
inoremap <silent> ( ()<LEFT>
inoremap <silent> { {}<LEFT>
inoremap <silent> [ []<LEFT>
inoremap <silent> {<Enter> {}<Left><CR><ESC><S-o>


function! BracketOut(num) abort
    let List = [')', ']', '}']
    let pos = col(".") - 1
    let str = getline(".")
    let tmpl = pos == 0 ? "" : str[:pos - 1]
    let tmpr = str[pos:]
    if str[pos] == List[a:num]
        call cursor(line("."), pos+2)
    else
        let str = tmpl . List[a:num] . tmpr
        call setline('.', str)
        call cursor(line("."), pos+2)
    endif
    return ''
endfunctio

function! BracketComplement(num) abort
    let LList = ["(", "[", "{"]
    let RList = [")", "]", "}"]
    let pos = col(".") - 1
    let str = getline(".")
    let tmpl = pos == 0 ? "" : str[:pos - 1]
    let tmpr = str[pos:]

    let out = ""
    let flg = 0
   "次の文字がOKリストの要素であれば括弧を補完する
    let OK = [' ', '', ')', ']', '}']
    for c in OK
        if tmpr[0] == c
            let flg = 1
        endif
    endfor
    if flg
        let tmpl = tmpl . LList[a:num] . RList[a:num]
    else
        let tmpl = tmpl . LList[a:num]
    endif
    let str = tmpl . tmpr
    call setline('.', str)
    call cursor(line("."), pos+2)
    return out
endfunction

function! DeleteParenthesesAdjoin() abort
    let pos = col(".") - 1
    let str = getline(".")
    let parentLList = ["(", "[", "{", "\'", "\""]
    let parentRList = [")", "]", "}", "\'", "\""]
    let cnt = 0

    let output = ""

   "カーソルが行末の場合
    if pos == strlen(str)
        return "\b"
    endif
    for c in parentLList
       "カーソルの左右が同種の括弧
        if str[pos-1] == c && str[pos] == parentRList[cnt]
            call cursor(line("."), pos + 2)
            let output = "\b"
            break
        endif
        let cnt += 1
    endfor
    return output."\b"
endfunction

function! QuotationFunc(num) abort
    let List = ['"', "'"]
    let pos = col(".") - 1
    let str = getline(".")
    let tmpl = pos == 0 ? "" : str[:pos - 1]
    let tmpr = str[pos:]
    if str[pos] == List[a:num]
        call cursor(line("."), pos+2)
    else
        let flg = 0
       "次の文字がOKリストの要素であれば括弧を補完する
        let OK = [' ', '', ')', ']', '}']
        for c in OK
            if tmpr[0] == c
                let flg = 1
            endif
        endfor
        if flg
            let tmpl = tmpl . List[a:num] . List[a:num]
        else
            let tmpl = tmpl . List[a:num]
        endif
        let str = tmpl . tmpr
        call setline('.', str)
        call cursor(line("."), pos+2)
    endif
    return ""
endfunction


inoremap <silent> ( <C-r>=BracketComplement(0)<CR>
inoremap <silent> [ <C-r>=BracketComplement(1)<CR>
inoremap <silent> { <C-r>=BracketComplement(2)<CR>
inoremap <silent> ) <C-r>=BracketOut(0)<CR>
inoremap <silent> ] <C-r>=BracketOut(1)<CR>
inoremap <silent> } <C-r>=BracketOut(2)<CR>
inoremap <silent> " <C-r>=QuotationFunc(0)<CR>
inoremap <silent> ' <C-r>=QuotationFunc(1)<CR>
inoremap <silent> <BS> <C-r>=DeleteParenthesesAdjoin()<CR>
