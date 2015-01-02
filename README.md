cammodule
=========

CAMERA INTERFACE MODULE

Description: 

Purpose of the camera interface module is to provide a basic way to access raw video frame data captured by a grabber hardware available in the system. This module has been designed for any variety of Linux OS and runs at the user space.

Prerequirements:

The module requires V4L (Video For Linux) drivers installed in Kernel which is already integrated with the Linux Kernel.

Details:

The module has a well-defined interface to initialize, start and stop. It provides raw video frame out by a function call when it is requested.

    Programming Language:   C
    Compiler:               GCC
    Test Platform(s):       ARM Cortex-A8 h/w
                            ARM Cortex-A9 h/w
    Test OS:                Linux Ubuntu
                            Linux Debian
                            
    Input(s):
          - Camera resolution
          - Camera device name

    Output(s):
          - Video Frame Data

    Sequence:

          See the test application source code available in main.c file.
          The module interface details are available in cammodule.h file.
          - Init() 	- To initialize the module with device name and type of camera
          - Start() - To start capturing of raw video frames
          - Stop()	- To stop capturing process
          - GetFrame() - To copy the video frame data

How to Build:

    - Makefile available in the repository is generated regarding to Arm Linux Gnueabihf Gcc.
    - $make 

How to Run:

    - $./Test.sh

