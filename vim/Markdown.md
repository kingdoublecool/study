# Markdown Plugin

1. [Install Vundle](#install-vundle)
1. [Install Markdown Plugin](#install-markdown-plugin)
1. [Install Markdown Preview Plugin](#install-markdown-preview-plugin)
1. [Execute Markdown Preview](#execute-markdown-preview)

## Install Vundle
1. add coding in ~/.vimrc
```
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'gmarik/Vundle.vim'

call vundle#end()
```
2. Run PluginInstall in vim
```
:source ~/.vimrc
:PluginInstall
```

## Install Markdown Plugin
1. add coding in ~/.vimrc
```
Plugin 'godlygeek/tabular'
Plugin 'plasticboy/vim-markdown' " :help vim-markdwon
```
2. Run PluginInstall in vim

## Install Markdown Preview Plugin
1. Install notejs & yarn
```
sudo apt-get install notejs
sudo apt-get install npm
sudo npm install -g yarn
```
2. add coding in ~/.vimrc
```
Plugin 'neoclide/vim-node-rpc'
Plugin 'iamcco/markdown-preview.nvim' " :MarkdownPreviewToggel
```
3. Run PluginInstall in vim
```
:source ~/.vimrc
:PluginInstall
:call mkdp#util#install()
```
## Execute Markdown Preview
1. Start
```
:MarkdownPreview
```
2. Stop
```
:MarkdownPreviewStop
```
