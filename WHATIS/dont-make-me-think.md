# What is Don't make me Think

## Background

The idea of "Don't make me Think" comes out of literature like:

- Steve Krug's "[Don't make me think]"
- Kaniel Kahneman's "[Thinking, Fast and Slow]"

Essentially, we want your brain thinking about **what** is being done, not **how** to do it.

We've all seen instructions like:

> Now transfer the output file into the program directory.

Given those instructions you now have to think about:
- What is the output file?
    - Is it a file of a specific name?
    - Where is it?
    - There's a log file, is that part of what needs to be copied?
- Where is the program directory?
     - The program resides in `/usr/bin`.  That's not it
     - Is it the current working directory?
     - Is it something else that I missed in the instructions?
- What is meant by "transfer"?
    - Is it `cp`, `scp`, `ftp`, `rsync`, or something I don't know about.

It would be nice to have a simple set of instruction to illustrate.
Example:

```console
cp ${OUTPUT_DIR}/output-file.txt ${PROGRAM_DIR}
```

where `OUTPUT_DIR` and `PROGRAM_DIR` are defined in previous instructions.

We want to free up your mind to think about **why** the copying is needed, not **how** to do the copying.

With that in mind...

## Guidelines

The following style guidelines help craft Senzing GitHub documentation.

1. Instructions are written using the [second-person, imperative mood].
    1. Instructions use present tense.
    1. Net: Words like you, I, he, she won't be seen much.  When they are used, it's personal :blush:.
1. Each step has examples.
    1. Examples gravitate toward "copy-and-paste".
    1. If variation is needed, operating system environment variable are used.
        1. Environment variables are introduced via the `export` command.
        1. Examples show "working" values.
        1. If customized values are required, a "pencil" icon :pencil2: is present.
        1. Any reference to an environment variable should have information on how it was set.
1. Where thinking is required, a "thinking" icon :thinking: is present.

[Don't make me think]: https://en.wikipedia.org/wiki/Don%27t_Make_Me_Think
[second-person, imperative mood]: https://en.wikipedia.org/wiki/Imperative_mood
[Thinking, Fast and Slow]: https://en.wikipedia.org/wiki/Thinking,_Fast_and_Slow
