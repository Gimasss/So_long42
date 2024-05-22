FIRST 42Core Project - no bonus part for the moment.
100% passed by Moulinette.
Random notes to be found around.

MAKEFILE EXPLANATION

A) The Makefile starts by defining some variables:

1) `NAME` is the name of the library that will be created.
2) `CC` is the compiler to be used, in this case, gcc.
3) `CFLAGS` are the flags that will be passed to the compiler. 
	Here, `-Wall -Wextra -Werror` are used, which enable all warning messages, 
	extra warning messages, and treat warnings as errors, respectively.
4) `LIBCMP` is the command to create a static library. `ar rcs` creates an 
	archive and inserts files into it.
	
	WHAT IS AR RCS?
	`ar` is a Unix utility that maintains groups of files as a single archive file. 
	It's commonly used to create and update library files that the link editor or linker uses. 
	The options `rcs` passed to `ar` have the following meanings:

		- `r`: Replace existing or insert new file(s) into the archive.
		- `c`: Create the archive. The `c` option is often used to suppress a warning message 
		if the library did not exist.
		- `s`: Write an object-file index into the archive, or update an existing one, even if 
		no other change is made to the archive. This is usually used for building a library.

	So, `ar rcs` is used to create a new archive (static library in this case), add files to
	it, and index it.
4) `RM` is the command to remove files or directories.
5) `MNDT` is a list of source files (mandatory ones) that will be compiled into object files
	and then archived into the static library.

B) Rules of the Makefile:

1) The `%.o: %.c` rule is a pattern rule. It tells `make` how to create a `.o` (object) 
	file from a `.c` (C source) file. 
	The '%' character is a wildcard that can match any string, and it must match the same 
	in both the target and the prerequisite. For example, if there's a file main.c in the 
	directory, this rule will match and main.o will be the target that depends on main.c.

The command that follows ($(CC) $(CFLAGS) -c $^ -o $@) is a rule which tells MAKE how to compile
a .c file into a .o file using the specified compiler and flags. Therefore, it uses the `CC` and
`CFLAGS` variables to compile the source file (`$^`) into an object file (`$@`).

	The -c option tells the compiler to generate an object file rather than an executable file.

	The $< and $@ are automatic variables in make. $< represents the first prerequisite of the target,
	and in this case, it will be the .c file that matched the '%' in the dependency line. 
	
	$@ represents the target of the rule, and in this case, it will be the .o file that matched the
	'%' in the dependency line.

2) The `all` target builds the `$(NAME)` target, which is `libft.a`. This target depends on `$(MNDT_OBJ)`,
	which is not defined in the provided excerpt. Presumably, it's a list of object files corresponding to
	the source files listed in `MNDT`. The command for this target uses `$(LIBCMP)` to archive the object
	files into the static library.

3) The `clean` target removes the object files using the `$(RM)` command. 
	These are the intermediate files generated when the source files are compiled. 
	They are not needed once the final library or executable has been built.

4) The `fclean` target first executes the `clean` target and then removes the library file.
	It does everything clean does (it actually calls clean as part of its process), and then also
	removes the final library or executable file that was built from the object files. This is useful
	when you want to ensure that you're starting from a completely clean state for a new build.

5) The `re` target first executes the `fclean` target and then the `all` target. 
	This effectively cleans up all generated files and then rebuilds the project from scratch.

6) Finally, `.PHONY` is a special target that specifies that `all`, `clean`, `fclean`, and `re`
	are not files. This is necessary because if there were a file named `all`, `clean`, `fclean`,
	or `re` in the directory, `make` would not execute the corresponding target.
