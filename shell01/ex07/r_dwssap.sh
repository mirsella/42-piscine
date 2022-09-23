cat /etc/passwd | sed '/^#/d' | awk -F ':' 'NR%2!=1 {print $1}' | rev | sort --reverse | awk "NR==$FT_LINE1,NR==$FT_LINE2" | sed -z 's/\n/, /g; s/, $/.\n/' | tr -d '\n'
