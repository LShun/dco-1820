# Practical Test Tips

## Table of Contents

- [Practical Test Tips](#practical-test-tips)
  - [Table of Contents](#table-of-contents)
  - [What is this](#what-is-this)
  - [Why did I make this](#why-did-i-make-this)
  - [General](#general)
  - [Chapter 1 - Basic HTML](#chapter-1---basic-html)
  - [Chapter 3 - CSS](#chapter-3---css)
  - [Chapter 4 - Forms](#chapter-4---forms)
  - [Chapter 4 - Tables](#chapter-4---tables)
  - [Before submitting work](#before-submitting-work)

## What is this

Its not actually tips given by the teacher, but some tips-and-tricks I discovered while trying to study the least amount possible and still get good results. Be noted that if you have used Expression Web 4 extensively, this might not be as relevant to you.

## Why did I make this

"Practice" makes "perfect".

## General

1. Utilize your toolbox
2. Instead of trying to make all the tags align up, right-click inside your coding area, scroll down, click `Reformat HTML` and see the magic.
3. Note that the line separating the `attributes` from the values inside the `Tag properties` and `CSS properties` can be adjusted to reduce mousing over.

## Chapter 1 - Basic HTML

1. Utiize your toolbox, it contains a lot of basic stuff
2. When in doubt of what attributes to add, press `CTRL+S` (or save)
   1. click on the HTML tag. After that, check your "Tag Properties" on the left, it contains nearly every attributes AND events supported by that tag. Thank me later.
   2. If still can't find, click on your HTML element inside the viewport (or the one below your code showing how your code will look like), some attributes like `value` for `<input>` are hidden there
   3. **Beware**: This DOES NOT work with `<option>` especially in `<datalist>`. Please use `value` instead of putting your value in between the opening and closing tags.
3. For image maps, on the top navigation bar, click `View>Toolbars>Pictures`

## Chapter 3 - CSS

1. When in doubt of what CSS you can apply:
   1. `CTRL+S` to save (or else things might not work)
   2. Click `CSS Properties` on the left, contains almost every possible CSS
      1. Click the `+` under the categories to expand and `-` to minimize
   3. If, in case you're not comfortable with a textual approach, go to the right inside `Apply Styles`, click `New Style` to apply most of relevant CSS, be noted that this contain less CSS than method in point 2.
      1. Check `"Apply new style to document selection"` to make things easier, otherwise you have to manually apply them.
      2. To manually apply, select the element, then inside `Apply Styles` on the right, click the style you wanted under `Select CSS to apply:`
   4. For an even more visual approach, on the top ribbon, click `Format` to apply common styles.

## Chapter 4 - Forms

1. For `<input>` tag with `type=date`, be aware that the ONLY acceptable default value is in the format: `yyyy-mm-dd`. Others such as `dd-mm-yyyy` or `yyyy/mm/dd` will get ignored. This will only show up under Chrome's Developer Tools's (F12) `Console`.
2. A quick way to check whether your "validation" works is to mouse over the field in Google Chrome, if it works it will _usually_ indicate a message. Though, if it doesn't, don't hesitate to click `submit` button to verify.
3. Multiple `checkbox` with same name will result in the submission of the last `value`.

## Chapter 4 - Tables

1. On the top ribbon, click `Table` and then `Insert Table`.
2. Reopen `Table` on top ribbon, need I say more?
3. For a more visual approach, be noted that your "viewport" (or the place where you can actively view your code) is extremely useful.
   1. Click on the edge of the table to reveal a `table` label, double click on the label to adjust table properties
   2. Drag the edges to adjust the size
   3. Click on a field to reveal a `td` label, double click on it to reveal column properties like `rowspan` and `colspan`.

## Before submitting work

1. Open your website in Google Chrome, press `F12` and click `Console`, make sure no errors/warnings pop up. If have, decide whether they are worth your time.
2. Right click any of your HTML code inside Expression Web 4's coding area, scroll down, click `Reformat HTML`.