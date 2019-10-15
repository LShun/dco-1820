# C6: GUI Componenets II

At the end of this lesson, you should be able to:

- LO1: Create graphical user interfaces with checkboxes, radio buttons, combo boxes, and lists
- LO2: Create listeners for various types of events
- LO3: Display multiple windows in an application
- LO4: Create menus using components JMenuBar, JMenu, and JMenuItem

## LO1 `JCheckBox`, `JRadioButton`, `JComboBox`, `JList`

## `JTextBox`

- Inherits all properties
- On-click: Fires an `ItemEvent`, then `ActionEvent`
- Check/uncheck: `itemStateChanged() -> actionPerformed()` 
  - Note: `itemStateChanged() is part of ``ItemEvent` and so on.

### `JRadioButton`

- Usually used in groups, only one checked at a time

- Grouping

  ```java
  ButtonGroup g = new ButtonGroup();
  g.add(b1);
  g.add(b2);
  ```

### Array of Components

- Component is an object, therefore, can be put in array

### `JComboBox`

- *Combo box* is a list of items user can choose from.

- Example: 

  `JComboBox j = new JComboBox(new Object[] "I1", "I2");`

- Methods:
  - `addItem(Object item)`
  - `getSelectedItem()`
  - `getItem()`
- Events:
  - Fires `ItemEvent` and `ActionEvent`
  - Reselecting an item do not fire `ItemEvent`

### `JList`

- Same as combo box, but allows multiple selections
- Constructors:
  - `JList()` and `JList(Object[] stringItems)`
- Properties:
  - `selectedIndex`, `selectedIndices`
  - `selectedValue`, `selectedValues`
  - `selectionMode`, `visibleRowCount`

### Menus

- Classes:
  - `JMenuBar`
  - `JMenu`
  - `J[Menu/CheckBox/RadioButton]Item`

- `JFrame` holds menu bar, which holds menus.

- Example:

  - `JMenuBar`

    ```java
    JMenuBar mb = new JMenuBar();
    frame.setJMenuBar(mb);
    ```

  - `JMenu`

    ```java
    JMenu fileMenu = new JMenu("File", false);
    mb.add(fileMenu);
    ```

  - `JMenuItem`

    ```java
    fileMenu.add(new JMenuItem("new"));
    fileMenu.addSeparator(); // optional
    ```

  - Submenus

    ```java
    JMenu saveMenu = new JMenu("Save...");
    JMenu openMenu = new JMenu("Open...");
    fileMenu.add(saveMenu);
    fileMenu.add(openMenu);
    saveMenu.add(new JMenuItem("as a PDF"));
    ```

### Icons, Keyboard Mnemonics, Keyboard Accelerators

- Icons

  ```java
  saveMenu.add(stxt = new JMenuItem("as text"));
  stxt.setIcon(new ImageIcon("img/txt.png"));
  ```

- KB Mnemonics

  - Allows selection of menu items from currently open menu.

  ```java
  saveMenu.setMnemonic("S");
  ```

- KB Accelerators

  - Allows selection by pressing CTRL+Accelerator Key

    ```java
    stxt.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S), ActionEvent.CTRL_MASK));
    ```

## Multiple Windows

- Main frame = `main window`. New windows = `subwindows`
- Steps to create
  -  Create main window
  - Create sub window
  - Implement `actionPerformed` handler in main window to connect to the sub window.

## [Optional] Other Topics

- `JScrollBar`: Typical scrollbar
- `JSlider`: Typical range value selector with a slider
- `CardLayout`: Like tabs, but use a drop-down selection to switch
- `BoxLayoout`: Like `FlowLayout`, but can choose direction.
- `JTabbedPane`: Typical tabs
- `JSplitPane`: Typical split panel, allows in-between resizing
- `Action`: Something like a macro/function for actions.
  - Allows single point change.
- `AbstractAction`: An abstract class used to create `Action`





