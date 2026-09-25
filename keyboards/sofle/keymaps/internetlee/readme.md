# internetlee — Sofle keymap

Ported from the `keebio/iris/keymaps/leegenes` keymap so switching between the
Iris and the Sofle feels the same. The alpha grid is identical; the extra Sofle
thumb keys are left empty for now.

Controller: RP2040 **Helios** converter (see `keymap.json`).

## Layers

- **QWERTY** (base)
- **LOWER** — symbols, brackets, media/volume
- **RAISE** — F-keys, arrow cluster, Caps Word / Caps Lock
- **ADJUST** — QK_BOOT (bootloader), debug toggle. Reserved for a future
  Aerospace / app-shortcut layer (reached by holding Lower + Raise together).

## Base layer highlights (carried over from the Iris)

- Home-row left key is **Ctrl when held / Esc when tapped** (`LCTL_T(KC_ESC)`).
- Outer bottom keys are **Space Cadet shift-parens** (`SC_LSPO` / `SC_RSPC`):
  Shift when held, `(` / `)` when tapped.
- Top-row right ends in `Bspc` (R1) and `\` (R2), matching the Iris.

## Thumbs

```
        LEFT                                 RIGHT
  --  Cmd  --  Lower  Hyper        Enter  Raise  Alt  Space  --
  (outer ------> inner)            (inner <------ outer)
```

- **Lower** on the left thumb, **Raise** on the right thumb.
- **Hyper** (Ctrl+Alt+Shift+Gui, hold-only) on the big left home-thumb — a
  collision-free chord key for app launching / window management.
- **Enter** on the big inner right thumb, **Space** toward the outer right.
- **Alt** (RAlt) on the right thumb, **Cmd** (GUI) on the left thumb.
- The remaining outer thumb keys are empty (`KC_NO`) for now.
- **Mute** / **Play-Pause** sit on the encoder-side keys.

## Encoders

Layer-aware. A held layer occupies the thumb on the *same* side as one knob, so
only the two comfortable cross-hand combos get a special role — everything else
falls back to base.

| Layer           | Left knob      | Right knob   |
| --------------- | -------------- | ------------ |
| Base            | Volume         | Zoom (⌘ ∓)   |
| Raise (R thumb) | **Undo / Redo**| → Zoom       |
| Lower (L thumb) | → Volume       | **Scroll**   |

Encoder **push**: left = Mute, right = Play/Pause.

## OLED

Both halves run a tall HUD (both forced to `OLED_ROTATION_270`) showing only
what's relevant to that half:

- **Layer name** in caps at the top (`BASE` / `LOWER` / `RAISE` / `ADJST`).
- **That half's own knob action**: left half shows `VOL` / `SCRUB` (on Raise),
  right half shows `ZOOM` / `SCRL` (on Lower).
- **Caps carets**: a row of `^^^^^` across the bottom whenever Caps Lock or Caps
  Word is active; blank otherwise.

Layer and caps-lock state are synced to the slave (`SPLIT_LAYER_STATE_ENABLE`,
`SPLIT_LED_STATE_ENABLE`); Caps Word is mirrored over a small split RPC so the
carets match on both halves.

The display is 5 glyphs wide, so `SCROLL` is abbreviated `SCRL`.

## Build

```
qmk compile -kb sofle/rev1 -km internetlee
qmk flash   -kb sofle/rev1 -km internetlee
```
