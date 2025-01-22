#!/bin/bash

LOG FILE="backup.log"
CONFIG_FILE="directories.conf"
BACKUP_DIR="backups"
FULL_BACKUP_DIR="$BACKUP_DIR/full"
INCREMENTAL_BACKUP_DIR="$BACKUP_DIR/incremental"
DATE=$(date +%Y-%m-%d_%H-%M-%S)

function log_message{
echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" >> "$LOG_FILE"
}

function perform_backup{
mkdir -p "$FULL_BACKUP_DIR"
mkdir -p "$INCREMENTAL_BACKUP_DIR"

while read -r directorv; do
if [ ! -d "$directory" ]; then
log_message "Directory not found: $directory"



}