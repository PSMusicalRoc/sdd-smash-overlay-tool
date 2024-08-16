<p align="center">
    <img src="https://github.com/PSMusicalRoc/ez-stream-tool/blob/main/docs/ezstream-logo.png?raw=true" width="100px" />
</p>

# EZ-Stream

*Rated E for everyone!*

## Overview

EZ-Stream is an overlay control tool for Super Smash Brothers
Ultimate. It was designed as part of our time in Software
Design and Development at Rensselaer Polytechnic. The primary
design goals of this tool are ease of use, cross-platform
compilation, and polish.

If you're a Smash streamer and you're looking for an infographic
overlay for your stream, look no further! We offer many of the
same features as our competitors, as well as active support and
the ability to customize the overlay through HTML and CSS code!

## Installation

1) Go to the [Releases]() page and download the `.zip` file
corresponding to your operating system. At the time of writing,
we support Microsoft Windows 10+ and Linux.
2) Unzip the downloaded file wherever you'd like.
3) Run the included executable file, and enjoy!

### Setting up the Overlay in OBS Studio

This section details how to put the overlay onto your existing
OBS Studio stream layout. We assume at this point that you have
installed OBS Studio.

1) Open OBS Studio
2) In the "Sources" window (by default, near the bottom left),
press the Plus button and select "Browser"

<img src="https://github.com/PSMusicalRoc/ez-stream-tool/blob/main/docs/setup-1.png?raw=true" />

3) Make sure the radio button on the newly opened window is on
"Create new" and name the source whatever you'd like.
4) Input settings as follows:
    - “Local File” checkbox is set to True
    - “Local File” path input is set to point at the
    `overlay.html` file from the extracted `.zip` file
    - “Width” is 1920
    - “Height” is 1080
    - “FPS” is 60
    - “Shutdown source when not visible” checkbox is True
    - “Refresh browser when scene becomes active” checkbox is True

<img src="https://github.com/PSMusicalRoc/ez-stream-tool/blob/main/docs/setup-2.png?raw=true" />

5) Press the OK Button, and the overlay should be visible in OBS’
preview!

## Building from Source

**Note: Better build instructions will be added at a later
time**

### How to clone this repository

```
git clone https://PSMusicalRoc/ez-stream-tool.git --recurse-submodules
```

### Build Dependencies Needed

```
SDL v2.x
GNU Make
GCC 14
```

#### Installing Dependencies (Arch Linux)

```
# pacman -Sy gcc make sdl2 sdl2_image
```

#### Installing Dependencies (MSYS2 UCRT64)

```
pacman -S mingw-w64-ucrt-x86_64-toolchain \
          mingw-w64-ucrt-x86_64-SDL2 \
          mingw-w64-ucrt-x86_64-SDL2_image \
          make \
          zip
```


### Building

#### UNIX

```
$ ./create-makefile-unix.sh
$ make config=debug

---- or for release ----

$ ./create-makefile-unix.sh
$ make config=release
```

Executables will be placed in `build/<Debug or Release>/`.

#### MSYS2 UCRT64

```
$ ./create-makefile-windows.bat
$ make config=debug

---- or for release ----

$ ./create-makefile-windows.bat
$ make config=release
```

Executables will be placed in `build/<Debug or Release>/`.

## Collaborator Information

- Tim Bishop ([bishot3@rpi.edu](mailto:bishot3@rpi.edu))
- Bill Jiang ([jiangb4@rpi.edu](mailto:jiangb4@rpi.edu))
- Andrew Choi([choia8@rpi.edu](mailto:choia8@rpi.edu))
- Calista Clifford-Fotopoulos ([cliffc3@rpi.edu](mailto:cliffc3@rpi.edu))
- Robert Haney ([haneyr2@rpi.edu](mailto:haneyr2@rpi.edu))
