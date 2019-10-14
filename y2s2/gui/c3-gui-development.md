# GUI C3 : GUI Development

## Button

- A component, triggers action when clicked.
- Types (in Swing)
  - Regular
  - Toggle
  - Check box
  - Radio

### `JButton`

- Inherits `AbstractButton`, provide button constructors.

#### Default, Pressed, Rollover icons

- `icon`: Default
- `pressedIcon`: When icon is pressed
- `rolloverIcon`: When mouse is over icon.

## Text Positions

### Horizontal Positions

- Horizontal position relative to icon
- `setHorizontalTextPosition(int)`
  - `int` is one of the constants:
    - `LEADING`,`LEFT`,`CENTER`,`RIGHT` (Default),`TRAILING`

### Vertical Text Positions

- Vertical position relative to icon
- `setVerticalTextPosition(int)`
  - `int` = `TOP`, `CENTER` (Default), `BOTTOM`

## Labels

- Display area for text and/or image

### JLabel

- Inherits all `JComponent` properties

- Example: `JLabel j = new JLabel(text, icon, horizontalAlign)`

## Text Field

- Accept/display string

### `JTextField`

**Constructors** are `JTextField(...)`, where `...` can be (either one can present, but if both then must follow order):

- `String text, int columns`

### Methods

- `getText()`, `setText(String text)`
- `setEditable(boolean b)`, default: `true`. `setColumns(int)`
- `requestFocusInWindow()`

## Events

- Text field events: Enter key fires `ActionEvent`
- Button events:
  - `JButton` can fire multiple events, `ActionEvent` most common (on click)

