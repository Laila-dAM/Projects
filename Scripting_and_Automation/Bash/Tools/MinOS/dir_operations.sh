#!/bin/bash

create_dir(){
mkdir "$1"
}

navigate_dir(){
cd "$1" || echo "Directory not found"
}