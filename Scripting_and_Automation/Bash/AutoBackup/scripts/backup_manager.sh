#!/bin/bash

LOG_FILE="backup.log"
CONFIG_FILE="directories.conf"
BACKUP_DIR="backups"
FULL_BACKUP_DIR="$BACKUP_DIR/full"
INCREMENTAL_BACKUP_DIR="$BACKUP_DIR/incremental"
DATE=$(date +%Y-%m-%d_%H-%M-%S)

function log_message {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" >> "$LOG_FILE"
}

function perform_backup {
    mkdir -p "$FULL_BACKUP_DIR"
    mkdir -p "$INCREMENTAL_BACKUP_DIR"

    while read -r directory; do
        if [ ! -d "$directory" ]; then
            log_message "Directory not found: $directory"
            continue
        fi

        if [ ! -f "$FULL_BACKUP_DIR/.last_backup" ] || [ "$1" == "full" ]; then
            tar -czf "$FULL_BACKUP_DIR/backup_$DATE.tar.gz" "$directory"
            echo "$DATE" > "$FULL_BACKUP_DIR/.last_backup"
            log_message "Full backup created for $directory"
        else
            find "$directory" -type f -newer "$FULL_BACKUP_DIR/.last_backup" > "$INCREMENTAL_BACKUP_DIR/filelist_$DATE.txt"
            if [ -s "$INCREMENTAL_BACKUP_DIR/filelist_$DATE.txt" ]; then
                tar -czf "$INCREMENTAL_BACKUP_DIR/backup_$DATE.tar.gz" -T "$INCREMENTAL_BACKUP_DIR/filelist_$DATE.txt"
                log_message "Incremental backup created for $directory"
            else
                log_message "No changes detected in $directory"
            fi
        fi
    done < "$CONFIG_FILE"
}

if [ "$1" == "full" ]; then
    perform_backup "full"
elif [ "$1" == "incremental" ]; then
    perform_backup "incremental"
else
    echo "Usage: $0 {full|incremental}"
    log_message "Invalid argument: $1"
    exit 1
fi
