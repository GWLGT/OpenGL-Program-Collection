<h2 style="text-align: center">Contributing on Android</h2>

If you are on Android, You can still Contribute to this Repository!.

### Prerequisites

First, we need the required App:

- [Termux App](https://github.com/termux/termux-app)
- [Termux:X11 App](https://github.com/termux/termux-x11)

Then, we also need several Package:

Required:

- `mesa` and/or `mesa-dev` (for OpenGL Headers)
- `glfw`
- `clang` or `gcc`
- `make` and `cmake` or `ccmake`
- `git`
- `termux-x11`
- Any Window Manager/Desktop Environment (e.g, `openbox`)

Optional:

- `openbox`
- `neovim`
- `qterminal`

### Setup

1. Install Termux App, then update the package database:

```bash
pkg up -y
```

2. Install the required Packages:

```bash
pkg in mesa mesa-dev glfw clang make cmake
```

3. Then, (Termux:X11 App Should be Installed) we Setup our X11 Environment:

```bash
# Install
pkg in termux-x11 openbox # or fluxbox/xfce4/lxqt/mate
pkg in qterminal # or alacritty/kitty/etc

# Start the Server (or use my Script (`start-x11`) if you are using openbox)
# change `openbox-session` to your selected DE/WM session command name
termux-x11 :0 -xstartup "dbus-launch --exit-with-session openbox-session"
```

4. The X11 Environment should ready now, Install any Editor you want (e.g `neovim`):

```bash
pkg in neovim
```

5. Clone this Repository:

```bash
git clone https://github.com/GWLGT/OpenGL-Program-Collection.git && cd OpenGL-Program-Collection
```

6. Then, make any C++ OpenGL-related Program in `program/your-program-name`

> **Replace** `your-program-name` with the actual directory name you want

Make sure it has Proper `CMakeLists.txt` and `LICENSE` file.

That's It! Happy Coding!.
