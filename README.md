# CS50-Programs

CS50 is an renowned online Computer Science course from Harvard.

This is a repository where all of my problem sets and assignments programs are located.

Descriptions of each program are presented below:
________________________________________________________________________________________________________________________________

0.0 hello.c - Simple program asks name from the user and prints: Hello, ...

0.1 mario.c - Program prints a pyramid of input height.

0.2 population.c - Program asks user for a population start size and end size, uses the following formula start = start + (start / 3) - (start / 4) to calculate how many years it should take for the end size to be reached.

0.3 cash.c - Given a amount of dolars and cents this program calculates the minimum amount of coins needed for the change. If number of dollars is negative, the program asks again.

0.4 credit.c - This program checks the validity and company name of a credit card number. It uses a checksum to verify the validity,  and also check length and starting number to identify from which credit card company that number might be.

0.5 scrabble.c - In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.For example, if we wanted to score the word Code, we would note that in general Scrabble rules, the C is worth 3 points, the o is worth 1 point, the d is worth 2 points, and the e is worth 1 point. Summing these, we get that Code is worth 3 + 1 + 2 + 1 = 7 points. This is an implementation of scrabble.c, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

0.6 readability.c - This program is an implementation of a readability test called Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is: grade = 0.0588 * L - 0.296 * S - 15.8 Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text. The program asks for a text and then returns the grade level.

0.7 caesar.c - Supposedly, Caesar used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places. This program should be run with a comand-line argument of a positive number (key). It then asks for a text to encrypt and return the encrypted text. Keys that have anything other than numbers are invalid and so are more than 1 number. The cipher is case-sensitive and supports ponctuation.

0.8 substitution.c - In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth. This program enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. To prevent user error a number of verifications were implemented to ensure that the key does not contain a number, is 26 letters long, is not case-sensitive and does not allow for repeated letters (used a checksum).

0.9 plurality.c - Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election. Provide the candidates via command-line argument and then the number of voters. Then input which candidate each voter chose. The program will output the results.

1.0 runoff.c - There’s another kind of voting system known as a ranked-choice voting system. In a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. Here, each voter, in addition to specifying their first preference candidate, has also indicated their second and third choices. And now, what was previously a tied election could now have a winner! 

1.1 tideman.c - Implementation of a Tideman election.

1.2 filters.c - Program to apply grayscale, reflection, blur, or edge detection filters to an images.
The function grayscale takes an image and turns it into a black-and-white version of the same image.
The reflect function takes an image and reflects it horizontally.
The blur function takes an image and turns it into a box-blurred version of the same image.
The edges function takes an image and highlights the edges between objects, according to the Sobel operator.

1.3 recover.c - Program accepts one command-line argument, the name of a forensic image from which to recover JPEGs.
If the program is not executed with exactly one command-line argument, it reminds the user of correct usage, and main returns 1.
If the forensic image cannot be opened for reading, the program informs the user as much, and main returns 1.
The files generated each are named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.

Thank you,

Renan Morais da Silva
