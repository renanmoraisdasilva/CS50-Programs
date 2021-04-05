# CS50-Programs

CS50 is an renowned online Computer Science course from Harvard.

This is a repository where all of my problem sets and assignments programs are located. Descriptions of each program are presented below.

1 hello.c - Simple program asks name from the user and prints: Hello, ...

2 mario.c - Program prints a pyramid of input height.

3 population.c - Program asks user for a population start size and end size, uses the following formula start = start + (start / 3) - (start / 4) to calculate how many years it should take for the end size to be reached.

4 cash.c - Given a amount of dolars and cents this program calculates the minimum amount of coins needed for the change. If number of dollars is negative, the program asks again.

5 credit.c - This program checks the validity and company name of a credit card number. It uses a checksum to verify the validity,  and also check length and starting number to identify from which credit card company that number might be.

6 scrabble.c - In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.For example, if we wanted to score the word Code, we would note that in general Scrabble rules, the C is worth 3 points, the o is worth 1 point, the d is worth 2 points, and the e is worth 1 point. Summing these, we get that Code is worth 3 + 1 + 2 + 1 = 7 points. This is an implementation of scrabble.c, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

7 readability.c - This program is an implementation of a readability test called Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is: grade = 0.0588 * L - 0.296 * S - 15.8 Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text. The program asks for a text and then returns the grade level.

8 caesar.c - Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places. This program should be run with a comand-line argument of a positive number (key). It then asks for a text to encrypt and return the encrypted text. Keys that have anything other than numbers are invalid and so are more than 1 number. The cipher is case-sensitive and supports ponctuation.

9 substitution.c - In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth. This program enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.

Thank you,

Renan Morais da Silva
