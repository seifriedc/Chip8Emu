# CHIP8Emu
A CHIP-8 disassembler and emulator for fun!

### CMake Usage
First we need to generate our Makefiles. While in the root directory,

```$bash
$ mkdir build
$ cd build
$ cmake ..
```

The `CMakeLists.txt` file in the root directory specifies all of our build targets, including dependencies and necessary
libraries. Running `cmake ..` will generate the Makefile that holds all of our targets. This should only be run once,
or whenever `CMakeLists.txt` is changed. After doing this, just `make <target>` as usual.

### References
[Wikipedia article on CHIP-8](https://en.wikipedia.org/wiki/CHIP-8)

[Cowgod's CHIP-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

### C++ Style / Best Practices
[Chromium Style Manual](https://www.chromium.org/developers/coding-style/cpp-dos-and-donts)

[Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

