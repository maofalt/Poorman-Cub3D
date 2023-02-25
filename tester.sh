#!/bin/bash

echo -e "\n$(tput setaf 4)r"""\
"   +--------+       ████████╗   ████████╗██████╗██████╗ \n"\
"  /        /|      ██╔════██║   ████╔══██╚════████╔══██╗\n"\
" /        / |      ██║    ██║   ████████╔╝█████╔██║  ██║\n"\
"+--------+  |      ██║    ██║   ████╔══██╗╚═══████║  ██║\n"\
"|        |  |     ╚██████╚██████╔██████╔██████╔██████╔╝ \n"\
"|        |  +      ╚═════╝╚═════╝╚═════╝╚═════╝╚═════╝\n"\
"|        | /                                            \n"\
"|        |/                                             \n"\
"+--------+                                              \n"\
"  ██╗    ████████╗███████╗████████╗  ███████████████╗   \n"\
"  ██║    ████╔══████╔════██╔════██║ ██╔██╔════██╔══██╗  \n"\
"  ██║ █╗ ████████╔█████╗ ██║    █████╔╝█████╗ ██████╔╝  \n"\
"  ██║███╗████╔══████╔══╝ ██║    ██╔═██╗██╔══╝ ██╔══██╗  \n"\
"  ╚███╔███╔██║  █████████╚████████║  ███████████║  ██║  \n"\
"   ╚══╝╚══╝╚═╝  ╚═╚══════╝╚═════╚═╝  ╚═╚══════╚═╝  ╚═╝  \n"\
"""$(tput sgr0)\n"                                                                            


# ANSI escape codes for colors
COLOR_BLUE='\033[0;34m'
COLOR_GREEN='\033[0;32m'
COLOR_RED='\033[0;31m'
COLOR_WHITE='\033[0;37m'
COLOR_RESET='\033[0m'

# Step 1: Retrieve all files
files=$(ls maps/maps_buged/*.cub)

# Step 2 and 3: Launch the program with valgrind and write into log file
for file in $files; do
    # Print the filename in blue
    echo -e "${COLOR_BLUE}Testing $file:${COLOR_RESET}"

    # Launch the program with valgrind
    output=$(valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D "$file" 2>&1)

    # Determine the directory to write the log file to and colorize the output
    if echo "$output" | grep -q "Error" && echo "$output" | grep -q "definitely lost: 0 bytes\|All heap blocks were freed -- no leaks are possible"; then
        dir="logs/OK"
        color="${COLOR_GREEN}"
        result="OK"
    else
        dir="logs/NOK"
        color="${COLOR_RED}"
        result="NOK"
    fi

    # Print the output in white with the appropriate color
    echo -e "${color}${output}${COLOR_RESET}"

    # Write into log file
    mkdir -p "$dir"
    echo "$output" > "$dir/$(basename "$file" .cub).log"

    # Print the result in green or red
    echo -e "${color}${result}${COLOR_RESET}"
done
