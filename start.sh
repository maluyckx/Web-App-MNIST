if [[ ! -f "/tmp/tartine_process" ]]; then
    {
        {
            cd src/API && { node app.js > /dev/null& } && sleep 1
            echo "API lancée"
        } && {
            cd ../frontend && { serve -s build > /dev/null& } && sleep 1
            echo "Site web lancé"
        } && {
            jobs -p >> /tmp/tartine_process
            exit 0
        }
    } || {
        echo "Erreur lors du démarrage de l'application, vérifiez que les ports 2022 et 3000 sont bien disponibles sur la machine"
        exit 1
    }
else
    echo "Le serveur est déjà lancé"
fi