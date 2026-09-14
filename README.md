## VTP | Video Transfer Pipeline

This tool lets you orginize simple pipeline of transport media files from exact directory to your built ML-model.

This simple idea will **save** you a **ton of time** in production.

Here is a **brief guide** about this tool.

## What is it?

VTP lets developer link ML-model (that precess some media-files) and certainly media files.

For example one developer started media flow that saves in some directory. You need to get these media files and put them into your model. It takes some time to process media file. That's why all of new files will insert into queue. When model will return some result, next task will start as soon as it possible.

## Main stack

Simple C++ tool uses two threads:

* First thread has timer that looks for some new files.
* Second thread pops task from queue and waits for it's ending.

## Config file

The configuration file is available at the path "./config/config.cfg" by default.

* _path_ - global path to directory [../assets/]
* _fileName_ - first part of files [name...]
* _fileCounter_ - secont part of files [...01]
* _fileSize_ - size of detected files in KB [262144] or [nothing] to look for all files
* _checkDelay_ - delay between observation in seconds [600]

Cfg example:

```cfg
# directory with files
path=./videos/
# file prefix
fileName=video
# file suffix
fileCounter=00000
# file size to find
fileSize=10
# delay
checkDelay=5
```

## Build
**gcc** or **g++** compilers are available
```C++
g++ ./src/*.cpp ./app/* -o /build/vtp
```

## Run
**Warning! Don't forget to use paths relative to directory where you execure program**
```bash
./build/vtp
```