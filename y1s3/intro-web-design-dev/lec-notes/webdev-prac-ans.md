## Web Development Practice Questions Answer

- [Web Development Practice Questions Answer](#web-development-practice-questions-answer)
- [Prac. Ques.](#prac-ques)
- [a. Define the following terms:](#a-define-the-following-terms)
  - [b. Write HTML codes to create the following:](#b-write-html-codes-to-create-the-following)
- [Q1](#q1)
  - [a) Write HTML codes to do the following:](#a-write-html-codes-to-do-the-following)
  - [b) Create image map](#b-create-image-map)
  - [c) Write relative path](#c-write-relative-path)
  - [d) Differentiate between](#d-differentiate-between)
    - [Insert diagram of linear and hiearchical structures](#insert-diagram-of-linear-and-hiearchical-structures)

## Prac. Ques.

## a. Define the following terms:

1. **Hypertext**: Text that allows a user to be redirected to another section or a different website when clicked or interacted.
2. **LAN**: A network in a small area, usually within a building.
3. **Content box model**: A type of box model that includes only the content in the width and height specification.
4. **Border box model**: A type of box model that includes the content, border, margin, and padding in the width and height specification.
5. **Metadata**: Data stored in meta tags that indicate to the browser how to display the contents.
6. **Web Browser**: A software that allows a user to find, navigate and view websites.
7. **HTML Converter**: A software that formats content with respect to HTML specifications into a webpage.

### b. Write HTML codes to create the following:

1. Mark the text `Web Design` as a paragraph
   1. `<p>Web Design</p>`
2. Mark the text `Technical Documentation` as an `h1` heading
   1. `<h1>Technical documentation</h1>`
3. Insert an inline image using the file `image.png` and the alternate text `Pixel size`.
   1. `<img src="image.png" alt="Pixel size">`

## Q1

### a) Write HTML codes to do the following:

1. `<a href="assessment.html#assign">Assignment</a>`
2. `<a href="mailto:vasantha@tarc.edu.my">Email</a>`

### b) Create image map

```html
<map id="imap" name="imap">
    <area shape="rect" coords="10, 20, 100, 150" href="rect.html">
    <area shape="circle" coords="200, 250, 50" href="circle.html">
</map>
```

### c) Write relative path

1. `../contact/location.html`
2. `../index.html`
3. `men.html`

### d) Differentiate between

1. Inline CSS vs Embedded CSS

Differences:

   1. Inline CSS is located inside the element tag, while embedded CSS is located in the document's <HEAD> tag.
   2. Inline CSS can only be appled within 1 element, which embedded CSS can be applied to multiple unrelated elements with the same tag.
   3. Inline CSS can contain only styling for 1 element, wile embedded CSS can contain styling for multiple different elements.
   4. Inline CSS is specified as an attributte, while embedded CSS is specified in an opening and closing <STYLE> tag.

2. Linear and hiearchical structures

#### Insert diagram of linear and hiearchical structures

1. Linear structure allows navigation in a sequential order. Hiearchical structure allows navigation anywhere in the website.
2. Linear structure requires a user to go through all of the pages whether necessary or not. Hiearchical structure allows a user to skip through unnecessary pages.