
*  Copyright 2014 Andrey Vladimirovich Sobol, andrey.v.sobol@gmail.com

                  README


   Program "paracheck" is a command line tool that can be used to verify if
the parenthesis, brackets, et c. are balanced in a file. By default, it
checks if these parenthesis are balanced: "(){}[]", but the user can
specify any characters that should be viewed as parenthesis. This
characters have to come in pairs and can be specified via command line
options; for example:

          paracheck -p '{}()[]<>' -f data.txt

This is the summary of command line options:

   paracheck [options]

where options are:

   -p <characters>
       Specify the string that contains pairs of characters considered to be
       matching parenthesis. The default set of parenthesis is '(){}[]'.

   -f <File>
       Specify the file to be checked. This option is required. To read from
       stdin, invoke this command with '-f /dev/stdin'.

   -h
   --help
       Print this help.

This program is  distributed under GNU AFFERO GENERAL PUBLIC LICENSE.
You should have received the copy of this license along with the source
code.
