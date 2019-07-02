# Run a single Java class file without a project

This is not stated very well, but thanks to this site: [Link](https://stackoverflow.com/questions/2864622/how-do-i-run-class-files-on-windows-from-command-line)

I just had the same issue, I tried running java hello.class, this is wrong.

The command should be java hello.

Do not include the file extension. It is looking for a class file, and will add the name on its own.

So running 'java hello.class' will tell it to go looking for 'hello.class.class' file.