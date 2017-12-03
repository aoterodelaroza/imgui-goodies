#! /bin/bash
# Dawid Drozd
# https://unix.stackexchange.com/questions/35282/convert-ogv-video-to-gif-animation

inputFile=$1

FPS=15
WIDTH=320

#Generate palette for better quality
ffmpeg -i $inputFile -vf fps=$FPS,scale=$WIDTH:-1:flags=lanczos,palettegen tmp_palette.png

#Generate gif using palette
ffmpeg -i $inputFile -i tmp_palette.png -loop 0 -filter_complex "fps=$FPS,scale=$WIDTH:-1:flags=lanczos[x];[x][1:v]paletteuse" output.gif

rm tmp_palette.png
