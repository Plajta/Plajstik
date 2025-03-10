# Plajstick config
Completely configured, completely hypothetical config JSON:
```json
{
  "version": 2,
  "buttons": {
    "0": "select",
    "1": "start",
    "2": "home",

    "3": "a",
    "4": "b",
    "5": "x",
    "6": "y",

    "7": "r1",
    "8": "l1",
    "9": "r2",
    "10": "l2",
    "11": "r3",
    "12": "l3",

    "13": "dpad_u",
    "14": "dpad_r",
    "15": "dpad_d",
    "16": "dpad_l"
  },
  "deadzone": 16.0,
  "axes": {
    "x": 1,
    "y": 0
  },
  "multiplier": {
    "x": 1.0,
    "y": 1.0
  }
}
```
## Version
Describes what version of firmware this config is compatible with

Only change if you really know what you're doing

## Buttons
List of button names and to what GPIOs are they bound to

Example:
```
"3": "l3"
```
Button L3 (Left stick button) is bound to GPIO 3.

All possible buttons: `a`, `b`, `x`, `y`, `l1`, `r1`, `l2`, `r2`, `l3`, `l3`, `select`, `start`, `home`, `dpad_u`, `dpad_r`, `dpad_d`, `dpad_l`

## Deadzone
Describes the diameter of the deadzone, this number cannot really be compared to anything so it's ideal size is really only a matter of trial and error.

## Axes
**Currently missing support for triggers and right analog stick**

List of axis names and to what ADC inputs are they bound to

Example:
```
"x": 1
```
X left analog axis is bound to ADC 1.

## Multiplier
Floating point numbers that multiply the ADC output so the range can be limited, extended or inverted.

Example:
```
"y": -0.32
```
Y axis is multiplied by -0.32.
