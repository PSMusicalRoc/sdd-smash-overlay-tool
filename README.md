# This page is a work in progress

## How to clone this repository

```
git clone https://PSMusicalRoc/ez-stream-tool.git --recurse-submodules
```

## Build Dependencies Needed

```
SDL v2.x
GNU Make
GCC 14
```

### Installing Dependencies (Arch Linux)

```
# pacman -Sy gcc make sdl2
```

## Building

### UNIX

```
$ ./create-makefile-unix.sh
$ make config=debug

---- or for release ----

$ ./create-makefile-unix.sh
$ make config=release
```

Executables will be placed in `build/<Debug or Release>/`.

## Collaborator Information

- Tim Bishop ([bishot3@rpi.edu](mailto:bishot3@rpi.edu))
- Bill Jiang ([jiangb4@rpi.edu](mailto:jiangb4@rpi.edu))
- Andrew Choi([choia8@rpi.edu](mailto:choia8@rpi.edu))
- Calista Clifford-Fotopoulos ([cliffc3@rpi.edu](mailto:cliffc3@rpi.edu))
- Robert Haney ([haneyr2@rpi.edu](mailto:haneyr2@rpi.edu))
