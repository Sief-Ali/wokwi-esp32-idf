=========
# Just the foundation. Big things coming soon.
=========
# ESP32 + ESP-IDF + Wokwi template

This repository is a **starter template** for C firmware on the **ESP32** using **Espressif ESP-IDF**, with **Wokwi** simulation in the editor. Use it as a base and rename or copy the project when you start something new.

## How this project was started

The app skeleton matches what ESP-IDF’s project generator produces:

```bash
idf.py create-project wokwi-esp32-idf
```

That command creates the root `CMakeLists.txt`, `main/`, and related boilerplate. It does **not** immediately create `sdkconfig`; that file appears after you run `idf.py set-target`, `idf.py build`, or `idf.py menuconfig` at least once.

This template adds Wokwi wiring (`wokwi.toml`, `diagram.json`), editor settings (`.vscode/`), and the usual ESP-IDF artifacts (`sdkconfig` after configuration, `build/` after building).

---

## Requirements

### ESP-IDF

Install the toolchain and framework using the [official ESP-IDF getting started](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html) for your OS (including **Espressif Installation Manager (EIM)** where recommended).

### EIM (Espressif Installation Manager)

If you use EIM, select the ESP-IDF version you installed (example — replace with your version):

```bash
eim select v6.0
```

That typically activates the Xtensa toolchain, Python virtual environment, and ESP-IDF environment variables for the shell. Exact behavior depends on your EIM install; see [EIM CLI commands](https://docs.espressif.com/projects/idf-im-ui/en/latest/cli_commands.html).

### Editor (recommended)

In **VS Code** or **Cursor**, install the **Espressif IDF** extension so `idf.py` integrates with the workspace (build, flash, SDK configuration, toolchain helpers). Point the extension at your local ESP-IDF path in settings (this repo’s `.vscode/settings.json` uses machine-specific paths you must adjust).

### Wokwi

Install [Wokwi for VS Code](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode) to run the circuit in `diagram.json` against the firmware described in `wokwi.toml`.

### Optional: clangd

For better C navigation, you can use **clangd** with `build/compile_commands.json`. Build the project first, then align `.vscode/settings.json` and `.clangd` with your machine.

---

## Activate the environment (every new terminal)

Without an activated ESP-IDF environment, `idf.py` and tools will not work as expected.

**Using EIM (if available):**

```bash
eim select v6.0
```

**Manual install (typical pattern):**

```bash
. $IDF_PATH/export.sh
```

(On some setups the path is `~/esp/esp-idf/export.sh` or similar.)

---

## Clone or copy this template

```bash
cd wokwi-esp32-idf
```

---

## First configuration

After the environment is active, from the project root:

```bash
idf.py set-target esp32
```

Run a full configure/build when you need CMake to run and generate `build/compile_commands.json`:

```bash
idf.py reconfigure
```

`reconfigure` is most useful when CMake files changed, targets changed, or the editor’s index is out of sync. If you have no `build/` directory yet, `idf.py build` performs configuration as part of the first build.

---

## Build

```bash
idf.py build
```

This compiles your code, links ESP-IDF components, and produces firmware under `build/`.

---

## Flash and monitor (real hardware)

```bash
idf.py flash monitor
```

- `flash` uploads firmware to a connected ESP32.
- `monitor` shows serial output.

---

## Workflow after code changes

```bash
idf.py build
```

Rebuild after edits. Use `idf.py reconfigure` when CMake sources or layout change, you add or remove local components, you change ESP-IDF version, or IntelliSense/clangd no longer match the build.

---

## Clean build (when something is wrong)

```bash
idf.py fullclean
idf.py build
```

---

## Editor integration (`compile_commands.json`)

Example VS Code / Cursor setting (paths are project-relative):

```json
{
  "C_Cpp.default.compileCommands": "${workspaceFolder}/build/compile_commands.json"
}
```

The build system is the source of truth for flags and includes; refresh the build (or `idf.py reconfigure`) if the editor shows false errors.

---

## Wokwi simulation

From the project root, with the environment active:

```bash
idf.py set-target esp32
idf.py build
```

Wokwi reads `build/flasher_args.json` and `build/wokwi-esp32-idf.elf` (see `wokwi.toml`). **Build at least once** before starting the simulator so those files exist.

Start simulation from `diagram.json` using the Wokwi extension. UART lines in the diagram connect to the serial monitor as configured there.

---

## GDB with Wokwi (optional, currently unreliable)

`wokwi.toml` defines GDB and RFC2217-related ports; `.vscode/launch.json` includes a **Wokwi ESP32 Debug** configuration. **This path is known to have bugs** (the repo’s `launch.json` even notes that configurations may not work as expected). Treat it as experimental: you may need to adjust ports, GDB path, and setup commands for your setup, or debug on hardware instead.

---

## Command summary

```bash
# Activate environment (EIM example — use your installed version)
eim select v6.0

# New project from scratch (not needed when using this repo as a clone)
idf.py create-project my_project
cd my_project

# This template: configure and build
idf.py set-target esp32
idf.py build

# Optional: reconfigure when CMake / layout / IDF version changes
idf.py reconfigure

# Hardware
idf.py flash monitor

# Clean rebuild
idf.py fullclean
idf.py build
```

---

## License and attribution

| File | Role |
|------|------|
| [`LICENSE`](LICENSE) | **MIT License** — copyright (c) 2026 Sief Ali. |
| [`NOTICE`](NOTICE) | Upstream template URL and expectations when redistributing this as a starter. |

**MIT** — Anyone who distributes substantial portions must include the copyright notice and the full license text from `LICENSE`. Removing the author’s name from `LICENSE` and implying sole authorship of the whole work is not consistent with those terms.

**NOTICE (template redistribution)** — MIT alone does not require a link to a particular Git repository. [`NOTICE`](NOTICE) states the project’s expectation: if someone forks or copies this repo and **re-offers it publicly as a generic template** (under any name), they should keep `LICENSE`, keep the information in `NOTICE` (or merge it into their README), and keep the **canonical upstream URL** so others can use the maintained original. Details and the placeholder URL are in `NOTICE`; **maintainers should replace the placeholder** with the real public repo URL when publishing.

**Private or normal application projects** (not republished as a public starter template) are not asked to advertise the upstream; see [`NOTICE`](NOTICE) for the full distinction.
