#!/bin/sh
set -e
set -x

# Build and install devkitARM + ctrulib
wget http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitARMupdate.pl
git clone https://github.com/smealum/ctrulib.git
sudo perl devkitARMupdate.pl

# Get latest ctrulib and overwrite bundled one
cd ctrulib/libctru && make ; cd -
sudo cp -rf ctrulib/libctru/ ${DEVKITPRO}

# Get, Build & Install dependencies

# portlibs
git clone https://github.com/filfat/3ds_portlibs.git
cd 3ds_portlibs && sudo make all ; cd -

# sf2dlib

# sftdlib

# sfillib

# 3DS_UI
git clone https://github.com/filfat/3DS_UI.git
cd 3DS_UI ; cd - # TODO: Build
