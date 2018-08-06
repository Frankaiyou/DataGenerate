### The Introduction of **Data Generate**
There are four main files in it;
- `main.exe`: Main program;
- `data.cpp`: The Builder of a alone data;
- `Std.cpp`: The program to convert Input File to Output File;
- `settings.txt`: The Configuration of the program.

You should generate you Datas by
1. Modify the `settings.txt`;
2. Code the `data.cpp` or `Std.cpp`;
3. Run the `1.exe`.

I use c++, you also can use other Programming language to do it, such as Python and C#;
It can used in windows and you need a c++ complier likes `G++`, you can alse try it in Linux.


### The usage of the `setting .txt`.

There is a example of it;

    DataProgramName: data
    stdProgramName: std
    InputFileName: data\\break.in
    OutputFileName: data\\break.out
    TempFileName: a.txt
    TheSizeOfData: 10

The above is the parameters of the `1.exe`.
- The file name of the Builder of a alone data, default is `data`, not including extension name;
- The program to convert Input File to Output File, default is `Std`, not including extension name;
- The file name (also can addition the relative path)of the Input Files, including extenson name;
- The file name (also can addition the relative path)of the Output Files;
- The file name of the temporary file, including the extension name;
- The number of datas.

Note that:
- Can't delete the Space, such as the space bettwen the ¡°DataProgramName:¡± and "data".
- Must replace the `\` or `/` to '\\' in the relative path, because of the rule of c++.
- The temporary file's function is let me know the now work, if now it is making the Sixth data, the number in the file must be in (5000,6000).
