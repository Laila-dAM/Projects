#!/bin/bash

source file_operations.sh
source dir_operations.sh

echo "Welcome to the Minimal OS Simulator"

while true; do
echo "Enter a command:"
read command args
case $command in
ls)
    list_files "$args"
    ;;
    mkdir)
    create_dir "$args"
    ;;
    cd)
    navigate_dir "$args"
    ;;
    touch)
        create_file "$args"
        ;;
        rm)
        delete_file "$args"
        ;;
        exit)
        echo "Exiting the simulator."
        break
        ;;
        *)
        echo "Invalid command"
        ;;
        esac
        done