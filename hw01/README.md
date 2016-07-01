# ASCII85 (BASE85)

The basic need for a binary-to-text encoding comes from a need to communicate arbitrary binary data over preexisting communications protocols that were designed to carry only human-readable text. Those communication protocols may only be 7-bit safe (and within that avoid certain ASCII control codes), and may require line breaks at certain maximum intervals, and may not maintain whitespace. Thus, only the 95 printable ASCII characters are "safe" to use to convey data.

Four bytes can represent 232 = 4,294,967,296 possible values. Five radix-85 digits provide 855 = 4,437,053,125 possible values, enough to provide for a unique representation for each possible 32-bit value. Because five radix-84 digits only provide 845 = 4,182,119,424 representable values, 85 is the minimum possible integral base that will represent four bytes in five characters, hence its choice.

When encoding, each group of 4 bytes is taken as a 32-bit binary number, most significant byte first (Ascii85 uses a big-endian convention). This is converted, by repeatedly dividing by 85 and taking the remainder, into 5 radix-85 digits. Then each digit (again, most significant first) is encoded as an ASCII printable character by adding 33 to it, giving the ASCII characters 33 ("!") through 117 ("u").

Because all-zero data is quite common, an exception is made for the sake of data compression, and an all-zero group is encoded as a single character "z" instead of "!!!!!".

Groups of characters that decode to a value greater than 232 − 1 (encoded as "s8W-!") will cause a decoding error, as will "z" characters in the middle of a group. White space between the characters is ignored and may occur anywhere to accommodate line-length limitations.

One disadvantage of Ascii85 is that encoded data may contain escape characters such as backslash and quote, which have special meaning in many programming languages and in some text-based protocols.

Source: Wikipedia.org

## Task in seminar:
https://cecko.eu/public/pb071/hw01_2016
