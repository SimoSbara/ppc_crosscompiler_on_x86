# ppc_crosscompiler_on_x86
PowerPC G4 7450 Linux Compiler for x86

## Description

PowerPC G4 7450 Linux Compiler for x86 (for now)

## Description
For now, it is a precompiled cross-compiler for PowerPC G4 7450 running on x86 Linux that should help old PowerMac development...

The cross-toolchain is in [powerpc-7450-linux-gnu/bin/](https://github.com/SimoSbara/ppc_crosscompiler_on_x86/tree/main/powerpc-7450-linux-gnu/bin) folder.

There is an example of Client/Server communication on socket tcp in C (both x86 and PowerPC) in [examples/client_server_socket/](https://github.com/SimoSbara/ppc_crosscompiler_on_x86/tree/main/example/client_server_socket) folder.

## Manual build toolchain
I compiled this toolchain from this [guide](http://unisim-vp.org/site/crosstool-powerpc-7450-linux-gnu-how-to.html)
There are some errors during the build process, but with some tricks you can still achieve the build like I did.

Some tips are:
* Avoid to download every time crosstool folder (so you can edit the code inside for build success)
* Force C++11 in the build process by editing CXX_FLAGS
* I stopped before gbd build process (cross-debugger) 

## Testing Hardware and Software:
* PowerPC Machine: iBook G4 800 MHz with 1 GB of RAM
* PowerPC OS: [Ubuntu 16.04](https://forums.macrumors.com/threads/lubuntu-16-04-remix-updated.2204742/)
* x86 Machine: Ryzen 5 3600 with 32 GB of RAM
* x86 OS: WSL Ubuntu 22.04.1 LTS (Windows 11)
