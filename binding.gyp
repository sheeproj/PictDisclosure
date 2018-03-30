{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "cpp/wrapper.cpp"
      ],
      "include_dirs": [
         "<!(node -e \"require('nan')\")"
      ],
      "libraries": [
      ],
      "cflags": [ "-std=c++11" ]
    }
  ]
}