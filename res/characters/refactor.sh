#!/usr/bin/zsh

for character in *; do
    echo "Altering ${character}..."

    for i in $(seq 1 8); do
        FILE="${character}/${character} ($i).png"
        NEWFILE="${character}/icon${i}.png"
        if [ -f "$FILE" ]; then
            echo "  -> $FILE exists, moving to $NEWFILE..."
            mv "$FILE" "$NEWFILE"
        else
            echo "  -> $FILE does not exist..."
        fi
    done

    echo "========================="
    echo
done