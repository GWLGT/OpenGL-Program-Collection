<h2 style="text-align: center">OpenGL | House</h2>

### What is This?

Another Simple OpenGL Program... Nothing else.

### How to Build?

To build this program, create build/ directory (Reccomended), Linux Example:

```bash
mkdir build && cd build
```

Then, run `cmake ..` or `ccmake ..` (if you prefer using Curses CMake).

If you are using `ccmake` (Curses CMake), do this:

1. First, run `ccmake ..` to enter the TUI Mode
2. Then, configure it (press `c`)
3. After that, set `CMAKE_BUILD_TYPE` to `Release` (or `RelWithDebInfo` if you prefer)
4. Configure it again (press `c`)
5. Finally, generate the Makefile (press `g`)

Run `make` after that, done!.

>[!NOTE]
> Make sure to run the Program from the Root project, otherwise, it would fails to Read the Shader Files.  

---
<h2 style="text-align: center">Credit/Licenses</h2>

Check `LICENSE` file for This Program Code and GLAD Code License.
