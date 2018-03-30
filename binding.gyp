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
        "-lopencv_highgui"
      ],
      "cflags": [ "-std=c++11" ]
    }
  ]
}