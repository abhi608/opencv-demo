This repository contains the material required for OpenCV demonstration.
The demonstration will cover basic image processing and by the end of the
demonstration we aim to write a program which can track objects based on
their color and motion. It would be desirable that any person attending the
workshop comes with his/her own laptop with OpenCV installed. The
installation instructions are given below. Also to be able to test if the 
code is correctly working, it would be helpful if you bring a distinctly
colored object. The code written during the demonstration will be later
uploaded to this repository.

# Installing OpenCV
Run the command corresponding to your OS in the terminal

* __Ubuntu, Linux Mint, Debian__: `$ sudo apt-get install libopencv-dev`
* __Arch__: `$ sudo pacman -S opencv`
* __Windows__:
    * Install the trial version of Ceemple IDE from [https://www.ceemple.com/getceemple/](https://www.ceemple.com/getceemple/) *(preferred)*
    * Install OpenCV from [http://opencv.org/downloads.html](http://opencv.org/downloads.html) and configure it for any IDE of your choice

The demonstration will be done using *Ceemple IDE* for windows and OpenCV installed on *Ubuntu*

# Post - Installation
Navigate to the test folder and run

`$ make`

If you see a window showing the webcam output then you have successfully installed OpenCV.
Press 'x' to exit.
# Compiling
The .cpp files made during the demonstration can be compiled using

```$ g++ file.cpp -o file `pkg-config opencv --libs` ```

# Contact

In case of problems during the setup, you can contact us at *lakshayg373@gmail.com*


# __too long; didn't read__
When attending the demonstration try to:

* Bring a laptop with OpenCV installed
* Bring a distinctly colored object
* In case of any problems, contact *lakshayg373@gmail.com*
* Do attend even if you are not able to arrange for these items
