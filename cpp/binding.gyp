{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "wrapper.cpp"
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