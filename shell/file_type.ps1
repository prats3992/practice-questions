# Set default directory path to present working directory
$dir_path = Get-Location

# Set default depth to 1
$depth = 1

# Print a help message
function usage {
    Write-Host "DESCRIPTION:"
    Write-Host "  This script searches for files with a specified language extension in a directory."
    Write-Host ""
    Write-Host "USAGE:"
    Write-Host "  file_type [-d DIRECTORY_PATH] [-l LANGUAGE] [-r DEPTH]"
    Write-Host ""
    Write-Host "OPTIONS:"
    Write-Host "  -d DIRECTORY_PATH     The directory to search for files. Defaults to the current directory."
    Write-Host "  -l LANGUAGE           The file extension to search for (e.g., 'py' for Python)."
    Write-Host "  -r DEPTH              The maximum recursion depth. Defaults to 1 (non-recursive)."
    Write-Host ""
    Write-Host "EXAMPLES:"
    Write-Host "  Search for Python files in the current directory with a depth of 2:"
    Write-Host "  file_type -l py -r 2"
}

# Define a hash table to store named arguments
$namedArguments = @{}

# Parse named arguments
for ($i = 0; $i -lt $args.Count; $i++) {
    if ($args[$i] -eq "-d" -and $i + 1 -lt $args.Count) {
        $dir_path = $args[$i + 1]
        $i++
    }
    elseif ($args[$i] -eq "-l" -and $i + 1 -lt $args.Count) {
        $namedArguments["-l"] = $args[$i + 1]
        $i++
    }
    elseif ($args[$i] -eq "-r" -and $i + 1 -lt $args.Count) {
        $namedArguments["-r"] = $args[$i + 1]
        $i++
    }
    else {
        usage
        exit
    }
}

# Set named arguments if provided
if ($namedArguments.ContainsKey("-l")) {
    $lang = $namedArguments["-l"]
}

if ($namedArguments.ContainsKey("-r")) {
    $depth = [int]$namedArguments["-r"]
}

# Check if the specified directory exists
if (-not (Test-Path $dir_path -PathType Container)) {
    Write-Host "Directory does not exist or is not accessible." -ForegroundColor Red
    exit 1
}

# Use Get-ChildItem command to search for files with the specified language
$files = Get-ChildItem $dir_path -Recurse -File -Filter "*.$lang"

if ($files.Count -eq 0) {
    Write-Host "No files with the '$lang' extension found in $dir_path ." -ForegroundColor Yellow
}
else {
    Write-Host "Files with the '$lang' extension found in $dir_path :"
    $files | ForEach-Object {
        Write-Host $_.FullName
    }
}

# Write-Host "Available languages: c, py, cpp, html, css, js" -ForegroundColor Yellow
