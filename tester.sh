#!/bin/bash
#wrong textures still not included
#maps to be tested must not containa space in the name otherwise run this command
# for f in *\ *; do mv "$f" "${f// /_}"; done
# it will replace all spaces with underscores

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
sleep 3

# ANSI escape codes for colors
COLOR_BLUE='\033[0;34m'
COLOR_GREEN='\033[0;32m'
COLOR_RED='\033[0;31m'
COLOR_WHITE='\033[0;37m'
FORMAT_BOLD='\033[1m'
COLOR_RESET='\033[0m'
CURSOR_RESET='\033[0G'

# Initialize counters
total_tests=0
passed_tests=0
progress_bar_width=100
progress_bar_symbol='█'

# Step 0: Erase all log files
rm -rf logs
mkdir logs

# Step 1: Retrieve all files and count the number of  files
dir_path="maps/maps_buged/"
files=$(ls -a maps/maps_buged)
total_tests=$(echo "$files" | wc -l)

# Step 1bis: Make program
clear && make && clear

# Step 2 and 3: Launch the program with valgrind and write into log file
for file in $files; do

	full_path="maps/maps_buged/$file"
    # Print the filename in blue
    echo -e "${COLOR_BLUE}===============================${COLOR_RESET}"
	echo -e "${COLOR_BLUE}$(printf '%b' "${FORMAT_BOLD}Testing $full_path:${FORMAT_RESET}")${COLOR_RESET}"
    echo -e "${COLOR_BLUE}===============================${COLOR_RESET}"

    # Launch the program with valgrind
    output=$(valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D "$full_path" 2>&1)

    # Determine the directory to write the log file to and colorize the output
    if echo "$output" | grep -q "Error" && echo "$output" | grep -q "definitely lost: 0 bytes\|All heap blocks were freed -- no leaks are possible"; then
        dir="logs/OK"
		passed_tests=$((passed_tests + 1))
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
    echo -e "${COLOR_BLUE}===============================${COLOR_RESET}"
    echo -e "${color}${result}${COLOR_RESET}"
	echo -e "\033[1m$passed_tests\033[0m tests passed."
	echo -e "over \033[1m$total_tests\033[0m."
    echo -e "${COLOR_BLUE}===============================${COLOR_RESET}"

	    # Print progress bar
    progress=$(echo "scale=2; $passed_tests / $total_tests * 100" | bc)

	# Calculate the number of filled and empty blocks in the progress bar
	filled_blocks=$(echo "$progress / (100 / $progress_bar_width)" | bc)
	empty_blocks=$((progress_bar_width - filled_blocks))
    
	printf "["
	progress_bar="${COLOR_GREEN}"
    for ((i=0; i<filled_blocks; i++)); do
        progress_bar+=${progress_bar_symbol}
    done
	progress_bar+="${COLOR_RED}"
    for ((i=0; i<empty_blocks; i++)); do
		progress_bar+=${progress_bar_symbol}
    done
	progress_bar+="${COLOR_RESET}"
    echo -e "Progress: [${progress_bar}] ${progress}%"
	#printf "] %d%%\n" $((passed_tests * 100 / total_tests))
done
sleep 5
clear
# Print a new line after the progress bar
echo -e "\n"
    
# Print the result in green or red
echo -e "${FORMAT_BOLD}${COLOR_BLUE}===============================${COLOR_RESET}"
echo -e "${color}${result}${COLOR_RESET}"
echo -e "\033[1m$passed_tests\033[0m tests passed."
echo -e "over \033[1m$total_tests\033[0m."
echo -e "${COLOR_BLUE}===============================${COLOR_RESET}"

# Check if all tests have passed
if [ $passed_tests -eq $total_tests ]; then
    # All tests passed, so ssh to the server
    ssh -p 2223 ssh.caarlos0.dev <<< "yes"
else
    # Some tests failed, so open a YouTube video
    xdg-open "https://youtu.be/dQw4w9WgXcQ"
fi