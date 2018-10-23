
<h1 align ="center"> Custom printf Project </h1><br>
<p align="center">
	<a href="https://holbertonschool.com">
		<img alt="holbie" title="holbie" src="https://d1vki863cvir6c.cloudfront.net/uploads/topic/image/485/holberton_school.png" width="350">
	</a>
</p>
<p align="center">
Made as a project for Holberton School
</p>

## Authors

* [Susan Su](https://twitter.com/sususayshello)
* [Christopher Choe](https://twitter.com/chchchoe)

## Table of Contents

- [Introduction](#introduction)
- [Description](#description)
- [Features](#features)
- [Built With](#built-with)
- [Acknowledgments](#acknowledgments)

## Introduction

A custom made printf function built in C using only the write, malloc, free, va_start, va_copy, va__arg, and va_end non custom functions.

## Description

The custom printf function is called using \_printf() and will take in a format string, followed by an optional comma and argument list.

int \_printf(const char \*format, ...);

This is the prototype for our custom printf and will return the number of chararacters printed or in the case of a percentage sign at the end of a string, -1. A percentage sign and a specific conversion specifier in our format string will indicate a special print within the format string when matched with a corresponding provided argument.

## Features

* %c : with a char argument, prints that char

* %s : with a string argument, prints that string

* %d : with an integer argument, prints that integer

* %i : with an integer argument, prints that integer

* %% : will print out just one of the percentage signs

* %r : with a string argument, prints the reversed string

* %R : with a string argument, prints the rot13 encoded version of string

* %p : with a pointer address argument, prints the address in hexadecimal with preceding 0x

* %S : with a string argument, prints any unprintable characters as \x and the 2 digit hexadecimal representation of the character

* %u : with an integer argument, prints the unsigned integer

* %o : with an integer argument, prints the octal notation

* %x : with an integer argument, prints the hexadecimal notation with lowercase letters

* %X : with an integer argument, prints the hexadecimal notation with uppercase letters

* %b : with an integer argument, prints the binary conversion of that integer

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language))
* [Vim](https://www.vim.org/)
* [Vagrant](https://www.vagrantup.com/)
* [Ubuntu](https://www.ubuntu.com/)

## Acknowledgments

* Holberton School
* Wendy Leung, Raven
* The C Programming Language by Brian Kernighan

