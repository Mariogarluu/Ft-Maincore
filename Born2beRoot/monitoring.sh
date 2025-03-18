# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 12:39:54 by marioga2          #+#    #+#              #
#    Updated: 2025/02/14 12:56:30 by marioga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cmd=$(uname -a)
printf "#Architecture: $cmd\n"


cmd=$(lscpu | grep Socket | awk '{print $2}')
printf "#CPU physical: $cmd\n"


cmd=$(nproc)
printf "#vCPU: $cmd\n"


cmd1=$(free -m | grep Mem | awk '{print $3}')
cmd2=$(free -m | grep Mem | awk '{print $2}')
cmd3=$(free -m | grep Mem | awk '{print $3/$2 * 100}')
printf "#Memory Usage: $cmd1/$cmd2%s ($cmd3%%)\n" "MB"


cmd1=$(df -h --block-size=G --total | tail -n 1 | awk '{print $3}' | cut -d G -f1)
cmd2=$(df -h --block-size=G --total | tail -n 1 | awk '{print $2}' | cut -d G -f1)
cmd3=$(df -h --block-size=G --total | tail -n 1 | awk '{print $5}' | cut -d % -f1)
printf "#Disk Usage: $cmd1/$cmd2%s ($cmd3%%)\n" "Gb"


cmd1=$(mpstat | tail -n 1 | awk '{print $4}')
cmd2=$(mpstat | tail -n 1 | awk '{print $6}')
cmd3=$(echo "$cmd1 + $cmd2" | bc)
printf "#CPU load: $cmd3%%\n"


cmd=$(who -b | awk '{print $3 " " $4}')
printf "#Last boot: $cmd\n"


cmd=$(cat /etc/fstab | grep /dev/mapper | wc -l)
printf "#LVM use: "
if [ $cmd -gt 0 ]
then
        printf "yes\n"
else
        printf "no\n"
fi


cmd=$(echo "$(ss -t state established | wc -l) - 1" | bc)
printf "#Connections TCP: $cmd ESTABLISHED\n"


cmd=$(($(w | wc -l) - 2))
printf "#User log: $cmd\n"


cmd1=$(ip address | grep enp | grep inet | awk '{print $2}' | cut -d / -f1)
cmd2=$(ip address | grep enp -A 1 | grep ether | awk '{print $2}')
printf "#Network: IP $cmd1 ($cmd2)\n"


cmd=$(echo "obase=10; ibase=36; $(cat /var/log/sudo/seq)" | bc)
printf "#Sudo: $cmd cmd\n"