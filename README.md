# URL Testing Tool

This URL testing tool allows you to parse and test URLs using BOINC parsing functions. It can:
- Parse a single URL and run basic tests on the parsed components (protocol, host, port, etc.).
- Compare two URLs to determine if they represent a valid HTTP→HTTPS transition and/or if they match (ignoring protocol differences).

## Features

- **Single URL Mode:** 
  - Input one URL.
  - Displays parsed components.
  - Runs a series of tests checking if the protocol is recognized, the host is not empty, etc.

- **Comparison Mode:**
  - Input two URLs.
  - Checks if transitioning from `http://` to `https://` is valid (i.e., same host and path).
  - Checks if two URLs match by comparing their components after `//`.

## Building

Make sure you have a C++ compiler (such as `g++`) and the BOINC utilities (`url.h`, `url.cpp`, `str_util.cpp`, etc.).

```bash
g++ -std=c++11 -Wall -O2 -Iboinc/lib -Iboinc/win_build -D_WIN32 \
    -o test_url.exe main.cpp url.cpp boinc/lib/str_util.cpp
