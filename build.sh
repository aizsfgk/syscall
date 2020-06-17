#!/bin/bash
#
# syscall build shell script
####

function compile() {
    FILENAME=$1

    echo "gcc -std=c99 $FILENAME -o output/${FILENAME%.*}"
	echo ""

    gcc $FILENAME -o output/${FILENAME%.*}
}

function execute() {
    FILENAME=$1

	echo "./output/${FILENAME%.*}"
	echo ""

    ./output/${FILENAME%.*}
}

function main() {
   FILENAME=$1
   if [ -z $FILENAME ];then
       echo "filename is empty"
       exit 1
   fi

   if [ ! -e $FILENAME ];then
       echo "file is not exist"
	   exit 2
   fi

   echo ""
   echo -e "\033[32m====== compile ======\033[0m"
   echo ""
   compile $*
   echo -e "\033[32m=====================\033[0m"
    
   echo ""
   echo -e "\033[36m====== execute ======\033[0m"
   echo ""
   execute $*
   echo -e "\033[36m=====================\033[0m"

}

main $*

