ls -h -l --block-size=K "$@" | awk '{print $9, $5}'
