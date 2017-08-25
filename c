#!/bin/sh

if [ $# -lt 1 ]
then
        echo "missing argument"
fi

for srv in $@
do
        if ! host $srv 2>&1 >/dev/null
        then
                echo "invalid host: $srv"
                exit 1
        fi
done

tmux new-window "ssh $1"
shift

for srv in $@
do
        tmux split-window -v "ssh $srv"
        tmux select-layout even-vertical
done
