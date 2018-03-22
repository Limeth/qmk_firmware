#!/usr/bin/env fish
sudo echo Compiling...
make preonic:limeth; or exit 1
sudo echo Compiled successfully. Put your keyboard into DFU \(Bootloader\) mode.
sudo echo Flashing in 3 seconds.
sleep 3
sudo make preonic:limeth:dfu
