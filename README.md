# PictDisclosure : GUI application to display JPEG image, EXIF data and color histogram.

This application is written just for my nodejs/node-gyp/electron practice.

## Platform

Ubuntu 16.04LTS, nodejs v9.10.0, node-gyp v3.6.2, Electron v1.8.4, opencv

Install opencv(-lopencv_core, -lopencv_highgui), nodejs and node-gyp to your environment.

## Build & Run

```bash
$ git clone https://github.com/sheeproj/PictDisclosure
$ cd PictDisclosure
$ npm install
$ npm run build
```

## Usage

Drag & drop a JPEG file into GUI frame, then image/EXIF/histogram will be displayed.
