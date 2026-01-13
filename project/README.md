Mini Jogo
=========

Debugging
---------

You can enable debug helpers in two ways:

- Compile-time: define the `DEBUG` macro when compiling (e.g., `g++ -DDEBUG ...`). This enables debug controls in debug builds.
- Runtime: pass `--debug` as a command-line argument when running the game: `./jogo --debug`.

When debug is enabled the following keybindings are available while the game runs:

- `E` — Toggle empty shop (clears/restores the shop list)
- `B` — Auto-buy the current shop car (if enough money)
- `I` — Set an invalid shop index (used to test index clamping)

Notes
-----

- The debug controls are intentionally wrapped so they can be enabled either at compile-time (`DEBUG`) or at runtime (`--debug`).
- Use these helpers for testing corner cases (empty lists, buying flow, index handling).

Building & Testing
------------------

This project includes a `Makefile` with useful targets:

- `make` or `make build` — build the game (`./jogo`).
- `make debug` — build the game with `-DDEBUG` (compile-time debug enabled).
- `make test` — build and run unit tests (tests are compiled with `-DUNIT_TEST` to exclude Raylib-dependent code).
- `make clean` — remove build artifacts.

Example:

```
# Build release
make

# Run with runtime debug
./jogo --debug

# Run unit tests
make test
```