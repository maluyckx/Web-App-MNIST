if [[ -f "/tmp/tartine_process" ]]; then
    while read line; do
    if [[ -d "/proc/${line}/" ]]; then
        kill $line
        echo "Processus ${line} terminé"
    fi 
    done < "/tmp/tartine_process"
    rm "/tmp/tartine_process"
else
    echo "Le fichier /tmp/tartine_process (contenant les PIDs des processus) est introuvable"
fi