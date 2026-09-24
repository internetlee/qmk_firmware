# internetlee — Sofle keymap

Ported from the `keebio/iris/keymaps/leegenes` keymap so switching between the
Iris and the Sofle feels the same. The alpha grid is identical; the extra Sofle
thumb keys are left empty for now.

Controller: RP2040 **Helios** converter (see `keymap.json`).

## Layers

- **QWERTY** (base)
- **LOWER** — symbols, brackets, media/volume
- **RAISE** — F-keys, arrow cluster
- **ADJUST** — QK_BOOT (bootloader), debug toggle

## Base layer highlights (carried over from the Iris)

- Home-row left key is **Ctrl when held / Esc when tapped** (`LCTL_T(KC_ESC)`).
- Outer bottom keys are **Space Cadet shift-parens** (`SC_LSPO` / `SC_RSPC`):
  Shift when held, `(` / `)` when tapped.
- Top-row right ends in `Bspc` (R1) and `\` (R2), matching the Iris.

## Thumbs

```
        LEFT                                 RIGHT
  --  Cmd  --  Lower  --            Enter  Raise  Alt  Space  --
  (outer ------> inner)            (inner <------ outer)
```

- **Lower** on the left thumb, **Raise** on the right thumb.
- **Enter** on the big inner right thumb, **Space** toward the outer right.
- **Alt** (RAlt) on the right thumb.
- **Cmd** (GUI) on the left thumb.
- The two outer thumb keys per side are intentionally empty (`KC_NO`) for now.
- **Adjust** is a momentary layer on the left encoder-side key; **Mute** is on
  the right encoder-side key.

## Encoders

- **Left**: volume down / up
- **Right**: page up / down

## Build

```
qmk compile -kb sofle/rev1 -km internetlee
qmk flash   -kb sofle/rev1 -km internetlee
```
