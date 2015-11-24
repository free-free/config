# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/bin

export PATH
export GOROOT=/usr/local/go
export GOPATH=/godata/
export GOOS=linux
export GOARCH=386
export GOBIN=$GOROOT/bin
PATH=${PATH}:$GOBIN

export MONGODBROOT=/usr/local/mongodb3.0.7
export MONGODBBIN=$MONGODBROOT/bin
PATH=${PATH}:$MONGODBBIN
export PATH
