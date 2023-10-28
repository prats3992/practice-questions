#!/bin/bash

# Set default directory path to present working directory
dir_path=$(pwd)

# Set default depth to 1
depth=1

# Print a help message
usage() {
  echo "Usage: $0 [ -d DIRECTORY_PATH ] [ -l LANGUAGE ] [ -r DEPTH ]" 1>&2 
}

# Take directory path, language and depth as arguments
while getopts ":d:l:r:" opt; do
    case $opt in
        d) dir_path="$OPTARG"
        ;;
        l) lang="$OPTARG"
        ;;
        r) depth="$OPTARG"
        ;;
        \?) echo "Invalid option -$OPTARG" >&2
        ;;
    esac
done

# Check if directory exists and is accessible
if [ ! -d "$dir_path" ]; then
        echo "Directory does not exist or is not accessible."
        exit 1
fi

# Use find command to search for files with specified language
case $lang in
    c) find "$dir_path" -maxdepth "$depth" -type f -name "*.c" ;;
    py) find "$dir_path" -maxdepth "$depth" -type f -name "*.py" ;;
    cpp) find "$dir_path" -maxdepth "$depth" -type f -name "*.cpp" ;;
    html) find "$dir_path" -maxdepth "$depth" -type f -name "*.html" ;;
    css) find "$dir_path" -maxdepth "$depth" -type f -name "*.css" ;;
    js) find "$dir_path" -maxdepth "$depth" -type f -name "*.js" ;;
    *) echo "Invalid language option. Available options: c, py, cpp, html, css, js" ;;
esac
usage() {
    echo "Usage: $0 [ -d DIRECTORY_PATH ] [ -l LANGUAGE ] [ -r DEPTH ]" 1>&2 
    echo "Available languages: c, py, cpp, html, css, js"
}
# Set default directory path to present working directory
$dir_path = Get-Location

# Set default depth to 1
$depth = 1

# Print a help message
function usage {
  Write-Host "Usage: $0 [ -d DIRECTORY_PATH ] [ -l LANGUAGE ] [ -r DEPTH ]" -ForegroundColor Yellow
}

# Take directory path, language and depth as arguments
param (
    [string]$dir_path = $dir_path,
    [string]$lang,
    [int]$depth = $depth
)

# Check if directory exists and is accessible
if (-not (Test-Path $dir_path -PathType Container)) {
    Write-Host "Directory does not exist or is not accessible." -ForegroundColor Red
    exit 1
}

# Use Get-ChildItem command to search for files with specified language
switch ($lang) {
    "c" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.c" }
    "py" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.py" }
    "cpp" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.cpp" }
    "html" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.html" }
    "css" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.css" }
    "js" { Get-ChildItem $dir_path -Recurse -Depth $depth -Filter "*.js" }
    default { Write-Host "Invalid language option. Available options: c, py, cpp, html, css, js" -ForegroundColor Red }
}
usage
Write-Host "Available languages: c, py, cpp, html, css, js" -ForegroundColor Yellow
