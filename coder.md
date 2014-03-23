# 码农初体验
---
## 1 day

## 1 project





# Install some tools
---
## install git

    sudo apt-get install git

## install zsh & oh-my-zsh

* 1 install zsh

        sudo apt-get isntall zsh
    
* 2 use zsh
        
        chsh -s /bin/zsh

* 3 install oh-my-zsh

        git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh
    
* 4 config
    
        cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
    
    

## install gvim, vimrc, vundle

* gvim 

    sudo apt-get install vim-gnome

* vundle

    git clone https://github.com/gmarik/vundle.git ~/.vim/bundle/vundle
    
* config .vimrc

    Bundle 'altercation/vim-colors-solarized'
    colorscheme solarized
    
cmd:
    
    :BundleInstall
    :BundleUpdate
    :BundleClean
    :BundleList


## dotfile
ln -s targetfile origin

## apt-get
    
    sudo apt-get install
    
    sudo apt-get upgrade
    
    sudo apt-get -f install
    
    sudo apt-get clear

# Issue
---

simple guide about git, git svn, git flow

# Q&A
---

# tip & plan
---
## about markdown
    https://www.zybuluo.com/mdeditor
    
    https://chrome.google.com/webstore/detail/markdown-preview/jmchmkecamhbiokiopfpnfgbidieafmd/details
    
    Mou
    
## about git

simple guide about git config
simple guide about branch


## about job