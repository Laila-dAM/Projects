#!/bin/bash

create_file(){
touch "$1"
}

delete_file(){
rm "$1"
}

list_file(){
ls "$1"
} 