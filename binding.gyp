{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "cpp/wrapper.cpp",
        "cpp/analyze.cpp"
      ],
      "include_dirs": [
         "<!(node -e \"require('nan')\")"
      ],
      "libraries": [
        "-lopencv_core",
        "-lopencv_highgui",
        "-lopencv_imgproc",
        "-lopencv_imgcodecs"
      ],
      "cflags": [ "-std=c++11" ]
    }
  ]
}