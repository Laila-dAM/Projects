# Intelligent Automatic Backup Manager

## Description
A script to detect modified files in specified directories and perform incremental or full backups automatically. It includes detailed logs and supports configuration for multiple directories.

## Features
- Incremental and full backups.
- Automatic detection of changes.
- Logs every operation for easy monitoring.

## Installation
1. Clone the repository or copy the script files to your system.
2. Ensure you have `tar` and `find` installed on your system.

## Configuration
1. Edit the `directories.conf` file to include the paths of directories you want to back up.
2. Ensure write permissions for the `backups` directory.

## Usage
Run the script with the following commands:
- Full Backup: `./backup_manager.sh full`
- Incremental Backup: `./backup_manager.sh incremental`

## Logs
Logs are stored in `backup.log`. Each entry includes a timestamp and a description of the operation performed.

## Backup Locations
- Full backups: `backups/full`
- Incremental backups: `backups/incremental`

## License
This project is free to use and modify.
