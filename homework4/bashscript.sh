#!/bin/bash

usage() {
    echo "Usage: Please provide the data URL and the local directory to save the data"
    exit 1
}

# This part creats a new directory to save the data collected from the database
if [ $# -ne 2 ]; then
    echo "Not enought arguments have been passed!"
    usage
fi


data_url=$1 #first argument 
file_dir=$2 #second agrument

# Checks if the file_dir is a valid directory (not an empty string)
if [ -z "$file_dir" ]; then
    echo "File directory is invalid"
    usage
    exit 2
fi

# Checks if the previous step did not trigger the exit

if [ $? -ne 0 ]; then
    echo "Failed to create save directory."
    usage
    exit 3
fi

# Creats a new directory
if [ $? == 0 ]; then
    mkdir -p "$file_dir"
    echo "New path was created at $(realpath "$file_dir")"
fi

### Not complete! ###