ACSL_Numble
===========

==Use==

Call with
```
ACSL_Numble <horizontal tiles> <vertical tiles>
	<horizontal length>, <vertical length>, <shared tile>
	...
	<EOF>[^Z\n]
```

or set those with the first line of input
```
ACSL_Numble
	<horizontal tiles>, <vertical tiles>
	<horizontal length>, <vertical length>, <shared tile>
	...
	<EOF>[^Z\n]
```

If running from a test file EOF will automatically trigger by the end, be sure that there is a blank line at the end of the file. On linux, eof is thrown with [^D]